#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE* targetFile;
int reg = -1;

int getReg() {
    if (reg >= 19) {
        printf("Out of registers\n");
        exit(1);
    }

    reg++;
    return reg;
}

void freeReg() {
    if (reg >= 0) reg--;
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
    }

    return -1;
}