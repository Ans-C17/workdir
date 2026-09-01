%{
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "exprtree.tab.h"

void yyerror(const char* s);
%}

%%

-?[0-9]+ {    
    yylval.num = atoi(yytext);
    return NUM;
}

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"%" {return MOD; }

"[" { return '['; }
"]" { return ']'; }

"(" { return '('; }
")" { return ')'; }
"," { return ','; }
 
"<=" { return LE; } // flex dont rly care about ordering, it checks for longest match first
"<" { return LT; } // if length same only it checks for order and returns whatever matched before
">=" { return GE; }
">" { return GT; }
"==" { return EQ; }
"!=" { return NE; }

[ \t\r\n] { } // a space before them to say space is also ignored

"begin" { return T_BEGIN; }
"end" { return T_END; }

"decl" { return DECL; }
"enddecl" { return ENDDECL; }
"int" { return INT; }
"str" { return STR; }

"read" { return READ; }
"write" { return WRITE; }

"if" { return IF; }
"then" { return THEN; }
"else" { return ELSE; }
"endif" { return ENDIF; }

"while" { return WHILE; }
"do" { return DO; }
"endwhile" { return ENDWHILE; }

"break" { return BREAK; }
"continue" { return CONTINUE; }

"repeat"    { return REPEAT; }
"until"     { return UNTIL; }

"=" { return ASSIGN; }
";" { return SEMICOLON; }

\"[^\"]*\" {
    yytext[yyleng - 1] = '\0';
    yylval.str = strdup(yytext + 1);
    return STRING;
}

[a-zA-Z][a-zA-Z0-9]* { // * => 0 or more; + => 1 or more
    yylval.str = strdup(yytext); // makes a copy of any string. (in the heap;)
    // strdup only allocs as much memory u need, wont reserve kore bytes that go to waste
    // ethra bytes aano size, athrakke allocate cheyyu [malloc(sizeof(string))]
    return ID;
}

. {
    printf("Unknown character: '%c' (ASCII %d)\n", yytext[0], yytext[0]);
    yyerror("Unknown character");
    exit(1);
}

%%

int yywrap() {
    return 1;
}