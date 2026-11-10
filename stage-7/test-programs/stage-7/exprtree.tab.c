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

#line 126 "exprtree.tab.c"

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

#line 242 "exprtree.tab.c"

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
#define YYLAST   716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  392

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      56,    57,     2,     2,    58,     2,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   136,   137,   140,   141,   146,   147,   150,
     151,   156,   156,   172,   173,   176,   183,   190,   208,   209,
     212,   219,   226,   234,   241,   248,   259,   260,   264,   264,
     279,   280,   283,   283,   293,   294,   297,   308,   309,   310,
     319,   319,   321,   321,   323,   326,   329,   344,   345,   346,
     356,   357,   373,   389,   401,   416,   427,   443,   453,   466,
     475,   494,   508,   521,   533,   536,   540,   543,   551,   553,
     556,   559,   564,   564,   566,   566,   575,   585,   588,   592,
     607,   620,   624,   628,   642,   642,   644,   644,   646,   657,
     659,   678,   689,   701,   709,   718,   732,   733,   736,   737,
     739,   742,   742,   764,   767,   771,   774,   777,   780,   783,
     786,   789,   792,   795,   798,   801,   805,   808,   811,   814,
     818,   821,   825,   828,   833,   837,   840,   845,   848,   852,
     856,   860,   864,   868,   872,   875,   878,   881,   884,   887,
     890,   893,   896,   899,   902,   905,   908,   911,   914,   917,
     920,   923,   926,   929,   932,   935,   938,   941,   946,   949
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "OR", "AND", "ADDRESS",
  "TYPE", "ENDTYPE", "ALLOC", "FREE", "CLASS", "ENDCLASS", "SELF", "NEW",
  "DELETE", "T_NULL", "T_BEGIN", "T_END", "DECL", "ENDDECL", "INT", "STR",
  "ASSIGN", "SEMICOLON", "MAIN", "RETURN", "READ", "WRITE", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK",
  "CONTINUE", "STRING", "UMINUS", "'{'", "'}'", "'('", "')'", "','", "'['",
  "']'", "'.'", "$accept", "Program", "TypeDefBlock", "ClassDefBlock",
  "ClassDefList", "ClassDef", "$@1", "ClassFieldList", "ClassField",
  "ClassMethodDeclList", "ClassMethodDecl", "ClassMethodDefList",
  "ClassMethodDef", "$@2", "TypeDefList", "TypeDef", "$@3",
  "FieldDeclList", "FieldDecl", "FieldType", "GDeclBlock", "GDeclList",
  "GDecl", "TypeName", "FType", "VarList", "Variable", "Field",
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
     305,   306,   307,   308,   123,   125,    40,    41,    44,    91,
      93,    46
};
# endif

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    21,   105,    92,    86,   181,  -194,  -194,   191,    29,
    -194,  -194,  -194,  -194,    46,  -194,     9,   108,    67,  -194,
      79,   151,  -194,  -194,   182,  -194,   182,   182,    54,  -194,
     162,  -194,   108,  -194,   227,   246,    67,  -194,  -194,  -194,
    -194,  -194,     2,  -194,   284,   263,   168,   320,    38,    39,
      59,  -194,  -194,   269,  -194,   378,  -194,  -194,  -194,  -194,
     343,  -194,   211,   433,   384,  -194,   242,  -194,  -194,   398,
     211,  -194,   218,  -194,  -194,  -194,   213,  -194,   251,   397,
     211,   203,   461,  -194,   353,   260,   261,   262,  -194,    74,
    -194,  -194,   211,  -194,   463,   438,   355,   211,   467,   418,
     472,  -194,    23,   502,   142,   508,   144,   509,   272,   239,
     276,   286,  -194,  -194,  -194,   512,  -194,   358,   457,   211,
     100,   490,   464,  -194,   211,   465,  -194,   211,   466,  -194,
     211,   469,   470,  -194,    18,  -194,   520,   471,   475,   473,
    -194,   483,   381,  -194,  -194,   110,  -194,   528,   437,   491,
     472,   385,   211,   388,   211,   390,   211,  -194,  -194,   488,
    -194,   542,  -194,  -194,  -194,   492,   141,   493,   291,   497,
     487,   498,    20,   503,   507,   515,   517,   543,   543,   513,
     522,   -30,   -17,  -194,   544,   437,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,   490,   539,   411,
     540,   415,   541,   422,   211,   518,   576,  -194,   577,    20,
    -194,   184,   581,   186,  -194,   266,    20,   291,  -194,  -194,
      20,   519,    -7,   612,  -194,   186,    20,    20,    20,   565,
     459,  -194,  -194,   235,   582,   271,   591,  -194,   566,  -194,
     545,  -194,   561,  -194,   562,  -194,   563,   432,  -194,   547,
     549,   114,   225,   519,   -49,  -194,   -42,    33,   169,  -194,
    -194,   295,   229,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,  -194,    41,   135,   323,
     348,   361,   546,   553,   556,   558,   625,  -194,   587,   588,
     657,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   586,   598,
     590,   567,   610,   611,   614,  -194,   434,   670,  -194,  -194,
     444,   400,   400,  -194,  -194,  -194,   130,   130,   130,   130,
     308,   308,   389,   336,   615,   616,   617,   613,   608,    20,
      20,   599,   653,  -194,   601,   655,  -194,   606,   685,   629,
      20,  -194,  -194,  -194,  -194,  -194,    20,  -194,  -194,  -194,
    -194,   543,   543,   376,   414,   654,   634,   656,   637,   472,
     635,   638,   154,   670,   410,   489,   -25,   660,  -194,   662,
    -194,   663,   490,  -194,   697,  -194,   543,   665,   666,  -194,
    -194,  -194,  -194,   648,   644,   516,  -194,  -194,  -194,  -194,
     669,  -194
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     8,     0,     0,    31,     1,     0,     0,
      32,     5,    30,    11,     0,    10,     0,     0,     0,     4,
       0,     0,     7,     9,     0,    41,     0,     0,     0,    43,
       0,    49,    47,    48,    50,     0,     0,    73,     3,    39,
      37,    38,     0,    35,     0,     0,    57,     0,     0,     0,
       0,    40,    42,     0,    51,     0,    72,     2,    33,    34,
       0,    14,    78,     0,    59,    46,     0,    44,    45,     0,
      78,    36,     0,    83,    81,    82,     0,    77,     0,     0,
      78,    56,     0,   101,     0,     0,     0,     0,    13,     0,
      19,    61,     0,    79,     0,    55,     0,    78,     0,    58,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    76,    80,     0,    63,     0,     0,    78,
       0,     0,     0,    17,    78,     0,    15,    78,     0,    16,
      78,     0,     0,    47,     0,    27,     0,     0,     0,     0,
      60,    54,     0,    85,    89,     0,    87,     0,     0,     0,
       0,     0,    78,     0,    78,     0,    78,    12,    26,     0,
      53,     0,    62,    84,    86,    95,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   102,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    88,     0,     0,
      67,     0,     0,     0,   149,    64,     0,     0,   151,   150,
       0,   153,   154,     0,   155,     0,     0,     0,     0,     0,
       0,   130,   131,     0,     0,     0,     0,    99,     0,   103,
       0,    22,     0,    20,     0,    21,     0,     0,    52,     0,
      90,     0,    64,     0,     0,    69,     0,     0,     0,   139,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,    71,    98,    75,    25,    23,    24,    28,    93,     0,
      65,     0,     0,     0,     0,   156,     0,    97,   140,   159,
       0,   134,   135,   136,   137,   138,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,   126,     0,     0,     0,
       0,   118,   119,   120,   121,   157,     0,   158,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,    96,     0,     0,     0,     0,   114,     0,
     115,     0,     0,    94,     0,    66,     0,     0,     0,   133,
     132,   116,   117,     0,     0,     0,   128,   129,    29,    92,
       0,   127
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,  -194,  -194,  -194,   692,  -194,  -194,  -194,  -194,
     618,  -194,   574,  -194,  -194,   704,  -194,  -194,   668,  -194,
    -194,  -194,   683,  -194,   -95,   468,  -148,  -145,  -194,  -194,
     676,  -194,   -63,   621,   -92,  -149,  -194,   569,  -194,  -194,
     453,  -193,   531,   212,  -194,  -168,  -183,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -117,  -194
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    14,    15,    21,    72,    88,    89,
      90,   134,   135,   337,     5,     6,    20,    42,    43,    44,
      18,    28,    29,    34,    35,    48,   221,   222,   183,    36,
      37,   122,    76,    77,    78,   121,   145,   146,   147,   166,
     306,   149,   184,    19,   100,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   307,   224
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   197,   239,   182,   240,   233,    39,    84,   302,   229,
     230,   379,   236,    24,   136,   303,     1,    96,   235,   234,
     210,   352,    31,   214,   215,     4,   216,   168,   144,   181,
     181,   234,   182,   182,   117,    40,    41,   181,   217,   136,
     182,    25,    26,    27,   236,   170,   239,   239,   218,   262,
      13,   133,    33,   144,   236,   223,   142,    58,    24,   123,
      16,   151,    17,   253,   153,   256,   254,   155,   257,   260,
      22,    31,   219,   157,    65,    67,   220,   277,   108,   124,
     278,   181,   181,    39,   182,   182,    51,    26,    27,   199,
     304,   201,   251,   203,   236,    68,    66,    66,   324,   259,
      32,    33,   234,   261,    73,     7,   109,   110,   111,   279,
     280,   281,    40,    41,    73,     8,   286,    66,   290,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   143,    74,    75,   263,   264,   265,   266,   267,
      10,   247,   163,    74,    75,    30,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   214,   215,   300,   216,   168,   207,   126,   383,
     129,   239,   239,   364,   365,     4,    46,   217,   252,    47,
     167,   168,   325,   168,   170,    13,   236,   218,   127,   208,
     130,    11,   239,   181,   181,    45,   182,   182,   385,   170,
     372,   170,   353,   354,   375,    73,   181,   181,    53,   182,
     182,   219,    85,   362,    62,   220,   305,    63,   181,   363,
      38,   182,   214,   215,    54,   216,   168,   181,   214,   215,
     182,   216,   168,    31,    74,    75,    81,   217,    57,    82,
      55,    86,    87,   217,   170,    93,   284,   218,    94,    97,
     170,   285,    98,   218,   102,   104,   106,   103,   105,   107,
      91,    92,   133,    33,   214,   215,   132,   216,   168,   103,
     137,   219,   301,   105,   209,   220,   309,   219,    60,   217,
     138,   220,   288,   107,    61,   167,   170,   289,   168,   218,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   258,   219,    64,   209,    69,   220,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   308,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,    71,
     326,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   327,   275,   265,   266,   267,
     101,    92,   116,    92,   167,   140,    92,   168,   328,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   169,   366,    70,   170,    79,   171,   162,    92,
      80,   167,   198,    92,   168,   200,    92,   202,    92,   173,
     174,   175,    83,   376,   377,   176,   177,    95,   178,   169,
     179,   180,   170,   167,   171,    99,   168,   114,   242,    92,
     118,   367,   244,    92,   119,   172,   173,   174,   175,   246,
      92,   169,   176,   177,   170,   178,   171,   179,   180,   297,
      92,   345,   346,   167,    49,    50,   168,   115,   173,   174,
     175,   347,   346,   120,   176,   177,   125,   178,   283,   179,
     180,   169,   128,   131,   170,   139,   171,   141,   150,   148,
     167,   152,   154,   168,   159,   156,   124,   127,   173,   174,
     175,   130,   165,   160,   176,   177,   378,   178,   169,   179,
     180,   170,   161,   171,   204,   205,   196,   167,   212,   231,
     168,   206,   209,   211,   213,   173,   174,   175,   232,   225,
     390,   176,   177,   226,   178,   169,   179,   180,   170,   167,
     171,   227,   168,   228,   237,   241,   243,   245,   248,   249,
     234,   250,   173,   174,   175,   255,   287,   169,   176,   177,
     170,   178,   171,   179,   180,   291,   292,   294,   295,   296,
     293,   339,   329,   341,   173,   174,   175,   298,   299,   330,
     282,   177,   331,   178,   332,   179,   180,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   334,   335,   338,   342,   343,   276,   340,
     344,   348,   349,   350,   352,   351,   355,   356,   357,   358,
     359,   333,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   360,   361,
     368,   369,   370,   336,   371,   373,   380,   374,   381,   382,
     384,   386,   387,   388,   389,   391,    23,   112,   158,    12,
      59,    52,    56,   113,   164,   310,   238
};

static const yytype_int16 yycheck[] =
{
     148,   150,   185,   148,   197,    35,     4,    70,    57,   177,
     178,    36,    61,     4,   109,    57,    19,    80,    35,    61,
     168,    46,     4,     3,     4,     4,     6,     7,   120,   177,
     178,    61,   177,   178,    97,    33,    34,   185,    18,   134,
     185,    32,    33,    34,    61,    25,   229,   230,    28,    56,
       4,    33,    34,   145,    61,   172,   119,    55,     4,    36,
      31,   124,    33,   211,   127,   213,   211,   130,   213,   217,
      24,     4,    52,    55,    36,    36,    56,   225,     4,    56,
     225,   229,   230,     4,   229,   230,    32,    33,    34,   152,
      57,   154,   209,   156,    61,    36,    58,    58,    57,   216,
      33,    34,    61,   220,     4,     0,    32,    33,    34,   226,
     227,   228,    33,    34,     4,    23,   233,    58,   235,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    32,    33,    34,     5,     6,     7,     8,     9,
      54,   204,    32,    33,    34,    37,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     3,     4,    60,     6,     7,    36,    36,   372,
      36,   364,   365,   351,   352,     4,     4,    18,     4,     7,
       4,     7,    57,     7,    25,     4,    61,    28,    56,    58,
      56,    20,   385,   351,   352,    54,   351,   352,   376,    25,
     359,    25,   329,   330,    60,     4,   364,   365,    56,   364,
     365,    52,     4,   340,    56,    56,    57,    59,   376,   346,
      18,   376,     3,     4,     7,     6,     7,   385,     3,     4,
     385,     6,     7,     4,    33,    34,     4,    18,    36,     7,
       4,    33,    34,    18,    25,     4,    21,    28,     7,    56,
      25,    26,    59,    28,     4,     4,     4,     7,     7,     7,
      57,    58,    33,    34,     3,     4,     4,     6,     7,     7,
       4,    52,    57,     7,    59,    56,    57,    52,     4,    18,
       4,    56,    21,     7,    31,     4,    25,    26,     7,    28,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    56,    52,     4,    59,    57,    56,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    57,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    36,
      57,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    57,    17,     7,     8,     9,
      57,    58,    57,    58,     4,    57,    58,     7,    57,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    22,    57,    56,    25,     3,    27,    57,    58,
      56,     4,    57,    58,     7,    57,    58,    57,    58,    39,
      40,    41,    54,    43,    44,    45,    46,    60,    48,    22,
      50,    51,    25,     4,    27,     4,     7,     4,    57,    58,
       3,    57,    57,    58,    56,    38,    39,    40,    41,    57,
      58,    22,    45,    46,    25,    48,    27,    50,    51,    57,
      58,    57,    58,     4,    26,    27,     7,    59,    39,    40,
      41,    57,    58,    31,    45,    46,     4,    48,    49,    50,
      51,    22,     4,     4,    25,     3,    27,    60,    54,    29,
       4,    56,    56,     7,     4,    56,    56,    56,    39,    40,
      41,    56,     4,    60,    45,    46,    47,    48,    22,    50,
      51,    25,    59,    27,    56,     3,    55,     4,    61,    36,
       7,    59,    59,    56,    56,    39,    40,    41,    36,    56,
      44,    45,    46,    56,    48,    22,    50,    51,    25,     4,
      27,    56,     7,    56,    30,    36,    36,    36,    60,     3,
      61,     4,    39,    40,    41,     4,     4,    22,    45,    46,
      25,    48,    27,    50,    51,     4,    30,    36,    36,    36,
      55,     3,    56,    36,    39,    40,    41,    60,    59,    56,
      45,    46,    56,    48,    56,    50,    51,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    56,    56,    59,    36,    36,    36,    59,
      36,    36,    36,    36,    46,    42,    57,     4,    57,     4,
      54,    36,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     3,    60,
      36,    57,    36,    36,    57,    60,    36,    59,    36,    36,
       3,    36,    36,    55,    60,    36,    14,    89,   134,     5,
      42,    28,    36,    92,   145,   262,   185
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    63,    64,     4,    76,    77,     0,    23,    65,
      54,    20,    77,     4,    66,    67,    31,    33,    82,   105,
      78,    68,    24,    67,     4,    32,    33,    34,    83,    84,
      37,     4,    33,    34,    85,    86,    91,    92,   105,     4,
      33,    34,    79,    80,    81,    54,     4,     7,    87,    87,
      87,    32,    84,    56,     7,     4,    92,   105,    55,    80,
       4,    31,    56,    59,     4,    36,    58,    36,    36,    57,
      56,    36,    69,     4,    33,    34,    94,    95,    96,     3,
      56,     4,     7,    54,    94,     4,    33,    34,    70,    71,
      72,    57,    58,     4,     7,    60,    94,    56,    59,     4,
     106,    57,     4,     7,     4,     7,     4,     7,     4,    32,
      33,    34,    72,    95,     4,    59,    57,    94,     3,    56,
      31,    97,    93,    36,    56,     4,    36,    56,     4,    36,
      56,     4,     4,    33,    73,    74,    86,     4,     4,     3,
      57,    60,    94,    32,    96,    98,    99,   100,    29,   103,
      54,    94,    56,    94,    56,    94,    56,    55,    74,     4,
      60,    59,    57,    32,    99,     4,   101,     4,     7,    22,
      25,    27,    38,    39,    40,    41,    45,    46,    48,    50,
      51,    88,    89,    90,   104,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    55,    97,    57,    94,
      57,    94,    57,    94,    56,     3,    59,    36,    58,    59,
      88,    56,    61,    56,     3,     4,     6,    18,    28,    52,
      56,    88,    89,   118,   119,    56,    56,    56,    56,   107,
     107,    36,    36,    35,    61,    35,    61,    30,   104,   108,
     103,    36,    57,    36,    57,    36,    57,    94,    60,     3,
       4,   118,     4,    88,    89,     4,    88,    89,    56,   118,
      88,   118,    56,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    36,    88,    89,   118,
     118,   118,    45,    49,    21,    26,   118,     4,    21,    26,
     118,     4,    30,    55,    36,    36,    36,    57,    60,    59,
      60,    57,    57,    57,    57,    57,   102,   118,    57,    57,
     102,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,    57,    57,    57,    57,    57,    56,
      56,    56,    56,    36,    56,    56,    36,    75,    59,     3,
      59,    36,    36,    36,    36,    57,    58,    57,    36,    36,
      36,    42,    46,   118,   118,    57,     4,    57,     4,    54,
       3,    60,   118,   118,   107,   107,    57,    57,    36,    57,
      36,    57,    97,    60,    59,    60,    43,    44,    47,    36,
      36,    36,    36,   103,     3,   107,    36,    36,    55,    60,
      44,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    68,    67,    69,    69,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    73,    73,    75,    74,
      76,    76,    78,    77,    79,    79,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    89,    90,
      90,    90,    91,    91,    93,    92,    94,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    98,    98,    99,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     104,   106,   105,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     114,   115,   116,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     3,     0,     2,
       1,     0,     9,     2,     0,     3,     3,     3,     2,     1,
       6,     6,     6,     7,     7,     7,     2,     1,     0,    10,
       2,     1,     0,     5,     2,     1,     3,     1,     1,     1,
       3,     2,     2,     1,     3,     3,     3,     1,     1,     1,
       1,     2,     9,     7,     6,     4,     3,     1,     4,     2,
       6,     4,     7,     5,     1,     4,     7,     2,     1,     3,
       3,     3,     2,     1,     0,    10,     3,     1,     0,     2,
       3,     1,     1,     1,     3,     2,     2,     1,     3,     1,
       3,     6,     9,     4,     7,     1,     3,     1,     4,     3,
       3,     0,     9,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     6,     7,     7,     5,     5,
       5,     5,     5,     5,     5,     4,     4,    10,     8,     8,
       2,     2,     7,     7,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     1,     1,     1,     3,     4,     4,     3
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
#line 135 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1745 "exprtree.tab.c"
    break;

  case 3:
#line 136 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1751 "exprtree.tab.c"
    break;

  case 4:
#line 137 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1757 "exprtree.tab.c"
    break;

  case 7:
#line 146 "exprtree.y"
                                            { PrintClassTable(); }
#line 1763 "exprtree.tab.c"
    break;

  case 11:
#line 156 "exprtree.y"
              {
              currentClass = CInstall((yyvsp[0].str), NULL);
              if (currentClass == NULL) {
                  fprintf(stderr, "Error: class '%s' is already defined or cannot be installed\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1775 "exprtree.tab.c"
    break;

  case 12:
#line 162 "exprtree.y"
                                                                                       {
              if (!Class_CheckMethodDefinitions(currentClass)) {
                  exit(1);
              }
              currentClass = NULL;
              currentMethod = NULL;
          }
#line 1787 "exprtree.tab.c"
    break;

  case 15:
#line 176 "exprtree.y"
                              {
               if (Class_Finstall(currentClass, "int", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "int", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1799 "exprtree.tab.c"
    break;

  case 16:
#line 183 "exprtree.y"
                              {
               if (Class_Finstall(currentClass, "str", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "str", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1811 "exprtree.tab.c"
    break;

  case 17:
#line 190 "exprtree.y"
                             {
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
#line 1831 "exprtree.tab.c"
    break;

  case 20:
#line 212 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("int"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1843 "exprtree.tab.c"
    break;

  case 21:
#line 219 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("str"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1855 "exprtree.tab.c"
    break;

  case 22:
#line 226 "exprtree.y"
                                                    {
                    Typetable *returnType = TLookup((yyvsp[-5].str));
                    if (returnType == NULL || Class_Minstall(currentClass, (yyvsp[-4].str), returnType, (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1868 "exprtree.tab.c"
    break;

  case 23:
#line 234 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("int")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1880 "exprtree.tab.c"
    break;

  case 24:
#line 241 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("str")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1892 "exprtree.tab.c"
    break;

  case 25:
#line 248 "exprtree.y"
                                                        {
                    Typetable *returnType = TLookup((yyvsp[-6].str));
                    if (returnType == NULL || !IsUserDefinedType(returnType) ||
                        Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(returnType), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid pointer return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1906 "exprtree.tab.c"
    break;

  case 28:
#line 264 "exprtree.y"
                                            {
                    currentMethod = Class_MatchMethodDefinition(currentClass, (yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
                    if (currentMethod == NULL) exit(1);
                    BeginMethodScope((yyvsp[-1].paramlist), currentClass);
                }
#line 1916 "exprtree.tab.c"
    break;

  case 29:
#line 268 "exprtree.y"
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
#line 1931 "exprtree.tab.c"
    break;

  case 32:
#line 283 "exprtree.y"
                 {
            if (TBeginDefinition((yyvsp[-1].str)) == NULL) {
                fprintf(stderr, "Error: type '%s' is already defined or cannot be started\n", (yyvsp[-1].str));
                exit(1);
            }
        }
#line 1942 "exprtree.tab.c"
    break;

  case 33:
#line 288 "exprtree.y"
                            {
            TFinishDefinition(TCurrentDefinition());
        }
#line 1950 "exprtree.tab.c"
    break;

  case 36:
#line 297 "exprtree.y"
                                   {
              Typetable *owner = TCurrentDefinition();
              if (owner == NULL ||
                  FInstall(owner, (yyvsp[-1].str), (yyvsp[-2].type), owner->size) == NULL) {
                  fprintf(stderr, "Error: duplicate field '%s' or invalid field declaration\n", (yyvsp[-1].str));
                  exit(1);
              }
              owner->size++;
          }
#line 1964 "exprtree.tab.c"
    break;

  case 37:
#line 308 "exprtree.y"
                { (yyval.type) = TLookup("int"); }
#line 1970 "exprtree.tab.c"
    break;

  case 38:
#line 309 "exprtree.y"
                { (yyval.type) = TLookup("str"); }
#line 1976 "exprtree.tab.c"
    break;

  case 39:
#line 310 "exprtree.y"
               {
              (yyval.type) = TLookup((yyvsp[0].str));
              if ((yyval.type) == NULL || !IsUserDefinedType((yyval.type))) {
                  fprintf(stderr, "Error: field type '%s' is undefined or not declarable here\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1988 "exprtree.tab.c"
    break;

  case 44:
#line 323 "exprtree.y"
                              {
           InstallGlobalVarList((yyvsp[-1].varlist), TLookup("int"), NULL);
       }
#line 1996 "exprtree.tab.c"
    break;

  case 45:
#line 326 "exprtree.y"
                             {
           InstallGlobalVarList((yyvsp[-1].varlist), TLookup("str"), NULL);
       }
#line 2004 "exprtree.tab.c"
    break;

  case 46:
#line 329 "exprtree.y"
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
#line 2022 "exprtree.tab.c"
    break;

  case 47:
#line 344 "exprtree.y"
               { (yyval.type) = TLookup("int"); }
#line 2028 "exprtree.tab.c"
    break;

  case 48:
#line 345 "exprtree.y"
               { (yyval.type) = TLookup("str"); }
#line 2034 "exprtree.tab.c"
    break;

  case 49:
#line 346 "exprtree.y"
               {
             Typetable *resolvedType = TLookup((yyvsp[0].str));
             if (resolvedType == NULL || !IsUserDefinedType(resolvedType)) {
                 fprintf(stderr, "Error: type '%s' is not defined yet\n", (yyvsp[0].str));
                 exit(1);
             }
             (yyval.type) = resolvedType;
         }
#line 2047 "exprtree.tab.c"
    break;

  case 50:
#line 356 "exprtree.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 2053 "exprtree.tab.c"
    break;

  case 51:
#line 357 "exprtree.y"
                     {
          (yyval.type) = PointerType((yyvsp[-1].type));
          if ((yyval.type) == NULL) {
              fprintf(stderr, "Error: pointer types are supported only for int and str\n");
              exit(1);
          }
      }
#line 2065 "exprtree.tab.c"
    break;

  case 52:
#line 373 "exprtree.y"
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
#line 2086 "exprtree.tab.c"
    break;

  case 53:
#line 389 "exprtree.y"
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
#line 2103 "exprtree.tab.c"
    break;

  case 54:
#line 401 "exprtree.y"
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
#line 2123 "exprtree.tab.c"
    break;

  case 55:
#line 416 "exprtree.y"
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
#line 2139 "exprtree.tab.c"
    break;

  case 56:
#line 427 "exprtree.y"
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
#line 2160 "exprtree.tab.c"
    break;

  case 57:
#line 443 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 2175 "exprtree.tab.c"
    break;

  case 58:
#line 453 "exprtree.y"
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
#line 2193 "exprtree.tab.c"
    break;

  case 59:
#line 466 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 2207 "exprtree.tab.c"
    break;

  case 60:
#line 475 "exprtree.y"
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
#line 2231 "exprtree.tab.c"
    break;

  case 61:
#line 494 "exprtree.y"
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
#line 2250 "exprtree.tab.c"
    break;

  case 62:
#line 508 "exprtree.y"
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
#line 2268 "exprtree.tab.c"
    break;

  case 63:
#line 521 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 2282 "exprtree.tab.c"
    break;

  case 64:
#line 533 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 2290 "exprtree.tab.c"
    break;

  case 65:
#line 536 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2299 "exprtree.tab.c"
    break;

  case 66:
#line 540 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2307 "exprtree.tab.c"
    break;

  case 67:
#line 543 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 2315 "exprtree.tab.c"
    break;

  case 68:
#line 551 "exprtree.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2321 "exprtree.tab.c"
    break;

  case 69:
#line 553 "exprtree.y"
                           {
                 (yyval.node) = makeMemberAccessNode(makeIdNode("self"), (yyvsp[0].str));
             }
#line 2329 "exprtree.tab.c"
    break;

  case 70:
#line 556 "exprtree.y"
                              {
                 (yyval.node) = makeMemberAccessNode((yyvsp[-2].node), (yyvsp[0].str));
             }
#line 2337 "exprtree.tab.c"
    break;

  case 71:
#line 559 "exprtree.y"
                           {
                 (yyval.node) = makeMemberAccessNode(makeFieldValueNode((yyvsp[-2].node)), (yyvsp[0].str));
             }
#line 2345 "exprtree.tab.c"
    break;

  case 74:
#line 566 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 2354 "exprtree.tab.c"
    break;

  case 75:
#line 569 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 2364 "exprtree.tab.c"
    break;

  case 76:
#line 575 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 2379 "exprtree.tab.c"
    break;

  case 77:
#line 585 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 2387 "exprtree.tab.c"
    break;

  case 78:
#line 588 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 2395 "exprtree.tab.c"
    break;

  case 79:
#line 592 "exprtree.y"
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
#line 2415 "exprtree.tab.c"
    break;

  case 80:
#line 607 "exprtree.y"
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
#line 2432 "exprtree.tab.c"
    break;

  case 81:
#line 620 "exprtree.y"
                {
              (yyval.paramtype).type = TLookup("int");
              (yyval.paramtype).classType = NULL;
          }
#line 2441 "exprtree.tab.c"
    break;

  case 82:
#line 624 "exprtree.y"
                {
              (yyval.paramtype).type = TLookup("str");
              (yyval.paramtype).classType = NULL;
          }
#line 2450 "exprtree.tab.c"
    break;

  case 83:
#line 628 "exprtree.y"
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
#line 2467 "exprtree.tab.c"
    break;

  case 88:
#line 646 "exprtree.y"
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
#line 2482 "exprtree.tab.c"
    break;

  case 89:
#line 657 "exprtree.y"
                      { (yyval.paramtype) = (yyvsp[0].paramtype); }
#line 2488 "exprtree.tab.c"
    break;

  case 90:
#line 659 "exprtree.y"
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
#line 2512 "exprtree.tab.c"
    break;

  case 91:
#line 678 "exprtree.y"
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
#line 2528 "exprtree.tab.c"
    break;

  case 92:
#line 689 "exprtree.y"
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
#line 2545 "exprtree.tab.c"
    break;

  case 93:
#line 701 "exprtree.y"
                     {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2558 "exprtree.tab.c"
    break;

  case 94:
#line 709 "exprtree.y"
                                 {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2572 "exprtree.tab.c"
    break;

  case 95:
#line 718 "exprtree.y"
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
#line 2589 "exprtree.tab.c"
    break;

  case 96:
#line 732 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2595 "exprtree.tab.c"
    break;

  case 97:
#line 733 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2601 "exprtree.tab.c"
    break;

  case 98:
#line 736 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2607 "exprtree.tab.c"
    break;

  case 99:
#line 737 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2613 "exprtree.tab.c"
    break;

  case 100:
#line 739 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2619 "exprtree.tab.c"
    break;

  case 101:
#line 742 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2627 "exprtree.tab.c"
    break;

  case 102:
#line 744 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TLookup("int"), "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2639 "exprtree.tab.c"
    break;

  case 103:
#line 764 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2647 "exprtree.tab.c"
    break;

  case 104:
#line 767 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2655 "exprtree.tab.c"
    break;

  case 105:
#line 771 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2663 "exprtree.tab.c"
    break;

  case 106:
#line 774 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2671 "exprtree.tab.c"
    break;

  case 107:
#line 777 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2679 "exprtree.tab.c"
    break;

  case 108:
#line 780 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2687 "exprtree.tab.c"
    break;

  case 109:
#line 783 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2695 "exprtree.tab.c"
    break;

  case 110:
#line 786 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2703 "exprtree.tab.c"
    break;

  case 111:
#line 789 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2711 "exprtree.tab.c"
    break;

  case 112:
#line 792 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2719 "exprtree.tab.c"
    break;

  case 113:
#line 795 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2727 "exprtree.tab.c"
    break;

  case 114:
#line 798 "exprtree.y"
                                              {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2735 "exprtree.tab.c"
    break;

  case 115:
#line 801 "exprtree.y"
                                           {
        (yyval.node) = makeAllocNode(makeFieldValueNode((yyvsp[-5].node)));
    }
#line 2743 "exprtree.tab.c"
    break;

  case 116:
#line 805 "exprtree.y"
                                               {
        (yyval.node) = makeClassAllocNode((yyvsp[-6].node), (yyvsp[-2].str));
    }
#line 2751 "exprtree.tab.c"
    break;

  case 117:
#line 808 "exprtree.y"
                                            {
        (yyval.node) = makeClassAllocNode(makeFieldValueNode((yyvsp[-6].node)), (yyvsp[-2].str));
    }
#line 2759 "exprtree.tab.c"
    break;

  case 118:
#line 811 "exprtree.y"
                                {
        (yyval.node) = makeFreeNode(makeIdNode((yyvsp[-2].str)));
    }
#line 2767 "exprtree.tab.c"
    break;

  case 119:
#line 814 "exprtree.y"
                                   {
        (yyval.node) = makeFreeNode(makeFieldValueNode((yyvsp[-2].node)));
    }
#line 2775 "exprtree.tab.c"
    break;

  case 120:
#line 818 "exprtree.y"
                                        {
        (yyval.node) = makeClassDeleteNode((yyvsp[-2].node));
    }
#line 2783 "exprtree.tab.c"
    break;

  case 121:
#line 821 "exprtree.y"
                                     {
        (yyval.node) = makeClassDeleteNode(makeFieldValueNode((yyvsp[-2].node)));
    }
#line 2791 "exprtree.tab.c"
    break;

  case 122:
#line 825 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2799 "exprtree.tab.c"
    break;

  case 123:
#line 828 "exprtree.y"
                                   {
        (yyval.node) = makeReadNode(makeFieldValueNode((yyvsp[-2].node)));
    }
#line 2807 "exprtree.tab.c"
    break;

  case 124:
#line 833 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2815 "exprtree.tab.c"
    break;

  case 125:
#line 837 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2823 "exprtree.tab.c"
    break;

  case 126:
#line 840 "exprtree.y"
                               {
        (yyval.node) = makeAssignNode(makeFieldValueNode((yyvsp[-3].node)), (yyvsp[-1].node));
    }
#line 2831 "exprtree.tab.c"
    break;

  case 127:
#line 845 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2839 "exprtree.tab.c"
    break;

  case 128:
#line 848 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2847 "exprtree.tab.c"
    break;

  case 129:
#line 852 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2855 "exprtree.tab.c"
    break;

  case 130:
#line 856 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2863 "exprtree.tab.c"
    break;

  case 131:
#line 860 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2871 "exprtree.tab.c"
    break;

  case 132:
#line 864 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2879 "exprtree.tab.c"
    break;

  case 133:
#line 868 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2887 "exprtree.tab.c"
    break;

  case 134:
#line 872 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2895 "exprtree.tab.c"
    break;

  case 135:
#line 875 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2903 "exprtree.tab.c"
    break;

  case 136:
#line 878 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2911 "exprtree.tab.c"
    break;

  case 137:
#line 881 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2919 "exprtree.tab.c"
    break;

  case 138:
#line 884 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2927 "exprtree.tab.c"
    break;

  case 139:
#line 887 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2935 "exprtree.tab.c"
    break;

  case 140:
#line 890 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2943 "exprtree.tab.c"
    break;

  case 141:
#line 893 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2951 "exprtree.tab.c"
    break;

  case 142:
#line 896 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2959 "exprtree.tab.c"
    break;

  case 143:
#line 899 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2967 "exprtree.tab.c"
    break;

  case 144:
#line 902 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2975 "exprtree.tab.c"
    break;

  case 145:
#line 905 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2983 "exprtree.tab.c"
    break;

  case 146:
#line 908 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2991 "exprtree.tab.c"
    break;

  case 147:
#line 911 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2999 "exprtree.tab.c"
    break;

  case 148:
#line 914 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3007 "exprtree.tab.c"
    break;

  case 149:
#line 917 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 3015 "exprtree.tab.c"
    break;

  case 150:
#line 920 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 3023 "exprtree.tab.c"
    break;

  case 151:
#line 923 "exprtree.y"
             {
        (yyval.node) = makeNullNode();
    }
#line 3031 "exprtree.tab.c"
    break;

  case 152:
#line 926 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 3039 "exprtree.tab.c"
    break;

  case 153:
#line 929 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3047 "exprtree.tab.c"
    break;

  case 154:
#line 932 "exprtree.y"
            {
        (yyval.node) = makeFieldValueNode((yyvsp[0].node));
    }
#line 3055 "exprtree.tab.c"
    break;

  case 155:
#line 935 "exprtree.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3063 "exprtree.tab.c"
    break;

  case 156:
#line 938 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 3071 "exprtree.tab.c"
    break;

  case 157:
#line 941 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 3079 "exprtree.tab.c"
    break;

  case 158:
#line 946 "exprtree.y"
                                      {
                  (yyval.node) = makeMethodCallNode((yyvsp[-3].node), (yyvsp[-1].node));
              }
#line 3087 "exprtree.tab.c"
    break;

  case 159:
#line 949 "exprtree.y"
                              {
                  (yyval.node) = makeMethodCallNode((yyvsp[-2].node), NULL);
              }
#line 3095 "exprtree.tab.c"
    break;


#line 3099 "exprtree.tab.c"

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
#line 954 "exprtree.y"


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
