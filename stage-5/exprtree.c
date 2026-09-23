#include "exprtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Gsymbol* Ghead = NULL;
Lsymbol* Lhead = NULL;
static TupleType *TupleHead = NULL;
static int nextTupleType = TYPE_TUPLE_BASE;
int nextBinding = 4096;
int nextLocalBinding = 1;

FunctionAST *FunctionASTHead = NULL;
static FunctionAST *functionASTTail = NULL;

static TupleType *FindTupleByType(int type) {
    TupleType *tuple = TupleHead;
    while (tuple != NULL) {
        if (tuple->type == type) return tuple;
        tuple = tuple->next;
    }
    return NULL;
}

int TupleTypeLookup(char *name) {
    TupleType *tuple = TupleHead;
    while (tuple != NULL) {
        if (strcmp(tuple->name, name) == 0) return tuple->type;
        tuple = tuple->next;
    }
    return -1;
}

int TuplePointerType(int tupleType) {
    return TYPE_TUPLE_PTR_BASE + (tupleType - TYPE_TUPLE_BASE);
}

int TypeSize(int type) {
    TupleType *tuple = FindTupleByType(type);
    return tuple == NULL ? 1 : tuple->size;
}

int InstallTupleType(char *name, Field *fields) {
    TupleType *tuple;
    Field *field;
    int offset = 0;

    if (TupleTypeLookup(name) != -1) {
        fprintf(stderr, "Error: tuple type '%s' is already declared\n", name);
        exit(1);
    }
    tuple = calloc(1, sizeof(TupleType));
    tuple->name = strdup(name);
    tuple->type = nextTupleType++;
    tuple->fields = fields;
    for (field = fields; field != NULL; field = field->next) {
        Field *previous;
        for (previous = fields; previous != field; previous = previous->next) {
            if (strcmp(previous->name, field->name) == 0) {
                fprintf(stderr, "Error: duplicate field '%s' in tuple '%s'\n", field->name, name);
                exit(1);
            }
        }
        field->offset = offset;
        offset += TypeSize(field->type);
    }
    tuple->size = offset;
    tuple->next = TupleHead;
    TupleHead = tuple;
    return tuple->type;
}

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

void Install(char *name, int type, int size, int rows, int cols, Paramstruct *paramlist, int flabel) { 
    // entry to symbol table
    if (Lookup(name)) {
        printf("Error: symbol '%s' is already declared\n", name);
        exit(1);
    }

    Gsymbol* newEntry = (Gsymbol*)malloc(sizeof(Gsymbol));

    newEntry->name = strdup(name);
    newEntry->type = type;
    newEntry->size = size;
    newEntry->rows = rows;
	newEntry->cols = cols;

    newEntry->paramlist = paramlist;
    newEntry->flabel = flabel;

    if (flabel == -1) { // flabel = -1 => no function
        newEntry->binding = nextBinding;
        nextBinding += size;
    }
    else {
        newEntry->binding = -1;
    }

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

/* Task 2(a): a definition must have exactly the signature declared globally. */
void CheckFunctionDefinition(char *name, int returnType, Paramstruct *paramlist) {
    Gsymbol *function = Lookup(name);
    Paramstruct *declared;
    Paramstruct *defined;
    int position = 1;

    if (function == NULL) {
        fprintf(stderr, "Error: function '%s' is defined without a global declaration\n", name);
        exit(1);
    }
    if (function->flabel == -1) {
        fprintf(stderr, "Error: '%s' is declared as a variable, not a function\n", name);
        exit(1);
    }
    if (function->type != returnType) {
        fprintf(stderr, "Error: return type of function '%s' does not match its declaration\n", name);
        exit(1);
    }

    declared = function->paramlist;
    defined = paramlist;
    while (declared != NULL && defined != NULL) {
        if (declared->type != defined->type ||
            strcmp(declared->name, defined->name) != 0) {
            fprintf(stderr,
                    "Error: parameter %d of function '%s' does not match its declaration\n",
                    position, name);
            exit(1);
        }
        declared = declared->next;
        defined = defined->next;
        position++;
    }

    if (declared != NULL || defined != NULL) {
        fprintf(stderr, "Error: parameter count of function '%s' does not match its declaration\n", name);
        exit(1);
    }
}

Lsymbol *LLookup(char *name) {
    Lsymbol *temp = Lhead;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

/* Lsymbol table

a      INT    -3    ← parameter
b      INT    -4    ← parameter
x      INT     1    ← local
msg    STR     2    ← local */

static void LInstall(char *name, int type, int binding) {
    Lsymbol *entry;
    Lsymbol *temp;

    if (LLookup(name) != NULL) {
        fprintf(stderr, "Error: local symbol '%s' is already declared in this function\n", name);
        exit(1);
    }

    entry = calloc(1, sizeof(Lsymbol));
    entry->name = strdup(name);
    entry->type = type;
    entry->binding = binding;

    if (Lhead == NULL) {
        Lhead = entry;
        return;
    }

    temp = Lhead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = entry;
}

/* Parameters are below BP; locals are above BP in the activation record. */
void BeginFunctionScope(Paramstruct *paramlist) {
    int parameterBinding = -3;

    Lhead = NULL;
    nextLocalBinding = 1;
    while (paramlist != NULL) {
        LInstall(paramlist->name, paramlist->type, parameterBinding--);
        paramlist = paramlist->next;
    }
}

void InstallLocalVariables(VarList *varlist, int type) {
    while (varlist != NULL) {
        LInstall(varlist->name, type, nextLocalBinding++);
        nextLocalBinding += TypeSize(type) - 1;
        varlist = varlist->next;
    }
}

void EndFunctionScope(void) {
    /* The AST nodes retain their Lsymbol pointers; later stages free them after codegen. */
    Lhead = NULL;
}

void SaveFunctionAST(char *name, tnode *body, int isMain) {
    FunctionAST *entry = calloc(1, sizeof(FunctionAST));
    Lsymbol *local = Lhead;
    tnode *tree = body;

    if (isMain) {
        tree = createTree(0, TYPE_INT, NODE_MAIN, name, body, NULL, NULL);
    }

    entry->name = strdup(name);
    entry->tree = tree;
    entry->localTable = local;
    while (local != NULL) {
        if (local->binding > 0) {
            entry->localCount += TypeSize(local->type);
        }
        local = local->next;
    }
    if (FunctionASTHead == NULL) {
        FunctionASTHead = entry;
    } else {
        functionASTTail->next = entry;
    }
    functionASTTail = entry;
}

static const char *TypeName(int type) {
    static char tupleName[80];
    TupleType *tuple;
    switch (type) {
        case TYPE_INT: return "INT";
        case TYPE_STR: return "STR";
        case TYPE_INT_PTR: return "INT_PTR";
        case TYPE_STR_PTR: return "STR_PTR";
        case TYPE_BOOL: return "BOOL";
        default:
            tuple = FindTupleByType(type);
            if (tuple != NULL) return tuple->name;
            if (type >= TYPE_TUPLE_PTR_BASE) {
                tuple = FindTupleByType(TYPE_TUPLE_BASE + type - TYPE_TUPLE_PTR_BASE);
                if (tuple != NULL) {
                    snprintf(tupleName, sizeof(tupleName), "%s_PTR", tuple->name);
                    return tupleName;
                }
            }
            return "?";
    }
}

static void PrintTableHeader(void) {
    printf("%-16s %-10s %-8s %-10s %-24s %-14s\n",
           "Name", "Type", "Size", "Binding", "Parameters", "Function label");
}

void PrintLocalSymbolTable(char *functionName) {
    Lsymbol *temp = Lhead;

    printf("\nLocal Symbol Table: %s\n", functionName);
    PrintTableHeader();
    while (temp != NULL) {
        printf("%-16s %-10s %-8s %-10d %-24s %-14s\n",
               temp->name, TypeName(temp->type), "-", temp->binding, "-", "-");
        temp = temp->next;
    }
}

void PrintSymbolTable() {
    Gsymbol *temp = Ghead;
    printf("\nGlobal Symbol Table\n");
    PrintTableHeader();

    while (temp != NULL) {
        if (temp->flabel == -1) {
            printf("%-16s %-10s %-8d %-10d %-24s %-14s\n",
                   temp->name, TypeName(temp->type), temp->size, temp->binding, "-", "-");
        } else {
            Paramstruct *param = temp->paramlist;
            char parameters[256] = "";
            if (param == NULL) {
                strcpy(parameters, "(none)");
            } else {
                while (param != NULL) {
                    size_t used = strlen(parameters);
                    snprintf(parameters + used, sizeof(parameters) - used, "%s%s %s",
                             used == 0 ? "" : ", ", TypeName(param->type), param->name);
                    param = param->next;
                }
            }
            char label[16];
            snprintf(label, sizeof(label), "F%d", temp->flabel);
            printf("%-16s %-10s %-8s %-10s %-24s %-14s\n",
                   temp->name, TypeName(temp->type), "-", "-", parameters, label);
        }

        temp = temp->next;
    }
}

tnode* makeAddressNode(tnode *var) { // creates an AST node for the address-of operator
    if (var->nodetype != NODE_ID && var->nodetype != NODE_FIELD) {
        fprintf(stderr, "Address-of operator can only be used with a variable\n");
        exit(1);
    }

    int pointerType;

    if (var->type == TYPE_INT)
        pointerType = TYPE_INT_PTR;
    else if (var->type == TYPE_STR)
        pointerType = TYPE_STR_PTR;
    else if (FindTupleByType(var->type) != NULL)
        pointerType = TuplePointerType(var->type);
    else {
        fprintf(stderr, "Cannot take address of a pointer\n");
        exit(1);
    }

    return createTree(0, pointerType, NODE_ADDRESS, NULL, var, NULL, NULL);
}

tnode* makeDereferenceNode(tnode *ptr) { // EX2: creates an AST node for dereferencing a pointer
    int valueType;

    if (ptr->type == TYPE_INT_PTR)
        valueType = TYPE_INT;
    else if (ptr->type == TYPE_STR_PTR)
        valueType = TYPE_STR;
    else if (ptr->type >= TYPE_TUPLE_PTR_BASE)
        valueType = TYPE_TUPLE_BASE + ptr->type - TYPE_TUPLE_PTR_BASE;
    else {
        fprintf(stderr, "Cannot dereference a non-pointer\n");
        exit(1);
    }

    return createTree(0, valueType, NODE_DEREFERENCE, NULL, ptr, NULL, NULL);
}

tnode* createTree(int val, int type, int nodetype, char* varname, tnode* l, tnode* m, tnode* r) {
    tnode* temp = (tnode*)malloc(sizeof(tnode));

    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    temp->varname = varname;
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    temp->arglist = NULL;
    temp->left = l;
    temp->middle = m;
    temp->right = r;

    return temp;
}

tnode* makeNumNode(int n) {
    return createTree(n, TYPE_INT, NODE_NUM, NULL, NULL, NULL, NULL);
}

tnode* makeStrNode(char *s) {
    return createTree(0, TYPE_STR, NODE_STR, s, NULL, NULL, NULL); // we put s into varname field as first arg (int val) is int
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
    else if (strcmp(op, "%") == 0) {
        nodetype = NODE_MOD;
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
    else if (strcmp(op, "||") == 0) {
        nodetype = NODE_OR;
        type = TYPE_BOOL;
    }
    else if (strcmp(op, "&&") == 0) {
        nodetype = NODE_AND;
        type = TYPE_BOOL;
    }
    else {
        fprintf(stderr, "Invalid operator %s\n", op);
        exit(1);
    }

    if ((nodetype == NODE_OR || nodetype == NODE_AND) &&
        (l->type != TYPE_BOOL || r->type != TYPE_BOOL)) {
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }
    if ((nodetype == NODE_EQ || nodetype == NODE_NE) && l->type != r->type) {
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }
    if (nodetype != NODE_EQ && nodetype != NODE_NE &&
        nodetype != NODE_OR && nodetype != NODE_AND &&
        (l->type != TYPE_INT || r->type != TYPE_INT)) {
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, type, nodetype, NULL, l, NULL, r);
}

tnode* makeIdNode(char* name) {
    Lsymbol *localEntry = LLookup(name);
    Gsymbol *globalEntry;
    tnode *node;

    /* Local scope takes precedence over a global declaration of the same name. */
    if (localEntry != NULL) {
        node = createTree(0, localEntry->type, NODE_ID, name, NULL, NULL, NULL);
        node->Lentry = localEntry;
        return node;
    }

    globalEntry = Lookup(name);
    if (globalEntry == NULL) {
        printf("Error: Variable %s not declared\n", name);
        exit(1);
    }
    if (globalEntry->flabel != -1) {
        fprintf(stderr, "Error: '%s' is a function; call it with parentheses\n", name);
        exit(1);
    }

    node = createTree(0, globalEntry->type, NODE_ID, name, NULL, NULL, NULL);
    node->Gentry = globalEntry;
    return node;
}

tnode* makeFieldNode(char *tupleName, char *fieldName) {
    tnode *base = makeIdNode(tupleName);
    TupleType *tuple = FindTupleByType(base->type);
    Field *field;

    if (tuple == NULL) {
        fprintf(stderr, "Error: '%s' is not a tuple variable\n", tupleName);
        exit(1);
    }
    for (field = tuple->fields; field != NULL; field = field->next) {
        if (strcmp(field->name, fieldName) == 0) {
            return createTree(field->offset, field->type, NODE_FIELD, fieldName,
                              base, NULL, NULL);
        }
    }
    fprintf(stderr, "Error: tuple '%s' has no field '%s'\n", tupleName, fieldName);
    exit(1);
}

tnode* makeAssignNode(tnode* id, tnode* expr) {
    if (id->type != expr->type) { // u can only assign an int/str (a = <bool> is gay)
        // eg: a = 5 > 3
        // i.e id type and rhs type same avanam
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, TYPE_INT, NODE_ASSIGN, NULL, id, NULL, expr);
}

tnode* makeReadNode(tnode* id) {
    if (FindTupleByType(id->type) != NULL) {
        fprintf(stderr, "Error: read() requires a tuple field, not a whole tuple\n");
        exit(1);
    }
    return createTree(0, TYPE_INT, NODE_READ, NULL, id, NULL, NULL);
}

tnode* makeWriteNode(tnode* expr) {
    if (FindTupleByType(expr->type) != NULL) {
        fprintf(stderr, "Error: write() expects an int or str expression, not a tuple\n");
        exit(1);
    }
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

tnode* makeReturnNode(tnode *expr) {
    if (expr->type != TYPE_INT && expr->type != TYPE_STR &&
        expr->type != TYPE_INT_PTR && expr->type != TYPE_STR_PTR) {
        fprintf(stderr, "Error: a function can return only an int, str, or pointer expression\n");
        exit(1);
    }
    return createTree(0, expr->type, NODE_RETURN, NULL, expr, NULL, NULL);
}

tnode* makeBodyNode(tnode *statements, tnode *returnNode) {
    return createTree(0, returnNode->type, NODE_BODY, NULL,
                      statements, NULL, returnNode);
}

tnode* finalizeBodyNode(tnode *body, int returnType, char *functionName) {
    if (body->type != returnType) {
        fprintf(stderr, "Error: return type of function '%s' does not match its declaration\n",
                functionName);
        exit(1);
    }
    return body;
}

tnode* makeArgListNode(tnode *expr) {
    return createTree(0, expr->type, NODE_ARG_LIST, NULL, expr, NULL, NULL);
}

tnode* appendArgNode(tnode *arglist, tnode *expr) {
    tnode *tail = arglist;
    tnode *newArg = makeArgListNode(expr);

    while (tail->right != NULL) {
        tail = tail->right;
    }
    tail->right = newArg;
    return arglist;
}

tnode* makeFunctionCallNode(char *name, tnode *arglist) {
    Gsymbol *function = Lookup(name);
    Paramstruct *formal;
    tnode *actual;
    int position = 1;
    tnode *node;

    if (function == NULL) {
        fprintf(stderr, "Error: function '%s' is not declared\n", name);
        exit(1);
    }
    if (function->flabel == -1) {
        fprintf(stderr, "Error: '%s' is a variable, not a function\n", name);
        exit(1);
    }

    formal = function->paramlist;
    actual = arglist;
    while (formal != NULL && actual != NULL) {
        if (formal->type != actual->left->type) {
            fprintf(stderr, "Error: argument %d of '%s' has the wrong type\n",
                    position, name);
            exit(1);
        }
        formal = formal->next;
        actual = actual->right;
        position++;
    }
    if (formal != NULL || actual != NULL) {
        fprintf(stderr, "Error: argument count of '%s' does not match its declaration\n", name);
        exit(1);
    }

    node = createTree(0, function->type, NODE_FUNCTION, name, NULL, NULL, NULL);
    node->Gentry = function;
    node->arglist = arglist;
    return node;
}

// for an array with 3 elements, the ast looks like this
//                   CONNECTOR
//               /            \
//           CONNECTOR       ASSIGN
//           /       \        /    \
//       ASSIGN     ASSIGN   ARRAY  30
//       /   \       /  \    |
//    ARRAY  10   ARRAY 20  some-expression
//      |            |
//    NUM(0)       NUM(1)

tnode* makeArrayNode(char* name, tnode* index) { // index is an expression E 
    if (LLookup(name) != NULL) {
        fprintf(stderr, "Error: local variable '%s' is not an array\n", name);
        exit(1);
    }
    struct Gsymbol* entry = Lookup(name);

    if (entry == NULL) {
        printf("Error: Variable %s not declared\n", name);
        exit(1);
    }

    if (index->type != TYPE_INT) {
        printf("Error: Array index must be an integer\n");
        exit(1);
    }

    if (index->nodetype == NODE_NUM) {
        if (index->val >= entry->size) {
            fprintf(stderr, "Error: Array index %d out of bounds (array size %d)\n", 
                    index->val, entry->size);
            exit(1);
        }
    }

    tnode* node = createTree(0, entry->type, NODE_ARRAY, name, index, NULL, NULL);
    node->Gentry = entry;

    return node;
}

tnode* makeArray2DNode(char *name, tnode *rowIndex, tnode *colIndex) {
	if (LLookup(name) != NULL) {
		fprintf(stderr, "Error: local variable '%s' is not an array\n", name);
		exit(1);
	}
	struct Gsymbol *entry = Lookup(name);

	if (entry == NULL) {
		printf("Error: Variable %s not declared\n", name);
		exit(1);
	}

	if (rowIndex->type != TYPE_INT || colIndex->type != TYPE_INT) {
		printf("Error: Array indices must be integers\n");
		exit(1);
	}

	tnode *node = createTree(0, entry->type, NODE_ARRAY2D, name, rowIndex, colIndex, NULL);
	node->Gentry = entry;

	return node;
}
