#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * This file walks the AST built by exprtree.c and writes XSM instructions.
 * It also owns temporary-register/label tracking, stack-frame setup, the
 * fixed-block heap routines, and runtime method-table initialization.
 */
extern FILE *targetFile;

int reg = -1;
int label = 0;

#define MAX_LOOP_DEPTH 100

static int loopTop = -1;
static int loopBreak[MAX_LOOP_DEPTH];
static int loopContinue[MAX_LOOP_DEPTH];
static int generatingMain;
static int currentLocalCount;

/* R19 is reserved for library-call scratch values. */
/*
 * FUNCTION: getReg
 * PURPOSE: Reserve the next temporary register for an AST expression.
 * INPUT: None.
 * RETURN: The reserved register number; exits if the register limit is reached.
 * FLOW: Advance the shared register counter and return the new value.
 */
int getReg(void) {
    if (reg >= 18) {
        fprintf(stderr, "Out of registers\n");
        exit(1);
    }
    return ++reg;
}

/*
 * FUNCTION: freeReg
 * PURPOSE: Release the most recently reserved temporary register.
 * INPUT: None.
 * RETURN: Nothing.
 * FLOW: Move the shared register counter back by one when a register is in use.
 */
void freeReg(void) {
    if (reg >= 0) {
        --reg;
    }
}

/*
 * FUNCTION: getLabel
 * PURPOSE: Give generated branches a unique label number.
 * INPUT: None.
 * RETURN: The next unused label number.
 * FLOW: Return the current counter, then advance it for the next request.
 */
int getLabel(void) {
    return label++;
}

/* Remember loop exit/continue labels so break and continue target the
 * innermost loop currently being generated. */
static void pushLoop(int breakLabel, int continueLabel) {
    loopBreak[++loopTop] = breakLabel;
    loopContinue[loopTop] = continueLabel;
}

/* Remove the innermost loop after its body has been generated. */
static void popLoop(void) {
    --loopTop;
}

/* Get a variable's address: locals use BP plus binding; globals use fixed binding. */
static int idAddress(tnode *t) {
    int addressReg = getReg();

    if (t->Lentry != NULL) {
        fprintf(targetFile, "MOV R%d, BP\n", addressReg);
        fprintf(targetFile, "ADD R%d, %d\n", addressReg, t->Lentry->binding);
    } else {
        fprintf(targetFile, "MOV R%d, %d\n", addressReg, t->Gentry->binding);
    }
    return addressReg;
}

/* Compute a one-dimensional element address as base plus its evaluated index. */
static int arrayAddress(tnode *t) {
    int indexReg = codeGen(t->left);
    int baseReg = getReg();

    if (t->Lentry != NULL) {
        fprintf(targetFile, "MOV R%d, BP\n", baseReg);
        fprintf(targetFile, "ADD R%d, %d\n", baseReg, t->Lentry->binding);
    } else {
        fprintf(targetFile, "MOV R%d, %d\n", baseReg, t->Gentry->binding);
    }
    fprintf(targetFile, "ADD R%d, R%d\n", indexReg, baseReg);
    freeReg();
    return indexReg;
}

/* Compute a row-major two-dimensional address: base + row*column_count + column. */
static int array2Address(tnode *t) {
    int rowReg = codeGen(t->left);
    int colReg = codeGen(t->middle);
    int baseReg = getReg();
    int colsReg = getReg();

    if (t->Lentry != NULL) {
        fprintf(targetFile, "MOV R%d, BP\n", baseReg);
        fprintf(targetFile, "ADD R%d, %d\n", baseReg, t->Lentry->binding);
        fprintf(targetFile, "MOV R%d, %d\n", colsReg, t->Lentry->cols);
    } else {
        fprintf(targetFile, "MOV R%d, %d\n", baseReg, t->Gentry->binding);
        fprintf(targetFile, "MOV R%d, %d\n", colsReg, t->Gentry->cols);
    }
    fprintf(targetFile, "MUL R%d, R%d\n", rowReg, colsReg);
    fprintf(targetFile, "ADD R%d, R%d\n", rowReg, colReg);
    fprintf(targetFile, "ADD R%d, R%d\n", rowReg, baseReg);

    freeReg();
    freeReg();
    freeReg();
    return rowReg;
}

/* Return the address of a variable, array element, dereference, or field. */
static int lvalueAddress(tnode *t) {
    int addressReg;

    switch (t->nodetype) {
    case NODE_ID:
        return idAddress(t);
    case NODE_ARRAY:
        return arrayAddress(t);
    case NODE_ARRAY2D:
        return array2Address(t);
    case NODE_DEREFERENCE:
        return codeGen(t->left);
    case NODE_FIELD:
        addressReg = lvalueAddress(t->left);
        /* Aggregate values (user-defined types and class objects) are stored
         * as pointers; fields live at offsets from the pointed-to block. */
        if (t->Fentry == NULL) {
            fprintf(stderr, "Error: field access has no field-table entry\n");
            exit(1);
        }
        fprintf(targetFile, "MOV R%d, [R%d]\n", addressReg, addressReg);
        fprintf(targetFile, "ADD R%d, %d\n", addressReg, t->Fentry->fieldIndex);
        return addressReg;
    default:
        fprintf(stderr, "Error: expression is not an assignable location\n");
        exit(1);
    }
}

/* Identify a class variable stored directly in a global or local slot. */
static int isDirectClassVariable(tnode *t) {
    return t != NULL && t->classType != NULL && t->nodetype == NODE_ID &&
           (t->Gentry != NULL || t->Lentry != NULL);
}

/* Check whether an assignable location stores the two words of a class value. */
static int isClassValueLocation(tnode *t) {
    return isDirectClassVariable(t) ||
           (t != NULL && t->nodetype == NODE_FIELD && t->classType != NULL &&
            t->Fentry != NULL);
}

/* Class values store [member pointer, vtable pointer]. */
/* Find the address of the vtable word paired with a class object's pointer. */
static int classVTableAddress(tnode *t) {
    int addressReg;

    if (t != NULL && t->nodetype == NODE_FIELD && t->classType != NULL &&
        t->Fentry != NULL) {
        addressReg = lvalueAddress(t);
        fprintf(targetFile, "ADD R%d, 1\n", addressReg);
        return addressReg;
    }

    if (!isDirectClassVariable(t)) {
        fprintf(stderr, "Error: class value does not have a pair binding\n");
        exit(1);
    }

    if (t->Lentry != NULL) {
        addressReg = getReg();
        fprintf(targetFile, "MOV R%d, BP\n", addressReg);
        fprintf(targetFile, "ADD R%d, %d\n", addressReg,
                t->Lentry->vtableBinding);
    } else {
        addressReg = getReg();
        fprintf(targetFile, "MOV R%d, %d\n", addressReg,
                t->Gentry->binding + 1);
    }
    return addressReg;
}

/* Load the vtable pointer for a class value; NULL has a zero table pointer. */
static int classVTableValue(tnode *t) {
    int addressReg;

    if (t != NULL && t->nodetype == NODE_NULL) {
        addressReg = getReg();
        fprintf(targetFile, "MOV R%d, 0\n", addressReg);
        return addressReg;
    }

    addressReg = classVTableAddress(t);
    fprintf(targetFile, "MOV R%d, [R%d]\n", addressReg, addressReg);
    return addressReg;
}

/* Stop the running XSM program through the shared runtime library. */
static void emitExit(void) {
    fprintf(targetFile, "MOV R19, \"Exit\"\n");
    fprintf(targetFile, "PUSH R19\nPUSH R19\nPUSH R19\nPUSH R19\nPUSH R19\n");
    fprintf(targetFile, "CALL 0\n");
}

/* Keep allocator code in the generated program.  R19 is outside the
 * expression register allocator; save the live expression registers before
 * using R1-R5 as allocator temporaries. */
static void saveRegsThrough(int lastReg) {
    int i;
    for (i = 0; i <= lastReg; ++i) fprintf(targetFile, "PUSH R%d\n", i);
}

/* Restore saved expression registers in reverse order, matching the pushes above. */
static void restoreRegsThrough(int lastReg) {
    int i;
    for (i = lastReg; i >= 0; --i) fprintf(targetFile, "POP R%d\n", i);
}

/* Build the free-block chain in heap words 1024..2047 before user code runs. */
static void emitHeapInit(void) {
    int loop = getLabel();
    int done = getLabel();

    /* Address 1024 stores the head.  Blocks are eight words each, starting
     * at 1032; the first word of each free block links to the next one. */
    fprintf(targetFile, "MOV R1, 1032\nMOV R2, 1040\nMOV R3, 2040\n");
    fprintf(targetFile, "L%d:\nMOV R4, R1\nEQ R4, R3\nJNZ R4, L%d\n", loop, done);
    fprintf(targetFile, "MOV [R1], R2\nADD R1, 8\nADD R2, 8\nJMP L%d\n", loop);
    fprintf(targetFile, "L%d:\nMOV R4, -1\nMOV [R1], R4\n", done);
    fprintf(targetFile, "MOV R1, 1024\nMOV R2, 1032\nMOV [R1], R2\n");
}

/* Generate an allocation request and return a free block. The allocator uses
 * eight-word blocks and preserves expression registers around its scratch work. */
static void emitAlloc(int resultReg, int savedTop, int size) {
    int bad = getLabel();
    int haveBlock = getLabel();
    int done = getLabel();

    saveRegsThrough(savedTop);
    fprintf(targetFile, "MOV R1, %d\nMOV R2, 0\nMOV R3, R1\nLE R3, R2\nJNZ R3, L%d\n", size, bad);
    fprintf(targetFile, "MOV R2, 8\nMOV R3, R1\nGT R3, R2\nJNZ R3, L%d\n", bad);
    fprintf(targetFile, "MOV R1, [1024]\nMOV R2, -1\nMOV R3, R1\nEQ R3, R2\nJZ R3, L%d\n", haveBlock);
    fprintf(targetFile, "L%d:\nMOV R1, -1\nMOV R%d, R1\nJMP L%d\n", bad, resultReg, done);
    fprintf(targetFile, "L%d:\nMOV R2, [R1]\nMOV [1024], R2\n", haveBlock);
    fprintf(targetFile, "MOV R%d, R1\nL%d:\n", resultReg, done);
    restoreRegsThrough(savedTop);
}

/* Return a valid allocated block to the free list; invalid addresses are ignored. */
static void emitFree(int pointerReg, int savedTop) {
    int bad = getLabel();
    int scan = getLabel();
    int clear = getLabel();
    int clearLoop = getLabel();
    int done = getLabel();

    saveRegsThrough(savedTop);
    fprintf(targetFile, "MOV R1, R%d\nMOV R2, 1032\nMOV R3, R1\nLT R3, R2\nJNZ R3, L%d\n", pointerReg, bad);
    fprintf(targetFile, "MOV R2, 2040\nMOV R3, R1\nGT R3, R2\nJNZ R3, L%d\n", bad);
    fprintf(targetFile, "MOV R2, R1\nSUB R2, 1032\nMOV R3, 8\nMOD R2, R3\nJNZ R2, L%d\n", bad);
    fprintf(targetFile, "MOV R2, [1024]\nL%d:\nMOV R3, -1\nMOV R4, R2\nEQ R4, R3\nJNZ R4, L%d\n", scan, clear);
    fprintf(targetFile, "MOV R4, R2\nEQ R4, R1\nJNZ R4, L%d\nMOV R2, [R2]\nJMP L%d\n", bad, scan);
    fprintf(targetFile, "L%d:\nMOV R3, R1\nMOV R4, 0\nMOV R5, 8\n", clear);
    fprintf(targetFile, "L%d:\nMOV [R3], R4\nADD R3, 1\nSUB R5, 1\nJNZ R5, L%d\n", clearLoop, clearLoop);
    fprintf(targetFile, "MOV R2, [1024]\nMOV [R1], R2\nMOV [1024], R1\nJMP L%d\n", done);
    fprintf(targetFile, "L%d:\nL%d:\n", bad, done);
    restoreRegsThrough(savedTop);
}

/* Call the runtime Read routine with the address of the requested variable. */
static void emitRead(tnode *variable) {
    int addressReg = lvalueAddress(variable);

    fprintf(targetFile, "MOV R19, \"Read\"\nPUSH R19\n");
    fprintf(targetFile, "MOV R19, -1\nPUSH R19\n");
    fprintf(targetFile, "PUSH R%d\nPUSH R19\nPUSH R19\nCALL 0\n", addressReg);
    fprintf(targetFile, "POP R19\nPOP R19\nPOP R19\nPOP R19\nPOP R19\n");
    freeReg();
}

/* Evaluate and push arguments in the stack order expected by the callee.
 * Class arguments occupy two words; the table pointer is pushed before the object pointer. */
static void pushArgs(tnode *arguments, Paramstruct *parameters) {
    int valueReg;

    if (arguments == NULL) {
        return;
    }

    pushArgs(arguments->right, parameters->next);
    if (parameters->classType != NULL) {
        int tableReg;

        if (arguments->left != NULL && arguments->left->nodetype == NODE_NULL) {
            fprintf(targetFile, "MOV R19, 0\nPUSH R19\nPUSH R19\n");
            return;
        }
        tableReg = classVTableValue(arguments->left);
        valueReg = codeGen(arguments->left);
        /* Push the second word first, leaving the member pointer at the
           parameter's base binding in the callee. */
        fprintf(targetFile, "PUSH R%d\nPUSH R%d\n", tableReg, valueReg);
        freeReg();
        freeReg();
        return;
    }

    valueReg = codeGen(arguments->left);
    fprintf(targetFile, "PUSH R%d\n", valueReg);
    freeReg();
}

/* Count stack words, not parameter count, because class values take two words. */
static int argWordCount(Paramstruct *parameters) {
    int count = 0;

    while (parameters != NULL) {
        count += parameters->classType != NULL ? 2 : 1;
        parameters = parameters->next;
    }
    return count;
}

/* Generate a direct function call, including saved registers, arguments,
 * return-value space, and caller-side stack cleanup. */
static int functionCall(tnode *t) {
    int savedTop = reg;
    int arguments = argWordCount(t->Gentry->paramlist);
    int i;
    int resultReg;

    for (i = 0; i <= savedTop; ++i) {
        fprintf(targetFile, "PUSH R%d\n", i);
    }

    pushArgs(t->arglist, t->Gentry->paramlist);
    fprintf(targetFile, "PUSH R19\n");
    fprintf(targetFile, "CALL F%d\n", t->Gentry->flabel);

    resultReg = getReg();
    fprintf(targetFile, "POP R%d\n", resultReg);
    while (arguments-- > 0) {
        /* Do not overwrite the returned value (which may be in R0). */
        fprintf(targetFile, "POP R19\n");
    }
    for (i = savedTop; i >= 0; --i) {
        fprintf(targetFile, "POP R%d\n", i);
    }
    return resultReg;
}

/* Resolve the receiver's runtime table slot, call that method, then remove
 * explicit arguments and the two hidden receiver values from the stack. */
static int methodCall(tnode *t) {
    int savedTop = reg;
    int arguments;
    int tableReg;
    int receiverReg;
    int resultReg;
    int i;

    if (t->Mentry == NULL || t->left == NULL) {
        fprintf(stderr, "Error: method call is missing its method or receiver\n");
        exit(1);
    }
    arguments = argWordCount(t->Mentry->paramlist);

    for (i = 0; i <= savedTop; ++i) {
        fprintf(targetFile, "PUSH R%d\n", i);
    }

    tableReg = classVTableValue(t->left);
    /* Push both implicit receiver values before the explicit parameters. */
    fprintf(targetFile, "PUSH R%d\n", tableReg);
    receiverReg = codeGen(t->left);
    fprintf(targetFile, "PUSH R%d\n", receiverReg);
    freeReg();

    fprintf(targetFile, "ADD R%d, %d\n", tableReg, t->Mentry->funcposition);
    fprintf(targetFile, "MOV R%d, [R%d]\n", tableReg, tableReg);

    pushArgs(t->arglist, t->Mentry->paramlist);
    fprintf(targetFile, "PUSH R19\n");
    fprintf(targetFile, "CALL R%d\n", tableReg);

    freeReg(); /* dynamically loaded method address */
    resultReg = getReg();
    fprintf(targetFile, "POP R%d\n", resultReg);
    while (arguments-- > 0) {
        fprintf(targetFile, "POP R19\n");
    }
    fprintf(targetFile, "POP R19\nPOP R19\n"); /* self object and vtable */
    for (i = savedTop; i >= 0; --i) {
        fprintf(targetFile, "POP R%d\n", i);
    }
    return resultReg;
}

/* Generate one two-operand XSM instruction and release its right operand register. */
static void binary(tnode *t, const char *instruction) {
    int leftReg = codeGen(t->left);
    int rightReg = codeGen(t->right);

    fprintf(targetFile, "%s R%d, R%d\n", instruction, leftReg, rightReg);
    freeReg();
}

/*
 * FUNCTION: codeGen
 * PURPOSE: Generate XSM instructions for one AST node.
 * INPUT: The AST node to translate.
 * RETURN: Register containing an expression result, or -1 for a statement.
 * FLOW: Visit child nodes as needed, emit the matching instruction sequence,
 * and manage temporary registers and control-flow labels.
 */
int codeGen(tnode *t) {
    int resultReg;
    int addressReg;
    int allocationSize;
    int labelOne;
    int labelTwo;

    if (t == NULL) {
        return -1;
    }

    switch (t->nodetype) {
    /* Leaf expressions either load a constant or fetch a value from its resolved address. */
    case NODE_NUM:
        resultReg = getReg();
        fprintf(targetFile, "MOV R%d, %d\n", resultReg, t->val);
        return resultReg;

    case NODE_STR:
        resultReg = getReg();
        fprintf(targetFile, "MOV R%d, \"%s\"\n", resultReg, t->varname);
        return resultReg;

    case NODE_NULL:
        resultReg = getReg();
        fprintf(targetFile, "MOV R%d, 0\n", resultReg);
        return resultReg;

    case NODE_ID:
        resultReg = idAddress(t);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    case NODE_ADDRESS:
        return idAddress(t->left);

    case NODE_DEREFERENCE:
        resultReg = codeGen(t->left);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    case NODE_FIELD:
        resultReg = lvalueAddress(t);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    case NODE_ARRAY:
        resultReg = arrayAddress(t);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    case NODE_ARRAY2D:
        resultReg = array2Address(t);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    /* Arithmetic and comparison nodes share binary(): it generates both children,
     * applies one XSM operation, and leaves the result in the left register. */
    case NODE_PLUS: binary(t, "ADD"); return reg;
    case NODE_MINUS: binary(t, "SUB"); return reg;
    case NODE_MUL:
    case NODE_AND: binary(t, "MUL"); return reg;
    case NODE_DIV: binary(t, "DIV"); return reg;
    case NODE_MOD: binary(t, "MOD"); return reg;
    case NODE_LT: binary(t, "LT"); return reg;
    case NODE_GT: binary(t, "GT"); return reg;
    case NODE_LE: binary(t, "LE"); return reg;
    case NODE_GE: binary(t, "GE"); return reg;
    case NODE_EQ: binary(t, "EQ"); return reg;
    case NODE_NE: binary(t, "NE"); return reg;

    case NODE_OR:
        labelOne = codeGen(t->left);
        labelTwo = codeGen(t->right);
        fprintf(targetFile, "ADD R%d, R%d\n", labelOne, labelTwo);
        fprintf(targetFile, "MOV R%d, 0\n", labelTwo);
        fprintf(targetFile, "NE R%d, R%d\n", labelOne, labelTwo);
        freeReg();
        return labelOne;

    /* Calls use separate helpers because direct calls and virtual method calls
     * have different label lookup and hidden-argument rules. */
    case NODE_FUNCTION:
        return functionCall(t);

    case NODE_METHOD_CALL:
        return methodCall(t);

    /* A class assignment copies both object and vtable words. Other assignments
     * evaluate the RHS and store one word at the lvalue address. */
    case NODE_ASSIGN:
        if (isClassValueLocation(t->left) &&
            (isClassValueLocation(t->right) ||
             (t->right != NULL && t->right->nodetype == NODE_NULL))) {
            int tableReg = classVTableValue(t->right);
            resultReg = codeGen(t->right);
            addressReg = lvalueAddress(t->left);
            fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
            {
                int tableAddress = classVTableAddress(t->left);
                fprintf(targetFile, "MOV [R%d], R%d\n", tableAddress, tableReg);
                freeReg();
            }
            freeReg();
            freeReg();
            freeReg();
            return -1;
        }
        resultReg = codeGen(t->right);
        addressReg = lvalueAddress(t->left);
        fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
        freeReg();
        freeReg();
        return -1;

    /* Allocation/deallocation call the in-program heap routines while preserving
     * live registers, then update the variable that stores the returned pointer. */
    case NODE_ALLOC:
        if (t->classType != NULL) {
            /* Stage 7 class objects use a fixed eight-word member block. */
            allocationSize = 8;
        } else if (t->left != NULL && t->left->typeEntry != NULL) {
            allocationSize = GetSize(t->left->typeEntry);
        } else {
            fprintf(stderr, "Error: allocation target has no allocatable type\n");
            exit(1);
        }
        resultReg = getReg();
        emitAlloc(resultReg, resultReg - 1, allocationSize);
        addressReg = lvalueAddress(t->left);
        fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
        if (t->classType != NULL && isClassValueLocation(t->left)) {
            int tableReg = getReg();
            fprintf(targetFile, "MOV R%d, %d\n", tableReg,
                    4096 + t->classType->classIndex * 8);
            {
                int tableAddress = classVTableAddress(t->left);
                fprintf(targetFile, "MOV [R%d], R%d\n", tableAddress, tableReg);
                freeReg();
            }
            freeReg();
        }
        freeReg();
        freeReg();
        return -1;

    case NODE_FREE:
        resultReg = codeGen(t->left);
        emitFree(resultReg, reg);
        freeReg();
        return -1;

    case NODE_CONNECTOR:
        codeGen(t->left);
        codeGen(t->right);
        return -1;

    /* I/O uses the runtime library ABI: push its operation arguments, CALL 0,
     * then remove the five words placed on the stack for the call. */
    case NODE_READ:
        emitRead(t->left);
        return -1;

    case NODE_WRITE:
        resultReg = codeGen(t->left);
        fprintf(targetFile, "MOV R19, \"Write\"\nPUSH R19\n");
        fprintf(targetFile, "MOV R19, -2\nPUSH R19\n");
        fprintf(targetFile, "PUSH R%d\nPUSH R19\nPUSH R19\nCALL 0\n", resultReg);
        fprintf(targetFile, "POP R19\nPOP R19\nPOP R19\nPOP R19\nPOP R19\n");
        freeReg();
        return -1;

    /* Control-flow nodes create labels and emit branches around or back to bodies. */
    case NODE_IF:
        resultReg = codeGen(t->left);
        labelOne = getLabel();
        labelTwo = getLabel();
        fprintf(targetFile, "JZ R%d, L%d\n", resultReg, labelOne);
        freeReg();
        codeGen(t->middle);
        fprintf(targetFile, "JMP L%d\nL%d:\n", labelTwo, labelOne);
        codeGen(t->right);
        fprintf(targetFile, "L%d:\n", labelTwo);
        return -1;

    case NODE_WHILE:
        labelOne = getLabel();
        labelTwo = getLabel();
        pushLoop(labelTwo, labelOne);
        fprintf(targetFile, "L%d:\n", labelOne);
        resultReg = codeGen(t->left);
        fprintf(targetFile, "JZ R%d, L%d\n", resultReg, labelTwo);
        freeReg();
        codeGen(t->right);
        fprintf(targetFile, "JMP L%d\nL%d:\n", labelOne, labelTwo);
        popLoop();
        return -1;

    case NODE_BREAK:
        if (loopTop >= 0) fprintf(targetFile, "JMP L%d\n", loopBreak[loopTop]);
        return -1;

    case NODE_CONTINUE:
        if (loopTop >= 0) fprintf(targetFile, "JMP L%d\n", loopContinue[loopTop]);
        return -1;

    case NODE_REPEAT:
        labelOne = getLabel();
        labelTwo = getLabel();
        pushLoop(labelTwo, labelTwo);
        fprintf(targetFile, "L%d:\n", labelOne);
        codeGen(t->right);
        fprintf(targetFile, "L%d:\n", labelTwo);
        resultReg = codeGen(t->left);
        fprintf(targetFile, "JZ R%d, L%d\n", resultReg, labelOne);
        freeReg();
        popLoop();
        return -1;

    case NODE_DOWHILE:
        labelOne = getLabel();
        labelTwo = getLabel();
        pushLoop(labelTwo, labelTwo);
        fprintf(targetFile, "L%d:\n", labelOne);
        codeGen(t->right);
        fprintf(targetFile, "L%d:\n", labelTwo);
        resultReg = codeGen(t->left);
        fprintf(targetFile, "JNZ R%d, L%d\n", resultReg, labelOne);
        freeReg();
        popLoop();
        return -1;

    case NODE_BODY:
        codeGen(t->left);
        return codeGen(t->right);

    /* A function return writes into the caller-reserved [BP-2] slot, restores
     * this frame's locals/BP, and returns to the saved instruction address. */
    case NODE_RETURN:
        resultReg = codeGen(t->left);
        if (generatingMain) {
            freeReg();
            emitExit();
            return -1;
        }
        addressReg = getReg();
        fprintf(targetFile, "MOV R%d, BP\n", addressReg);
        fprintf(targetFile, "SUB R%d, 2\n", addressReg);
        fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
        freeReg();
        freeReg();
        while (currentLocalCount-- > 0) fprintf(targetFile, "POP R0\n");
        fprintf(targetFile, "POP BP\nRET\n");
        return -1;
    }
    return -1;
}

/* Save the caller's BP, establish this frame's BP, and reserve its local words. */
static void prologue(int localCount) {
    int i;

    fprintf(targetFile, "PUSH BP\nMOV BP, SP\n");
    for (i = 0; i < localCount; ++i) {
        fprintf(targetFile, "PUSH R0\n");
    }
}

/* Clear each fixed-size runtime table, then place method labels in their slots. */
static void initializeVirtualFunctionTables(void) {
    Classtable *classEntry;

    fprintf(targetFile, "MOV R0, 0\n");
    for (classEntry = CGetHead(); classEntry != NULL; classEntry = classEntry->next) {
        Memberfunclist *method;
        int slot;
        int tableBase = 4096 + classEntry->classIndex * 8;

        for (slot = 0; slot < 8; ++slot) {
            fprintf(targetFile, "MOV [%d], R0\n", tableBase + slot);
        }
        for (method = classEntry->vfuncptr; method != NULL; method = method->next) {
            int entryAddress = tableBase + method->funcposition;
            fprintf(targetFile, "MOV R1, F%d\n", method->flabel);
            fprintf(targetFile, "MOV [%d], R1\n", entryAddress);
        }
    }
}

/*
 * FUNCTION: generateProgram
 * PURPOSE: Write the complete XSM program for all collected methods/functions.
 * INPUT: Linked list of ordinary function and main ASTs.
 * RETURN: Nothing; writes the target program to targetFile.
 * FLOW: Emit the runtime header and heap, initialize dispatch tables, then
 * generate every method and function with its own stack-frame setup.
 */
void generateProgram(FunctionAST *functions) {
    FunctionAST *function;
    MethodAST *method;

    /* Header word 8 enables the runtime library used by Write/Read/Exit. */
    fprintf(targetFile, "0\n2056\n0\n0\n0\n0\n0\n1\n");
    fprintf(targetFile, "MOV SP, %d\n", nextBinding - 1);
    emitHeapInit();
    fprintf(targetFile, "MOV R0, 0\n");
    initializeVirtualFunctionTables();
    fprintf(targetFile, "JMP MAIN\n");

    /* Methods have their own AST list and labels assigned at declaration. */
    for (method = MethodASTHead; method != NULL; method = method->next) {
        reg = -1;
        loopTop = -1;
        generatingMain = 0;
        currentLocalCount = method->localCount;
        fprintf(targetFile, "F%d:\n", method->methodEntry->flabel);
        prologue(method->localCount);
        codeGen(method->tree);
    }

    for (function = functions; function != NULL; function = function->next) {
        reg = -1;
        loopTop = -1;
        currentLocalCount = function->localCount;

        if (function->tree->nodetype == NODE_MAIN) {
            generatingMain = 1;
            fprintf(targetFile, "MAIN:\n");
            prologue(function->localCount);
            codeGen(function->tree->left);
        } else {
            generatingMain = 0;
            fprintf(targetFile, "F%d:\n", Lookup(function->name)->flabel);
            prologue(function->localCount);
            codeGen(function->tree);
        }
    }
}
