#ifndef CODEGEN_H
#define CODEGEN_H

#include "exprtree.h"

int getReg();
void freeReg();
int getLabel();

/* Generate XSM for an AST node; returns its result register or -1 for statements. */
int codeGen(tnode *root);
/* Emit startup code and all saved functions, including heap initialization. */
void generateProgram(FunctionAST *functions);

#endif
