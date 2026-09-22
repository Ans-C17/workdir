#ifndef EXPRTREE_H
#define EXPRTREE_H

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
    NODE_AND
};

enum {
	TYPE_INT,
    TYPE_BOOL,
    TYPE_STR,
    TYPE_INT_PTR,
    TYPE_STR_PTR
};

typedef struct Paramstruct {
    char* name;
    int type;
    struct Paramstruct* next;
} Paramstruct;

typedef struct VarList { // int a, b, c indel, oronninum oru node aayit linked list aakan
    // install() vilikumbo ivarellarum gsymbol tableilek povum
    char* name;
    int size; // arrays aanel we declare value for this size
    int rows; // number of rows for 2D array
    int cols; // number of columns for 2D array
    int isPointer; // 1 if pointer, else 0
    int isFunction; // distinguishes a function declaration from a variable declaration
    struct Paramstruct* paramlist;
    struct VarList* next;
} VarList;

typedef struct Gsymbol {
    char *name;
    int type;
    int size; // default 1, we take the value of varlist and copy it here, gtable is the collection of all varlists
    int rows;
	int cols;
    int binding; // memory address of the variable (4099)
    struct Paramstruct* paramlist;
    int flabel;
    struct Gsymbol* next;
} Gsymbol;

typedef struct Lsymbol {
    char *name;
    int type;
    int binding;
    struct Lsymbol *next;
} Lsymbol;

typedef struct tnode {
	int type; // type of variable - INT, BOOL for now
	int val; // value of a number for NUM nodes - 5, 10
	char* varname; // name of a variable for ID nodes - a,b,...,z
    int nodetype; // information about non-leaf nodes - read/write/connector/+/* etc
    Gsymbol* Gentry; // pointer to corresponding GST entry
    Lsymbol* Lentry; // pointer to corresponding local-symbol-table entry
    struct tnode *arglist; // expressions passed to a function call
    struct tnode *left, *middle, *right;
} tnode;

typedef struct FunctionAST {
    char *name;
    tnode *tree;
    Lsymbol *localTable;
    int localCount;
    struct FunctionAST *next;
} FunctionAST;

extern FunctionAST *FunctionASTHead;
extern int nextBinding;

tnode* createTree(int val, int type, int nodetype, char* varname, tnode* l, tnode* m, tnode* r);

tnode* makeNumNode(int n);
tnode* makeStrNode(char *s);

tnode* makeOperatorNode(char* op, tnode* l, tnode* r);
tnode* makeIdNode(char* name);
tnode* makeAssignNode(tnode* id, tnode* expr);
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
tnode* finalizeBodyNode(tnode *body, int returnType, char *functionName);
tnode* makeFunctionCallNode(char *name, tnode *arglist);
tnode* makeArgListNode(tnode *expr);
tnode* appendArgNode(tnode *arglist, tnode *expr);
void SaveFunctionAST(char *name, tnode *body, int isMain);

tnode* makeArrayNode(char* name, tnode* index); // for accessing array elements
tnode* makeArray2DNode(char *name, tnode *rowIndex, tnode *colIndex);

tnode* makeAddressNode(tnode *var); // creates an AST node for the address-of operator
tnode* makeDereferenceNode(tnode *ptr); // creates an AST node for dereferencing a pointer

struct Gsymbol* Lookup(char* name);
void Install(char* name, int type, int size, int rows, int cols, Paramstruct *paramlist, int flabel); // add new var to symbol table    
void CheckFunctionDefinition(char *name, int returnType, Paramstruct *paramlist);
Lsymbol *LLookup(char *name);
void BeginFunctionScope(Paramstruct *paramlist);
void InstallLocalVariables(VarList *varlist, int type);
void EndFunctionScope(void);
void PrintLocalSymbolTable(char *functionName);
void PrintSymbolTable();

#endif
