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

/* Find tuple metadata by its numeric type ID. */
static TupleType *FindTupleByType(int type) {
    TupleType *tuple = TupleHead;
    while (tuple != NULL) {
        if (tuple->type == type) return tuple;
        tuple = tuple->next;
    }
    return NULL;
}

/* Find a tuple's numeric type by its declared name. */
int TupleTypeLookup(char *name) {
    TupleType *tuple = TupleHead;
    while (tuple != NULL) {
        if (strcmp(tuple->name, name) == 0) return tuple->type;
        tuple = tuple->next;
    }
    return -1;
}

/* Map a tuple value type ID to the corresponding tuple-pointer type ID. */
int TuplePointerType(int tupleType) {
    return TYPE_TUPLE_PTR_BASE + (tupleType - TYPE_TUPLE_BASE);
}

/* Return tuple storage width in words; all scalar and pointer types occupy one. */
int TypeSize(int type) {
    TupleType *tuple = FindTupleByType(type);
    return tuple == NULL ? 1 : tuple->size;
}

/* Validate fields, assign sequential offsets, and register a new tuple type. */
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

/* Search the global table by name; used for variables, function signatures, and labels. */
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

/*
 * Install one global variable or function signature.
 * Inputs: name/type/storage dimensions/signature/label from GDecl. Return: none.
 * Variables receive nextBinding storage; functions store paramlist/flabel and
 * no data binding. GDecl is the caller; duplicate names are rejected here.
 */
void Install(char *name, int type, int size, int rows, int cols, int isArray,
             Paramstruct *paramlist, int flabel) { 
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
    newEntry->isArray = isArray;

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

/* The definition must match scalar/array kind and any declared 2D column count. */
/*
 * Compare a definition header against its global declaration.
 * Inputs: function name, return type, and definition parameter list. Return: none.
 * Checks existence, function-vs-variable, return type, parameter names/types,
 * and count; exits on mismatch. Called at the start of FDef in exprtree.y.
 */
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
            strcmp(declared->name, defined->name) != 0 ||
            declared->isArray != defined->isArray ||
            declared->cols != defined->cols) {
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

/* Search the active function's local/parameter list; makeIdNode checks this before globals. */
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

/* Append a local, scalar parameter, or array parameter with its BP offset. */
static void LInstall(char *name, int type, int binding, int isArray,
                     int isArrayParam, int size, int rows, int cols) {
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
    entry->isArray = isArray;
    entry->isArrayParam = isArrayParam;
    entry->size = size;
    entry->rows = rows;
    entry->cols = cols;

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

/* Parameters are below BP; array parameters use one slot containing the caller's base address. */
/*
 * Start a new function scope and install parameters at BP-3, BP-4, etc.
 * Input: formal parameter list (NULL for main/no-argument functions). Return: none.
 * Resets Lhead/nextLocalBinding. Called before parsing each function's locals.
 */
void BeginFunctionScope(Paramstruct *paramlist) {
    int parameterBinding = -3;

    Lhead = NULL;
    nextLocalBinding = 1;
    while (paramlist != NULL) {
        LInstall(paramlist->name, paramlist->type, parameterBinding--,
                 paramlist->isArray, paramlist->isArray, 0,
                 paramlist->rows, paramlist->cols);
        paramlist = paramlist->next;
    }
}

/* Add locals above BP; arrays reserve all elements and tuple locals reserve their full size. */
void InstallLocalVariables(VarList *varlist, int type) {
    while (varlist != NULL) {
        int storageSize = varlist->isArray ? varlist->size : TypeSize(type);
        LInstall(varlist->name, type, nextLocalBinding, varlist->isArray,
                 0, storageSize, varlist->rows, varlist->cols);
        nextLocalBinding += storageSize;
        varlist = varlist->next;
    }
}

/* Clear active local lookup after saving the AST; AST nodes still retain Lsymbol pointers. */
void EndFunctionScope(void) {
    /* The AST nodes retain their Lsymbol pointers; later stages free them after codegen. */
    Lhead = NULL;
}

/*
 * Append the completed function tree to FunctionASTHead for later codegen.
 * Inputs: function name, finalized body, and whether this is main. Return: none.
 * Retains the local-table nodes referenced by the AST and counts local words.
 */
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
            entry->localCount += local->size;
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

/* Convert internal type IDs to printable names for symbol-table output. */
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

/* Print the shared column heading for local and global symbol tables. */
static void PrintTableHeader(void) {
    printf("%-16s %-10s %-8s %-10s %-24s %-14s\n",
           "Name", "Type", "Size", "Binding", "Parameters", "Function label");
}

/* Print the currently active function's parameters and locals. */
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

/* Print global variables and function signatures, including each function label. */
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
                    if (param->isArray && param->cols > 0) {
                        snprintf(parameters + used, sizeof(parameters) - used,
                                 "%s%s %s[][%d]", used == 0 ? "" : ", ",
                                 TypeName(param->type), param->name, param->cols);
                    } else if (param->isArray) {
                        snprintf(parameters + used, sizeof(parameters) - used,
                                 "%s%s %s[]", used == 0 ? "" : ", ",
                                 TypeName(param->type), param->name);
                    } else {
                        snprintf(parameters + used, sizeof(parameters) - used, "%s%s %s",
                                 used == 0 ? "" : ", ", TypeName(param->type), param->name);
                    }
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

/* Build a pointer-valued node for taking the address of a supported variable/field. */
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

/* Build an l-value node of the pointed-to type; reject non-pointer operands. */
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

/* Allocate a zero-initialized AST node with the supplied type, kind, and children. */
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

/* Create an integer literal leaf node. */
tnode* makeNumNode(int n) {
    return createTree(n, TYPE_INT, NODE_NUM, NULL, NULL, NULL, NULL);
}

/* Create a string literal leaf node. */
tnode* makeStrNode(char *s) {
    return createTree(0, TYPE_STR, NODE_STR, s, NULL, NULL, NULL); // we put s into varname field as first arg (int val) is int
}

/* Map operator text to an AST kind, validate operand types, and assign result type. */
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

/*
 * Resolve an identifier and attach its local/global symbol entry.
 * Input: source name. Return: typed NODE_ID or compilation error.
 * Local lookup runs first, so a local declaration shadows a same-named global.
 */
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

/* Resolve a tuple field and store its type and word offset in the AST node. */
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

/* Check l-value/RHS type equality and build NODE_ASSIGN for later codegen. */
tnode* makeAssignNode(tnode* id, tnode* expr) {
    if (id->type != expr->type) { // u can only assign an int/str (a = <bool> is gay)
        // eg: a = 5 > 3
        // i.e id type and rhs type same avanam
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, TYPE_INT, NODE_ASSIGN, NULL, id, NULL, expr);
}

/* Build an input statement; whole tuples cannot be read directly. */
tnode* makeReadNode(tnode* id) {
    if (FindTupleByType(id->type) != NULL) {
        fprintf(stderr, "Error: read() requires a tuple field, not a whole tuple\n");
        exit(1);
    }
    return createTree(0, TYPE_INT, NODE_READ, NULL, id, NULL, NULL);
}

/* Build an output statement; whole tuples cannot be written directly. */
tnode* makeWriteNode(tnode* expr) {
    if (FindTupleByType(expr->type) != NULL) {
        fprintf(stderr, "Error: write() expects an int or str expression, not a tuple\n");
        exit(1);
    }
    return createTree(0, TYPE_INT, NODE_WRITE, NULL, expr, NULL, NULL);
}

/* Join two sequential statements into one AST chain node. */
tnode* makeConnectorNode(tnode* l, tnode* r) {
    return createTree(0, TYPE_INT, NODE_CONNECTOR, NULL, l, NULL, r);
}

/* Require a boolean condition and build an if/optional-else AST node. */
tnode* makeIfNode(tnode* cond, tnode* thenStmt, tnode* elseStmt) {
    if (cond->type != TYPE_BOOL) {
        fprintf(stderr, "Type mismatch\n"); // if (a + b) ❌ --- if (a < b) ✅
        exit(1);
    }

    return createTree(0, TYPE_BOOL, NODE_IF, NULL, cond, thenStmt, elseStmt);
}

/* Require a boolean condition and build a while-loop AST node. */
tnode* makeWhileNode(tnode* cond, tnode* body) {
    if (cond->type != TYPE_BOOL) {
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, TYPE_BOOL, NODE_WHILE, NULL, cond, NULL, body);
}

/* Create a break node; codegen resolves it against the active loop stack. */
tnode* makeBreakNode() {
    return createTree(0, TYPE_INT, NODE_BREAK, NULL, NULL, NULL, NULL);
}

/* Create a continue node; codegen resolves it against the active loop stack. */
tnode* makeContinueNode() {
    return createTree(0, TYPE_INT, NODE_CONTINUE, NULL, NULL, NULL, NULL);
}

/* Build a repeat-until node with its condition and body in codegen's expected slots. */
tnode* makeRepeatNode(tnode* body, tnode* cond) {
    return createTree(0, TYPE_BOOL, NODE_REPEAT, NULL, cond, NULL, body);
}

/* Build a do-while node with its condition and body in codegen's expected slots. */
tnode* makeDoWhileNode(tnode* body, tnode* cond) {
    return createTree(0, TYPE_BOOL, NODE_DOWHILE, NULL, cond, NULL, body);
}

/* Build NODE_RETURN after checking the expression has a supported returnable type. */
tnode* makeReturnNode(tnode *expr) {
    if (expr->type != TYPE_INT && expr->type != TYPE_STR &&
        expr->type != TYPE_INT_PTR && expr->type != TYPE_STR_PTR) {
        fprintf(stderr, "Error: a function can return only an int, str, or pointer expression\n");
        exit(1);
    }
    return createTree(0, expr->type, NODE_RETURN, NULL, expr, NULL, NULL);
}

/* Keep function statements and the required final return in a NODE_BODY. */
tnode* makeBodyNode(tnode *statements, tnode *returnNode) {
    return createTree(0, returnNode->type, NODE_BODY, NULL,
                      statements, NULL, returnNode);
}

/* Compare the parsed body's return type with the declared function return type. */
tnode* finalizeBodyNode(tnode *body, int returnType, char *functionName) {
    if (body->type != returnType) {
        fprintf(stderr, "Error: return type of function '%s' does not match its declaration\n",
                functionName);
        exit(1);
    }
    return body;
}

/* Create one argument-list cell: expression in left, next argument in right. */
tnode* makeArgListNode(tnode *expr) {
    return createTree(0, expr->type, NODE_ARG_LIST, NULL, expr, NULL, NULL);
}

/* Append an argument to the tail, preserving source order for signature checking. */
tnode* appendArgNode(tnode *arglist, tnode *expr) {
    tnode *tail = arglist;
    tnode *newArg = makeArgListNode(expr);

    while (tail->right != NULL) {
        tail = tail->right;
    }
    tail->right = newArg;
    return arglist;
}

/*
 * Validate a function call against its global signature and build NODE_FUNCTION.
 * Inputs: callee name and linked actual expressions. Return: typed call node.
 * Checks callee kind, each argument type, and argument count. Called by E's
 * ID(args) rules; codeGen later uses the attached Gentry and arglist.
 */
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
        tnode *argument = actual->left;
        int actualIsArray = 0;
        int actualCols = 0;

        if (argument->nodetype == NODE_ID) {
            if (argument->Lentry != NULL) {
                actualIsArray = argument->Lentry->isArray;
                actualCols = argument->Lentry->cols;
            } else if (argument->Gentry != NULL) {
                actualIsArray = argument->Gentry->isArray;
                actualCols = argument->Gentry->cols;
            }
        }

        /* Array arguments must match element type and rank; 2D arrays also match columns. */
        if (formal->isArray) {
            if (!actualIsArray || formal->type != argument->type ||
                formal->cols != actualCols) {
                fprintf(stderr,
                        "Error: argument %d of '%s' must be a matching %s array\n",
                        position, name, formal->cols > 0 ? "2D" : "1D");
                exit(1);
            }
        } else if (actualIsArray || formal->type != argument->type) {
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

/* Resolve a 1D global array access and check integer index and literal bounds. */
tnode* makeArrayNode(char* name, tnode* index) { // index is an expression E 
    Lsymbol *local = LLookup(name);
    Gsymbol *global = local == NULL ? Lookup(name) : NULL;
    int isArray = local != NULL ? local->isArray : (global != NULL && global->isArray);
    int size = local != NULL ? local->size : (global != NULL ? global->size : 0);
    int cols = local != NULL ? local->cols : (global != NULL ? global->cols : 0);
    int type = local != NULL ? local->type : (global != NULL ? global->type : -1);

    if (local == NULL && global == NULL) {
        printf("Error: Variable %s not declared\n", name);
        exit(1);
    }
    if (!isArray || cols > 0) {
        fprintf(stderr, "Error: '%s' is not a one-dimensional array\n", name);
        exit(1);
    }

    if (index->type != TYPE_INT) {
        printf("Error: Array index must be an integer\n");
        exit(1);
    }

    if (index->nodetype == NODE_NUM) {
        if (size > 0 && index->val >= size) {
            fprintf(stderr, "Error: Array index %d out of bounds (array size %d)\n", 
                    index->val, size);
            exit(1);
        }
    }

    tnode* node = createTree(0, type, NODE_ARRAY, name, index, NULL, NULL);
    node->Gentry = global;
    node->Lentry = local;

    return node;
}

/* Resolve a 2D global array access and require integer row/column expressions. */
tnode* makeArray2DNode(char *name, tnode *rowIndex, tnode *colIndex) {
	Lsymbol *local = LLookup(name);
	Gsymbol *global = local == NULL ? Lookup(name) : NULL;
	int rows = local != NULL ? local->rows : (global != NULL ? global->rows : 0);
	int cols = local != NULL ? local->cols : (global != NULL ? global->cols : 0);
	int isArray = local != NULL ? local->isArray : (global != NULL && global->isArray);
	int type = local != NULL ? local->type : (global != NULL ? global->type : -1);
	int isUnknownRows = local != NULL && local->isArrayParam && rows == 0;

	if (local == NULL && global == NULL) {
		printf("Error: Variable %s not declared\n", name);
		exit(1);
	}
	if (!isArray || cols <= 0 || (rows <= 0 && !isUnknownRows)) {
		fprintf(stderr, "Error: '%s' is not a two-dimensional array\n", name);
		exit(1);
	}

	if (rowIndex->type != TYPE_INT || colIndex->type != TYPE_INT) {
		printf("Error: Array indices must be integers\n");
		exit(1);
	}

	if (!isUnknownRows && rowIndex->nodetype == NODE_NUM && rowIndex->val >= rows) {
		fprintf(stderr, "Error: row index %d out of bounds (row count %d)\n", rowIndex->val, rows);
		exit(1);
	}
	if (colIndex->nodetype == NODE_NUM && colIndex->val >= cols) {
		fprintf(stderr, "Error: column index %d out of bounds (column count %d)\n", colIndex->val, cols);
		exit(1);
	}
	tnode *node = createTree(0, type, NODE_ARRAY2D, name, rowIndex, colIndex, NULL);
	node->Gentry = global;
	node->Lentry = local;

	return node;
}
