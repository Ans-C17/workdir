%{
/* Flex converts source characters into the tokens consumed by exprtree.y. */
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "exprtree.tab.h"

void yyerror(const char* s);
%}

%%

/* Numeric literals carry their integer value to the parser. */
[0-9]+ {    
    yylval.num = atoi(yytext);
    return NUM;
}

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"%" {return MOD; }

"&" { return ADDRESS; }

"[" { return '['; }
"]" { return ']'; }

"{" { return '{'; }
"}" { return '}'; }

"(" { return '('; }
")" { return ')'; }
"," { return ','; }
"." { return '.'; }
 
/* Multi-character operators are matched as complete tokens before single ones. */
"<=" { return LE; } // Flex selects the longest matching token.
"<" { return LT; } // if length same only it checks for order and returns whatever matched before
">=" { return GE; }
">" { return GT; }
"==" { return EQ; }
"!=" { return NE; }
"||" { return OR; }
"&&" { return AND; }

/* Whitespace separates tokens but has no meaning to the grammar. */
[ \t\r\n] { }

/* Reserved words must appear before the identifier rule so they get keyword tokens. */
"begin" { return T_BEGIN; }
"end" { return T_END; }
"main" { return MAIN; }
"return" { return RETURN; }

"decl" { return DECL; }
"enddecl" { return ENDDECL; }
"int" { return INT; }
"str" { return STR; }
"type" { return TYPE; }
"endtype" { return ENDTYPE; }
"class" { return CLASS; }
"endclass" { return ENDCLASS; }
"extends" { return EXTENDS; }
"self" { return SELF; }
"NULL" { return T_NULL; }

"read" { return READ; }
"write" { return WRITE; }
"alloc" { return ALLOC; }
"free" { return FREE; }
"new" { return NEW; }
"delete" { return DELETE; }

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

/* Remove the surrounding quotes and pass an owned copy of the string to Bison. */
\"[^\"]*\" {
    yytext[yyleng - 1] = '\0';
    yylval.str = strdup(yytext + 1);
    return STRING;
}

[a-zA-Z][a-zA-Z0-9]* {
    /* Keep an owned copy because Flex reuses its yytext buffer for later tokens. */
    yylval.str = strdup(yytext);
    return ID;
}

/* Anything not matched above is a source error; report it instead of ignoring it. */
. {
    printf("Unknown character: '%c' (ASCII %d)\n", yytext[0], yytext[0]);
    yyerror("Unknown character");
    exit(1);
}

%%

/* Tell Flex that this compiler reads one input stream only. */
int yywrap() {
    return 1;
}
