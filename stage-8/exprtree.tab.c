/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exprtree.y"

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
Classtable *currentClass = NULL;
Memberfunclist *currentMethod = NULL;

static void InstallGlobalVarList(VarList *variables, Typetable *type,
                                 Classtable *classType) {
    VarList *variable;

    if (classType != NULL) {
        for (variable = variables; variable != NULL; variable = variable->next) {
            if (variable->isArray || variable->isPointer || variable->isFunction) {
                fprintf(stderr, "Error: class variables must be scalar global variables\n");
                exit(1);
            }
        }
    }

    for (variable = variables; variable != NULL; variable = variable->next) {
        if (classType != NULL) {
            InstallClassVariable(variable->name, classType);
        } else {
            Typetable *variableType = type;
            if (variable->isPointer) {
                variableType = PointerType(type);
                if (variableType == NULL) {
                    fprintf(stderr, "Error: pointer declarations are supported only for int and str\n");
                    exit(1);
                }
            }

            if (variable->isFunction) {
                Install(variable->name, variableType, 0, 0, 0, 0,
                        variable->paramlist, nextFunctionLabel++);
            } else {
                Install(variable->name, variableType, variable->size,
                        variable->rows, variable->cols, variable->isArray,
                        NULL, -1);
            }
        }
    }
}

static void CheckClassFieldOrder(void) {
    if (currentClass != NULL && currentClass->methodCount != 0) {
        fprintf(stderr, "Error: class fields must be declared before methods in class '%s'\n",
                currentClass->name);
        exit(1);
    }
}

#line 134 "exprtree.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    EXTENDS = 280,
    SELF = 281,
    NEW = 282,
    DELETE = 283,
    T_NULL = 284,
    T_BEGIN = 285,
    T_END = 286,
    DECL = 287,
    ENDDECL = 288,
    INT = 289,
    STR = 290,
    ASSIGN = 291,
    SEMICOLON = 292,
    MAIN = 293,
    RETURN = 294,
    READ = 295,
    WRITE = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    ENDIF = 300,
    WHILE = 301,
    DO = 302,
    ENDWHILE = 303,
    REPEAT = 304,
    UNTIL = 305,
    BREAK = 306,
    CONTINUE = 307,
    STRING = 308,
    UMINUS = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 65 "exprtree.y"

    tnode* node;
    char* str;
    int num;
    VarList* varlist;
    Paramstruct* paramlist;
    Typetable* type;
    ParamTypeInfo paramtype;

#line 251 "exprtree.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRTREE_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   750

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,    58,     2,     2,    59,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   144,   144,   145,   146,   149,   150,   154,   155,   158,
     159,   162,   162,   179,   180,   181,   184,   192,   200,   218,
     225,   232,   240,   247,   254,   265,   266,   269,   269,   284,
     285,   288,   288,   298,   299,   302,   313,   314,   315,   324,
     324,   326,   326,   328,   331,   334,   349,   350,   351,   361,
     362,   365,   366,   382,   398,   410,   425,   436,   452,   462,
     475,   484,   503,   517,   530,   542,   545,   549,   552,   557,
     559,   562,   565,   570,   570,   572,   572,   581,   591,   594,
     598,   613,   626,   630,   634,   648,   648,   650,   650,   652,
     663,   665,   684,   695,   707,   715,   724,   738,   739,   742,
     743,   745,   748,   748,   770,   773,   777,   780,   783,   786,
     789,   792,   795,   798,   801,   804,   807,   810,   813,   816,
     819,   822,   825,   829,   832,   837,   841,   844,   849,   852,
     856,   860,   864,   868,   872,   876,   879,   882,   885,   888,
     891,   894,   897,   900,   903,   906,   909,   912,   915,   918,
     921,   924,   927,   930,   933,   936,   939,   942,   945,   949,
     952
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "OR", "AND", "ADDRESS",
  "TYPE", "ENDTYPE", "ALLOC", "FREE", "CLASS", "ENDCLASS", "EXTENDS",
  "SELF", "NEW", "DELETE", "T_NULL", "T_BEGIN", "T_END", "DECL", "ENDDECL",
  "INT", "STR", "ASSIGN", "SEMICOLON", "MAIN", "RETURN", "READ", "WRITE",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT",
  "UNTIL", "BREAK", "CONTINUE", "STRING", "UMINUS", "'{'", "'}'", "'('",
  "')'", "','", "'['", "']'", "'.'", "$accept", "Program", "TypeDefBlock",
  "ClassDefBlock", "ClassDefList", "ClassDef", "$@1", "ClassMemberDecls",
  "ClassField", "ClassMethodDecl", "ClassMethodDefList", "ClassMethodDef",
  "$@2", "TypeDefList", "TypeDef", "$@3", "FieldDeclList", "FieldDecl",
  "FieldType", "GDeclBlock", "GDeclList", "GDecl", "TypeName",
  "ClassParentOpt", "FType", "VarList", "Variable", "Field",
  "MemberAccess", "FDefBlock", "FDef", "$@4", "ParamList", "Param",
  "ParamType", "LdeclBlock", "LDecList", "LDecl", "LocalType", "IdList",
  "ArgList", "Body", "ReturnStmt", "MainBlock", "$@5", "Slist", "Stmt",
  "InputStmt", "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt",
  "ContinueStmt", "RepeatStmt", "DoWhileStmt", "E", "FieldFunction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   123,   125,    40,    41,    44,
      91,    93,    46
};
# endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    35,    51,   116,    49,   180,  -179,  -179,    95,   114,
    -179,  -179,  -179,   138,     2,  -179,    21,   154,    78,  -179,
      89,   199,  -179,  -179,  -179,   198,  -179,   198,   198,    25,
    -179,   151,  -179,   154,  -179,   224,   270,    78,  -179,  -179,
    -179,  -179,  -179,    18,  -179,   271,  -179,   226,   155,   281,
      60,    77,    81,  -179,  -179,   195,  -179,   239,  -179,  -179,
    -179,  -179,   234,   268,    91,   298,   247,  -179,   214,  -179,
    -179,   251,    91,  -179,  -179,  -179,  -179,  -179,   230,  -179,
     215,   250,    91,   185,   310,  -179,   240,    42,  -179,    91,
    -179,   318,   274,   249,    91,   355,   305,   356,  -179,   242,
      97,   248,   254,  -179,  -179,  -179,  -179,   428,  -179,   257,
     390,    91,    45,   386,   417,   -30,   469,  -179,   419,    97,
     473,   -13,   474,    50,   475,   420,  -179,   422,   259,  -179,
    -179,    57,  -179,   480,   476,   429,   356,  -179,    91,   430,
    -179,  -179,   434,  -179,    91,   439,  -179,    91,   444,  -179,
     483,  -179,  -179,  -179,   443,    83,   445,   256,   449,   447,
     450,   306,   455,   456,   457,   462,   591,   591,   484,   487,
      -5,    47,  -179,   489,   476,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,   386,   262,    91,    91,
     267,    91,   269,    91,   468,   528,  -179,   529,   306,  -179,
      38,   530,   101,  -179,   207,   306,   256,  -179,  -179,   306,
     478,   479,   481,   667,  -179,   101,   306,   306,   306,   619,
     504,  -179,  -179,   266,   531,   276,   532,  -179,   506,  -179,
     491,   511,   272,   302,   512,   387,   515,   389,  -179,   482,
     498,     4,   218,   478,   -21,  -179,    44,    76,   175,  -179,
    -179,   331,   233,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,  -179,   129,   149,   359,
     385,   398,   502,   503,   505,   507,   680,  -179,   508,   509,
     713,  -179,  -179,  -179,  -179,   534,  -179,  -179,   536,  -179,
     537,   518,   565,   519,   543,   551,   553,   555,  -179,   391,
     726,  -179,  -179,   395,   216,   216,  -179,  -179,  -179,   189,
     189,   189,   189,   344,   344,   427,   372,   556,   557,   559,
     526,   525,   306,   306,   539,   595,  -179,   542,   597,  -179,
    -179,   547,  -179,  -179,   603,   546,   306,  -179,  -179,  -179,
    -179,  -179,   306,  -179,  -179,  -179,  -179,   591,   591,   413,
     452,   574,   558,   581,   562,   356,   560,   564,   145,   726,
     448,   535,    96,   585,  -179,   588,  -179,   590,   386,  -179,
     625,  -179,   591,   592,   593,  -179,  -179,  -179,  -179,   578,
     575,   563,  -179,  -179,  -179,  -179,   598,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     8,     0,     0,    30,     1,     0,     0,
      31,     5,    29,    50,     0,    10,     0,     0,     0,     4,
       0,     0,    11,     7,     9,     0,    40,     0,     0,     0,
      42,     0,    48,    46,    47,    51,     0,     0,    74,     3,
      38,    36,    37,     0,    34,     0,    49,     0,    58,     0,
       0,     0,     0,    39,    41,     0,    52,     0,    73,     2,
      32,    33,     0,     0,    79,     0,    60,    45,     0,    43,
      44,     0,    79,    35,    15,    84,    82,    83,     0,    78,
       0,     0,    79,    57,     0,   102,     0,     0,    62,     0,
      80,     0,    56,     0,    79,     0,    59,     0,    75,     0,
      26,     0,     0,    13,    14,    77,    81,     0,    64,     0,
       0,    79,     0,     0,     0,     0,     0,    46,     0,    26,
       0,     0,     0,     0,     0,     0,    61,    55,     0,    86,
      90,     0,    88,     0,     0,     0,     0,    18,    79,     0,
      12,    25,     0,    16,    79,     0,    17,    79,     0,    54,
       0,    63,    85,    87,    96,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   103,     0,     0,    79,    79,
       0,    79,     0,    79,     0,     0,    89,     0,     0,    68,
       0,     0,     0,   150,    65,     0,     0,   152,   151,     0,
     154,   155,    69,     0,   156,     0,     0,     0,     0,     0,
       0,   131,   132,     0,     0,     0,     0,   100,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
      91,     0,    65,     0,     0,    70,     0,     0,     0,   140,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,    72,    99,    76,    21,     0,    27,    19,     0,    20,
       0,    94,     0,    66,     0,     0,     0,     0,   157,     0,
      98,   141,   160,     0,   135,   136,   137,   138,   139,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,   127,
      24,     0,    22,    23,     0,     0,     0,   119,   120,   121,
     122,   158,     0,   159,   123,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,    97,
       0,     0,     0,     0,   115,     0,   116,     0,     0,    95,
       0,    67,     0,     0,     0,   134,   133,   117,   118,     0,
       0,     0,   129,   130,    28,    93,     0,   128
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -179,  -179,   630,  -179,  -179,  -179,  -179,
     520,  -179,  -179,  -179,   641,  -179,  -179,   605,  -179,  -179,
    -179,   620,  -179,  -179,    22,   238,  -134,  -131,  -104,  -179,
     613,  -179,   -44,   566,    52,  -135,  -179,   521,  -179,  -179,
     399,  -178,   488,   162,  -179,  -162,  -172,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,   -88,  -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    14,    15,    47,    87,   103,   104,
     118,   119,   331,     5,     6,    20,    43,    44,    45,    18,
      29,    30,    35,    22,    36,    50,   210,   211,   212,    37,
      38,   114,    78,    79,    80,   113,   131,   132,   133,   155,
     299,   135,   173,    19,    97,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   300,   214
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     170,   186,   229,   171,   219,   220,    13,   137,   230,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    40,   199,   143,    25,    23,   138,    86,    25,
     172,   223,   170,   170,     1,   171,   171,   295,    93,     4,
     170,   226,   242,   171,   144,   157,    99,   229,   229,    75,
     109,     7,    41,    42,    26,    27,    28,   224,    53,    27,
      28,    75,   172,   172,   159,   293,   243,   128,   246,   244,
     172,   247,   250,   213,    60,   100,   101,   102,   129,    76,
      77,   267,    32,   225,   268,   170,   170,   146,   171,   171,
     152,    76,    77,    40,   187,    75,   172,    67,   172,    13,
     190,    32,   296,   192,    10,   156,   224,   147,   157,   226,
     241,   172,    33,    34,    69,   172,   172,   249,    70,    68,
     196,   251,   120,    41,    42,    76,    77,   159,   269,   270,
     271,   117,    34,   375,   297,   276,    68,   280,   226,     8,
      68,   120,   197,   348,   232,   233,    16,   235,    17,   237,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    21,   130,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   203,   204,
      39,   205,   157,   130,     4,   360,   361,   317,   229,   229,
     379,   224,    31,   206,   253,   254,   255,   256,   257,    59,
      11,   159,    48,    46,   207,    49,   371,   318,    55,   229,
     381,   226,    64,   170,   170,    65,   171,   171,    83,    90,
     368,    84,    91,   255,   256,   257,   170,   170,   208,   171,
     171,    56,   209,   298,   349,   350,   203,   204,   170,   205,
     157,   171,    94,   172,   172,    95,   115,   170,   358,   116,
     171,   206,   121,    71,   359,   122,   172,   172,   123,   159,
     156,   124,   207,   157,   248,    51,    52,   198,   172,   203,
     204,    73,   205,   157,    57,    62,   294,   172,   198,   203,
     204,    63,   205,   157,   206,    66,   208,   274,    88,    89,
     209,   302,   159,   275,   206,   207,    72,   278,    98,    89,
      74,    81,   159,   279,    82,   207,    85,   108,    89,   203,
     204,    92,   205,   157,    96,   126,    89,   151,    89,   208,
     231,    89,   106,   209,   206,   234,    89,   236,    89,   208,
     285,    89,   159,   209,   107,   207,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   110,   208,
     286,    89,   111,   209,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   112,   301,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   134,   319,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   125,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   320,   265,   288,    89,   290,    89,   341,
     342,   127,   156,   343,   342,   157,   321,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     158,   362,   136,   139,   159,   140,   160,   142,   145,   148,
     156,   149,   150,   157,   154,   185,   194,   188,   162,   163,
     164,   189,   372,   373,   165,   166,   191,   167,   158,   168,
     169,   193,   159,   195,   160,   198,   200,   202,   156,   201,
     363,   157,   215,   216,   217,   161,   162,   163,   164,   218,
     227,   221,   165,   166,   222,   167,   158,   168,   169,   238,
     159,   239,   160,   240,   245,   277,   281,   282,   252,   156,
     224,   226,   157,   291,   162,   163,   164,   283,   284,   287,
     165,   166,   289,   167,   273,   168,   169,   158,   292,   322,
     323,   159,   324,   160,   325,   327,   328,   156,   335,   347,
     157,   330,   348,   332,   333,   162,   163,   164,   334,   336,
     337,   165,   166,   374,   167,   158,   168,   169,   338,   159,
     339,   160,   340,   344,   345,   156,   346,   351,   157,   352,
     353,   354,   355,   162,   163,   164,   356,   357,   386,   165,
     166,   364,   167,   158,   168,   169,   365,   159,   366,   160,
     367,   369,   376,   156,   370,   377,   157,   378,   380,   382,
     383,   162,   163,   164,   384,   387,   385,   165,   166,   141,
     167,   158,   168,   169,    24,   159,    12,   160,    61,    54,
      58,   303,   153,     0,     0,   105,     0,     0,     0,   162,
     163,   164,   228,     0,     0,   272,   166,     0,   167,     0,
     168,   169,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,     0,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   326,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,     0,     0,     0,     0,     0,
     329
};

static const yytype_int16 yycheck[] =
{
     134,   136,   174,   134,   166,   167,     4,    37,   186,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     4,   157,    37,     4,    24,    57,    72,     4,
     134,    36,   166,   167,    19,   166,   167,    58,    82,     4,
     174,    62,     4,   174,    57,     7,     4,   219,   220,     4,
      94,     0,    34,    35,    33,    34,    35,    62,    33,    34,
      35,     4,   166,   167,    26,    61,   200,   111,   202,   200,
     174,   202,   206,   161,    56,    33,    34,    35,    33,    34,
      35,   215,     4,    36,   215,   219,   220,    37,   219,   220,
      33,    34,    35,     4,   138,     4,   200,    37,   202,     4,
     144,     4,    58,   147,    55,     4,    62,    57,     7,    62,
     198,   215,    34,    35,    37,   219,   220,   205,    37,    59,
      37,   209,   100,    34,    35,    34,    35,    26,   216,   217,
     218,    34,    35,    37,    58,   223,    59,   225,    62,    23,
      59,   119,    59,    47,   188,   189,    32,   191,    34,   193,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    25,   112,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,     3,     4,
      18,     6,     7,   131,     4,   347,   348,    58,   360,   361,
     368,    62,    38,    18,     5,     6,     7,     8,     9,    37,
      20,    26,     4,     4,    29,     7,    61,    58,    57,   381,
     372,    62,    57,   347,   348,    60,   347,   348,     4,     4,
     355,     7,     7,     7,     8,     9,   360,   361,    53,   360,
     361,     7,    57,    58,   322,   323,     3,     4,   372,     6,
       7,   372,    57,   347,   348,    60,     4,   381,   336,     7,
     381,    18,     4,    58,   342,     7,   360,   361,     4,    26,
       4,     7,    29,     7,    57,    27,    28,    60,   372,     3,
       4,    37,     6,     7,     4,     4,    58,   381,    60,     3,
       4,    55,     6,     7,    18,     4,    53,    21,    58,    59,
      57,    58,    26,    27,    18,    29,    57,    21,    58,    59,
      32,     3,    26,    27,    57,    29,    55,    58,    59,     3,
       4,    61,     6,     7,     4,    58,    59,    58,    59,    53,
      58,    59,     4,    57,    18,    58,    59,    58,    59,    53,
      58,    59,    26,    57,    60,    29,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,    53,
      58,    59,    57,    57,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    32,    58,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    30,    58,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    58,    17,    58,    59,    58,    59,    58,
      59,    61,     4,    58,    59,     7,    58,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      22,    58,    55,     4,    26,    56,    28,     4,     4,     4,
       4,    61,    60,     7,     4,    56,     3,    57,    40,    41,
      42,    57,    44,    45,    46,    47,    57,    49,    22,    51,
      52,    57,    26,    60,    28,    60,    57,    57,     4,    62,
      58,     7,    57,    57,    57,    39,    40,    41,    42,    57,
      31,    37,    46,    47,    37,    49,    22,    51,    52,    61,
      26,     3,    28,     4,     4,     4,     4,    31,    57,     4,
      62,    62,     7,    61,    40,    41,    42,    56,    37,    37,
      46,    47,    37,    49,    50,    51,    52,    22,    60,    57,
      57,    26,    57,    28,    57,    57,    57,     4,     3,    43,
       7,    37,    47,    37,    37,    40,    41,    42,    60,    60,
      37,    46,    47,    48,    49,    22,    51,    52,    37,    26,
      37,    28,    37,    37,    37,     4,    37,    58,     7,     4,
      58,     4,    55,    40,    41,    42,     3,    61,    45,    46,
      47,    37,    49,    22,    51,    52,    58,    26,    37,    28,
      58,    61,    37,     4,    60,    37,     7,    37,     3,    37,
      37,    40,    41,    42,    56,    37,    61,    46,    47,   119,
      49,    22,    51,    52,    14,    26,     5,    28,    43,    29,
      37,   252,   131,    -1,    -1,    89,    -1,    -1,    -1,    40,
      41,    42,   174,    -1,    -1,    46,    47,    -1,    49,    -1,
      51,    52,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    64,    65,     4,    76,    77,     0,    23,    66,
      55,    20,    77,     4,    67,    68,    32,    34,    82,   106,
      78,    25,    86,    24,    68,     4,    33,    34,    35,    83,
      84,    38,     4,    34,    35,    85,    87,    92,    93,   106,
       4,    34,    35,    79,    80,    81,     4,    69,     4,     7,
      88,    88,    88,    33,    84,    57,     7,     4,    93,   106,
      56,    80,     4,    55,    57,    60,     4,    37,    59,    37,
      37,    58,    57,    37,    32,     4,    34,    35,    95,    96,
      97,     3,    57,     4,     7,    55,    95,    70,    58,    59,
       4,     7,    61,    95,    57,    60,     4,   107,    58,     4,
      33,    34,    35,    71,    72,    96,     4,    60,    58,    95,
       3,    57,    32,    98,    94,     4,     7,    34,    73,    74,
      87,     4,     7,     4,     7,     3,    58,    61,    95,    33,
      97,    99,   100,   101,    30,   104,    55,    37,    57,     4,
      56,    73,     4,    37,    57,     4,    37,    57,     4,    61,
      60,    58,    33,   100,     4,   102,     4,     7,    22,    26,
      28,    39,    40,    41,    42,    46,    47,    49,    51,    52,
      89,    90,    91,   105,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    56,    98,    95,    57,    57,
      95,    57,    95,    57,     3,    60,    37,    59,    60,    89,
      57,    62,    57,     3,     4,     6,    18,    29,    53,    57,
      89,    90,    91,   119,   120,    57,    57,    57,    57,   108,
     108,    37,    37,    36,    62,    36,    62,    31,   105,   109,
     104,    58,    95,    95,    58,    95,    58,    95,    61,     3,
       4,   119,     4,    89,    90,     4,    89,    90,    57,   119,
      89,   119,    57,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    37,    89,    90,   119,
     119,   119,    46,    50,    21,    27,   119,     4,    21,    27,
     119,     4,    31,    56,    37,    58,    58,    37,    58,    37,
      58,    61,    60,    61,    58,    58,    58,    58,    58,   103,
     119,    58,    58,   103,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,    58,    58,    58,
      58,    58,    57,    57,    57,    57,    37,    57,    57,    37,
      37,    75,    37,    37,    60,     3,    60,    37,    37,    37,
      37,    58,    59,    58,    37,    37,    37,    43,    47,   119,
     119,    58,     4,    58,     4,    55,     3,    61,   119,   119,
     108,   108,    58,    58,    37,    58,    37,    58,    98,    61,
      60,    61,    44,    45,    48,    37,    37,    37,    37,   104,
       3,   108,    37,    37,    56,    61,    45,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    69,    68,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    75,    74,    76,
      76,    78,    77,    79,    79,    80,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    90,
      91,    91,    91,    92,    92,    94,    93,    95,    95,    95,
      96,    96,    97,    97,    97,    98,    98,    99,    99,   100,
     101,   102,   102,   102,   102,   102,   102,   103,   103,   104,
     104,   105,   107,   106,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   112,   112,   113,   113,
     114,   115,   116,   117,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     3,     0,     2,
       1,     0,     9,     2,     2,     0,     3,     3,     3,     6,
       6,     6,     7,     7,     7,     2,     0,     0,    10,     2,
       1,     0,     5,     2,     1,     3,     1,     1,     1,     3,
       2,     2,     1,     3,     3,     3,     1,     1,     1,     2,
       0,     1,     2,     9,     7,     6,     4,     3,     1,     4,
       2,     6,     4,     7,     5,     1,     4,     7,     2,     1,
       3,     3,     3,     2,     1,     0,    10,     3,     1,     0,
       2,     3,     1,     1,     1,     3,     2,     2,     1,     3,
       1,     3,     6,     9,     4,     7,     1,     3,     1,     4,
       3,     3,     0,     9,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     6,     7,     7,     5,
       5,     5,     5,     5,     5,     5,     4,     4,    10,     8,
       8,     2,     2,     7,     7,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     4,     4,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 144 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1762 "exprtree.tab.c"
    break;

  case 3:
#line 145 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1768 "exprtree.tab.c"
    break;

  case 4:
#line 146 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1774 "exprtree.tab.c"
    break;

  case 7:
#line 154 "exprtree.y"
                                            { PrintClassTable(); }
#line 1780 "exprtree.tab.c"
    break;

  case 11:
#line 162 "exprtree.y"
                             {
              currentClass = CInstall((yyvsp[-1].str), (yyvsp[0].str));
              if (currentClass == NULL) {
                  fprintf(stderr, "Error: class '%s' is already defined, has an invalid parent, or cannot be installed\n", (yyvsp[-1].str));
                  exit(1);
              }
          }
#line 1792 "exprtree.tab.c"
    break;

  case 12:
#line 168 "exprtree.y"
                                                                     {
              if (!Class_CheckMethodDefinitions(currentClass)) {
                  exit(1);
              }
              currentClass = NULL;
              currentMethod = NULL;
          }
#line 1804 "exprtree.tab.c"
    break;

  case 16:
#line 184 "exprtree.y"
                              {
               CheckClassFieldOrder();
               if (Class_Finstall(currentClass, "int", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "int", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1817 "exprtree.tab.c"
    break;

  case 17:
#line 192 "exprtree.y"
                              {
               CheckClassFieldOrder();
               if (Class_Finstall(currentClass, "str", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "str", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1830 "exprtree.tab.c"
    break;

  case 18:
#line 200 "exprtree.y"
                             {
               CheckClassFieldOrder();
               if (TLookup((yyvsp[-2].str)) == NULL && CLookup((yyvsp[-2].str)) == NULL) {
                   fprintf(stderr, "Error: field type '%s' is not defined before this class\n", (yyvsp[-2].str));
                   exit(1);
               }
               if (currentClass != NULL && CLookup((yyvsp[-2].str)) == currentClass) {
                   fprintf(stderr, "Error: class fields may use only previously defined classes\n");
                   exit(1);
               }
               if (Class_Finstall(currentClass, (yyvsp[-2].str), (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           (yyvsp[-2].str), (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1851 "exprtree.tab.c"
    break;

  case 19:
#line 218 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("int"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1863 "exprtree.tab.c"
    break;

  case 20:
#line 225 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("str"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1875 "exprtree.tab.c"
    break;

  case 21:
#line 232 "exprtree.y"
                                                    {
                    Typetable *returnType = TLookup((yyvsp[-5].str));
                    if (returnType == NULL || Class_Minstall(currentClass, (yyvsp[-4].str), returnType, (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1888 "exprtree.tab.c"
    break;

  case 22:
#line 240 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("int")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1900 "exprtree.tab.c"
    break;

  case 23:
#line 247 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("str")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1912 "exprtree.tab.c"
    break;

  case 24:
#line 254 "exprtree.y"
                                                        {
                    Typetable *returnType = TLookup((yyvsp[-6].str));
                    if (returnType == NULL || !IsUserDefinedType(returnType) ||
                        Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(returnType), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid pointer return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1926 "exprtree.tab.c"
    break;

  case 27:
#line 269 "exprtree.y"
                                            {
                    currentMethod = Class_MatchMethodDefinition(currentClass, (yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
                    if (currentMethod == NULL) exit(1);
                    BeginMethodScope((yyvsp[-1].paramlist), currentClass);
                }
#line 1936 "exprtree.tab.c"
    break;

  case 28:
#line 273 "exprtree.y"
                                          {
                    char qualifiedName[256];
                    snprintf(qualifiedName, sizeof(qualifiedName), "%s.%s",
                             currentClass->name, (yyvsp[-8].str));
                    SaveMethodAST(currentClass, currentMethod,
                                  finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), qualifiedName));
                    PrintLocalSymbolTable(qualifiedName);
                    EndFunctionScope();
                    currentMethod = NULL;
                }
#line 1951 "exprtree.tab.c"
    break;

  case 31:
#line 288 "exprtree.y"
                 {
            if (TBeginDefinition((yyvsp[-1].str)) == NULL) {
                fprintf(stderr, "Error: type '%s' is already defined or cannot be started\n", (yyvsp[-1].str));
                exit(1);
            }
        }
#line 1962 "exprtree.tab.c"
    break;

  case 32:
#line 293 "exprtree.y"
                            {
            TFinishDefinition(TCurrentDefinition());
        }
#line 1970 "exprtree.tab.c"
    break;

  case 35:
#line 302 "exprtree.y"
                                   {
              Typetable *owner = TCurrentDefinition();
              if (owner == NULL ||
                  FInstall(owner, (yyvsp[-1].str), (yyvsp[-2].type), owner->size) == NULL) {
                  fprintf(stderr, "Error: duplicate field '%s' or invalid field declaration\n", (yyvsp[-1].str));
                  exit(1);
              }
              owner->size++;
          }
#line 1984 "exprtree.tab.c"
    break;

  case 36:
#line 313 "exprtree.y"
                { (yyval.type) = TLookup("int"); }
#line 1990 "exprtree.tab.c"
    break;

  case 37:
#line 314 "exprtree.y"
                { (yyval.type) = TLookup("str"); }
#line 1996 "exprtree.tab.c"
    break;

  case 38:
#line 315 "exprtree.y"
               {
              (yyval.type) = TLookup((yyvsp[0].str));
              if ((yyval.type) == NULL || !IsUserDefinedType((yyval.type))) {
                  fprintf(stderr, "Error: field type '%s' is undefined or not declarable here\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 2008 "exprtree.tab.c"
    break;

  case 43:
#line 328 "exprtree.y"
                              {
           InstallGlobalVarList((yyvsp[-1].varlist), TLookup("int"), NULL);
       }
#line 2016 "exprtree.tab.c"
    break;

  case 44:
#line 331 "exprtree.y"
                             {
           InstallGlobalVarList((yyvsp[-1].varlist), TLookup("str"), NULL);
       }
#line 2024 "exprtree.tab.c"
    break;

  case 45:
#line 334 "exprtree.y"
                            {
           Typetable *type = TLookup((yyvsp[-2].str));
           Classtable *classType = CLookup((yyvsp[-2].str));

           if (type != NULL && IsUserDefinedType(type)) {
               InstallGlobalVarList((yyvsp[-1].varlist), type, NULL);
           } else if (classType != NULL) {
               InstallGlobalVarList((yyvsp[-1].varlist), NULL, classType);
           } else {
               fprintf(stderr, "Error: type or class '%s' is not defined\n", (yyvsp[-2].str));
               exit(1);
           }
       }
#line 2042 "exprtree.tab.c"
    break;

  case 46:
#line 349 "exprtree.y"
               { (yyval.type) = TLookup("int"); }
#line 2048 "exprtree.tab.c"
    break;

  case 47:
#line 350 "exprtree.y"
               { (yyval.type) = TLookup("str"); }
#line 2054 "exprtree.tab.c"
    break;

  case 48:
#line 351 "exprtree.y"
               {
             Typetable *resolvedType = TLookup((yyvsp[0].str));
             if (resolvedType == NULL || !IsUserDefinedType(resolvedType)) {
                 fprintf(stderr, "Error: type '%s' is not defined yet\n", (yyvsp[0].str));
                 exit(1);
             }
             (yyval.type) = resolvedType;
         }
#line 2067 "exprtree.tab.c"
    break;

  case 49:
#line 361 "exprtree.y"
                            { (yyval.str) = (yyvsp[0].str); }
#line 2073 "exprtree.tab.c"
    break;

  case 50:
#line 362 "exprtree.y"
                             { (yyval.str) = NULL; }
#line 2079 "exprtree.tab.c"
    break;

  case 51:
#line 365 "exprtree.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 2085 "exprtree.tab.c"
    break;

  case 52:
#line 366 "exprtree.y"
                     {
          (yyval.type) = PointerType((yyvsp[-1].type));
          if ((yyval.type) == NULL) {
              fprintf(stderr, "Error: pointer types are supported only for int and str\n");
              exit(1);
          }
      }
#line 2097 "exprtree.tab.c"
    break;

  case 53:
#line 382 "exprtree.y"
                                                 {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-6].str);
        newVar->rows = (yyvsp[-4].num);
        newVar->cols = (yyvsp[-1].num);
        newVar->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-8].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-8].varlist);
    }
#line 2118 "exprtree.tab.c"
    break;

  case 54:
#line 398 "exprtree.y"
                                 { 
        VarList *newVar = calloc(1, sizeof(struct VarList));
        newVar->name = (yyvsp[-6].str);
        newVar->rows = (yyvsp[-4].num);
        newVar->cols = (yyvsp[-1].num);
        newVar->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 2135 "exprtree.tab.c"
    break;

  case 55:
#line 410 "exprtree.y"
                                 { 
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num); // array ayond size koduk
        newVar->rows = (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-5].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 2155 "exprtree.tab.c"
    break;

  case 56:
#line 425 "exprtree.y"
                     {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num);
        newVar->rows = (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 2171 "exprtree.tab.c"
    break;

  case 57:
#line 436 "exprtree.y"
                     {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-2].varlist);
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-2].varlist);
    }
#line 2192 "exprtree.tab.c"
    break;

  case 58:
#line 452 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 2207 "exprtree.tab.c"
    break;

  case 59:
#line 462 "exprtree.y"
                         { // adds a pointer variable to the declaration list
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        
        VarList *temp = (yyvsp[-3].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-3].varlist);
    }
#line 2225 "exprtree.tab.c"
    break;

  case 60:
#line 475 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 2239 "exprtree.tab.c"
    break;

  case 61:
#line 484 "exprtree.y"
                                     {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->size = 1;
        newVar->rows = 0;
        newVar->cols = 0;
        newVar->isPointer = 0;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        newVar->next = NULL;

        VarList *temp = (yyvsp[-5].varlist);
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 2263 "exprtree.tab.c"
    break;

  case 62:
#line 503 "exprtree.y"
                        {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->size = 1;
        newVar->rows = 0;
        newVar->cols = 0;
        newVar->isPointer = 0;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 2282 "exprtree.tab.c"
    break;

  case 63:
#line 517 "exprtree.y"
                                           {
        VarList *newVar = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-6].varlist);

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);

        while (tail->next != NULL) tail = tail->next;
        tail->next = newVar;
        (yyval.varlist) = (yyvsp[-6].varlist);
    }
#line 2300 "exprtree.tab.c"
    break;

  case 64:
#line 530 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 2314 "exprtree.tab.c"
    break;

  case 65:
#line 542 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 2322 "exprtree.tab.c"
    break;

  case 66:
#line 545 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2331 "exprtree.tab.c"
    break;

  case 67:
#line 549 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2339 "exprtree.tab.c"
    break;

  case 68:
#line 552 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 2347 "exprtree.tab.c"
    break;

  case 69:
#line 557 "exprtree.y"
                     { (yyval.node) = makeFieldValueNode((yyvsp[0].node)); }
#line 2353 "exprtree.tab.c"
    break;

  case 70:
#line 559 "exprtree.y"
                           {
                 (yyval.node) = makeMemberAccessNode(makeIdNode("self"), (yyvsp[0].str));
             }
#line 2361 "exprtree.tab.c"
    break;

  case 71:
#line 562 "exprtree.y"
                              {
                 (yyval.node) = makeMemberAccessNode((yyvsp[-2].node), (yyvsp[0].str));
             }
#line 2369 "exprtree.tab.c"
    break;

  case 72:
#line 565 "exprtree.y"
                           {
                 (yyval.node) = makeMemberAccessNode((yyvsp[-2].node), (yyvsp[0].str));
             }
#line 2377 "exprtree.tab.c"
    break;

  case 75:
#line 572 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 2386 "exprtree.tab.c"
    break;

  case 76:
#line 575 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 2396 "exprtree.tab.c"
    break;

  case 77:
#line 581 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 2411 "exprtree.tab.c"
    break;

  case 78:
#line 591 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 2419 "exprtree.tab.c"
    break;

  case 79:
#line 594 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 2427 "exprtree.tab.c"
    break;

  case 80:
#line 598 "exprtree.y"
                     {
        Paramstruct *p = calloc(1, sizeof(Paramstruct));

        if ((yyvsp[-1].paramtype).type == NULL && (yyvsp[-1].paramtype).classType == NULL) {
            fprintf(stderr, "Error: parameter type is not defined\n");
            exit(1);
        }

        p->name = (yyvsp[0].str);
        p->type = (yyvsp[-1].paramtype).type;
        p->classType = (yyvsp[-1].paramtype).classType;
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 2447 "exprtree.tab.c"
    break;

  case 81:
#line 613 "exprtree.y"
                       {
        Paramstruct *p = calloc(1, sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = PointerType((yyvsp[-2].paramtype).type);
        if (p->type == NULL) {
            fprintf(stderr, "Error: pointer parameters are supported only for int and str\n");
            exit(1);
        }
        p->next = NULL;
        (yyval.paramlist) = p;
    }
#line 2464 "exprtree.tab.c"
    break;

  case 82:
#line 626 "exprtree.y"
                {
              (yyval.paramtype).type = TLookup("int");
              (yyval.paramtype).classType = NULL;
          }
#line 2473 "exprtree.tab.c"
    break;

  case 83:
#line 630 "exprtree.y"
                {
              (yyval.paramtype).type = TLookup("str");
              (yyval.paramtype).classType = NULL;
          }
#line 2482 "exprtree.tab.c"
    break;

  case 84:
#line 634 "exprtree.y"
               {
              Typetable *type = TLookup((yyvsp[0].str));
              Classtable *classType = CLookup((yyvsp[0].str));

              if (type != NULL && IsUserDefinedType(type)) {
                  (yyval.paramtype).type = type;
                  (yyval.paramtype).classType = NULL;
              } else {
                  (yyval.paramtype).type = NULL;
                  (yyval.paramtype).classType = classType;
              }
          }
#line 2499 "exprtree.tab.c"
    break;

  case 89:
#line 652 "exprtree.y"
                                   {
        if ((yyvsp[-2].paramtype).classType != NULL) {
            InstallLocalClassVariables((yyvsp[-1].varlist), (yyvsp[-2].paramtype).classType);
        } else if ((yyvsp[-2].paramtype).type == NULL) {
            fprintf(stderr, "Error: local variable type is not defined\n");
            exit(1);
        } else {
            InstallLocalVariables((yyvsp[-1].varlist), (yyvsp[-2].paramtype).type);
        }
    }
#line 2514 "exprtree.tab.c"
    break;

  case 90:
#line 663 "exprtree.y"
                      { (yyval.paramtype) = (yyvsp[0].paramtype); }
#line 2520 "exprtree.tab.c"
    break;

  case 91:
#line 665 "exprtree.y"
                       {
        VarList* newNode = calloc(1, sizeof(VarList));

        newNode->name = strdup((yyvsp[0].str));
        newNode->size = 1;
        newNode->rows = 0;
        newNode->cols = 0;
        newNode->isPointer = 0;
        newNode->next = NULL;

        VarList *temp = (yyvsp[-2].varlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        (yyval.varlist) = (yyvsp[-2].varlist);
    }
#line 2544 "exprtree.tab.c"
    break;

  case 92:
#line 684 "exprtree.y"
                                {
        VarList *newNode = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-5].varlist);
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 2560 "exprtree.tab.c"
    break;

  case 93:
#line 695 "exprtree.y"
                                            {
        VarList *newNode = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-8].varlist);
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        (yyval.varlist) = (yyvsp[-8].varlist);
    }
#line 2577 "exprtree.tab.c"
    break;

  case 94:
#line 707 "exprtree.y"
                     {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2590 "exprtree.tab.c"
    break;

  case 95:
#line 715 "exprtree.y"
                                 {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2604 "exprtree.tab.c"
    break;

  case 96:
#line 724 "exprtree.y"
         {
        VarList* newNode = calloc(1, sizeof(VarList));

        newNode->name = strdup((yyvsp[0].str));
        newNode->size = 1;
        newNode->rows = 0;
        newNode->cols = 0;
        newNode->isPointer = 0;
        newNode->next = NULL;

        (yyval.varlist) = newNode;
    }
#line 2621 "exprtree.tab.c"
    break;

  case 97:
#line 738 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2627 "exprtree.tab.c"
    break;

  case 98:
#line 739 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2633 "exprtree.tab.c"
    break;

  case 99:
#line 742 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2639 "exprtree.tab.c"
    break;

  case 100:
#line 743 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2645 "exprtree.tab.c"
    break;

  case 101:
#line 745 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2651 "exprtree.tab.c"
    break;

  case 102:
#line 748 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2659 "exprtree.tab.c"
    break;

  case 103:
#line 750 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TLookup("int"), "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2671 "exprtree.tab.c"
    break;

  case 104:
#line 770 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2679 "exprtree.tab.c"
    break;

  case 105:
#line 773 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2687 "exprtree.tab.c"
    break;

  case 106:
#line 777 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2695 "exprtree.tab.c"
    break;

  case 107:
#line 780 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2703 "exprtree.tab.c"
    break;

  case 108:
#line 783 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2711 "exprtree.tab.c"
    break;

  case 109:
#line 786 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2719 "exprtree.tab.c"
    break;

  case 110:
#line 789 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2727 "exprtree.tab.c"
    break;

  case 111:
#line 792 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2735 "exprtree.tab.c"
    break;

  case 112:
#line 795 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2743 "exprtree.tab.c"
    break;

  case 113:
#line 798 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2751 "exprtree.tab.c"
    break;

  case 114:
#line 801 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2759 "exprtree.tab.c"
    break;

  case 115:
#line 804 "exprtree.y"
                                              {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2767 "exprtree.tab.c"
    break;

  case 116:
#line 807 "exprtree.y"
                                           {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2775 "exprtree.tab.c"
    break;

  case 117:
#line 810 "exprtree.y"
                                               {
        (yyval.node) = makeClassAllocNode((yyvsp[-6].node), (yyvsp[-2].str));
    }
#line 2783 "exprtree.tab.c"
    break;

  case 118:
#line 813 "exprtree.y"
                                            {
        (yyval.node) = makeClassAllocNode((yyvsp[-6].node), (yyvsp[-2].str));
    }
#line 2791 "exprtree.tab.c"
    break;

  case 119:
#line 816 "exprtree.y"
                                {
        (yyval.node) = makeFreeNode(makeIdNode((yyvsp[-2].str)));
    }
#line 2799 "exprtree.tab.c"
    break;

  case 120:
#line 819 "exprtree.y"
                                   {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2807 "exprtree.tab.c"
    break;

  case 121:
#line 822 "exprtree.y"
                                        {
        (yyval.node) = makeClassDeleteNode((yyvsp[-2].node));
    }
#line 2815 "exprtree.tab.c"
    break;

  case 122:
#line 825 "exprtree.y"
                                     {
        (yyval.node) = makeClassDeleteNode((yyvsp[-2].node));
    }
#line 2823 "exprtree.tab.c"
    break;

  case 123:
#line 829 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2831 "exprtree.tab.c"
    break;

  case 124:
#line 832 "exprtree.y"
                                   {
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2839 "exprtree.tab.c"
    break;

  case 125:
#line 837 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2847 "exprtree.tab.c"
    break;

  case 126:
#line 841 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2855 "exprtree.tab.c"
    break;

  case 127:
#line 844 "exprtree.y"
                               {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2863 "exprtree.tab.c"
    break;

  case 128:
#line 849 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2871 "exprtree.tab.c"
    break;

  case 129:
#line 852 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2879 "exprtree.tab.c"
    break;

  case 130:
#line 856 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2887 "exprtree.tab.c"
    break;

  case 131:
#line 860 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2895 "exprtree.tab.c"
    break;

  case 132:
#line 864 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2903 "exprtree.tab.c"
    break;

  case 133:
#line 868 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2911 "exprtree.tab.c"
    break;

  case 134:
#line 872 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2919 "exprtree.tab.c"
    break;

  case 135:
#line 876 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2927 "exprtree.tab.c"
    break;

  case 136:
#line 879 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2935 "exprtree.tab.c"
    break;

  case 137:
#line 882 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2943 "exprtree.tab.c"
    break;

  case 138:
#line 885 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2951 "exprtree.tab.c"
    break;

  case 139:
#line 888 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2959 "exprtree.tab.c"
    break;

  case 140:
#line 891 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2967 "exprtree.tab.c"
    break;

  case 141:
#line 894 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2975 "exprtree.tab.c"
    break;

  case 142:
#line 897 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2983 "exprtree.tab.c"
    break;

  case 143:
#line 900 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2991 "exprtree.tab.c"
    break;

  case 144:
#line 903 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2999 "exprtree.tab.c"
    break;

  case 145:
#line 906 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3007 "exprtree.tab.c"
    break;

  case 146:
#line 909 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3015 "exprtree.tab.c"
    break;

  case 147:
#line 912 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3023 "exprtree.tab.c"
    break;

  case 148:
#line 915 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3031 "exprtree.tab.c"
    break;

  case 149:
#line 918 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3039 "exprtree.tab.c"
    break;

  case 150:
#line 921 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 3047 "exprtree.tab.c"
    break;

  case 151:
#line 924 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 3055 "exprtree.tab.c"
    break;

  case 152:
#line 927 "exprtree.y"
             {
        (yyval.node) = makeNullNode();
    }
#line 3063 "exprtree.tab.c"
    break;

  case 153:
#line 930 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 3071 "exprtree.tab.c"
    break;

  case 154:
#line 933 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3079 "exprtree.tab.c"
    break;

  case 155:
#line 936 "exprtree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3087 "exprtree.tab.c"
    break;

  case 156:
#line 939 "exprtree.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3095 "exprtree.tab.c"
    break;

  case 157:
#line 942 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 3103 "exprtree.tab.c"
    break;

  case 158:
#line 945 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 3111 "exprtree.tab.c"
    break;

  case 159:
#line 949 "exprtree.y"
                                             {
                  (yyval.node) = makeMethodCallNode((yyvsp[-3].node), (yyvsp[-1].node));
              }
#line 3119 "exprtree.tab.c"
    break;

  case 160:
#line 952 "exprtree.y"
                                     {
                  (yyval.node) = makeMethodCallNode((yyvsp[-2].node), NULL);
              }
#line 3127 "exprtree.tab.c"
    break;


#line 3131 "exprtree.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 957 "exprtree.y"


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

    TypeTableCreate();
    if (yyparse() != 0) {
        fclose(yyin);
        return 1;
    }

    PrintTypeTable();
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
