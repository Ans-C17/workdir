#ifndef EXPRTREE_H
#define EXPRTREE_H

/* AST node kinds. codeGen() switches on these values to emit each operation. */
enum {
    NODE_NUM,
    NODE_STR,
    NODE_ID,
    NODE_ADDRESS,
    NODE_DEREFERENCE,
    NODE_ARRAY,
    NODE_ARRAY2D,
    NODE_PLUS,
    NODE_MINUS,
    NODE_MUL,
    NODE_DIV,
    NODE_MOD,
    NODE_READ,
    NODE_WRITE,
    NODE_ASSIGN,
    NODE_CONNECTOR,
    NODE_LT,
    NODE_GT,
    NODE_LE,
    NODE_GE,
    NODE_NE,
    NODE_EQ,
    NODE_IF,
    NODE_WHILE,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_REPEAT,
    NODE_DOWHILE,
    NODE_RETURN,
    NODE_BODY,
    NODE_FUNCTION,
    NODE_MAIN,
    NODE_ARG_LIST,
    NODE_OR,
    NODE_AND,
    NODE_FIELD,
    NODE_NULL,
    NODE_ALLOC,
    NODE_FREE,
    NODE_METHOD_CALL
};

/* Primitive AST type codes; named type identity is kept in Typetable pointers. */
enum {
	TYPE_INT,
    TYPE_BOOL,
    TYPE_STR,
    TYPE_INT_PTR,
    TYPE_STR_PTR,
    TYPE_VOID,
    TYPE_NULL
};

/* One named type and its fields; built-in and user-defined types share this list. */
typedef struct Typetable {
    char *name;                 // type name
    int size;                   // number of words in a value of this type
    struct Fieldlist *fields;   // fields for user-defined aggregate types
    struct Typetable *next;
} Typetable;

typedef struct Classtable Classtable;
typedef struct Memberfunclist Memberfunclist;

/* A declaration can refer either to a normal type or to a class type. */
typedef struct ParamTypeInfo {
    Typetable *type;
    Classtable *classType;
} ParamTypeInfo;

/* One aggregate/class field and its word offset in the containing value. */
typedef struct Fieldlist {
    char *name;                 // field name
    int fieldIndex;             // position in the containing type
    Typetable *type;            // declared type-table type, if any
    Classtable *classType;      // declared class type, if any
    struct Fieldlist *next;
} Fieldlist;

/* One formal parameter; linked in source order for signature checks and calls. */
typedef struct Paramstruct {
    char* name;
    Typetable *type;
    Classtable *classType;
    struct Paramstruct* next;
} Paramstruct;

/* Method signature and dispatch information. funcposition is its stable vtable slot. */
struct Memberfunclist {
    char *name;
    Classtable *ownerClass;     // class that declares or overrides this method
    Typetable *type;            // method return type
    Paramstruct *paramlist;
    int funcposition;
    int flabel;
    int isDefined;
    Memberfunclist *next;
};

/* Class layout, inherited parent link, and method slots used by semantic checks/codegen. */
struct Classtable {
    char *name;
    Fieldlist *memberfield;
    Memberfunclist *vfuncptr;
    Classtable *parentptr;      // NULL in stage 7; inheritance comes in stage 8
    int classIndex;
    int fieldCount;
    int fieldWords;             // object words used by fields (class references use two)
    int methodCount;
    Classtable *next;
};

/* Temporary list built by parser declaration rules before entries enter a symbol table. */
typedef struct VarList { // int a, b, c indel, oronninum oru node aayit linked list aakan
    // install() vilikumbo ivarellarum gsymbol tableilek povum
    char* name;
    int size; // arrays aanel we declare value for this size
    int rows; // number of rows for 2D array
    int cols; // number of columns for 2D array
    int isArray;
    int isPointer; // 1 if pointer, else 0
    int isFunction; // distinguishes a function declaration from a variable declaration
    struct Paramstruct* paramlist;
    struct VarList* next;
} VarList;

/* Global names: variables use binding; functions use signature and flabel. */
typedef struct Gsymbol {
    char *name;
    Typetable *type;
    Classtable *classType;      // non-NULL for a global class variable
    int size; // default 1, we take the value of varlist and copy it here, gtable is the collection of all varlists
    int rows;
	int cols;
    int isArray;
    int binding; // memory address of the variable (4099)
    struct Paramstruct* paramlist;
    int flabel;
    struct Gsymbol* next;
} Gsymbol;

/* Parameters and locals for one function/method, addressed relative to BP. */
typedef struct Lsymbol {
    char *name;
    Typetable *type;
    Classtable *classType;       // non-NULL for class-typed locals, parameters, or self
    int binding;
    int vtableBinding;            // BP-relative slot for the second word of a class value
    int size;
    int rows;
    int cols;
    int isArray;
    struct Lsymbol *next;
} Lsymbol;

/* AST node shared by expressions and statements; symbol/table links are filled
 * during semantic analysis so code generation can use resolved bindings directly. */
typedef struct tnode {
	int type; // legacy primitive type code used by existing AST/codegen logic
    Typetable *typeEntry; // exact type identity, including user-defined types
    Classtable *classType; // class identity for self and class-valued expressions
    Classtable *classOwner; // owner class for a class member selection
	int val; // value of a number for NUM nodes - 5, 10
	char* varname; // name of a variable for ID nodes - a,b,...,z
    int nodetype; // information about non-leaf nodes - read/write/connector/+/* etc
    Gsymbol* Gentry; // pointer to corresponding GST entry
    Lsymbol* Lentry; // pointer to corresponding local-symbol-table entry
    Fieldlist *Fentry; // field-table entry for a NODE_FIELD
    Memberfunclist *Mentry; // method-table entry for a NODE_METHOD_CALL
    struct tnode *arglist; // expressions passed to a function call
    struct tnode *left, *middle, *right;
} tnode;

/* Saved function/main syntax tree plus the local table needed during codegen. */
typedef struct FunctionAST {
    char *name;
    tnode *tree;
    Lsymbol *localTable;
    int localCount;
    struct FunctionAST *next;
} FunctionAST;

/* Saved method tree paired with its owning class and method-table entry. */
typedef struct MethodAST {
    Classtable *classEntry;
    Memberfunclist *methodEntry;
    tnode *tree;
    Lsymbol *localTable;
    int localCount;
    struct MethodAST *next;
} MethodAST;

extern FunctionAST *FunctionASTHead;
extern MethodAST *MethodASTHead;
extern int nextBinding;
extern int nextFunctionLabel;

/* Type-table creation, lookup, and user-defined type construction. */
void TypeTableCreate(void);
Typetable *TLookup(char *name);
Typetable *TInstall(char *name, int size, Fieldlist *fields);
Fieldlist *FLookup(Typetable *type, char *name);
int GetSize(Typetable *type);
int IsUserDefinedType(Typetable *type);
void PrintTypeTable(void);
Typetable *PointerType(Typetable *type);
int TypeCode(Typetable *type);
Typetable *TBeginDefinition(char *name);
Typetable *TCurrentDefinition(void);
Fieldlist *FInstall(Typetable *owner, char *name, Typetable *fieldType, int fieldIndex);
void TFinishDefinition(Typetable *type);

/* Class and method table operations, including inherited table construction. */
Classtable *CInstall(char *name, char *parentClassName);
Classtable *CLookup(char *name);
Classtable *CGetHead(void);
Fieldlist *Class_Finstall(Classtable *classEntry, char *typeName, char *fieldName);
Memberfunclist *Class_Minstall(Classtable *classEntry, char *name,
                               Typetable *returnType, Paramstruct *paramlist);
Memberfunclist *Class_Mlookup(Classtable *classEntry, char *name);
Memberfunclist *Class_MatchMethodDefinition(Classtable *classEntry, char *name,
                                             Typetable *returnType, Paramstruct *paramlist);
int Class_CheckMethodDefinitions(Classtable *classEntry);
Fieldlist *Class_Flookup(Classtable *classEntry, char *name);
void PrintClassTable(void);

/* AST construction helpers called by exprtree.y semantic actions. */
tnode* createTree(int val, int type, int nodetype, char* varname, tnode* l, tnode* m, tnode* r);

tnode* makeNumNode(int n);
tnode* makeStrNode(char *s);
tnode* makeNullNode(void);

tnode* makeOperatorNode(char* op, tnode* l, tnode* r);
tnode* makeIdNode(char* name);
tnode* makeAssignNode(tnode* id, tnode* expr);
tnode* makeAllocNode(tnode *target);
tnode* makeFreeNode(tnode *target);
tnode* makeClassAllocNode(tnode *target, char *className);
tnode* makeClassDeleteNode(tnode *target);
tnode* makeReadNode(tnode* id);
tnode* makeWriteNode(tnode* expr);
tnode* makeConnectorNode(tnode* l, tnode* r);

tnode* makeIfNode(tnode* cond, tnode* thenStmt, tnode* elseStmt);
tnode* makeWhileNode(tnode* cond, tnode* body);

tnode* makeBreakNode();
tnode* makeContinueNode();

tnode* makeRepeatNode(tnode* body, tnode* cond);
tnode* makeDoWhileNode(tnode* body, tnode* cond);
tnode* makeReturnNode(tnode *expr);
tnode* makeBodyNode(tnode *statements, tnode *returnNode);
tnode* finalizeBodyNode(tnode *body, Typetable *returnType, char *functionName);
tnode* makeFunctionCallNode(char *name, tnode *arglist);
tnode* makeArgListNode(tnode *expr);
tnode* appendArgNode(tnode *arglist, tnode *expr);
void SaveFunctionAST(char *name, tnode *body, int isMain);
void SaveMethodAST(Classtable *classEntry, Memberfunclist *methodEntry, tnode *body);

tnode* makeArrayNode(char* name, tnode* index); // for accessing array elements
tnode* makeArray2DNode(char *name, tnode *rowIndex, tnode *colIndex);
tnode* makeFieldNode(tnode *base, char *fieldName);
tnode* makeMemberAccessNode(tnode *base, char *memberName);
tnode* makeFieldValueNode(tnode *memberAccess);
tnode* makeMethodCallNode(tnode *memberAccess, tnode *arglist);

tnode* makeAddressNode(tnode *var); // creates an AST node for the address-of operator
tnode* makeDereferenceNode(tnode *ptr); // creates an AST node for dereferencing a pointer

/* Symbol-table and scope operations used during declarations and name resolution. */
struct Gsymbol* Lookup(char* name);
void Install(char* name, Typetable *type, int size, int rows, int cols, int isArray, Paramstruct *paramlist, int flabel);
void InstallClassVariable(char *name, Classtable *classType);
void CheckFunctionDefinition(char *name, Typetable *returnType, Paramstruct *paramlist);
Lsymbol *LLookup(char *name);
void BeginFunctionScope(Paramstruct *paramlist);
void BeginMethodScope(Paramstruct *paramlist, Classtable *classEntry);
void InstallLocalVariables(VarList *varlist, Typetable *type);
void InstallLocalClassVariables(VarList *varlist, Classtable *classType);
void EndFunctionScope(void);
void PrintLocalSymbolTable(char *functionName);
void PrintSymbolTable();

#endif
