#ifndef CODEGEN_H
#define CODEGEN_H

#include "exprtree.h"

int getReg();
void freeReg();
int getLabel();

/* Translate an AST subtree; expression nodes return their result register. */
int codeGen(tnode *root);
/* Emit the header and code for all saved functions in the compilation. */
void generateProgram(FunctionAST *functions);

#endif
