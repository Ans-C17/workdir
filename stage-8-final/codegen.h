#ifndef CODEGEN_H
#define CODEGEN_H

#include "exprtree.h"

/* Register and label helpers used while translating each AST. */
int getReg();
void freeReg();
int getLabel();

/* Translate one AST node, or the saved program AST list, into targetFile. */
int codeGen(tnode *root);
void generateProgram(FunctionAST *functions);

#endif
