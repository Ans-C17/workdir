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

#line 86 "exprtree.tab.c"

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
    T_BEGIN = 274,
    T_END = 275,
    DECL = 276,
    ENDDECL = 277,
    INT = 278,
    STR = 279,
    ASSIGN = 280,
    SEMICOLON = 281,
    MAIN = 282,
    RETURN = 283,
    READ = 284,
    WRITE = 285,
    IF = 286,
    THEN = 287,
    ELSE = 288,
    ENDIF = 289,
    WHILE = 290,
    DO = 291,
    ENDWHILE = 292,
    REPEAT = 293,
    UNTIL = 294,
    BREAK = 295,
    CONTINUE = 296,
    STRING = 297,
    UMINUS = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "exprtree.y"

    tnode* node;
    char* str;
    int num;
    VarList* varlist;
    Paramstruct* paramlist;

#line 190 "exprtree.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


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
      47,    48,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    89,    91,    91,    93,    93,    95,
     120,   123,   127,   128,   140,   155,   166,   179,   188,   204,
     214,   227,   236,   255,   269,   282,   294,   297,   301,   304,
     308,   308,   310,   310,   319,   329,   332,   336,   345,   354,
     354,   356,   356,   358,   362,   381,   395,   396,   399,   400,
     402,   405,   405,   415,   419,   436,   439,   443,   446,   449,
     452,   455,   458,   461,   464,   467,   471,   475,   479,   483,
     486,   490,   494,   498,   502,   506,   510,   513,   516,   519,
     522,   525,   528,   531,   534,   537,   540,   543,   546,   549,
     552,   555,   558,   561,   564,   567,   570
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "OR", "AND", "ADDRESS",
  "T_BEGIN", "T_END", "DECL", "ENDDECL", "INT", "STR", "ASSIGN",
  "SEMICOLON", "MAIN", "RETURN", "READ", "WRITE", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK",
  "CONTINUE", "STRING", "UMINUS", "','", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "FType", "VarList", "Variable", "FDefBlock", "FDef", "$@1", "ParamList",
  "Param", "LdeclBlock", "LDecList", "LDecl", "IdList", "ArgList", "Body",
  "ReturnStmt", "MainBlock", "$@2", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt",
  "ContinueStmt", "RepeatStmt", "DoWhileStmt", "E", YY_NULLPTR
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
     295,   296,   297,   298,    44,    91,    93,    40,    41,   123,
     125
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   365,   108,   -21,    30,     3,   -76,    -7,    16,    46,
       8,     9,    32,    49,   454,   454,    61,    94,    78,   384,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   119,   -76,    24,    89,   -76,   -21,   131,
     142,     3,   -76,   -76,    82,   -76,   -76,    16,    82,    82,
      82,   473,   130,   -76,   -76,    82,   121,   -76,   -76,   -76,
      35,   154,   -25,   109,   -76,   117,   -76,   -76,   -76,    81,
      82,    16,   -76,    82,   -76,   298,   124,   102,   202,   215,
     134,   135,   510,   -76,   176,    25,   136,   -76,    40,   138,
      25,    36,   -76,   -76,   228,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,   139,   159,
     162,   157,   210,    82,    82,   -76,   147,    67,   -19,   -76,
      25,    88,   243,   -76,    29,   -76,    57,   554,   -76,   144,
     144,   -76,   -76,   -76,    85,    85,    85,    85,   260,   260,
     247,   190,    82,   -76,   -76,   454,   454,   272,   285,   203,
     -76,   245,    25,   -76,    58,   248,    25,   227,   254,   -76,
      82,   -76,   340,   330,   403,    -2,   290,   314,   -76,   -76,
     -76,   273,    77,    25,   132,   299,   274,   554,   -76,   454,
     295,   296,   -76,   -76,   278,   280,   -76,    79,   -76,   322,
     153,   -76,   419,   277,   254,   438,   -76,   -76,   -76,   325,
     -76,   -76,   -23,   -76,   -76,    82,   309,   419,   -76,   299,
     304,   286,   -76,   327,   532,   -76,   315,   288,   -76,   -76,
     -76,   -76,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       6,    10,    11,     0,     8,     0,     0,     1,    10,    12,
       0,     0,    31,     3,     0,    29,    54,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,    55,     5,     7,
      19,     0,     0,     0,    13,     0,    30,     2,    91,    26,
       0,     0,    92,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,    36,    21,     9,     0,     0,
      36,     0,    81,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,    35,
      36,    18,     0,    51,     0,    95,     0,    47,    82,    76,
      77,    78,    79,    80,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    66,    67,     0,     0,     0,     0,    17,
      37,     0,     0,    23,     0,     0,    36,    20,     0,    32,
       0,    96,     0,     0,     0,     0,     0,     0,    38,    34,
      25,     0,     0,    36,     0,     0,     0,    46,    28,     0,
       0,     0,    75,    74,     0,    16,    22,     0,    40,     0,
       0,    42,     0,     0,     0,     0,    70,    71,    15,     0,
      24,    45,     0,    39,    41,     0,     0,     0,    52,     0,
       0,     0,    43,     0,     0,    49,     0,     0,    69,    14,
      44,    50,    48,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   303,     0,   -76,   -76,    -1,   -76,
     300,   -76,   -75,   187,   146,   -76,   152,   -76,   -76,   149,
     155,    11,   -76,    -6,   -15,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    33,    34,   117,    40,    62,    74,    41,
      42,   176,   118,   119,   175,   190,   191,   202,   126,   193,
     206,     6,   158,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    87,    35,   212,    57,    39,    36,    45,    51,    52,
      77,    78,    79,    18,    18,   124,    43,    82,    18,    88,
       7,   213,     1,     8,   182,   152,    38,    32,    60,   153,
      37,    61,    92,    35,   146,    94,    57,    57,    44,    68,
      69,    39,    70,     8,   121,   154,    76,   122,    31,    32,
      18,    18,    67,   127,    71,    47,    48,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      93,   150,    46,   152,   151,   147,   148,   159,    72,    49,
      84,   172,    85,    73,   125,    68,    69,    53,    70,     8,
      95,    96,    97,    98,    99,     1,    50,     2,   187,     3,
      71,   160,   152,    55,   162,   161,   170,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      54,   152,   177,   152,    72,   186,    44,   200,    91,    73,
      30,    31,    32,   155,     7,   156,    63,     8,    64,   163,
     164,    58,    31,    32,    18,    18,    65,    83,    57,    57,
     110,    97,    98,    99,   188,    31,    32,    89,    86,    10,
      11,    12,    18,    18,    90,    13,    14,   214,    15,    81,
      16,    17,   109,   195,   189,   203,    31,    32,    18,   116,
      57,   113,   114,   120,   142,   143,   207,   123,   144,   145,
     189,    18,    57,   149,    18,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    18,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   146,   157,   167,   168,
     111,   171,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   112,   107,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   173,   174,   128,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   183,   184,   192,   185,
     165,   196,   197,   194,   198,   199,   201,   208,   211,   215,
     218,   220,   219,   166,     7,   222,    59,     8,   223,   169,
     209,    66,   204,     0,   108,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   217,    10,
      11,    12,   216,   179,   180,    13,    14,     0,    15,     7,
      16,    17,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,   178,     0,     7,     0,
       0,     8,     0,     0,    10,    11,    12,     0,     0,     0,
      13,    14,     0,    15,    56,    16,    17,     7,     0,     0,
       8,     0,     0,    10,    11,    12,     0,     0,     0,    13,
      14,     0,    15,     7,    16,    17,     8,     0,     0,     0,
       0,     0,    10,    11,    12,     0,     0,     0,    13,    14,
     181,    15,     7,    16,    17,     8,     0,   205,    10,    11,
      12,     0,     0,     0,    13,    14,     0,    15,     7,    16,
      17,     8,     0,     0,     0,     0,     0,    10,    11,    12,
       0,     0,   210,    13,    14,     0,    15,     7,    16,    17,
       8,     0,     0,    10,    11,    12,     0,     0,     0,    13,
      14,     0,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,     0,     0,    80,    14,
       0,    15,     0,    16,    17,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,   115,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,   221,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107
};

static const yytype_int16 yycheck[] =
{
       1,    26,     2,    26,    19,     5,    27,     8,    14,    15,
      48,    49,    50,    14,    15,    90,     5,    55,    19,    44,
       4,    44,    19,     7,    26,    44,    23,    24,     4,    48,
       0,     7,    70,    33,    36,    73,    51,    52,    45,     3,
       4,    41,     6,     7,     4,   120,    47,     7,    23,    24,
      51,    52,    41,    91,    18,    47,    47,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      71,     4,    26,    44,     7,   113,   114,    48,    42,    47,
      45,   156,    47,    47,    48,     3,     4,    26,     6,     7,
       5,     6,     7,     8,     9,    19,    47,    21,   173,    23,
      18,    44,    44,    25,   142,    48,    48,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      26,    44,   160,    44,    42,    48,    45,    48,    47,    47,
      22,    23,    24,    45,     4,    47,    47,     7,     7,   145,
     146,    22,    23,    24,   145,   146,     4,    26,   163,   164,
      48,     7,     8,     9,    22,    23,    24,    48,     4,    29,
      30,    31,   163,   164,    47,    35,    36,   205,    38,    39,
      40,    41,    48,   179,   174,    22,    23,    24,   179,     3,
     195,    47,    47,    47,    45,    26,   192,    49,    26,    32,
     190,   192,   207,    46,   195,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   207,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    36,     4,    45,     4,
      48,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    48,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    47,    21,    48,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    26,     3,    19,    46,
      48,    26,    26,    49,    46,    45,     4,    50,     3,    20,
      26,     4,    46,    48,     4,    20,    33,     7,    50,   152,
     194,    41,   190,    -1,    46,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,   209,    29,
      30,    31,   207,    33,    34,    35,    36,    -1,    38,     4,
      40,    41,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    46,    -1,     4,    -1,
      -1,     7,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    -1,    38,    20,    40,    41,     4,    -1,    -1,
       7,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,    35,
      36,    -1,    38,     4,    40,    41,     7,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      37,    38,     4,    40,    41,     7,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    36,    -1,    38,     4,    40,
      41,     7,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    -1,    34,    35,    36,    -1,    38,     4,    40,    41,
       7,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,    35,
      36,    -1,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      -1,    38,    -1,    40,    41,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    21,    23,    52,    53,    72,     4,     7,    20,
      29,    30,    31,    35,    36,    38,    40,    41,    59,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      22,    23,    24,    54,    55,    56,    27,     0,    23,    56,
      57,    60,    61,    72,    45,    59,    26,    47,    47,    47,
      47,    74,    74,    26,    26,    25,    20,    75,    22,    55,
       4,     7,    58,    47,     7,     4,    61,    72,     3,     4,
       6,    18,    42,    47,    59,    85,    59,    85,    85,    85,
      35,    39,    85,    26,    45,    47,     4,    26,    44,    48,
      47,    47,    85,    59,    85,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    46,    48,
      48,    48,    48,    47,    47,    26,     3,    56,    63,    64,
      47,     4,     7,    49,    63,    48,    69,    85,    48,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    45,    26,    26,    32,    36,    85,    85,    46,
       4,     7,    44,    48,    63,    45,    47,     4,    73,    48,
      44,    48,    85,    74,    74,    48,    48,    45,     4,    64,
      48,     3,    63,    47,    21,    65,    62,    85,    46,    33,
      34,    37,    26,    26,     3,    46,    48,    63,    22,    56,
      66,    67,    19,    70,    49,    74,    26,    26,    46,    45,
      48,     4,    68,    22,    67,    28,    71,    74,    50,    65,
      34,     3,    26,    44,    85,    20,    71,    70,    26,    46,
       4,    26,    20,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    62,    61,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      71,    73,    72,    72,    72,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    77,    78,    79,
      79,    80,    81,    82,    83,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     1,     2,     9,     7,     6,     4,     3,     1,
       4,     2,     6,     4,     7,     5,     1,     4,     7,     2,
       2,     1,     0,    10,     3,     1,     0,     2,     3,     3,
       2,     2,     1,     3,     3,     1,     3,     1,     4,     3,
       3,     0,     9,     4,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     4,    10,
       8,     8,     2,     2,     7,     7,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     3,     4
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
#line 87 "exprtree.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 1584 "exprtree.tab.c"
    break;

  case 3:
#line 88 "exprtree.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 1590 "exprtree.tab.c"
    break;

  case 4:
#line 89 "exprtree.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 1596 "exprtree.tab.c"
    break;

  case 9:
#line 95 "exprtree.y"
                               {
    // if i have like 
    // int a, b;
    // int c, d; (in two lines)
    // the varlist gon be like two diff linked lists, and each time reduction is done, we traverse thru
    VarList* temp = (yyvsp[-1].varlist);

    while (temp != NULL) {
        int varType = (yyvsp[-2].num);
        if (temp->isPointer) {
            if ((yyvsp[-2].num) == TYPE_INT) varType = TYPE_INT_PTR;
            else if ((yyvsp[-2].num) == TYPE_STR) varType = TYPE_STR_PTR;
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
}
#line 1625 "exprtree.tab.c"
    break;

  case 10:
#line 120 "exprtree.y"
           {
        (yyval.num) = TYPE_INT;
    }
#line 1633 "exprtree.tab.c"
    break;

  case 11:
#line 123 "exprtree.y"
          {
        (yyval.num) = TYPE_STR;
    }
#line 1641 "exprtree.tab.c"
    break;

  case 12:
#line 127 "exprtree.y"
             { (yyval.num) = (yyvsp[0].num); }
#line 1647 "exprtree.tab.c"
    break;

  case 13:
#line 128 "exprtree.y"
                 {
          (yyval.num) = ((yyvsp[-1].num) == TYPE_INT) ? TYPE_INT_PTR : TYPE_STR_PTR;
      }
#line 1655 "exprtree.tab.c"
    break;

  case 14:
#line 140 "exprtree.y"
                                                 {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-6].str);
        newVar->rows = (yyvsp[-4].num);
        newVar->cols = (yyvsp[-1].num);
        newVar->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-8].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-8].varlist);
    }
#line 1675 "exprtree.tab.c"
    break;

  case 15:
#line 155 "exprtree.y"
                                 { 
        VarList *newVar = calloc(1, sizeof(struct VarList));
        newVar->name = (yyvsp[-6].str);
        newVar->rows = (yyvsp[-4].num);
        newVar->cols = (yyvsp[-1].num);
        newVar->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1691 "exprtree.tab.c"
    break;

  case 16:
#line 166 "exprtree.y"
                                 { 
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num); // array ayond size koduk
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-5].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 1709 "exprtree.tab.c"
    break;

  case 17:
#line 179 "exprtree.y"
                     {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num);
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1723 "exprtree.tab.c"
    break;

  case 18:
#line 188 "exprtree.y"
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
#line 1744 "exprtree.tab.c"
    break;

  case 19:
#line 204 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 1759 "exprtree.tab.c"
    break;

  case 20:
#line 214 "exprtree.y"
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
#line 1777 "exprtree.tab.c"
    break;

  case 21:
#line 227 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1791 "exprtree.tab.c"
    break;

  case 22:
#line 236 "exprtree.y"
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
#line 1815 "exprtree.tab.c"
    break;

  case 23:
#line 255 "exprtree.y"
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
#line 1834 "exprtree.tab.c"
    break;

  case 24:
#line 269 "exprtree.y"
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
#line 1852 "exprtree.tab.c"
    break;

  case 25:
#line 282 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 1866 "exprtree.tab.c"
    break;

  case 26:
#line 294 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 1874 "exprtree.tab.c"
    break;

  case 27:
#line 297 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 1883 "exprtree.tab.c"
    break;

  case 28:
#line 301 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1891 "exprtree.tab.c"
    break;

  case 29:
#line 304 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 1899 "exprtree.tab.c"
    break;

  case 32:
#line 310 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].num), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 1908 "exprtree.tab.c"
    break;

  case 33:
#line 313 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].num), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 1918 "exprtree.tab.c"
    break;

  case 34:
#line 319 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 1933 "exprtree.tab.c"
    break;

  case 35:
#line 329 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 1941 "exprtree.tab.c"
    break;

  case 36:
#line 332 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 1949 "exprtree.tab.c"
    break;

  case 37:
#line 336 "exprtree.y"
                {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = (yyvsp[-1].num);
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 1963 "exprtree.tab.c"
    break;

  case 38:
#line 345 "exprtree.y"
                  {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = ((yyvsp[-2].num) == TYPE_INT) ? TYPE_INT_PTR : TYPE_STR_PTR;
        p->next = NULL;
        (yyval.paramlist) = p;
    }
#line 1976 "exprtree.tab.c"
    break;

  case 43:
#line 358 "exprtree.y"
                              {
        InstallLocalVariables((yyvsp[-1].varlist), (yyvsp[-2].num));
    }
#line 1984 "exprtree.tab.c"
    break;

  case 44:
#line 362 "exprtree.y"
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
#line 2008 "exprtree.tab.c"
    break;

  case 45:
#line 381 "exprtree.y"
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
#line 2025 "exprtree.tab.c"
    break;

  case 46:
#line 395 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2031 "exprtree.tab.c"
    break;

  case 47:
#line 396 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2037 "exprtree.tab.c"
    break;

  case 48:
#line 399 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2043 "exprtree.tab.c"
    break;

  case 49:
#line 400 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2049 "exprtree.tab.c"
    break;

  case 50:
#line 402 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2055 "exprtree.tab.c"
    break;

  case 51:
#line 405 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2063 "exprtree.tab.c"
    break;

  case 52:
#line 407 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TYPE_INT, "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2075 "exprtree.tab.c"
    break;

  case 53:
#line 415 "exprtree.y"
                                    {
        root = (yyvsp[-2].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2084 "exprtree.tab.c"
    break;

  case 54:
#line 419 "exprtree.y"
                              {
        root = NULL; // no syntax tree as T_BEGIN & T_END are non-terminals
        (yyval.node) = NULL;
    }
#line 2093 "exprtree.tab.c"
    break;

  case 55:
#line 436 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2101 "exprtree.tab.c"
    break;

  case 56:
#line 439 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2109 "exprtree.tab.c"
    break;

  case 57:
#line 443 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2117 "exprtree.tab.c"
    break;

  case 58:
#line 446 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2125 "exprtree.tab.c"
    break;

  case 59:
#line 449 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2133 "exprtree.tab.c"
    break;

  case 60:
#line 452 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2141 "exprtree.tab.c"
    break;

  case 61:
#line 455 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2149 "exprtree.tab.c"
    break;

  case 62:
#line 458 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2157 "exprtree.tab.c"
    break;

  case 63:
#line 461 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2165 "exprtree.tab.c"
    break;

  case 64:
#line 464 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2173 "exprtree.tab.c"
    break;

  case 65:
#line 467 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2181 "exprtree.tab.c"
    break;

  case 66:
#line 471 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2189 "exprtree.tab.c"
    break;

  case 67:
#line 475 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2197 "exprtree.tab.c"
    break;

  case 68:
#line 479 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2205 "exprtree.tab.c"
    break;

  case 69:
#line 483 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2213 "exprtree.tab.c"
    break;

  case 70:
#line 486 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2221 "exprtree.tab.c"
    break;

  case 71:
#line 490 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2229 "exprtree.tab.c"
    break;

  case 72:
#line 494 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2237 "exprtree.tab.c"
    break;

  case 73:
#line 498 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2245 "exprtree.tab.c"
    break;

  case 74:
#line 502 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2253 "exprtree.tab.c"
    break;

  case 75:
#line 506 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2261 "exprtree.tab.c"
    break;

  case 76:
#line 510 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2269 "exprtree.tab.c"
    break;

  case 77:
#line 513 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2277 "exprtree.tab.c"
    break;

  case 78:
#line 516 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2285 "exprtree.tab.c"
    break;

  case 79:
#line 519 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2293 "exprtree.tab.c"
    break;

  case 80:
#line 522 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2301 "exprtree.tab.c"
    break;

  case 81:
#line 525 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2309 "exprtree.tab.c"
    break;

  case 82:
#line 528 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2317 "exprtree.tab.c"
    break;

  case 83:
#line 531 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2325 "exprtree.tab.c"
    break;

  case 84:
#line 534 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2333 "exprtree.tab.c"
    break;

  case 85:
#line 537 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2341 "exprtree.tab.c"
    break;

  case 86:
#line 540 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2349 "exprtree.tab.c"
    break;

  case 87:
#line 543 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2357 "exprtree.tab.c"
    break;

  case 88:
#line 546 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2365 "exprtree.tab.c"
    break;

  case 89:
#line 549 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2373 "exprtree.tab.c"
    break;

  case 90:
#line 552 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2381 "exprtree.tab.c"
    break;

  case 91:
#line 555 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 2389 "exprtree.tab.c"
    break;

  case 92:
#line 558 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 2397 "exprtree.tab.c"
    break;

  case 93:
#line 561 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 2405 "exprtree.tab.c"
    break;

  case 94:
#line 564 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2413 "exprtree.tab.c"
    break;

  case 95:
#line 567 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 2421 "exprtree.tab.c"
    break;

  case 96:
#line 570 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2429 "exprtree.tab.c"
    break;


#line 2433 "exprtree.tab.c"

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
#line 574 "exprtree.y"


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
