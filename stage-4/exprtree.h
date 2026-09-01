#ifndef EXPRTREE_H
#define EXPRTREE_H

enum {
    NODE_NUM,
    NODE_STR,
    NODE_ID,
    NODE_ARRAY,
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
    NODE_DOWHILE
};

enum {
	TYPE_INT,
    TYPE_BOOL,
    TYPE_STR
};

typedef struct VarList { // like how Slist is stored as AST everytime reduction happens,
    // varlist should store each varname per reduction, we do it as linked list
    char* name;
    int size; // arrays aanel we declare value for this size
    struct VarList* next;
} VarList;

typedef struct Gsymbol {
    char *name;
    int type;
    int size; // default 1
    int binding;
    struct Gsymbol* next;
} Gsymbol;

typedef struct tnode {
	int type; // type of variable - INT, BOOL for now
	int val; // value of a number for NUM nodes - 5, 10
	char* varname; // name of a variable for ID nodes - a,b,...,z
	int nodetype; // information about non-leaf nodes - read/write/connector/+/* etc
    Gsymbol* Gentry; // pointer to corresponding GST entry
	struct tnode *left, *middle, *right; 
} tnode;

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

tnode* makeArrayNode(char* name, tnode* index); // for accessing array elements

struct Gsymbol* Lookup(char* name);
void Install(char* name, int type, int size); // add new var to symbol table
void PrintSymbolTable();

#endif