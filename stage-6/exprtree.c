#include "exprtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Gsymbol* Ghead = NULL;
Lsymbol* Lhead = NULL;
int nextBinding = 4096;
int nextLocalBinding = 1;

static Typetable *Thead = NULL;
static Typetable *Ttail = NULL;
static Typetable *TcurrentDefinition = NULL;

/*
 * FUNCTION: CreateTypeEntry
 * PURPOSE: Add one named type to the end of the type table.
 * INPUT: Type name and number of words used by the type.
 * RETURN: The new type entry, or NULL if memory allocation fails.
 * FLOW: Allocate and fill an entry, then link it after the current table tail.
 * This is used by TypeTableCreate() for built-in types and TInstall() for
 * user-defined types.
 */
static Typetable *CreateTypeEntry(const char *name, int size) {
    Typetable *entry = calloc(1, sizeof(Typetable));
    if (entry == NULL) return NULL;

    entry->name = strdup(name);
    if (entry->name == NULL) {
        free(entry);
        return NULL;
    }
    entry->size = size;

    if (Thead == NULL) Thead = entry;
    else Ttail->next = entry;
    Ttail = entry;
    return entry;
}

/*
 * FUNCTION: TypeTableCreate
 * PURPOSE: Create the built-in type entries needed by the compiler.
 * INPUT: None.
 * RETURN: Nothing. Stops compilation if the table cannot be created.
 * FLOW: Add int, str, bool, void, null, int_ptr, and str_ptr once, before
 * yyparse() reads declarations. User-defined entries are added later by
 * TBeginDefinition().
 */
void TypeTableCreate(void) {
    /* Safe to call more than once; preserve user entries if already initialized. */
    if (Thead != NULL) return;

    if (CreateTypeEntry("int", 1) == NULL ||
        CreateTypeEntry("str", 1) == NULL ||
        CreateTypeEntry("bool", 1) == NULL ||
        CreateTypeEntry("void", 0) == NULL ||
        CreateTypeEntry("null", 0) == NULL ||
        CreateTypeEntry("int_ptr", 1) == NULL ||
        CreateTypeEntry("str_ptr", 1) == NULL) {
        fprintf(stderr, "Error: could not initialize type table\n");
        exit(1);
    }
}

/*
 * FUNCTION: PointerType
 * PURPOSE: Find the built-in pointer type that matches int or str.
 * INPUT: The base type entry.
 * RETURN: int_ptr or str_ptr; NULL for unsupported types.
 * FLOW: Match the base type name against the two pointer types supported here.
 * Update this function and TypeTableCreate() if more pointer types are added.
 */
Typetable *PointerType(Typetable *type) {
    if (type == NULL) return NULL;
    if (strcmp(type->name, "int") == 0) return TLookup("int_ptr");
    if (strcmp(type->name, "str") == 0) return TLookup("str_ptr");
    return NULL;
}

/*
 * FUNCTION: TypeCode
 * PURPOSE: Convert a built-in type entry to the AST's small type code.
 * INPUT: A type-table entry.
 * RETURN: The matching TYPE_* value, or -1 for a user-defined type.
 * FLOW: Compare the entry with built-in types. User-defined type identity is
 * kept separately in each node's typeEntry pointer.
 */
int TypeCode(Typetable *type) {
    if (type == NULL) return -1;
    if (strcmp(type->name, "int") == 0) return TYPE_INT;
    if (strcmp(type->name, "str") == 0) return TYPE_STR;
    if (strcmp(type->name, "bool") == 0) return TYPE_BOOL;
    if (strcmp(type->name, "int_ptr") == 0) return TYPE_INT_PTR;
    if (strcmp(type->name, "str_ptr") == 0) return TYPE_STR_PTR;
    return -1; /* User-defined identity is kept in the node's typeEntry pointer. */
}

/* Find the built-in type entry used when createTree() receives a TYPE_* code. */
static Typetable *TypeEntryForCode(int type) {
    switch (type) {
        case TYPE_INT: return TLookup("int");
        case TYPE_STR: return TLookup("str");
        case TYPE_BOOL: return TLookup("bool");
        case TYPE_INT_PTR: return TLookup("int_ptr");
        case TYPE_STR_PTR: return TLookup("str_ptr");
        default: return NULL;
    }
}

/*
 * FUNCTION: TLookup
 * PURPOSE: Find a type entry by its name.
 * INPUT: Type name.
 * RETURN: Matching Typetable entry, or NULL if the name is not defined.
 * FLOW: Search the linked type table from its first entry to its last.
 * Used by grammar actions, declaration checks, and field/type validation.
 */
Typetable *TLookup(char *name) {
    Typetable *entry;
    if (name == NULL) return NULL;

    for (entry = Thead; entry != NULL; entry = entry->next) {
        if (strcmp(entry->name, name) == 0) return entry;
    }
    return NULL;
}

/*
 * FUNCTION: TInstall
 * PURPOSE: Add a type entry and attach a complete list of fields, if supplied.
 * INPUT: Type name, type size, and optional linked list of fields.
 * RETURN: New type entry, or NULL for a duplicate name or invalid field list.
 * FLOW: Check that field types exist and field names are unique, assign each
 * field its word index, then append the type to the table. TBeginDefinition()
 * also uses this to add an empty entry before recursive fields are read.
 */
Typetable *TInstall(char *name, int size, Fieldlist *fields) {
    Typetable *entry;
    Fieldlist *field;
    int index = 0;
    if (name == NULL || TLookup(name) != NULL) return NULL;

    /* Each user-defined field is one word; assign positions in declaration order. */
    for (field = fields; field != NULL; field = field->next) {
        Fieldlist *previous;
        Typetable *knownType;
        for (knownType = Thead; knownType != NULL; knownType = knownType->next) {
            if (knownType == field->type) break;
        }
        if (field->name == NULL || field->type == NULL || knownType == NULL) return NULL;
        for (previous = fields; previous != field; previous = previous->next) {
            if (strcmp(previous->name, field->name) == 0) return NULL;
        }
        field->fieldIndex = index++;
    }

    entry = CreateTypeEntry(name, size);
    if (entry == NULL) return NULL;
    entry->fields = fields;
    return entry;
}

/*
 * FUNCTION: TBeginDefinition
 * PURPOSE: Start a type definition before its fields have been read.
 * INPUT: The new type name.
 * RETURN: The incomplete type entry, or NULL if the name/state is invalid.
 * FLOW: Add an empty type entry and mark it as the type currently being built.
 * The grammar then calls FInstall() for each field and TFinishDefinition()
 * after the closing brace. Adding the name first allows self-reference.
 */
Typetable *TBeginDefinition(char *name) {
    Typetable *entry;
    if (name == NULL || TLookup(name) != NULL || TcurrentDefinition != NULL) return NULL;

    /* Install the name first, allowing a field to refer back to this same type. */
    entry = TInstall(name, 0, NULL);
    if (entry == NULL) return NULL;
    TcurrentDefinition = entry;
    return entry;
}

/* Return the type entry currently receiving fields from the parser. */
Typetable *TCurrentDefinition(void) {
    return TcurrentDefinition;
}

/*
 * FUNCTION: FInstall
 * PURPOSE: Add one field to the type currently being defined.
 * INPUT: Owner type, field name, field type, and field position.
 * RETURN: The new field entry, or NULL if the field/type is invalid or repeated.
 * FLOW: Check the owner and field type, reject duplicate names, then append a
 * Fieldlist entry. Called by the FieldDecl grammar rule for each declaration.
 */
Fieldlist *FInstall(Typetable *owner, char *name, Typetable *fieldType, int fieldIndex) {
    Fieldlist *field;
    Fieldlist *tail;
    Typetable *knownType;
    if (owner == NULL || name == NULL || fieldType == NULL || owner != TcurrentDefinition)
        return NULL;
    for (knownType = Thead; knownType != NULL; knownType = knownType->next) {
        if (knownType == fieldType) break;
    }
    if (knownType == NULL) return NULL;
    if (FLookup(owner, name) != NULL) return NULL;

    field = calloc(1, sizeof(Fieldlist));
    if (field == NULL) return NULL;
    field->name = strdup(name);
    if (field->name == NULL) {
        free(field);
        return NULL;
    }
    field->fieldIndex = fieldIndex;
    field->type = fieldType;
    if (owner->fields == NULL) owner->fields = field;
    else {
        tail = owner->fields;
        while (tail->next != NULL) tail = tail->next;
        tail->next = field;
    }
    return field;
}

/*
 * FUNCTION: TFinishDefinition
 * PURPOSE: Mark a user-defined type as complete and record its field count.
 * INPUT: The type entry being completed.
 * RETURN: Nothing. Stops compilation if it is not the active definition.
 * FLOW: Count the linked fields, store the count as the type size, and clear
 * TcurrentDefinition. Called after the type's closing brace is parsed.
 */
void TFinishDefinition(Typetable *type) {
    Fieldlist *field;
    int size = 0;
    if (type == NULL || type != TcurrentDefinition) {
        fprintf(stderr, "Error: invalid type definition state\n");
        exit(1);
    }
    for (field = type->fields; field != NULL; field = field->next) size++;
    type->size = size;
    TcurrentDefinition = NULL;
}

/*
 * FUNCTION: FLookup
 * PURPOSE: Find a field by name inside one user-defined type.
 * INPUT: Owner type and field name.
 * RETURN: Matching Fieldlist entry, or NULL if the field is absent.
 * FLOW: Search only that type's field list. makeFieldNode() uses this to check
 * each part of an expression such as item.next.value.
 */
Fieldlist *FLookup(Typetable *type, char *name) {
    Fieldlist *field;
    if (type == NULL || name == NULL) return NULL;

    for (field = type->fields; field != NULL; field = field->next) {
        if (strcmp(field->name, name) == 0) return field;
    }
    return NULL;
}

/* Return a user-defined type's field count; alloc() uses it as the requested size. */
int GetSize(Typetable *type) {
    return type == NULL ? 0 : type->size;
}

/* Return true for named user types and false for built-in types or NULL. */
int IsUserDefinedType(Typetable *type) {
    return type != NULL &&
           type != TLookup("int") &&
           type != TLookup("str") &&
           type != TLookup("bool") &&
           type != TLookup("void") &&
           type != TLookup("null") &&
           type != TLookup("int_ptr") &&
           type != TLookup("str_ptr");
}

/* Print the type and field tables for checking the parser's Stage 6 results. */
void PrintTypeTable(void) {
    Typetable *type;

    printf("\nType Table\n");
    printf("%-20s %s\n", "Type", "Size (words)");
    printf("%-20s %s\n", "--------------------", "------------");

    for (type = Thead; type != NULL; type = type->next) {
        printf("%-20s %d\n", type->name, type->size);
    }

    printf("\nField Table\n");
    printf("%-20s %-12s %-20s %s\n",
           "Type", "Field index", "Field name", "Field type");
    printf("%-20s %-12s %-20s %s\n",
           "--------------------", "------------", "--------------------", "----------");
    for (type = Thead; type != NULL; type = type->next) {
        Fieldlist *field;
        for (field = type->fields; field != NULL; field = field->next) {
            printf("%-20s %-12d %-20s %s\n",
                   type->name, field->fieldIndex, field->name,
                   field->type == NULL ? "?" : field->type->name);
        }
    }
}

FunctionAST *FunctionASTHead = NULL;
static FunctionAST *functionASTTail = NULL;

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

/* Store the resolved type pointer in the global table; variables get memory bindings. */
void Install(char *name, Typetable *type, int size, int rows, int cols, int isArray, Paramstruct *paramlist, int flabel) {
    // entry to symbol table
    if (type == NULL) {
        fprintf(stderr, "Error: symbol '%s' has an undefined type\n", name);
        exit(1);
    }
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

/* Task 2(a): a definition must have exactly the signature declared globally. */
/* Check a definition against its declaration using exact type entries and parameter names. */
void CheckFunctionDefinition(char *name, Typetable *returnType, Paramstruct *paramlist) {
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

static void LInstall(char *name, Typetable *type, int binding,
                     int size, int rows, int cols, int isArray) {
    Lsymbol *entry;
    Lsymbol *temp;

    if (type == NULL) {
        fprintf(stderr, "Error: local symbol '%s' has an undefined type\n", name);
        exit(1);
    }
    if (LLookup(name) != NULL) {
        fprintf(stderr, "Error: local symbol '%s' is already declared in this function\n", name);
        exit(1);
    }

    entry = calloc(1, sizeof(Lsymbol));
    entry->name = strdup(name);
    entry->type = type;
    entry->binding = binding;
    entry->size = size;
    entry->rows = rows;
    entry->cols = cols;
    entry->isArray = isArray;

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
        LInstall(paramlist->name, paramlist->type, parameterBinding--,
                 1, 0, 0, 0);
        paramlist = paramlist->next;
    }
}

void InstallLocalVariables(VarList *varlist, Typetable *type) {
    while (varlist != NULL) {
        int size = varlist->isArray ? varlist->size : 1;
        LInstall(varlist->name, type, nextLocalBinding,
                 size, varlist->rows, varlist->cols, varlist->isArray);
        nextLocalBinding += size;
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

static const char *SymbolTypeName(Typetable *type) {
    return type == NULL ? "?" : type->name;
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
        printf("%-16s %-10s %-8d %-10d %-24s %-14s\n",
               temp->name, SymbolTypeName(temp->type), temp->size, temp->binding, "-", "-");
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
                   temp->name, SymbolTypeName(temp->type), temp->size, temp->binding, "-", "-");
        } else {
            Paramstruct *param = temp->paramlist;
            char parameters[256] = "";
            if (param == NULL) {
                strcpy(parameters, "(none)");
            } else {
                while (param != NULL) {
                    size_t used = strlen(parameters);
                    snprintf(parameters + used, sizeof(parameters) - used, "%s%s %s",
                             used == 0 ? "" : ", ", SymbolTypeName(param->type), param->name);
                    param = param->next;
                }
            }
            char label[16];
            snprintf(label, sizeof(label), "F%d", temp->flabel);
            printf("%-16s %-10s %-8s %-10s %-24s %-14s\n",
                   temp->name, SymbolTypeName(temp->type), "-", "-", parameters, label);
        }

        temp = temp->next;
    }
}

tnode* makeAddressNode(tnode *var) { // creates an AST node for the address-of operator
    if (var->nodetype != NODE_ID) {
        fprintf(stderr, "Address-of operator can only be used with a variable\n");
        exit(1);
    }

    int pointerType;

    if (var->type == TYPE_INT)
        pointerType = TYPE_INT_PTR;
    else if (var->type == TYPE_STR)
        pointerType = TYPE_STR_PTR;
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
    else {
        fprintf(stderr, "Cannot dereference a non-pointer\n");
        exit(1);
    }

    return createTree(0, valueType, NODE_DEREFERENCE, NULL, ptr, NULL, NULL);
}

/*
 * FUNCTION: createTree
 * PURPOSE: Allocate and initialize one AST node.
 * INPUT: Node value/type/kind/name and its three child pointers.
 * RETURN: The new node.
 * FLOW: Set all fields, including symbol/type links, to known values before
 * returning. Stage 6 type constructors then set typeEntry to the exact named
 * type, which is needed for assignment and field checks.
 */
tnode* createTree(int val, int type, int nodetype, char* varname, tnode* l, tnode* m, tnode* r) {
    tnode* temp = (tnode*)malloc(sizeof(tnode));

    temp->val = val;
    temp->type = type;
    temp->typeEntry = TypeEntryForCode(type);
    temp->nodetype = nodetype;
    temp->varname = varname;
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    temp->Fentry = NULL;
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

/*
 * FUNCTION: makeNullNode
 * PURPOSE: Build the AST leaf for the ExpL NULL constant.
 * INPUT: None.
 * RETURN: A node with the built-in null type.
 * FLOW: Save both the old TYPE_NULL code and the type-table entry. Assignment
 * and equality checks use that entry to allow NULL with user-defined values.
 */
tnode* makeNullNode(void) {
    tnode *node = createTree(0, TYPE_NULL, NODE_NULL, NULL, NULL, NULL, NULL);
    node->typeEntry = TLookup("null");
    return node;
}

/*
 * FUNCTION: makeOperatorNode
 * PURPOSE: Build an operator node after checking its operand types.
 * INPUT: Operator text and left/right expression nodes.
 * RETURN: A typed AST node; stops compilation on a type mismatch.
 * FLOW: Convert the operator to a node kind, check the operand types, and
 * return a node with the result type. Equality uses exact type-entry identity;
 * NULL may be compared with a user-defined type. Extend these checks when a
 * new operator or type combination is added.
 */
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
    if (nodetype == NODE_EQ || nodetype == NODE_NE) {
        int sameNamedType = l->typeEntry == r->typeEntry;
        int leftIsNull = l->typeEntry == TLookup("null");
        int rightIsNull = r->typeEntry == TLookup("null");
        int nullComparedWithUserType =
            (leftIsNull && IsUserDefinedType(r->typeEntry)) ||
            (rightIsNull && IsUserDefinedType(l->typeEntry));

        if (!sameNamedType && !nullComparedWithUserType) {
            fprintf(stderr, "Type mismatch\n");
            exit(1);
        }
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
 * FUNCTION: makeIdNode
 * PURPOSE: Build a variable node and attach its declared type and symbol entry.
 * INPUT: Variable name.
 * RETURN: A typed AST leaf; stops compilation if the name is invalid.
 * FLOW: Search the current function's locals first, then globals. Save the
 * exact Typetable pointer so later Stage 6 checks can distinguish named types.
 */
tnode* makeIdNode(char* name) {
    Lsymbol *localEntry = LLookup(name);
    Gsymbol *globalEntry;
    tnode *node;

    /* Local scope takes precedence over a global declaration of the same name. */
    if (localEntry != NULL) {
        node = createTree(0, TypeCode(localEntry->type), NODE_ID, name, NULL, NULL, NULL);
        node->typeEntry = localEntry->type;
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

    node = createTree(0, TypeCode(globalEntry->type), NODE_ID, name, NULL, NULL, NULL);
    node->typeEntry = globalEntry->type;
    node->Gentry = globalEntry;
    return node;
}

/*
 * FUNCTION: makeAssignNode
 * PURPOSE: Build an assignment after checking that both sides have compatible types.
 * INPUT: Destination variable/field node and right-side expression node.
 * RETURN: Assignment AST node; stops compilation on a type mismatch.
 * FLOW: Require the same Typetable entry on both sides. The only exception is
 * NULL assigned to a user-defined variable. Field assignment reaches here
 * through the Field grammar and uses the same rule as ordinary assignment.
 */
tnode* makeAssignNode(tnode* id, tnode* expr) {
    /* NULL is the only value allowed to differ from the destination's named type. */
    int nullToUserType = expr->typeEntry == TLookup("null") &&
                         IsUserDefinedType(id->typeEntry);

    if (id->typeEntry != expr->typeEntry && !nullToUserType) {
        /* Different named types cannot be assigned; NULL is handled above. */
        fprintf(stderr, "Type mismatch\n");
        exit(1);
    }

    return createTree(0, TYPE_INT, NODE_ASSIGN, NULL, id, NULL, expr);
}

/*
 * FUNCTION: makeAllocNode
 * PURPOSE: Build an alloc() statement for a user-defined variable or field.
 * INPUT: The AST node that will hold the allocated object's address.
 * RETURN: NODE_ALLOC, or stops compilation for an invalid target/type size.
 * FLOW: Require a user-defined type, check that its field count is 1 to 8,
 * then record the requested type on the node. codeGen() later asks emitAlloc()
 * for a heap block and stores the returned address in this target.
 */
tnode* makeAllocNode(tnode *target) {
    int size;
    tnode *node;

    if (target == NULL || !IsUserDefinedType(target->typeEntry)) {
        fprintf(stderr, "Error: alloc() target must have a user-defined type\n");
        exit(1);
    }

    /* The fixed allocator returns 8-word blocks, so reject larger types here. */
    size = GetSize(target->typeEntry);
    if (size <= 0 || size > 8) {
        fprintf(stderr,
                "Error: type '%s' needs %d words; alloc() supports types of 1 to 8 words\n",
                target->typeEntry->name, size);
        exit(1);
    }

    node = createTree(0, TYPE_INT, NODE_ALLOC, NULL, target, NULL, NULL);
    node->typeEntry = target->typeEntry;
    return node;
}

/*
 * FUNCTION: makeFreeNode
 * PURPOSE: Build a free() statement for a user-defined variable or field.
 * INPUT: The AST node whose stored heap address should be released.
 * RETURN: NODE_FREE, or stops compilation if the target is not user-defined.
 * FLOW: Check the target type and create the node. codeGen() reads the stored
 * address and emits the instructions that return its block to the free list.
 */
tnode* makeFreeNode(tnode *target) {
    tnode *node;

    if (target == NULL || !IsUserDefinedType(target->typeEntry)) {
        fprintf(stderr, "Error: free() argument must have a user-defined type\n");
        exit(1);
    }

    node = createTree(0, TYPE_INT, NODE_FREE, NULL, target, NULL, NULL);
    node->typeEntry = target->typeEntry;
    return node;
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

/*
 * FUNCTION: makeReturnNode
 * PURPOSE: Build a function return node and reject unsupported return values.
 * INPUT: Return expression AST.
 * RETURN: NODE_RETURN carrying the expression's exact type entry.
 * FLOW: Reject bool, void, NULL, or missing type entries, then copy the
 * expression type. finalizeBodyNode() later compares it with the declaration.
 */
tnode* makeReturnNode(tnode *expr) {
    if (expr->typeEntry == NULL || expr->typeEntry == TLookup("bool") ||
        expr->typeEntry == TLookup("void") || expr->typeEntry == TLookup("null")) {
        fprintf(stderr, "Error: invalid function return type\n");
        exit(1);
    }
    tnode *node = createTree(0, expr->type, NODE_RETURN, NULL, expr, NULL, NULL);
    node->typeEntry = expr->typeEntry;
    return node;
}

tnode* makeBodyNode(tnode *statements, tnode *returnNode) {
    tnode *node = createTree(0, returnNode->type, NODE_BODY, NULL,
                             statements, NULL, returnNode);
    node->typeEntry = returnNode->typeEntry;
    return node;
}

/*
 * FUNCTION: finalizeBodyNode
 * PURPOSE: Check a function body's return type against its declaration.
 * INPUT: Body AST, declared return type, and function name for the error.
 * RETURN: The same body node when its exact named type matches.
 * FLOW: Compare type-table entry pointers; reject a mismatch before code
 * generation. Called by the function and main grammar actions.
 */
tnode* finalizeBodyNode(tnode *body, Typetable *returnType, char *functionName) {
    if (body->typeEntry != returnType) {
        fprintf(stderr, "Error: return type of function '%s' does not match its declaration\n",
                functionName);
        exit(1);
    }
    return body;
}

tnode* makeArgListNode(tnode *expr) {
    tnode *node = createTree(0, expr->type, NODE_ARG_LIST, NULL, expr, NULL, NULL);
    node->typeEntry = expr->typeEntry;
    return node;
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
        if (formal->type != actual->left->typeEntry) {
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

    node = createTree(0, TypeCode(function->type), NODE_FUNCTION, name, NULL, NULL, NULL);
    node->typeEntry = function->type;
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
    Lsymbol *local = LLookup(name);
    Gsymbol *global = local == NULL ? Lookup(name) : NULL;
    Typetable *elementType;
    int size, cols, isArray;

    if (local == NULL && global == NULL) {
        fprintf(stderr, "Error: array '%s' is not declared\n", name);
        exit(1);
    }
    elementType = local != NULL ? local->type : global->type;
    size = local != NULL ? local->size : global->size;
    cols = local != NULL ? local->cols : global->cols;
    isArray = local != NULL ? local->isArray : global->isArray;
    if (!isArray) {
        fprintf(stderr, "Error: '%s' is not an array\n", name);
        exit(1);
    }
    if (cols > 0) {
        fprintf(stderr, "Error: two-dimensional array '%s' requires two indices\n", name);
        exit(1);
    }

    if (index->type != TYPE_INT) {
        printf("Error: Array index must be an integer\n");
        exit(1);
    }

    if (index->nodetype == NODE_NUM) {
        if (index->val >= size) {
            fprintf(stderr, "Error: Array index %d out of bounds (array size %d)\n", 
                    index->val, size);
            exit(1);
        }
    }

    tnode* node = createTree(0, TypeCode(elementType), NODE_ARRAY, name, index, NULL, NULL);
    node->typeEntry = elementType;
    node->Gentry = global;
    node->Lentry = local;

    return node;
}

tnode* makeArray2DNode(char *name, tnode *rowIndex, tnode *colIndex) {
	Lsymbol *local = LLookup(name);
	Gsymbol *global = local == NULL ? Lookup(name) : NULL;
	Typetable *elementType;
	int rows, cols, isArray;

	if (local == NULL && global == NULL) {
		fprintf(stderr, "Error: array '%s' is not declared\n", name);
		exit(1);
	}
	elementType = local != NULL ? local->type : global->type;
	rows = local != NULL ? local->rows : global->rows;
	cols = local != NULL ? local->cols : global->cols;
	isArray = local != NULL ? local->isArray : global->isArray;
	if (!isArray || rows <= 0 || cols <= 0) {
		fprintf(stderr, "Error: '%s' is not a two-dimensional array\n", name);
		exit(1);
	}

	if (rowIndex->type != TYPE_INT || colIndex->type != TYPE_INT) {
		printf("Error: Array indices must be integers\n");
		exit(1);
	}

	if (rowIndex->nodetype == NODE_NUM && rowIndex->val >= rows) {
		fprintf(stderr, "Error: row index %d out of bounds (row count %d)\n", rowIndex->val, rows);
		exit(1);
	}
	if (colIndex->nodetype == NODE_NUM && colIndex->val >= cols) {
		fprintf(stderr, "Error: column index %d out of bounds (column count %d)\n", colIndex->val, cols);
		exit(1);
	}
	tnode *node = createTree(0, TypeCode(elementType), NODE_ARRAY2D, name, rowIndex, colIndex, NULL);
	node->typeEntry = elementType;
	node->Gentry = global;
	node->Lentry = local;

	return node;
}

/*
 * FUNCTION: makeFieldNode
 * PURPOSE: Build one part of a dotted field expression and check it exists.
 * INPUT: Base variable/field AST and the next field name after a dot.
 * RETURN: NODE_FIELD with its field-table entry and exact field type.
 * FLOW: Look up the name on base->typeEntry, then create the new node. For a
 * chain like head.next.value, the next call receives the previous field node.
 * codeGen() later follows Fentry->fieldIndex to reach this field's word.
 * MODIFICATION HINT: Add field-type validation or new field syntax here.
 */
tnode* makeFieldNode(tnode *base, char *fieldName) {
    Fieldlist *field;
    tnode *node;

    if (base == NULL || base->typeEntry == NULL || fieldName == NULL) {
        fprintf(stderr, "Error: invalid field access\n");
        exit(1);
    }

    if (base->typeEntry->fields == NULL) {
        fprintf(stderr, "Error: type '%s' has no fields\n", base->typeEntry->name);
        exit(1);
    }

    /* Use the preceding expression's type, so every nested field link is checked. */
    field = FLookup(base->typeEntry, fieldName);
    if (field == NULL) {
        fprintf(stderr, "Error: type '%s' has no field named '%s'\n",
                base->typeEntry->name, fieldName);
        exit(1);
    }

    node = createTree(0, TypeCode(field->type), NODE_FIELD, fieldName,
                      base, NULL, NULL);
    node->typeEntry = field->type;
    node->Fentry = field;
    return node;
}
