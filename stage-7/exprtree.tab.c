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
#define YYLAST   731

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  393

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
       0,   135,   135,   136,   137,   140,   141,   145,   146,   149,
     150,   153,   153,   168,   169,   172,   179,   186,   203,   204,
     207,   214,   221,   229,   236,   243,   254,   255,   258,   258,
     273,   274,   277,   277,   287,   288,   291,   302,   303,   304,
     313,   313,   315,   315,   317,   320,   323,   338,   339,   340,
     350,   351,   367,   383,   395,   410,   421,   437,   447,   460,
     469,   488,   502,   515,   527,   530,   534,   537,   542,   544,
     547,   550,   555,   555,   557,   557,   566,   576,   579,   583,
     598,   611,   615,   619,   633,   633,   635,   635,   637,   648,
     650,   669,   680,   692,   700,   709,   723,   724,   727,   728,
     730,   733,   733,   755,   758,   762,   765,   768,   771,   774,
     777,   780,   783,   786,   789,   792,   795,   798,   801,   804,
     807,   810,   814,   817,   822,   826,   829,   834,   837,   841,
     845,   849,   853,   857,   861,   864,   867,   870,   873,   876,
     879,   882,   885,   888,   891,   894,   897,   900,   903,   906,
     909,   912,   915,   918,   921,   924,   927,   930,   934,   937
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
       0,    50,   123,    95,   124,    93,  -194,  -194,   190,   -20,
    -194,  -194,  -194,  -194,     2,  -194,    19,   162,    11,  -194,
     112,   156,  -194,  -194,   212,  -194,   212,   212,   110,  -194,
     175,  -194,   162,  -194,   205,   231,    11,  -194,  -194,  -194,
    -194,  -194,    54,  -194,   246,   252,   169,   263,    -9,    -8,
      -1,  -194,  -194,   232,  -194,   237,  -194,  -194,  -194,  -194,
     276,  -194,   283,   407,   265,  -194,   259,  -194,  -194,   292,
     283,  -194,   286,  -194,  -194,  -194,    82,  -194,   261,   314,
     283,   280,   425,  -194,   129,   336,   337,   338,  -194,   245,
    -194,  -194,   283,  -194,   431,   374,   187,   283,   440,   391,
     421,  -194,    59,   456,    65,   458,    66,   461,   398,   304,
     399,   400,  -194,  -194,  -194,   466,  -194,   218,   430,   283,
     277,   460,   438,  -194,   283,   442,  -194,   283,   445,  -194,
     283,   463,   464,  -194,   219,  -194,   506,   465,   470,   462,
    -194,   468,   380,  -194,  -194,   281,  -194,   510,   432,   473,
     421,   406,   283,   410,   283,   417,   283,  -194,  -194,   481,
    -194,   536,  -194,  -194,  -194,   482,    26,   485,   404,   487,
     479,   490,   266,   491,   492,   493,   497,   538,   538,   518,
     522,   -30,   -23,  -194,   550,   432,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,   460,   530,   427,
     545,   429,   554,   439,   283,   531,   589,  -194,   590,   266,
    -194,    69,   591,    73,  -194,   375,   266,   404,  -194,  -194,
     266,   532,   535,   541,   607,  -194,    73,   266,   266,   266,
     560,   454,  -194,  -194,   230,   594,   236,   598,  -194,   573,
    -194,   549,  -194,   571,  -194,   602,  -194,   603,   450,  -194,
     580,   582,   121,    47,   532,    39,  -194,   118,   139,    18,
    -194,  -194,   290,   170,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,  -194,   140,   145,
     318,   343,   356,   553,   586,   599,   627,   620,  -194,   628,
     629,   652,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   630,
     683,   631,   651,   655,   656,   657,  -194,   455,   665,  -194,
    -194,   459,   433,   433,  -194,  -194,  -194,   184,   184,   184,
     184,   563,   563,   384,   639,   658,   659,   660,   661,   653,
     266,   266,   640,   694,  -194,   643,   697,  -194,   648,   701,
     645,   266,  -194,  -194,  -194,  -194,  -194,   266,  -194,  -194,
    -194,  -194,   538,   538,   371,   409,   670,   650,   672,   654,
     421,   649,   662,   155,   665,   405,   484,   -28,   674,  -194,
     676,  -194,   677,   460,  -194,   711,  -194,   538,   679,   680,
    -194,  -194,  -194,  -194,   663,   664,   511,  -194,  -194,  -194,
    -194,   681,  -194
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
       0,   153,   154,    68,     0,   155,     0,     0,     0,     0,
       0,     0,   130,   131,     0,     0,     0,     0,    99,     0,
     103,     0,    22,     0,    20,     0,    21,     0,     0,    52,
       0,    90,     0,    64,     0,     0,    69,     0,     0,     0,
     139,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,    71,    98,    75,    25,    23,    24,    28,    93,
       0,    65,     0,     0,     0,     0,   156,     0,    97,   140,
     159,     0,   134,   135,   136,   137,   138,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,   126,     0,     0,
       0,     0,   118,   119,   120,   121,   157,     0,   158,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,    96,     0,     0,     0,     0,   114,
       0,   115,     0,     0,    94,     0,    66,     0,     0,     0,
     133,   132,   116,   117,     0,     0,     0,   128,   129,    29,
      92,     0,   127
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,  -194,  -194,  -194,   705,  -194,  -194,  -194,  -194,
     633,  -194,   592,  -194,  -194,   715,  -194,  -194,   685,  -194,
    -194,  -194,   695,  -194,   -95,    33,  -148,  -145,  -106,  -194,
     689,  -194,   -63,   636,  -104,  -149,  -194,   584,  -194,  -194,
     467,  -193,   546,    72,  -194,  -168,  -183,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -117,  -194
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    14,    15,    21,    72,    88,    89,
      90,   134,   135,   338,     5,     6,    20,    42,    43,    44,
      18,    28,    29,    34,    35,    48,   221,   222,   223,    36,
      37,   122,    76,    77,    78,   121,   145,   146,   147,   166,
     307,   149,   184,    19,   100,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   308,   225
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   197,   240,   182,   241,   234,    13,    84,   380,   230,
     231,    16,   236,    17,   136,    31,   144,    96,   353,     1,
     210,   214,   215,    24,   216,   168,    22,    65,    67,   181,
     181,   235,   182,   182,   117,    68,   217,   181,   237,   136,
     182,   144,   183,   170,    32,    33,   218,   240,   240,    66,
      66,    25,    26,    27,     4,   224,   142,    66,    39,    49,
      50,   151,   207,   254,   153,   257,   255,   155,   258,   261,
     219,   183,   183,   253,   220,   306,   168,   167,   278,   183,
     168,   279,   181,   181,   208,   182,   182,    40,    41,   199,
      38,   201,   252,   203,   170,   123,   303,     4,   170,   260,
     237,   126,   129,   262,   302,   183,   209,   183,    57,    58,
     280,   281,   282,    11,    24,   124,    39,   287,     8,   291,
     183,   127,   130,     7,   183,   183,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,    91,
      92,   248,    51,    26,    27,    40,    41,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   214,   215,   304,   216,   168,    10,   235,
     384,   301,   240,   240,   365,   366,   101,    92,   217,   264,
     265,   266,   267,   268,    13,   170,   305,   325,   218,    30,
     237,   235,   326,   240,   181,   181,   237,   182,   182,   386,
      45,   373,    54,   354,   355,   376,    46,   181,   181,    47,
     182,   182,   219,    31,   363,    62,   220,   310,    63,   181,
     364,    53,   182,   214,   215,    55,   216,   168,   181,   214,
     215,   182,   216,   168,   116,    92,   183,   183,   217,   108,
      60,   285,   133,    33,   217,   170,   286,   289,   218,   183,
     183,   170,   290,    81,   218,    93,    82,    64,    94,   214,
     215,   183,   216,   168,   157,   140,    92,   109,   110,   111,
     183,    73,   219,    61,   217,    73,   220,    73,   219,    69,
      85,   170,   220,    70,   218,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,    31,   143,
      74,    75,    71,   163,    74,    75,    74,    75,   219,    86,
      87,    80,   220,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,    97,   133,    33,    98,
     102,   104,   106,   103,   105,   107,    83,   309,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,    95,   327,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     328,   276,   132,   137,   138,   103,   105,   107,   167,   167,
      79,   168,   168,   329,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   169,   367,    99,
     170,   259,   171,   115,   209,   114,   167,   162,    92,   168,
     266,   267,   268,   118,   173,   174,   175,   119,   377,   378,
     176,   177,   120,   178,   169,   179,   180,   170,   167,   171,
     125,   168,   128,   198,    92,   131,   368,   200,    92,   139,
     172,   173,   174,   175,   202,    92,   169,   176,   177,   170,
     178,   171,   179,   180,   243,    92,   245,    92,   167,   148,
     141,   168,   150,   173,   174,   175,   247,    92,   152,   176,
     177,   154,   178,   284,   179,   180,   169,   298,    92,   170,
     159,   171,   346,   347,   165,   167,   348,   347,   168,   156,
     124,   127,   160,   173,   174,   175,   130,   161,   196,   176,
     177,   379,   178,   169,   179,   180,   170,   204,   171,   205,
     212,   206,   167,   211,   209,   168,   213,   226,   227,   228,
     173,   174,   175,   229,   232,   391,   176,   177,   233,   178,
     169,   179,   180,   170,   167,   171,   242,   168,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   173,   174,   175,
     238,   244,   169,   176,   177,   170,   178,   171,   179,   180,
     246,   249,   250,   235,   251,   256,   237,   263,   288,   173,
     174,   175,   292,   293,   294,   283,   177,   295,   178,   330,
     179,   180,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   296,   297,
     299,   300,   331,   277,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   332,   334,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   333,   335,   336,   340,   342,   337,   339,
     341,   343,   344,   345,   349,   350,   351,   356,   357,   353,
     358,   359,   360,   352,   361,   362,   369,   370,   371,   374,
     381,   372,   382,   383,   385,   387,   388,   392,   389,    23,
      12,   375,   112,    52,   390,    56,   158,    59,   113,   164,
     311,   239
};

static const yytype_int16 yycheck[] =
{
     148,   150,   185,   148,   197,    35,     4,    70,    36,   177,
     178,    31,    35,    33,   109,     4,   120,    80,    46,    19,
     168,     3,     4,     4,     6,     7,    24,    36,    36,   177,
     178,    61,   177,   178,    97,    36,    18,   185,    61,   134,
     185,   145,   148,    25,    33,    34,    28,   230,   231,    58,
      58,    32,    33,    34,     4,   172,   119,    58,     4,    26,
      27,   124,    36,   211,   127,   213,   211,   130,   213,   217,
      52,   177,   178,     4,    56,    57,     7,     4,   226,   185,
       7,   226,   230,   231,    58,   230,   231,    33,    34,   152,
      18,   154,   209,   156,    25,    36,    57,     4,    25,   216,
      61,    36,    36,   220,    57,   211,    59,   213,    36,    55,
     227,   228,   229,    20,     4,    56,     4,   234,    23,   236,
     226,    56,    56,     0,   230,   231,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    57,
      58,   204,    32,    33,    34,    33,    34,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     3,     4,    57,     6,     7,    54,    61,
     373,    60,   365,   366,   352,   353,    57,    58,    18,     5,
       6,     7,     8,     9,     4,    25,    57,    57,    28,    37,
      61,    61,    57,   386,   352,   353,    61,   352,   353,   377,
      54,   360,     7,   330,   331,    60,     4,   365,   366,     7,
     365,   366,    52,     4,   341,    56,    56,    57,    59,   377,
     347,    56,   377,     3,     4,     4,     6,     7,   386,     3,
       4,   386,     6,     7,    57,    58,   352,   353,    18,     4,
       4,    21,    33,    34,    18,    25,    26,    21,    28,   365,
     366,    25,    26,     4,    28,     4,     7,     4,     7,     3,
       4,   377,     6,     7,    55,    57,    58,    32,    33,    34,
     386,     4,    52,    31,    18,     4,    56,     4,    52,    57,
       4,    25,    56,    56,    28,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     4,    32,
      33,    34,    36,    32,    33,    34,    33,    34,    52,    33,
      34,    56,    56,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    56,    33,    34,    59,
       4,     4,     4,     7,     7,     7,    54,    57,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    60,    57,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      57,    17,     4,     4,     4,     7,     7,     7,     4,     4,
       3,     7,     7,    57,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    22,    57,     4,
      25,    56,    27,    59,    59,     4,     4,    57,    58,     7,
       7,     8,     9,     3,    39,    40,    41,    56,    43,    44,
      45,    46,    31,    48,    22,    50,    51,    25,     4,    27,
       4,     7,     4,    57,    58,     4,    57,    57,    58,     3,
      38,    39,    40,    41,    57,    58,    22,    45,    46,    25,
      48,    27,    50,    51,    57,    58,    57,    58,     4,    29,
      60,     7,    54,    39,    40,    41,    57,    58,    56,    45,
      46,    56,    48,    49,    50,    51,    22,    57,    58,    25,
       4,    27,    57,    58,     4,     4,    57,    58,     7,    56,
      56,    56,    60,    39,    40,    41,    56,    59,    55,    45,
      46,    47,    48,    22,    50,    51,    25,    56,    27,     3,
      61,    59,     4,    56,    59,     7,    56,    56,    56,    56,
      39,    40,    41,    56,    36,    44,    45,    46,    36,    48,
      22,    50,    51,    25,     4,    27,    36,     7,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    39,    40,    41,
      30,    36,    22,    45,    46,    25,    48,    27,    50,    51,
      36,    60,     3,    61,     4,     4,    61,    56,     4,    39,
      40,    41,     4,    30,    55,    45,    46,    36,    48,    56,
      50,    51,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    36,    36,
      60,    59,    56,    36,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    56,    36,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    56,    56,    56,     3,    36,    36,    59,
      59,    36,    36,    36,    36,    36,    36,    57,     4,    46,
      57,     4,    54,    42,     3,    60,    36,    57,    36,    60,
      36,    57,    36,    36,     3,    36,    36,    36,    55,    14,
       5,    59,    89,    28,    60,    36,   134,    42,    92,   145,
     263,   185
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
      56,    88,    89,    90,   118,   119,    56,    56,    56,    56,
     107,   107,    36,    36,    35,    61,    35,    61,    30,   104,
     108,   103,    36,    57,    36,    57,    36,    57,    94,    60,
       3,     4,   118,     4,    88,    89,     4,    88,    89,    56,
     118,    88,   118,    56,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    36,    88,    89,
     118,   118,   118,    45,    49,    21,    26,   118,     4,    21,
      26,   118,     4,    30,    55,    36,    36,    36,    57,    60,
      59,    60,    57,    57,    57,    57,    57,   102,   118,    57,
      57,   102,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,    57,    57,    57,    57,    57,
      56,    56,    56,    56,    36,    56,    56,    36,    75,    59,
       3,    59,    36,    36,    36,    36,    57,    58,    57,    36,
      36,    36,    42,    46,   118,   118,    57,     4,    57,     4,
      54,     3,    60,   118,   118,   107,   107,    57,    57,    36,
      57,    36,    57,    97,    60,    59,    60,    43,    44,    47,
      36,    36,    36,    36,   103,     3,   107,    36,    36,    55,
      60,    44,    36
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
#line 1749 "exprtree.tab.c"
    break;

  case 3:
#line 136 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1755 "exprtree.tab.c"
    break;

  case 4:
#line 137 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1761 "exprtree.tab.c"
    break;

  case 7:
#line 145 "exprtree.y"
                                            { PrintClassTable(); }
#line 1767 "exprtree.tab.c"
    break;

  case 11:
#line 153 "exprtree.y"
              {
              currentClass = CInstall((yyvsp[0].str), NULL);
              if (currentClass == NULL) {
                  fprintf(stderr, "Error: class '%s' is already defined or cannot be installed\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1779 "exprtree.tab.c"
    break;

  case 12:
#line 159 "exprtree.y"
                                                                                       {
              if (!Class_CheckMethodDefinitions(currentClass)) {
                  exit(1);
              }
              currentClass = NULL;
              currentMethod = NULL;
          }
#line 1791 "exprtree.tab.c"
    break;

  case 15:
#line 172 "exprtree.y"
                              {
               if (Class_Finstall(currentClass, "int", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "int", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1803 "exprtree.tab.c"
    break;

  case 16:
#line 179 "exprtree.y"
                              {
               if (Class_Finstall(currentClass, "str", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "str", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1815 "exprtree.tab.c"
    break;

  case 17:
#line 186 "exprtree.y"
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
#line 1835 "exprtree.tab.c"
    break;

  case 20:
#line 207 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("int"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1847 "exprtree.tab.c"
    break;

  case 21:
#line 214 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("str"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1859 "exprtree.tab.c"
    break;

  case 22:
#line 221 "exprtree.y"
                                                    {
                    Typetable *returnType = TLookup((yyvsp[-5].str));
                    if (returnType == NULL || Class_Minstall(currentClass, (yyvsp[-4].str), returnType, (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1872 "exprtree.tab.c"
    break;

  case 23:
#line 229 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("int")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1884 "exprtree.tab.c"
    break;

  case 24:
#line 236 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("str")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1896 "exprtree.tab.c"
    break;

  case 25:
#line 243 "exprtree.y"
                                                        {
                    Typetable *returnType = TLookup((yyvsp[-6].str));
                    if (returnType == NULL || !IsUserDefinedType(returnType) ||
                        Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(returnType), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid pointer return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1910 "exprtree.tab.c"
    break;

  case 28:
#line 258 "exprtree.y"
                                            {
                    currentMethod = Class_MatchMethodDefinition(currentClass, (yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
                    if (currentMethod == NULL) exit(1);
                    BeginMethodScope((yyvsp[-1].paramlist), currentClass);
                }
#line 1920 "exprtree.tab.c"
    break;

  case 29:
#line 262 "exprtree.y"
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
#line 1935 "exprtree.tab.c"
    break;

  case 32:
#line 277 "exprtree.y"
                 {
            if (TBeginDefinition((yyvsp[-1].str)) == NULL) {
                fprintf(stderr, "Error: type '%s' is already defined or cannot be started\n", (yyvsp[-1].str));
                exit(1);
            }
        }
#line 1946 "exprtree.tab.c"
    break;

  case 33:
#line 282 "exprtree.y"
                            {
            TFinishDefinition(TCurrentDefinition());
        }
#line 1954 "exprtree.tab.c"
    break;

  case 36:
#line 291 "exprtree.y"
                                   {
              Typetable *owner = TCurrentDefinition();
              if (owner == NULL ||
                  FInstall(owner, (yyvsp[-1].str), (yyvsp[-2].type), owner->size) == NULL) {
                  fprintf(stderr, "Error: duplicate field '%s' or invalid field declaration\n", (yyvsp[-1].str));
                  exit(1);
              }
              owner->size++;
          }
#line 1968 "exprtree.tab.c"
    break;

  case 37:
#line 302 "exprtree.y"
                { (yyval.type) = TLookup("int"); }
#line 1974 "exprtree.tab.c"
    break;

  case 38:
#line 303 "exprtree.y"
                { (yyval.type) = TLookup("str"); }
#line 1980 "exprtree.tab.c"
    break;

  case 39:
#line 304 "exprtree.y"
               {
              (yyval.type) = TLookup((yyvsp[0].str));
              if ((yyval.type) == NULL || !IsUserDefinedType((yyval.type))) {
                  fprintf(stderr, "Error: field type '%s' is undefined or not declarable here\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1992 "exprtree.tab.c"
    break;

  case 44:
#line 317 "exprtree.y"
                              {
           InstallGlobalVarList((yyvsp[-1].varlist), TLookup("int"), NULL);
       }
#line 2000 "exprtree.tab.c"
    break;

  case 45:
#line 320 "exprtree.y"
                             {
           InstallGlobalVarList((yyvsp[-1].varlist), TLookup("str"), NULL);
       }
#line 2008 "exprtree.tab.c"
    break;

  case 46:
#line 323 "exprtree.y"
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
#line 2026 "exprtree.tab.c"
    break;

  case 47:
#line 338 "exprtree.y"
               { (yyval.type) = TLookup("int"); }
#line 2032 "exprtree.tab.c"
    break;

  case 48:
#line 339 "exprtree.y"
               { (yyval.type) = TLookup("str"); }
#line 2038 "exprtree.tab.c"
    break;

  case 49:
#line 340 "exprtree.y"
               {
             Typetable *resolvedType = TLookup((yyvsp[0].str));
             if (resolvedType == NULL || !IsUserDefinedType(resolvedType)) {
                 fprintf(stderr, "Error: type '%s' is not defined yet\n", (yyvsp[0].str));
                 exit(1);
             }
             (yyval.type) = resolvedType;
         }
#line 2051 "exprtree.tab.c"
    break;

  case 50:
#line 350 "exprtree.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 2057 "exprtree.tab.c"
    break;

  case 51:
#line 351 "exprtree.y"
                     {
          (yyval.type) = PointerType((yyvsp[-1].type));
          if ((yyval.type) == NULL) {
              fprintf(stderr, "Error: pointer types are supported only for int and str\n");
              exit(1);
          }
      }
#line 2069 "exprtree.tab.c"
    break;

  case 52:
#line 367 "exprtree.y"
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
#line 2090 "exprtree.tab.c"
    break;

  case 53:
#line 383 "exprtree.y"
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
#line 2107 "exprtree.tab.c"
    break;

  case 54:
#line 395 "exprtree.y"
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
#line 2127 "exprtree.tab.c"
    break;

  case 55:
#line 410 "exprtree.y"
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
#line 2143 "exprtree.tab.c"
    break;

  case 56:
#line 421 "exprtree.y"
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
#line 2164 "exprtree.tab.c"
    break;

  case 57:
#line 437 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 2179 "exprtree.tab.c"
    break;

  case 58:
#line 447 "exprtree.y"
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
#line 2197 "exprtree.tab.c"
    break;

  case 59:
#line 460 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 2211 "exprtree.tab.c"
    break;

  case 60:
#line 469 "exprtree.y"
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
#line 2235 "exprtree.tab.c"
    break;

  case 61:
#line 488 "exprtree.y"
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
#line 2254 "exprtree.tab.c"
    break;

  case 62:
#line 502 "exprtree.y"
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
#line 2272 "exprtree.tab.c"
    break;

  case 63:
#line 515 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 2286 "exprtree.tab.c"
    break;

  case 64:
#line 527 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 2294 "exprtree.tab.c"
    break;

  case 65:
#line 530 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2303 "exprtree.tab.c"
    break;

  case 66:
#line 534 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2311 "exprtree.tab.c"
    break;

  case 67:
#line 537 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 2319 "exprtree.tab.c"
    break;

  case 68:
#line 542 "exprtree.y"
                     { (yyval.node) = makeFieldValueNode((yyvsp[0].node)); }
#line 2325 "exprtree.tab.c"
    break;

  case 69:
#line 544 "exprtree.y"
                           {
                 (yyval.node) = makeMemberAccessNode(makeIdNode("self"), (yyvsp[0].str));
             }
#line 2333 "exprtree.tab.c"
    break;

  case 70:
#line 547 "exprtree.y"
                              {
                 (yyval.node) = makeMemberAccessNode((yyvsp[-2].node), (yyvsp[0].str));
             }
#line 2341 "exprtree.tab.c"
    break;

  case 71:
#line 550 "exprtree.y"
                           {
                 (yyval.node) = makeMemberAccessNode((yyvsp[-2].node), (yyvsp[0].str));
             }
#line 2349 "exprtree.tab.c"
    break;

  case 74:
#line 557 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 2358 "exprtree.tab.c"
    break;

  case 75:
#line 560 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 2368 "exprtree.tab.c"
    break;

  case 76:
#line 566 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 2383 "exprtree.tab.c"
    break;

  case 77:
#line 576 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 2391 "exprtree.tab.c"
    break;

  case 78:
#line 579 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 2399 "exprtree.tab.c"
    break;

  case 79:
#line 583 "exprtree.y"
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
#line 2419 "exprtree.tab.c"
    break;

  case 80:
#line 598 "exprtree.y"
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
#line 2436 "exprtree.tab.c"
    break;

  case 81:
#line 611 "exprtree.y"
                {
              (yyval.paramtype).type = TLookup("int");
              (yyval.paramtype).classType = NULL;
          }
#line 2445 "exprtree.tab.c"
    break;

  case 82:
#line 615 "exprtree.y"
                {
              (yyval.paramtype).type = TLookup("str");
              (yyval.paramtype).classType = NULL;
          }
#line 2454 "exprtree.tab.c"
    break;

  case 83:
#line 619 "exprtree.y"
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
#line 2471 "exprtree.tab.c"
    break;

  case 88:
#line 637 "exprtree.y"
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
#line 2486 "exprtree.tab.c"
    break;

  case 89:
#line 648 "exprtree.y"
                      { (yyval.paramtype) = (yyvsp[0].paramtype); }
#line 2492 "exprtree.tab.c"
    break;

  case 90:
#line 650 "exprtree.y"
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
#line 2516 "exprtree.tab.c"
    break;

  case 91:
#line 669 "exprtree.y"
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
#line 2532 "exprtree.tab.c"
    break;

  case 92:
#line 680 "exprtree.y"
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
#line 2549 "exprtree.tab.c"
    break;

  case 93:
#line 692 "exprtree.y"
                     {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2562 "exprtree.tab.c"
    break;

  case 94:
#line 700 "exprtree.y"
                                 {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2576 "exprtree.tab.c"
    break;

  case 95:
#line 709 "exprtree.y"
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
#line 2593 "exprtree.tab.c"
    break;

  case 96:
#line 723 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2599 "exprtree.tab.c"
    break;

  case 97:
#line 724 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2605 "exprtree.tab.c"
    break;

  case 98:
#line 727 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2611 "exprtree.tab.c"
    break;

  case 99:
#line 728 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2617 "exprtree.tab.c"
    break;

  case 100:
#line 730 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2623 "exprtree.tab.c"
    break;

  case 101:
#line 733 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2631 "exprtree.tab.c"
    break;

  case 102:
#line 735 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TLookup("int"), "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2643 "exprtree.tab.c"
    break;

  case 103:
#line 755 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2651 "exprtree.tab.c"
    break;

  case 104:
#line 758 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2659 "exprtree.tab.c"
    break;

  case 105:
#line 762 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2667 "exprtree.tab.c"
    break;

  case 106:
#line 765 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2675 "exprtree.tab.c"
    break;

  case 107:
#line 768 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2683 "exprtree.tab.c"
    break;

  case 108:
#line 771 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2691 "exprtree.tab.c"
    break;

  case 109:
#line 774 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2699 "exprtree.tab.c"
    break;

  case 110:
#line 777 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2707 "exprtree.tab.c"
    break;

  case 111:
#line 780 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2715 "exprtree.tab.c"
    break;

  case 112:
#line 783 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2723 "exprtree.tab.c"
    break;

  case 113:
#line 786 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2731 "exprtree.tab.c"
    break;

  case 114:
#line 789 "exprtree.y"
                                              {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2739 "exprtree.tab.c"
    break;

  case 115:
#line 792 "exprtree.y"
                                           {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2747 "exprtree.tab.c"
    break;

  case 116:
#line 795 "exprtree.y"
                                               {
        (yyval.node) = makeClassAllocNode((yyvsp[-6].node), (yyvsp[-2].str));
    }
#line 2755 "exprtree.tab.c"
    break;

  case 117:
#line 798 "exprtree.y"
                                            {
        (yyval.node) = makeClassAllocNode((yyvsp[-6].node), (yyvsp[-2].str));
    }
#line 2763 "exprtree.tab.c"
    break;

  case 118:
#line 801 "exprtree.y"
                                {
        (yyval.node) = makeFreeNode(makeIdNode((yyvsp[-2].str)));
    }
#line 2771 "exprtree.tab.c"
    break;

  case 119:
#line 804 "exprtree.y"
                                   {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2779 "exprtree.tab.c"
    break;

  case 120:
#line 807 "exprtree.y"
                                        {
        (yyval.node) = makeClassDeleteNode((yyvsp[-2].node));
    }
#line 2787 "exprtree.tab.c"
    break;

  case 121:
#line 810 "exprtree.y"
                                     {
        (yyval.node) = makeClassDeleteNode((yyvsp[-2].node));
    }
#line 2795 "exprtree.tab.c"
    break;

  case 122:
#line 814 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2803 "exprtree.tab.c"
    break;

  case 123:
#line 817 "exprtree.y"
                                   {
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2811 "exprtree.tab.c"
    break;

  case 124:
#line 822 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2819 "exprtree.tab.c"
    break;

  case 125:
#line 826 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2827 "exprtree.tab.c"
    break;

  case 126:
#line 829 "exprtree.y"
                               {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2835 "exprtree.tab.c"
    break;

  case 127:
#line 834 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2843 "exprtree.tab.c"
    break;

  case 128:
#line 837 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2851 "exprtree.tab.c"
    break;

  case 129:
#line 841 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2859 "exprtree.tab.c"
    break;

  case 130:
#line 845 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2867 "exprtree.tab.c"
    break;

  case 131:
#line 849 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2875 "exprtree.tab.c"
    break;

  case 132:
#line 853 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2883 "exprtree.tab.c"
    break;

  case 133:
#line 857 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2891 "exprtree.tab.c"
    break;

  case 134:
#line 861 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2899 "exprtree.tab.c"
    break;

  case 135:
#line 864 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2907 "exprtree.tab.c"
    break;

  case 136:
#line 867 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2915 "exprtree.tab.c"
    break;

  case 137:
#line 870 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2923 "exprtree.tab.c"
    break;

  case 138:
#line 873 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2931 "exprtree.tab.c"
    break;

  case 139:
#line 876 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2939 "exprtree.tab.c"
    break;

  case 140:
#line 879 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2947 "exprtree.tab.c"
    break;

  case 141:
#line 882 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2955 "exprtree.tab.c"
    break;

  case 142:
#line 885 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2963 "exprtree.tab.c"
    break;

  case 143:
#line 888 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2971 "exprtree.tab.c"
    break;

  case 144:
#line 891 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2979 "exprtree.tab.c"
    break;

  case 145:
#line 894 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2987 "exprtree.tab.c"
    break;

  case 146:
#line 897 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2995 "exprtree.tab.c"
    break;

  case 147:
#line 900 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3003 "exprtree.tab.c"
    break;

  case 148:
#line 903 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3011 "exprtree.tab.c"
    break;

  case 149:
#line 906 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 3019 "exprtree.tab.c"
    break;

  case 150:
#line 909 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 3027 "exprtree.tab.c"
    break;

  case 151:
#line 912 "exprtree.y"
             {
        (yyval.node) = makeNullNode();
    }
#line 3035 "exprtree.tab.c"
    break;

  case 152:
#line 915 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 3043 "exprtree.tab.c"
    break;

  case 153:
#line 918 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3051 "exprtree.tab.c"
    break;

  case 154:
#line 921 "exprtree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3059 "exprtree.tab.c"
    break;

  case 155:
#line 924 "exprtree.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3067 "exprtree.tab.c"
    break;

  case 156:
#line 927 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 3075 "exprtree.tab.c"
    break;

  case 157:
#line 930 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 3083 "exprtree.tab.c"
    break;

  case 158:
#line 934 "exprtree.y"
                                             {
                  (yyval.node) = makeMethodCallNode((yyvsp[-3].node), (yyvsp[-1].node));
              }
#line 3091 "exprtree.tab.c"
    break;

  case 159:
#line 937 "exprtree.y"
                                     {
                  (yyval.node) = makeMethodCallNode((yyvsp[-2].node), NULL);
              }
#line 3099 "exprtree.tab.c"
    break;


#line 3103 "exprtree.tab.c"

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
#line 942 "exprtree.y"


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
