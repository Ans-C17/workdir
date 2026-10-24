/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_EXPRTREE_TAB_H_INCLUDED
# define YY_YY_EXPRTREE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    MOD = 264,
    LT = 265,
    GT = 266,
    LE = 267,
    GE = 268,
    EQ = 269,
    NE = 270,
    OR = 271,
    AND = 272,
    ADDRESS = 273,
    TYPE = 274,
    ENDTYPE = 275,
    ALLOC = 276,
    FREE = 277,
    CLASS = 278,
    ENDCLASS = 279,
    SELF = 280,
    NEW = 281,
    DELETE = 282,
    T_NULL = 283,
    T_BEGIN = 284,
    T_END = 285,
    DECL = 286,
    ENDDECL = 287,
    INT = 288,
    STR = 289,
    ASSIGN = 290,
    SEMICOLON = 291,
    MAIN = 292,
    RETURN = 293,
    READ = 294,
    WRITE = 295,
    IF = 296,
    THEN = 297,
    ELSE = 298,
    ENDIF = 299,
    WHILE = 300,
    DO = 301,
    ENDWHILE = 302,
    REPEAT = 303,
    UNTIL = 304,
    BREAK = 305,
    CONTINUE = 306,
    STRING = 307,
    UMINUS = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "exprtree.y"

    tnode* node;
    char* str;
    int num;
    VarList* varlist;
    Paramstruct* paramlist;
    Typetable* type;
    ParamTypeInfo paramtype;

#line 121 "exprtree.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRTREE_TAB_H_INCLUDED  */
