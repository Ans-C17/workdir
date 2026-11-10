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
int getReg(void) {
    if (reg >= 18) {
        fprintf(stderr, "Out of registers\n");
        exit(1);
    }
    return ++reg;
}

void freeReg(void) {
    if (reg >= 0) {
        --reg;
    }
}

int getLabel(void) {
    return label++;
}

static void pushLoop(int breakLabel, int continueLabel) {
    loopBreak[++loopTop] = breakLabel;
    loopContinue[loopTop] = continueLabel;
}

static void popLoop(void) {
    --loopTop;
}

/* An Lentry uses BP-relative storage; otherwise the variable is global. */
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

/*
 * FUNCTION: lvalueAddress
 * PURPOSE: Find where an assignable variable or field is stored.
 * INPUT: AST node for a variable, array element, dereference, or field.
 * RETURN: Register holding the memory address; the register remains in use.
 * FLOW: Find the base address. For each NODE_FIELD, load the object's pointer
 * from that slot and add Fentry->fieldIndex. Assignment, read, and alloc use
 * this function to find their destination.
 * MODIFICATION HINT: If a new kind of assignable target is added, handle it
 * in this switch and check its read and write code-generation paths.
 */
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
        /* A user-defined value is represented by a pointer in its storage slot. */
        fprintf(targetFile, "MOV R%d, [R%d]\n", addressReg, addressReg);
        fprintf(targetFile, "ADD R%d, %d\n", addressReg, t->Fentry->fieldIndex);
        return addressReg;
    default:
        fprintf(stderr, "Error: expression is not an assignable location\n");
        exit(1);
    }
}

static void emitExit(void) {
    fprintf(targetFile, "MOV R19, \"Exit\"\n");
    fprintf(targetFile, "PUSH R19\nPUSH R19\nPUSH R19\nPUSH R19\nPUSH R19\n");
    fprintf(targetFile, "CALL 0\n");
}

/*
 * FUNCTION: saveRegsThrough
 * PURPOSE: Protect values that heap instructions are about to overwrite.
 * INPUT: Highest live expression-register number.
 * RETURN: Nothing. Writes PUSH instructions to targetFile.
 * FLOW: Push R0 through lastReg in order. restoreRegsThrough() must pop them
 * in reverse order after the allocator work is complete.
 */
static void saveRegsThrough(int lastReg) {
    int i;
    for (i = 0; i <= lastReg; ++i) fprintf(targetFile, "PUSH R%d\n", i);
}

/*
 * FUNCTION: restoreRegsThrough
 * PURPOSE: Restore expression values saved before heap instructions ran.
 * INPUT: Highest saved register number.
 * RETURN: Nothing. Writes POP instructions to targetFile.
 * FLOW: Pop lastReg down to R0, reversing saveRegsThrough()'s push order.
 */
static void restoreRegsThrough(int lastReg) {
    int i;
    for (i = lastReg; i >= 0; --i) fprintf(targetFile, "POP R%d\n", i);
}

/*
 * FUNCTION: emitHeapInit
 * PURPOSE: Generate startup instructions that prepare the Stage 6 heap.
 * INPUT: None.
 * RETURN: Nothing. Writes instructions to targetFile.
 * FLOW: Link eight-word blocks from 1032 through 2040, mark the last link -1,
 * then put the first block address at 1024. generateProgram() calls this once
 * before MAIN can allocate an object.
 * MODIFICATION HINT: If heap range or block size changes, update this function,
 * emitAlloc(), and emitFree() together.
 */
static void emitHeapInit(void) {
    int loop = getLabel();
    int done = getLabel();

    /* Address 1024 stores the head. Blocks start at 1032 and are 8 words apart.
       The first word in each free block points to the next available block. */
    fprintf(targetFile, "MOV R1, 1032\nMOV R2, 1040\nMOV R3, 2040\n");
    fprintf(targetFile, "L%d:\nMOV R4, R1\nEQ R4, R3\nJNZ R4, L%d\n", loop, done);
    fprintf(targetFile, "MOV [R1], R2\nADD R1, 8\nADD R2, 8\nJMP L%d\n", loop);
    fprintf(targetFile, "L%d:\nMOV R4, -1\nMOV [R1], R4\n", done);
    fprintf(targetFile, "MOV R1, 1024\nMOV R2, 1032\nMOV [R1], R2\n");
}

/*
 * FUNCTION: emitAlloc
 * PURPOSE: Generate instructions to take one block from the free list.
 * INPUT: Result register, highest live register, and requested type size.
 * RETURN: None. Generated code puts the block address in resultReg, or -1
 * when size is invalid or no blocks remain.
 * FLOW: Save live registers; reject sizes outside 1..8; remove the free-list
 * head; place its address in resultReg; restore the saved registers. Returns
 * -1 in resultReg if size is invalid or the list is empty.
 * CALLED BY: The NODE_ALLOC case in codeGen().
 */
static void emitAlloc(int resultReg, int savedTop, int size) {
    int bad = getLabel();
    int haveBlock = getLabel();
    int done = getLabel();

    /* The allocator uses R1-R4, so protect any expression values already there. */
    saveRegsThrough(savedTop);
    fprintf(targetFile, "MOV R1, %d\nMOV R2, 0\nMOV R3, R1\nLE R3, R2\nJNZ R3, L%d\n", size, bad);
    fprintf(targetFile, "MOV R2, 8\nMOV R3, R1\nGT R3, R2\nJNZ R3, L%d\n", bad);
    fprintf(targetFile, "MOV R1, [1024]\nMOV R2, -1\nMOV R3, R1\nEQ R3, R2\nJZ R3, L%d\n", haveBlock);
    fprintf(targetFile, "L%d:\nMOV R1, -1\nMOV R%d, R1\nJMP L%d\n", bad, resultReg, done);
    fprintf(targetFile, "L%d:\nMOV R2, [R1]\nMOV [1024], R2\n", haveBlock);
    fprintf(targetFile, "MOV R%d, R1\nL%d:\n", resultReg, done);
    restoreRegsThrough(savedTop);
}

/*
 * FUNCTION: emitFree
 * PURPOSE: Generate instructions to return an allocated block to the free list.
 * INPUT: Register holding the block address and highest live register.
 * RETURN: None. Invalid, misaligned, or already-free addresses are ignored.
 * FLOW: Save live registers; check the address range and 8-word alignment;
 * reject a block already in the free list; clear its eight words; link it at
 * the list head; restore registers. Invalid addresses are ignored.
 * CALLED BY: The NODE_FREE case in codeGen(). The source variable is not reset.
 * MODIFICATION HINT: Keep validation and block layout consistent with
 * emitHeapInit() and emitAlloc().
 */
static void emitFree(int pointerReg, int savedTop) {
    int bad = getLabel();
    int scan = getLabel();
    int clear = getLabel();
    int clearLoop = getLabel();
    int done = getLabel();

    /* Check heap range, 8-word alignment, and that the block is not already free. */
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

/* Emit a Read library call using the address found by lvalueAddress(). */
static void emitRead(tnode *variable) {
    int addressReg = lvalueAddress(variable);

    fprintf(targetFile, "MOV R19, \"Read\"\nPUSH R19\n");
    fprintf(targetFile, "MOV R19, -1\nPUSH R19\n");
    fprintf(targetFile, "PUSH R%d\nPUSH R19\nPUSH R19\nCALL 0\n", addressReg);
    fprintf(targetFile, "POP R19\nPOP R19\nPOP R19\nPOP R19\nPOP R19\n");
    freeReg();
}

static void pushArgs(tnode *arguments) {
    int valueReg;

    if (arguments == NULL) {
        return;
    }

    pushArgs(arguments->right);
    valueReg = codeGen(arguments->left);
    fprintf(targetFile, "PUSH R%d\n", valueReg);
    freeReg();
}

static int argCount(tnode *arguments) {
    int count = 0;

    while (arguments != NULL) {
        ++count;
        arguments = arguments->right;
    }
    return count;
}

static int functionCall(tnode *t) {
    int savedTop = reg;
    int arguments = argCount(t->arglist);
    int i;
    int resultReg;

    for (i = 0; i <= savedTop; ++i) {
        fprintf(targetFile, "PUSH R%d\n", i);
    }

    pushArgs(t->arglist);
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

static void binary(tnode *t, const char *instruction) {
    int leftReg = codeGen(t->left);
    int rightReg = codeGen(t->right);

    fprintf(targetFile, "%s R%d, R%d\n", instruction, leftReg, rightReg);
    freeReg();
}

/*
 * FUNCTION: codeGen
 * PURPOSE: Generate XSM instructions for one AST node and its children.
 * INPUT: AST node to translate.
 * RETURN: Register holding an expression result, or -1 for a statement.
 * FLOW: Select the instruction sequence from nodetype and recursively generate
 * child expressions/statements. Stage 6 NODE_FIELD reads a heap field;
 * NODE_ALLOC stores a newly allocated block address; NODE_FREE returns a block.
 * MODIFICATION HINT: For a new AST node, add its case here and update its
 * constructor/type checks in exprtree.c and its grammar action in exprtree.y.
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

    /*
     * A NODE_FIELD read uses lvalueAddress() to find its heap word, then loads
     * the value stored in that word. The same address helper is used for
     * assignment and read targets in this file.
     */
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
        resultReg = codeGen(t->right);
        addressReg = lvalueAddress(t->left);
        fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
        freeReg();
        freeReg();
        return -1;

    /*
     * Ask the heap for enough words for this type, then store the returned
     * address in the target variable/field. A -1 result means allocation failed.
     */
    case NODE_ALLOC:
        resultReg = getReg();
        emitAlloc(resultReg, resultReg - 1, GetSize(t->left->typeEntry));
        addressReg = lvalueAddress(t->left);
        fprintf(targetFile, "MOV [R%d], R%d\n", addressReg, resultReg);
        freeReg();
        freeReg();
        return -1;

    /* Read the target's stored heap address and return that block to the free list. */
    case NODE_FREE:
        resultReg = codeGen(t->left);
        emitFree(resultReg, reg);
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

/* Set up a function's stack frame and reserve its local-variable words. */
static void prologue(int localCount) {
    int i;

    fprintf(targetFile, "PUSH BP\nMOV BP, SP\n");
    for (i = 0; i < localCount; ++i) {
        fprintf(targetFile, "PUSH R0\n");
    }
}

/*
 * FUNCTION: generateProgram
 * PURPOSE: Generate the complete target program.
 * INPUT: Linked list of completed function ASTs. RETURN: Nothing; writes targetFile.
 * FLOW: Write header and stack setup; call emitHeapInit() to create the free
 * list; jump over function bodies to MAIN; then emit each function label,
 * stack frame, and body through codeGen().
 * MODIFICATION HINT: If heap initialization or program startup changes, start
 * here and in emitHeapInit().
 */
void generateProgram(FunctionAST *functions) {
    FunctionAST *function;

    /* Header word 8 enables the runtime library used by Write/Read/Exit. */
    fprintf(targetFile, "0\n2056\n0\n0\n0\n0\n0\n1\n");
    fprintf(targetFile, "MOV SP, %d\n", nextBinding - 1);
    emitHeapInit();
    fprintf(targetFile, "MOV R0, 0\n");
    fprintf(targetFile, "JMP MAIN\n");

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
