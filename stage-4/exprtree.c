#include "exprtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Gsymbol* Ghead = NULL;
int nextBinding = 4096;

Gsymbol* Lookup(char *name) { // searches the symbol table and returns the address of the matching symbol-table entry
    Gsymbol* temp = Ghead;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Install(char *name, int type, int size) { // entry to linked list
    if (Lookup(name)) {
        printf("Error: Variable %s already declared\n", name);
        exit(1);
    }

    Gsymbol* newEntry = (Gsymbol*)malloc(sizeof(Gsymbol));

    newEntry->name = strdup(name);
    newEntry->type = type;
    newEntry->size = size;
    newEntry->binding = nextBinding;
    nextBinding = nextBinding + size;
    newEntry->next = NULL;

    if (Ghead == NULL) {
        Ghead = newEntry;
    } else {
        Gsymbol *temp = Ghead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newEntry;
    }
}

void PrintSymbolTable() {
    Gsymbol *temp = Ghead;
    printf("Name\tType\tSize\tBinding\n");

    while (temp != NULL) {
        printf("%s\t", temp->name);
        if (temp->type == TYPE_INT)
            printf("INT\t");
        else if (temp->type == TYPE_STR)
            printf("STR\t");

        printf("%d\t%d\n", temp->size, temp->binding);
        temp = temp->next;
    }
}

tnode* createTree(int val, int type, int nodetype, char* varname, tnode* l, tnode* m, tnode* r) {
    tnode* temp = (tnode*)malloc(sizeof(tnode));

    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    temp->varname = varname;
    temp->Gentry = NULL;
    temp->left = l;
    temp->middle = m;
    temp->right = r;

    return temp;
}

tnode* makeNumNode(int n) {
    return createTree(n, TYPE_INT, NODE_NUM, NULL, NULL, NULL, NULL);
}

tnode* makeStrNode(char *s) {
    return createTree(0, TYPE_STR, NODE_STR, s, NULL, NULL, NULL);
}

tnode* makeOperatorNode(char* op, tnode* l, tnode* r) {
    int nodetype;
    int type;

    if (strcmp(op, "+") == 0) {
        nodetype = NODE_PLUS;
        type = TYPE_INT;
    }
    else if (strcmp(op, "-") == 0) {
        nodetype = NODE_MINUS;
        type = TYPE_INT;
    }
    else if (strcmp(op, "*") == 0) {
        nodetype = NODE_MUL;
        type = TYPE_INT;
    }
    else if (strcmp(op, "/") == 0) {
        nodetype = NODE_DIV;
        type = TYPE_INT;
    }
    else if (strcmp(op, "<") == 0) {
        nodetype = NODE_LT;
        type = TYPE_BOOL;
    }
    else if (strcmp(op, ">") == 0) {
        nodetype = NODE_GT;
        type = TYPE_BOOL;
    }
    else if (strcmp(op, "<=") == 0) {
        nodetype = NODE_LE;
        type = TYPE_BOOL;
    }
    else if (strcmp(op, ">=") == 0) {
        nodetype = NODE_GE;
        type = TYPE_BOOL;
    }
    else if (strcmp(op, "!=") == 0) {
        nodetype = NODE_NE;
        type = TYPE_BOOL;
    }
    else if (strcmp(op, "==") == 0) {
        nodetype = NODE_EQ;
        type = TYPE_BOOL;
    }
    else {
        fprintf(stderr, "Invalid operator %s\n", op);
        exit(1);
    }

    if (l->type != TYPE_INT || r->type != TYPE_INT) { // left and right operands should both be strictly int 
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, type, nodetype, NULL, l, NULL, r);
}

tnode* makeIdNode(char* name) {
    // 1. check if the var is declared, look into symbol table
    Gsymbol* entry = Lookup(name);
    if (entry == NULL) {
        printf("Error: Variable %s not declared\n", name);
        exit(1);
    }

    // 2. make the ast node of it, and make the node point to the gst entry
    tnode* node = createTree(0, entry->type, NODE_ID, name, NULL, NULL, NULL);
    node->Gentry = entry;
    return node;
}

tnode* makeAssignNode(tnode* id, tnode* expr) {
    if (expr->type != TYPE_INT) { // u can only assign an int (a = <bool> is gay)
        // eg: a = 5 > 3
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, TYPE_INT, NODE_ASSIGN, NULL, id, NULL, expr);
}

tnode* makeReadNode(tnode* id) {
    return createTree(0, TYPE_INT, NODE_READ, NULL, id, NULL, NULL);
}

tnode* makeWriteNode(tnode* expr) {
    return createTree(0, TYPE_INT, NODE_WRITE, NULL, expr, NULL, NULL);
}

tnode* makeConnectorNode(tnode* l, tnode* r) {
    return createTree(0, TYPE_INT, NODE_CONNECTOR, NULL, l, NULL, r);
}

tnode* makeIfNode(tnode* cond, tnode* thenStmt, tnode* elseStmt) {
    if (cond->type != TYPE_BOOL) {
        fprintf(stderr, "Type mismatch\n"); // if (a + b) ❌ --- if (a < b) ✅
        exit(1);
    }

    return createTree(0, TYPE_BOOL, NODE_IF, NULL, cond, thenStmt, elseStmt);
}

tnode* makeWhileNode(tnode* cond, tnode* body) {
    if (cond->type != TYPE_BOOL) {
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, TYPE_BOOL, NODE_WHILE, NULL, cond, NULL, body);
}

tnode* makeBreakNode() {
    return createTree(0, TYPE_INT, NODE_BREAK, NULL, NULL, NULL, NULL);
}

tnode* makeContinueNode() {
    return createTree(0, TYPE_INT, NODE_CONTINUE, NULL, NULL, NULL, NULL);
}

tnode* makeRepeatNode(tnode* body, tnode* cond) {
    return createTree(0, TYPE_BOOL, NODE_REPEAT, NULL, cond, NULL, body);
}

tnode* makeDoWhileNode(tnode* body, tnode* cond) {
    return createTree(0, TYPE_BOOL, NODE_DOWHILE, NULL, cond, NULL, body);
}