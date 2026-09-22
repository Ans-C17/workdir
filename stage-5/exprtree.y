%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "codegen.h"

int yylex();
void yyerror(const char* s);

tnode* root;

FILE* targetFile;
int nextFunctionLabel = 0;
%}

%union{
    tnode* node;
    char* str;
    int num;
    VarList* varlist;
    Paramstruct* paramlist;
}

// we do SYNTAX ANALYSIS here - checking if the syntax is right like ID ASSIGN E SEMICOLON
// SEMANTIC ANALYSIS = is the meaning valid?
// a = b < c; can pass the above grammar SYNTACTICALLY, but fails SEMANTICALLY

%token <num> NUM 
%token <str> ID
// bison terminology: the SEMANTIC VALUE associated with NUM is <num>, 
// i.e bisons way of saying this is the C value associated with the grammar symbol

// these guys dont return a semantic value
// oru if kanda u know its an if, ok, but oru num kanda u need the value of the num, hence <num> exists
%token PLUS MINUS MUL DIV MOD
%token LT GT LE GE EQ NE OR AND

%token ADDRESS

%token T_BEGIN T_END 
%token DECL ENDDECL
%token INT STR
%token ASSIGN SEMICOLON
%token MAIN RETURN

%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token REPEAT UNTIL
%token BREAK CONTINUE
%token <str> STRING

// 1. terminal -> %TOKEN (with or without semantic value, declaration required)
// 2. non terminal -> %TYPE (not required if no semantic value)

%type <node> Program MainBlock Body ReturnStmt ArgList Slist Stmt InputStmt OutputStmt AsgStmt E Variable
%type <node> IfStmt WhileStmt
%type <node> BreakStmt ContinueStmt
%type <node> RepeatStmt DoWhileStmt

%type <num> Type // Type gets INT or STR and returns TYPE_INT or TYPE_STR as an integer value
%type <varlist> VarList
%type <varlist> IdList
%type <paramlist> ParamList
%type <paramlist> Param

%left OR
%left AND
%left EQ NE // a + 5 < b * 2 -> (a + 5) < (b * 2) => arithmetic before comparison
%left LT GT LE GE // conventionally equality operators lower precedence than relation operators
%left PLUS MINUS
%left MUL DIV MOD

%start Program

%%
// the parser internally has one big automaton of ALL the grammar rules combined
// so when it asks for next yylex() call, it gets one lookahead token
// The current automaton state determines which tokens are valid next - 
// and which transition/action to take out of all the branches
// it decides between shift and reduce by matching the token
// if it is partially matched it shifts to next state, expecting another token
// if it matches a complete grammar rule, it reduces it into the non terminal on the left
// runs the yacc code block, and continues on with the reduced state
Program : GDeclBlock FDefBlock MainBlock { $$ = $3; }
        | GDeclBlock MainBlock           { $$ = $2; }
        | MainBlock                      { $$ = $1; };

GDeclBlock : DECL GDeclList ENDDECL | DECL ENDDECL;

GDeclList : GDeclList GDecl | GDecl;

GDecl : Type VarList SEMICOLON {
    // if i have like 
    // int a, b;
    // int c, d; (in two lines)
    // the varlist gon be like two diff linked lists, and each time reduction is done, we traverse thru
    VarList* temp = $2;

    while (temp != NULL) {
        int varType = $1;
        if (temp->isPointer) {
            if ($1 == TYPE_INT) varType = TYPE_INT_PTR;
            else if ($1 == TYPE_STR) varType = TYPE_STR_PTR;
        }

        if (temp->isFunction) {
            Install(temp->name, varType, 0, 0, 0, temp->paramlist,
                    nextFunctionLabel++);
        } else {
            Install(temp->name, varType, temp->size, temp->rows, temp->cols,
                    NULL, -1);
        }
        temp = temp->next;
    }
};

Type : INT {
        $$ = TYPE_INT;
    }
    | STR {
        $$ = TYPE_STR;
    };

/*
This supports all of these:
    int a;
    int a[10];
    int a[10], b[10];
    int a, b[5];
    int a[10], b, c[20];
*/
VarList : VarList ',' ID '[' NUM ']' '[' NUM ']' {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = $3;
        newVar->rows = $5;
        newVar->cols = $8;
        newVar->size = $5 * $8;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = $1;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        $$ = $1;
    }
    | ID '[' NUM ']' '[' NUM ']' { 
        VarList *newVar = calloc(1, sizeof(struct VarList));
        newVar->name = $1;
        newVar->rows = $3;
        newVar->cols = $6;
        newVar->size = $3 * $6;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        $$ = newVar;
    }
    | VarList ',' ID '[' NUM ']' { 
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = $3;
        newVar->size = $5; // array ayond size koduk
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = $1;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        $$ = $1;
    }
    | ID '[' NUM ']' {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = $1;
        newVar->size = $3;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        $$ = newVar;
    }
    | VarList ',' ID {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = $3;
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = $1;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newVar;
        $$ = $1;
    }
    | ID {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = $1;
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        $$ = newVar;
    } 
    | VarList ',' MUL ID { // adds a pointer variable to the declaration list
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = $4;
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        
        VarList *temp = $1;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        $$ = $1;
    } 
    | MUL ID {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = $2;
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        $$ = newVar;
    }
    |  VarList ',' ID'('ParamList')' {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = $3;
        newVar->size = 1;
        newVar->rows = 0;
        newVar->cols = 0;
        newVar->isPointer = 0;
        newVar->isFunction = 1;
        newVar->paramlist = $5;
        newVar->next = NULL;

        VarList *temp = $1;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newVar;
        $$ = $1;
    }
    | ID'('ParamList')' {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = $1;
        newVar->size = 1;
        newVar->rows = 0;
        newVar->cols = 0;
        newVar->isPointer = 0;
        newVar->isFunction = 1;
        newVar->paramlist = $3;
        newVar->next = NULL;

        $$ = newVar;
    };

// n â†’ makeIdNode("n")
// arr[i] â†’ makeArrayNode("arr", AST of i)
Variable : ID {
        $$ = makeIdNode($1);
    }
    | ID '[' E ']' { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        $$ = makeArrayNode($1, $3);
    }
    | ID '[' E ']' '[' E ']' {
        $$ = makeArray2DNode($1, $3, $6);
    }
    | MUL Variable { // allows a dereferenced pointer as an assignment target
        $$ = makeDereferenceNode($2);
    };

FDefBlock : FDefBlock FDef | FDef;

FDef : Type ID'('ParamList')' {
        CheckFunctionDefinition($2, $1, $4);
        BeginFunctionScope($4);
    } '{' LdeclBlock Body '}' {
        SaveFunctionAST($2, finalizeBodyNode($9, $1, $2), 0);
        PrintLocalSymbolTable($2);
        EndFunctionScope();
    };

ParamList : ParamList ',' Param {
        Paramstruct *temp = $1;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = $3;
        $$ = $1;
    }
    | Param {
        $$ = $1;
    }
    | { // param can be empty
        $$ = NULL;
    };

Param : Type ID {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = $2;
        p->type = $1;
        p->next = NULL;

        $$ = p;
    };

LdeclBlock : DECL LDecList ENDDECL | DECL ENDDECL;

LDecList : LDecList LDecl | LDecl;

LDecl : Type IdList SEMICOLON {
        InstallLocalVariables($2, $1);
    };

IdList : IdList ',' ID {
        VarList* newNode = calloc(1, sizeof(VarList));

        newNode->name = strdup($3);
        newNode->size = 1;
        newNode->rows = 0;
        newNode->cols = 0;
        newNode->isPointer = 0;
        newNode->next = NULL;

        VarList *temp = $1;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        $$ = $1;
    }
    | ID {
        VarList* newNode = calloc(1, sizeof(VarList));

        newNode->name = strdup($1);
        newNode->size = 1;
        newNode->rows = 0;
        newNode->cols = 0;
        newNode->isPointer = 0;
        newNode->next = NULL;

        $$ = newNode;
    };

// Each argument-list node holds one expression in left and the next argument in right.
ArgList : ArgList ',' E { $$ = appendArgNode($1, $3); }
        | E             { $$ = makeArgListNode($1); };

/* A function body must end with exactly one return statement. */
Body : T_BEGIN Slist ReturnStmt T_END { $$ = makeBodyNode($2, $3); }
     | T_BEGIN ReturnStmt T_END       { $$ = makeBodyNode(NULL, $2); };

ReturnStmt : RETURN E SEMICOLON { $$ = makeReturnNode($2); };

/* main is a function with no parameters and an int return type. */
MainBlock : INT MAIN '(' ')' '{' {
        BeginFunctionScope(NULL);
    } LdeclBlock Body '}' {
        root = finalizeBodyNode($8, TYPE_INT, "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        $$ = NULL;
    }
    /* Stage 4 form retained so existing non-function test programs still parse. */
    | T_BEGIN Slist T_END SEMICOLON {
        root = $2;
        $$ = $2;
    } 
    | T_BEGIN T_END SEMICOLON {
        root = NULL; // no syntax tree as T_BEGIN & T_END are non-terminals
        $$ = NULL;
    };

// so Slist is not storing the source text
// it just stores the pointer. the root = $2 (remember, %type <node> slist?)
// i.e Whenever I have an Slist, its semantic value is a tnode*

// we play pointer passing/propagation not pointer traversal
// pointer traversal happens when we walk the AST in codeGen()
// we pass the same pointer upward .. Slist : Slist Stmtile $$ would be $2 of Program : Tbegin Slist Tend

// matte missinte bottom up parser varacha manasilavum (stack, i/p, action)
// u will see stack being [begin, Slist, Stmt] after reducing second read to stmt
// so Slist Stmt, i.e stack top 2 elements have a reduction rule of Slist -> Slist Stmt
// so stack is [begin slist] again now
Slist : Slist Stmt {
        $$ = makeConnectorNode($1, $2);
    }
    | Stmt {
        $$ = $1;
    };

Stmt : InputStmt {
        $$ = $1;
    }
    | OutputStmt {
        $$ = $1;
    }
    | AsgStmt {
        $$ = $1;
    } 
    | IfStmt {
        $$ = $1;
    } 
    | WhileStmt {
        $$ = $1;
    } 
    | BreakStmt {
        $$ = $1;
    }
    | ContinueStmt {
        $$ = $1;
    }
    | RepeatStmt {
        $$ = $1;
    }
    | DoWhileStmt {
        $$ = $1;
    };

InputStmt : READ '(' Variable ')' SEMICOLON { // u read into a var, like read(b);
        $$ = makeReadNode($3);
    };

OutputStmt : WRITE '(' E ')' SEMICOLON { // u can write an expression like write(5+8);
        $$ = makeWriteNode($3);
    };

AsgStmt : Variable ASSIGN E SEMICOLON {
        $$ = makeAssignNode($1, $3);
    };

IfStmt : IF '(' E ')' THEN Slist ELSE Slist ENDIF SEMICOLON {
        $$ = makeIfNode($3, $6, $8);
    }
    | IF '(' E ')' THEN Slist ENDIF SEMICOLON {
        $$ = makeIfNode($3, $6, NULL);
    };

WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE SEMICOLON {
        $$ = makeWhileNode($3, $6);        
    };

BreakStmt : BREAK SEMICOLON {
        $$ = makeBreakNode();
    };

ContinueStmt : CONTINUE SEMICOLON {
        $$ = makeContinueNode();
    };

RepeatStmt : REPEAT Slist UNTIL '(' E ')' SEMICOLON {
        $$ = makeRepeatNode($2, $5);
    };

DoWhileStmt : DO Slist WHILE '(' E ')' SEMICOLON {
        $$ = makeDoWhileNode($2, $5);
    };
    
E : E PLUS E {
        $$ = makeOperatorNode("+", $1, $3);
    }
    | E MINUS E {
        $$ = makeOperatorNode("-", $1, $3);
    }
    | E MUL E {
        $$ = makeOperatorNode("*", $1, $3);
    }
    | E DIV E {
        $$ = makeOperatorNode("/", $1, $3);
    }
    | E MOD E {
        $$ = makeOperatorNode("%", $1, $3);
    }
    | '(' E ')' {
        $$ = $2;
    }
    | E LT E {
        $$ = makeOperatorNode("<", $1, $3);
    }
    | E GT E {
        $$ = makeOperatorNode(">", $1, $3);
    }
    | E LE E {
        $$ = makeOperatorNode("<=", $1, $3);
    }
    | E GE E {
        $$ = makeOperatorNode(">=", $1, $3);
    }
    | E EQ E {
        $$ = makeOperatorNode("==", $1, $3);
    }
    | E NE E {
        $$ = makeOperatorNode("!=", $1, $3);
    }
    | E OR E {
        $$ = makeOperatorNode("||", $1, $3);
    }
    | E AND E {
        $$ = makeOperatorNode("&&", $1, $3);
    }
    | NUM {
        $$ = makeNumNode($1);
    }
    | STRING {
        $$ = makeStrNode($1);
    }
    | ADDRESS Variable { // address-of operator returns the address of a variable
        $$ = makeAddressNode($2);
    }
    | Variable {
        $$ = $1;
    }
    | ID'('')' {
        $$ = makeFunctionCallNode($1, NULL);
    }
    | ID'('ArgList')' {
        $$ = makeFunctionCallNode($1, $3);
    };

%%

extern FILE* yyin; // it is file pointer of lexer. defaulted to "stdin"
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open input file\n");
        return 1;
    }

    if (yyparse() != 0) {
        fclose(yyin);
        return 1;
    }

    PrintSymbolTable();
    targetFile = fopen("target.xsm", "w");
    if (targetFile == NULL) {
        fprintf(stderr, "Could not open target.xsm for writing\n");
        fclose(yyin);
        return 1;
    }
    generateProgram(FunctionASTHead);
    fclose(targetFile);
    fclose(yyin);
    return 0;
}

void yyerror(const char* s) {
    printf("%s\n", s);
}
