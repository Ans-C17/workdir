#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>

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
 * PURPOSE: Allocate the next temporary XSM register.
 * INPUT: none. RETURN: register number, or exits when the pool is exhausted.
 * FLOW: increments global reg; R19 stays reserved for runtime scratch use.
 * Change this with freeReg() if the register pool or scratch convention changes.
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
 * PURPOSE: Release the most recently allocated temporary register.
 * INPUT/RETURN: none. FLOW: decrements reg when one is allocated.
 * This is a compile-time allocator only; it emits no instruction. Keep
 * allocations/releases balanced in every codeGen branch.
 */
void freeReg(void) {
    if (reg >= 0) {
        --reg;
    }
}

/* Return the next unique numeric suffix for an emitted control-flow label. */
int getLabel(void) {
    return label++;
}

/* Save the active loop's destinations so nested break/continue target this loop. */
static void pushLoop(int breakLabel, int continueLabel) {
    loopBreak[++loopTop] = breakLabel;
    loopContinue[loopTop] = continueLabel;
}

/* Remove the loop destinations after code for that loop has been emitted. */
static void popLoop(void) {
    --loopTop;
}

/* An Lentry uses BP-relative storage; otherwise the variable is global. */
/*
 * FUNCTION: idAddress
 * PURPOSE: Put a variable's address into a newly allocated register.
 * INPUT: resolved NODE_ID with either Lentry or Gentry. RETURN: address register.
 * FLOW: locals/parameters use BP + relative binding; globals use absolute binding.
 * Address calculation changes here if the activation-record layout changes.
 */
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

/* Add the field offset stored in t->val to the containing tuple's base address. */
static int fieldAddress(tnode *t) {
    int addressReg = idAddress(t->left);

    fprintf(targetFile, "ADD R%d, %d\n", addressReg, t->val);
    return addressReg;
}

/* Test whether a type ID belongs to the tuple-value range. */
static int isTupleType(int type) {
    return type >= TYPE_TUPLE_BASE && type < TYPE_TUPLE_PTR_BASE;
}

/* Return the base address of a direct tuple or a dereferenced tuple pointer. */
static int tupleAddress(tnode *t) {
    if (t->nodetype == NODE_ID) {
        return idAddress(t);
    }
    if (t->nodetype == NODE_DEREFERENCE) {
        return codeGen(t->left);
    }
    fprintf(stderr, "Tuple assignment requires a tuple variable or dereferenced tuple pointer\n");
    exit(1);
}

/* Whole tuples are stored as consecutive field words. */
/* Copy a tuple word by word; R19 is scratch so both base-address registers survive. */
static void copyTuple(tnode *destination, tnode *source) {
    int destinationReg;
    int sourceReg;
    int words;
    int i;

    words = TypeSize(destination->type);
    destinationReg = tupleAddress(destination);
    sourceReg = tupleAddress(source);
    for (i = 0; i < words; ++i) {
        fprintf(targetFile, "MOV R19, [R%d]\n", sourceReg);
        fprintf(targetFile, "MOV [R%d], R19\n", destinationReg);
        if (i + 1 < words) {
            fprintf(targetFile, "INR R%d\nINR R%d\n", destinationReg, sourceReg);
        }
    }
    freeReg();
    freeReg();
}

/* Compute global 1D array address base + evaluated index. */
static int arrayAddress(tnode *t) {
    int indexReg = codeGen(t->left);
    int baseReg = getReg();

    if (t->Lentry != NULL) {
        fprintf(targetFile, "MOV R%d, BP\n", baseReg);
        fprintf(targetFile, "ADD R%d, %d\n", baseReg, t->Lentry->binding);
        /* An array parameter's BP slot stores the base address, not element 0. */
        if (t->Lentry->isArrayParam) {
            fprintf(targetFile, "MOV R%d, [R%d]\n", baseReg, baseReg);
        }
    } else {
        fprintf(targetFile, "MOV R%d, %d\n", baseReg, t->Gentry->binding);
    }
    fprintf(targetFile, "ADD R%d, R%d\n", indexReg, baseReg);
    freeReg();
    return indexReg;
}

/* Compute global 2D row-major address base + row*cols + column. */
static int array2Address(tnode *t) {
    int rowReg = codeGen(t->left);
    int colReg = codeGen(t->middle);
    int baseReg = getReg();
    int colsReg = getReg();

    if (t->Lentry != NULL) {
        fprintf(targetFile, "MOV R%d, BP\n", baseReg);
        fprintf(targetFile, "ADD R%d, %d\n", baseReg, t->Lentry->binding);
        fprintf(targetFile, "MOV R%d, %d\n", colsReg, t->Lentry->cols);
        if (t->Lentry->isArrayParam) {
            fprintf(targetFile, "MOV R%d, [R%d]\n", baseReg, baseReg);
        }
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

/* Emit the XSM Exit runtime call used when execution reaches main's return. */
static void emitExit(void) {
    fprintf(targetFile, "MOV R19, \"Exit\"\n");
    fprintf(targetFile, "PUSH R19\nPUSH R19\nPUSH R19\nPUSH R19\nPUSH R19\n");
    fprintf(targetFile, "CALL 0\n");
}

/*
 * Emit the Read runtime protocol for an l-value AST. Computes its address,
 * pushes the five library arguments, calls address 0, and removes those words.
 * Extend the address selection here when the language adds a new l-value kind.
 */
static void emitRead(tnode *variable) {
    int addressReg;

    if (variable->nodetype == NODE_ID) {
        addressReg = idAddress(variable);
    } else if (variable->nodetype == NODE_FIELD) {
        addressReg = fieldAddress(variable);
    } else if (variable->nodetype == NODE_ARRAY) {
        addressReg = arrayAddress(variable);
    } else if (variable->nodetype == NODE_ARRAY2D) {
        addressReg = array2Address(variable);
    } else {
        addressReg = codeGen(variable->left);
    }

    fprintf(targetFile, "MOV R19, \"Read\"\nPUSH R19\n");
    fprintf(targetFile, "MOV R19, -1\nPUSH R19\n");
    fprintf(targetFile, "PUSH R%d\nPUSH R19\nPUSH R19\nCALL 0\n", addressReg);
    fprintf(targetFile, "POP R19\nPOP R19\nPOP R19\nPOP R19\nPOP R19\n");
    freeReg();
}

/* Push arguments in reverse order; array formals receive a base address, not an element. */
static void pushArgs(tnode *arguments, Paramstruct *formals) {
    int valueReg;

    if (arguments == NULL) {
        return;
    }

    pushArgs(arguments->right, formals->next);
    if (formals->isArray) {
        tnode *array = arguments->left;
        valueReg = getReg();
        if (array->Lentry != NULL) {
            fprintf(targetFile, "MOV R%d, BP\n", valueReg);
            fprintf(targetFile, "ADD R%d, %d\n", valueReg, array->Lentry->binding);
            if (array->Lentry->isArrayParam) {
                fprintf(targetFile, "MOV R%d, [R%d]\n", valueReg, valueReg);
            }
        } else {
            fprintf(targetFile, "MOV R%d, %d\n", valueReg, array->Gentry->binding);
        }
    } else {
        valueReg = codeGen(arguments->left);
    }
    fprintf(targetFile, "PUSH R%d\n", valueReg);
    freeReg();
}

/* Count argument-list cells so the caller can discard their stack words. */
static int argCount(tnode *arguments) {
    int count = 0;

    while (arguments != NULL) {
        ++count;
        arguments = arguments->right;
    }
    return count;
}

/*
 * FUNCTION: functionCall
 * PURPOSE: Emit the caller side of NODE_FUNCTION and return its result register.
 * INPUT: typed call node with Gentry/flabel and arglist. RETURN: allocated result register.
 * FLOW: save live regs; push reversed args and result slot; CALL F<label>; pop
 * result; discard args; restore saved regs. Callee setup/return is in prologue()
 * and NODE_RETURN. Keep both sides synchronized when changing the stack ABI.
 */
static int functionCall(tnode *t) {
    int savedTop = reg;
    int arguments = argCount(t->arglist);
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

/* Generate two operands, emit one binary instruction, and leave result in leftReg. */
static void binary(tnode *t, const char *instruction) {
    int leftReg = codeGen(t->left);
    int rightReg = codeGen(t->right);

    fprintf(targetFile, "%s R%d, R%d\n", instruction, leftReg, rightReg);
    freeReg();
}

/*
 * FUNCTION: codeGen
 * PURPOSE: Generate XSM code for an AST node.
 * INPUT: AST node.
 * RETURN: Register number containing the result, or -1 if it is a statement.
 * FLOW: Handles each type of AST node and generates the corresponding XSM instructions.
 */
int codeGen(tnode *t) {
    int resultReg;
    int addressReg;
    int labelOne;
    int labelTwo;

    if (t == NULL) {
        return -1;
    }

    switch (t->nodetype) {
    case NODE_NUM:
        resultReg = getReg();
        fprintf(targetFile, "MOV R%d, %d\n", resultReg, t->val);
        return resultReg;

    case NODE_STR:
        resultReg = getReg();
        fprintf(targetFile, "MOV R%d, \"%s\"\n", resultReg, t->varname);
        return resultReg;

    case NODE_ID:
        resultReg = idAddress(t);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    case NODE_FIELD:
        resultReg = fieldAddress(t);
        fprintf(targetFile, "MOV R%d, [R%d]\n", resultReg, resultReg);
        return resultReg;

    case NODE_ADDRESS:
        if (t->left->nodetype == NODE_FIELD) {
            return fieldAddress(t->left);
        }
        return idAddress(t->left);

    case NODE_DEREFERENCE:
        resultReg = codeGen(t->left);
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

    case NODE_FUNCTION:
        return functionCall(t);

    case NODE_ASSIGN:
        if (isTupleType(t->left->type)) {
            copyTuple(t->left, t->right);
            return -1;
        }
        resultReg = codeGen(t->right);
        if (t->left->nodetype == NODE_ID) {
            addressReg = idAddress(t->left);
        } else if (t->left->nodetype == NODE_FIELD) {
            addressReg = fieldAddress(t->left);
        } else if (t->left->nodetype == NODE_ARRAY) {
            addressReg = arrayAddress(t->left);
        } else if (t->left->nodetype == NODE_ARRAY2D) {
            addressReg = array2Address(t->left);
        } else {
            addressReg = codeGen(t->left->left);
        }
        fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
        freeReg();
        freeReg();
        return -1;

    case NODE_CONNECTOR:
        codeGen(t->left);
        codeGen(t->right);
        return -1;

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
    /* Callee epilogue: place result at BP-2, pop locals and saved BP, RET. */

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

/*
 * FUNCTION: prologue
 * PURPOSE: Set up the function's stack frame.
 * INPUT: Number of local variables.
 * RETURN: Nothing.
 * FLOW:
 *   1. Save the caller's BP.
 *   2. Set BP to the current SP.
 *   3. Allocate space for the function's local variables.
 */
static void prologue(int localCount) {
    int i;

    fprintf(targetFile, "PUSH BP\nMOV BP, SP\n");
    for (i = 0; i < localCount; ++i) {
        fprintf(targetFile, "PUSH R0\n");
    }
}

/*
 * FUNCTION: generateProgram
 * PURPOSE: Generate the complete XSM program.
 * INPUT: The linked list containing all function ASTs.
 * RETURN: Nothing. Writes the generated code to targetFile.
 * FLOW:
 *   1. Write the XSM program header and initialize SP.
 *   2. Loop through all functions in the list.
 *   3. Print each function's label (MAIN or F0, F1, etc.).
 *   4. Set up space for its local variables.
 *   5. Call codeGen() to generate its instructions.
 */
void generateProgram(FunctionAST *functions) {
    FunctionAST *function;

    fprintf(targetFile, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(targetFile, "MOV SP, %d\nJMP MAIN\n", nextBinding - 1);

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
