#ifndef CODEGEN_H
#define CODEGEN_H

#include "exprtree.h"

int getReg();
void freeReg();
int getLabel();

/*
 * FUNCTION: codeGen
 * PURPOSE: Generate XSM instructions for one AST node.
 * INPUT: AST node to translate.
 * RETURN: Register holding an expression result, or -1 for a statement.
 * FLOW: Visit the node and its children; Stage 6 field/alloc/free cases use
 * lvalueAddress() and the heap emitters in codegen.c.
 */
int codeGen(tnode *root);
/*
 * FUNCTION: generateProgram
 * PURPOSE: Write the complete XSM program to targetFile.
 * INPUT: Linked list of saved function ASTs.
 * RETURN: Nothing.
 * FLOW: Write the header and stack start, initialize the Stage 6 heap, then
 * emit MAIN and each function.
 */
void generateProgram(FunctionAST *functions);

#endif
