#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE* targetFile;
int reg = -1;
int label = 0;

#define MAX_LOOP_DEPTH 100 // nested loops require stack
int loopTop = -1; // innermost loop
int loopBreak[MAX_LOOP_DEPTH];
int loopContinue[MAX_LOOP_DEPTH];
int breakTarget[MAX_LOOP_DEPTH];
int breakTop = -1;

int getReg() {
    if (reg >= 19) {
        printf("Out of registers\n");
        exit(1);
    }

    reg++;
    return reg;
}

int getLabel() {
    return label++; // post-increment
}

void freeReg() {
    if (reg >= 0) reg--;
}

void pushLoop(int breakLabel, int continueLabel) {
    if (loopTop >= MAX_LOOP_DEPTH - 1 || breakTop >= MAX_LOOP_DEPTH - 1) {
        printf("Too many nested loops\n");
        exit(1);
    }

    loopTop++;
    breakTop++;

    // push to stacks
    loopBreak[loopTop] = breakLabel;
    loopContinue[loopTop] = continueLabel;
    breakTarget[breakTop] = breakLabel;
}

void popLoop() {
    if (loopTop >= 0) loopTop--;
    if (breakTop >= 0) breakTop--;
}

void pushBreakTarget(int target) {
    if (breakTop >= MAX_LOOP_DEPTH - 1) {
        printf("Too many nested breakable statements\n");
        exit(1);
    }
    breakTarget[++breakTop] = target;
}

void popBreakTarget() {
    if (breakTop >= 0) breakTop--;
}

int codeGen(tnode* t) {
    if (t == NULL)
        return -1;

    switch (t->nodetype) {
        case NODE_NUM: {
            int r = getReg();
            fprintf(targetFile, "MOV R%d, %d\n", r, t->val);
            return r;
        }
        
        case NODE_ID: { // whenever stuff like d = a * 3 + b comes -> so we fetch values of them and stores it in reg
            int r = getReg();
            int addr = 4096 + (t->varname[0] - 'a');
            fprintf(targetFile, "MOV R%d, [%d]\n", r, addr); // [5000] means fetch value from addr 5000
            return r;
        }

        // fall through - group all 4 ops together
        case NODE_PLUS:
        case NODE_MINUS:
        case NODE_MUL:
        case NODE_DIV: { 
            int leftReg = codeGen(t->left);
            int rightReg = codeGen(t->right);

            switch (t->nodetype) {
                case NODE_PLUS:
                    fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_MINUS:
                    fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_MUL:
                    fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_DIV:
                    fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
                    break;
            }

            freeReg(); // free rightReg
            return leftReg; // assembly stores result from rightReg into leftReg
        }

        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
        case NODE_EQ:
        case NODE_NE: {
            int leftReg = codeGen(t->left);
            int rightReg = codeGen(t->right);

            switch (t->nodetype) {
                case NODE_LT:
                    fprintf(targetFile, "LT R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_GT:
                    fprintf(targetFile, "GT R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_LE:
                    fprintf(targetFile, "LE R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_GE:
                    fprintf(targetFile, "GE R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_EQ:
                    fprintf(targetFile, "EQ R%d, R%d\n", leftReg, rightReg);
                    break;

                case NODE_NE:
                    fprintf(targetFile, "NE R%d, R%d\n", leftReg, rightReg);
                    break;
            }
            
            freeReg();
            return leftReg;
        }

        case NODE_ASSIGN: {
            int r = codeGen(t->right);
            int addr = 4096 + (t->left->varname[0] - 'a');
            fprintf(targetFile, "MOV [%d], R%d\n", addr, r); // Overwrite the RAM box (4096 + i) with the VALUE currently sitting in Ri
            freeReg();
            return -1;
        }

        case NODE_CONNECTOR: {
            codeGen(t->left); // Goes left, runs read(a) (or_anything_else), prints its XSM assembly to the file.
            codeGen(t->right); // u know
            return -1;
        }

        // five elements of stack
        // 1. function code
        // 2. arg1
        // 3. arg2
        // 4. arg3
        // 5. return value slot

        case NODE_WRITE: {
            int r = codeGen(t->left); 
            // we take t->left coz write only has one child, that child is the 
            // root of the entire subtree.. whether it be operator, node or id


            // For Write, the ABI contract says:
            // Arg1 = -2 (-2 = stdout)
            // Arg2 = Buffer (here buffer means the reg that contains the value u wanna print)
            // Arg3 = unused
            // i.e take value from the buffer (reg) and print in stdout

            fprintf(targetFile, "MOV R2, \"Write\"\n");
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "MOV R2, -2\n");
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "PUSH R%d\n", r);
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "PUSH R0\n");
            fprintf(targetFile, "CALL 0\n");

            // POP (return_value_reg + 3 arguments + function code)
            fprintf(targetFile, "POP R0\n");
            fprintf(targetFile, "POP R1\n");
            fprintf(targetFile, "POP R1\n");
            fprintf(targetFile, "POP R1\n");
            fprintf(targetFile, "POP R1\n");

            freeReg();

            return -1;
        }

        case NODE_READ: {
            int addr = 4096 + (t->left->varname[0] - 'a');
            
            // For Read, the ABI contract says:
            // Arg1 = -1 (-1 = stdin)
            // Arg2 = Buffer (here buffer means which reg to store the value into)
            // Arg3 = unused
            // i.e take value from stdin and store it in buffer

            fprintf(targetFile, "MOV R2, \"Read\"\n");
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "MOV R2, -1\n");
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "MOV R2, %d\n", addr);
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "PUSH R2\n");
            fprintf(targetFile, "PUSH R0\n");
            fprintf(targetFile, "CALL 0\n");

            // remove return value + 3 arguments + function code
            fprintf(targetFile, "POP R0\n");
            fprintf(targetFile, "POP R1\n");
            fprintf(targetFile, "POP R1\n");
            fprintf(targetFile, "POP R1\n");
            fprintf(targetFile, "POP R1\n");
            return -1;
        }

        case NODE_IF: {
            int condReg = codeGen(t->left);
            int labelElse = getLabel();
            int labelEnd = getLabel();

            fprintf(targetFile, "JZ R%d, L%d\n", condReg, labelElse);
            freeReg();
            
            codeGen(t->middle); // if body
            // if execute aaya, jump to end by skipping else
            fprintf(targetFile, "JMP L%d\n", labelEnd);
            
            // same labelElse value 
            fprintf(targetFile, "L%d:\n", labelElse);
            if (t->right != NULL) codeGen(t->right); // else body

            fprintf(targetFile, "L%d:\n", labelEnd);
            return -1;
        }

        case NODE_WHILE: {
            int labelStart = getLabel();
            int labelEnd = getLabel();

            pushLoop(labelEnd, labelStart); 
            // break = leave and go to LabelEnd
            // continue = start again so labelStart

            fprintf(targetFile, "L%d:\n", labelStart);
            int condReg = codeGen(t->left); // check true
            fprintf(targetFile, "JZ R%d, L%d\n", condReg, labelEnd); // false aanel

            freeReg();
            codeGen(t->right); // body
            fprintf(targetFile, "JMP L%d\n", labelStart); // loop

            fprintf(targetFile, "L%d:\n", labelEnd); // next label heading
            popLoop();
            return -1;
        }

        case NODE_BREAK: {
            if (breakTop >= 0) {
                fprintf(targetFile, "JMP L%d\n", breakTarget[breakTop]);
            }

            return -1;
        }

        case NODE_CONTINUE: {
            if (loopTop >= 0) {
                fprintf(targetFile, "JMP L%d\n", loopContinue[loopTop]);
            }

            return -1;
        }

        case NODE_REPEAT: {
            int labelStart = getLabel();
            int labelCondition = getLabel();
            int labelEnd = getLabel();

            // condition check is at the bottom not top
            pushLoop(labelEnd, labelCondition);
            fprintf(targetFile, "L%d:\n", labelStart);
            codeGen(t->right);

            // condition check
            fprintf(targetFile, "L%d:\n", labelCondition);
            int condReg = codeGen(t->left);

            // repeat as long as condition is FALSE
            fprintf(targetFile, "JZ R%d, L%d\n", condReg, labelStart);

            freeReg();
            fprintf(targetFile, "L%d:\n", labelEnd);
            popLoop();
            return -1;
        }

        case NODE_DOWHILE: {
            int labelStart = getLabel();
            int labelCondition = getLabel();
            int labelEnd = getLabel();

            pushLoop(labelEnd, labelCondition);
            fprintf(targetFile, "L%d:\n", labelStart);

            codeGen(t->right);

            fprintf(targetFile, "L%d:\n", labelCondition);
            int condReg = codeGen(t->left);

            fprintf(targetFile, "JNZ R%d, L%d\n", condReg, labelStart);
            freeReg();

            fprintf(targetFile, "L%d:\n", labelEnd);
            popLoop();
            return -1;
        }

        case NODE_SWITCH: {
            int valueReg = codeGen(t->left);
            int endLabel = getLabel();
            int defaultLabel = t->middle ? getLabel() : endLabel;

            /* Count cases so each case gets a label before dispatch is emitted. */
            int count = 0;
            tnode *walk = t->right;
            while (walk && walk->nodetype == NODE_CONNECTOR) {
                count++;
                walk = walk->left;
            }
            if (walk) count++;

            tnode **caseNodes = count ? malloc(sizeof(tnode*) * count) : NULL;
            int *caseLabels = count ? malloc(sizeof(int) * count) : NULL;
            if (count && !caseNodes) {
                fprintf(stderr, "Out of memory while generating switch\n");
                exit(1);
            }
            if (count && !caseLabels) {
                fprintf(stderr, "Out of memory while generating switch\n");
                exit(1);
            }

            /* The parser links each new case on the right; reverse that into source order. */
            int index = count - 1;
            tnode *c = t->right;
            while (c && c->nodetype == NODE_CONNECTOR) {
                caseNodes[index--] = c->right;
                c = c->left;
            }
            if (c) caseNodes[index] = c;

            for (int i = 0; i < count; i++) {
                caseLabels[i] = getLabel();
                int caseReg = getReg();
                fprintf(targetFile, "MOV R%d, %d\n", caseReg, caseNodes[i]->val);
                /* EQ overwrites its first register; preserve valueReg for later cases. */
                fprintf(targetFile, "EQ R%d, R%d\n", caseReg, valueReg);
                fprintf(targetFile, "JNZ R%d, L%d\n", caseReg, caseLabels[i]);
                freeReg();
            }
            fprintf(targetFile, "JMP L%d\n", defaultLabel);
            freeReg();

            /* A case body falls through to the next case unless it executes break. */
            pushBreakTarget(endLabel);
            for (int i = 0; i < count; i++) {
                fprintf(targetFile, "L%d:\n", caseLabels[i]);
                codeGen(caseNodes[i]->left);
            }
            fprintf(targetFile, "L%d:\n", defaultLabel);
            if (t->middle) codeGen(t->middle->left);
            fprintf(targetFile, "L%d:\n", endLabel);
            popBreakTarget();
            free(caseLabels);
            free(caseNodes);
            return -1;
        }
    }

    return -1;
}
