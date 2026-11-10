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
    TUPLE = 284,
    READ = 285,
    WRITE = 286,
    IF = 287,
    THEN = 288,
    ELSE = 289,
    ENDIF = 290,
    WHILE = 291,
    DO = 292,
    ENDWHILE = 293,
    REPEAT = 294,
    UNTIL = 295,
    BREAK = 296,
    CONTINUE = 297,
    STRING = 298,
    UMINUS = 299
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
    Field* fieldlist;

#line 192 "exprtree.tab.c"

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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   574

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


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
      45,    46,     2,     2,    47,     2,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    94,    95,    97,    97,    99,    99,   102,
     126,   138,   141,   146,   147,   159,   175,   187,   201,   211,
     227,   237,   250,   259,   272,   281,   300,   316,   322,   324,
     331,   339,   348,   353,   363,   366,   370,   373,   376,   380,
     380,   383,   383,   393,   403,   406,   410,   419,   429,   437,
     450,   450,   452,   452,   455,   458,   462,   476,   495,   510,
     511,   515,   516,   518,   522,   522,   532,   536,   553,   556,
     560,   563,   566,   569,   572,   575,   578,   581,   584,   588,
     592,   596,   600,   603,   607,   611,   615,   619,   623,   628,
     631,   634,   637,   640,   643,   646,   649,   652,   655,   658,
     661,   664,   667,   670,   673,   676,   679,   682,   685,   688
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
  "SEMICOLON", "MAIN", "RETURN", "TUPLE", "READ", "WRITE", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK",
  "CONTINUE", "STRING", "UMINUS", "'('", "')'", "','", "'['", "']'", "'.'",
  "'{'", "'}'", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl",
  "Type", "FType", "VarList", "FieldList", "FieldDecl", "TupleVarList",
  "Variable", "FDefBlock", "FDef", "$@1", "ParamList", "Param",
  "LdeclBlock", "LDecList", "LDecl", "IdList", "ArgList", "Body",
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
     295,   296,   297,   298,   299,    40,    41,    44,    91,    93,
      46,   123,   125
};
# endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,   328,    22,   -12,    10,    11,   -73,   143,   114,     2,
      -6,    -2,    44,    71,   443,   443,   100,   119,     8,   359,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   136,   109,   -73,   121,    99,   -73,   -12,
     149,   156,    11,   -73,   -73,   116,   192,   -73,   -73,   114,
     116,   116,   116,   462,   373,   -73,   -73,   116,   172,   -73,
     271,   -73,   -73,   106,   205,   -20,   171,   -73,   272,   -73,
     -73,   -73,   -28,   116,   114,   -73,   116,   -73,    52,   -73,
     213,   214,   228,   241,   273,   275,   500,   -73,    31,    31,
     318,   278,   -73,   161,   235,    31,    84,   -73,   -73,   256,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   253,   299,   300,   291,   290,   116,   116,
     -73,   324,    25,   -73,   163,    89,   -73,   281,    31,   141,
     327,   -73,   125,   -73,   154,   544,   -73,   199,   199,   -73,
     -73,   -73,    91,    91,    91,    91,   170,   170,   557,   270,
     116,   -73,   -73,   443,   443,   283,   298,   -73,   181,    31,
     285,   330,   -73,    31,   288,   157,    31,   334,   293,   319,
     -73,   -73,   116,    98,   315,   390,   -21,   313,   -73,   337,
     -18,   -73,   294,   -73,   -73,   339,   -73,   164,   304,    31,
     126,   336,   310,   544,   -73,   443,   342,   345,   -73,   -73,
     -73,   -73,   183,   314,   323,   -73,   325,   167,   -73,   370,
     188,   140,   -73,   412,   326,   319,   426,   -73,   -73,   -73,
     371,   378,   -73,   379,   -73,   181,   -73,   372,   -15,   -73,
     -73,   116,   363,   412,   -73,   336,   358,   -73,   338,   343,
      -7,    -5,   -73,   381,   522,   -73,   366,   341,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       6,    11,    12,     0,     0,     8,     0,     0,     1,    11,
      13,     0,     0,    40,     3,     0,     0,    38,    67,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,    68,
       0,     5,     7,    20,     0,     0,     0,    14,     0,    39,
       2,   104,    34,     0,     0,   105,     0,   107,     0,    37,
       0,     0,     0,     0,     0,     0,     0,    66,     0,    45,
       0,    22,     9,     0,     0,    45,     0,    94,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
      81,     0,     0,    28,     0,     0,    44,     0,    45,    19,
       0,    64,     0,   108,     0,    60,    95,    89,    90,    91,
      92,    93,    96,    97,    98,    99,   100,   101,   102,   103,
       0,    79,    80,     0,     0,     0,     0,    29,     0,     0,
      46,     0,    26,     0,    18,     0,    45,     0,    21,     0,
      41,   109,     0,     0,     0,     0,     0,     0,    32,     0,
       0,    27,     0,    47,    43,     0,    24,     0,     0,    45,
       0,     0,     0,    59,    36,     0,     0,     0,    88,    87,
      33,    10,     0,    48,     0,    25,    17,     0,    51,     0,
       0,     0,    53,     0,     0,     0,     0,    83,    84,    30,
       0,     0,    16,     0,    23,     0,    58,     0,     0,    50,
      52,     0,     0,     0,    65,     0,     0,    31,     0,     0,
       0,     0,    54,     0,     0,    62,     0,     0,    82,    49,
      15,    56,    55,    57,    63,    61,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,   354,     7,   -73,   -73,   -73,   240,
     177,    -1,   -73,   364,   -73,   -72,   244,   193,   -73,   200,
     190,   -73,   189,   185,    -4,   -73,   -11,   -17,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -26
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    34,    35,   124,    41,    65,   122,   123,
     180,    77,    42,    43,   192,   125,   126,   191,   211,   212,
     228,   134,   214,   232,     6,   169,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    44,    59,    53,    54,   198,    92,    47,   201,    36,
      38,   242,    40,    18,    18,    37,   154,    96,    18,   251,
      45,   252,    46,   132,    81,    82,    83,    93,    48,   202,
       1,    86,   243,    57,    39,    32,    59,    59,    70,    49,
     202,    36,   243,    50,    30,    31,    32,    97,    80,    40,
      99,    33,    18,    18,    31,    32,   165,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     135,   158,   159,    98,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    71,    72,    51,
      73,     8,   155,   156,   187,   121,   100,   101,   102,   103,
     104,   113,    74,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    52,   207,     7,    71,
      72,     8,    73,     8,   173,    63,    55,    75,    64,    76,
     133,    61,    31,    32,    74,   162,   163,     1,    33,     2,
      60,     3,   174,   175,    66,    56,   193,   194,   208,    31,
      32,    89,    18,    18,    90,   209,    67,    59,    59,    75,
      68,    76,   229,    31,    32,   129,   121,   160,   130,   209,
     161,   170,   163,    18,    18,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   216,   178,   166,   219,   179,   167,
     220,    45,   226,    46,    18,   227,    79,   210,    87,    59,
     171,   172,   233,   186,   163,   244,   102,   103,   104,    91,
     205,   163,    18,   224,   163,    18,    59,    94,   210,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    18,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
     115,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   116,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   131,   117,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   150,   136,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    88,    95,   118,     7,
     119,   127,     8,   128,   153,   151,   152,   154,   157,   176,
     164,   168,     7,   182,   183,     8,   185,   188,   189,   199,
     190,   200,   204,   203,   177,    10,    11,    12,     9,   195,
     196,    13,    14,   206,    15,   213,    16,    17,    10,    11,
      12,   215,   221,     7,    13,    14,     8,    15,   217,    16,
      17,   218,   222,   223,   225,   237,   226,     7,   234,    58,
       8,   238,   239,   245,   248,   253,   255,   249,    62,    10,
      11,    12,   250,   256,     7,    13,    14,     8,    15,   181,
      16,    17,   240,    10,    11,    12,    69,   184,   235,    13,
      14,   230,    15,    85,    16,    17,     7,   241,   246,     8,
      10,    11,    12,     0,   247,     0,    13,    14,   197,    15,
       7,    16,    17,     8,     0,     0,     0,     0,     0,     0,
     231,     0,    10,    11,    12,     0,     0,     7,    13,    14,
       8,    15,     0,    16,    17,     0,    10,    11,    12,     0,
       0,   236,    13,    14,     0,    15,     7,    16,    17,     8,
       0,     0,     0,    10,    11,    12,     0,     0,     0,    13,
      14,     0,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,     0,     0,    84,    14,
       0,    15,     0,    16,    17,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   112
};

static const yytype_int16 yycheck[] =
{
       1,     5,    19,    14,    15,    26,    26,     8,    26,     2,
       0,    26,     5,    14,    15,    27,    37,    45,    19,    26,
      48,    26,    50,    95,    50,    51,    52,    47,    26,    47,
      19,    57,    47,    25,    23,    24,    53,    54,    42,    45,
      47,    34,    47,    45,    22,    23,    24,    73,    49,    42,
      76,    29,    53,    54,    23,    24,   128,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      96,    46,    47,    74,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     3,     4,    45,
       6,     7,   118,   119,   166,    88,     5,     6,     7,     8,
       9,    49,    18,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    45,   189,     4,     3,
       4,     7,     6,     7,   150,     4,    26,    43,     7,    45,
      46,    22,    23,    24,    18,    46,    47,    19,    29,    21,
       4,    23,   153,   154,    45,    26,   172,    49,    22,    23,
      24,    45,   153,   154,    48,    29,     7,   174,   175,    43,
       4,    45,    22,    23,    24,     4,   159,     4,     7,    29,
       7,    46,    47,   174,   175,     5,     6,     7,     8,     9,
      10,    11,    12,    13,   195,     4,    45,     4,     7,    48,
       7,    48,     4,    50,   195,     7,     4,   190,    26,   216,
      46,    47,   213,    46,    47,   231,     7,     8,     9,     4,
      46,    47,   213,    46,    47,   216,   233,    46,   211,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   233,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    46,
      46,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    46,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    51,    46,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    48,    46,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    45,    45,    45,     4,
      45,     3,     7,    45,    33,    26,    26,    37,     4,    46,
      49,     4,     4,    48,     4,     7,    48,     3,    45,    26,
      21,     4,     3,    49,    46,    30,    31,    32,    20,    34,
      35,    36,    37,    49,    39,    19,    41,    42,    30,    31,
      32,    51,    48,     4,    36,    37,     7,    39,    26,    41,
      42,    26,    49,    48,     4,     4,     4,     4,    52,    20,
       7,     3,     3,    20,    26,     4,    20,    49,    34,    30,
      31,    32,    49,    52,     4,    36,    37,     7,    39,   159,
      41,    42,   225,    30,    31,    32,    42,   163,   215,    36,
      37,   211,    39,    40,    41,    42,     4,   227,   233,     7,
      30,    31,    32,    -1,   235,    -1,    36,    37,    38,    39,
       4,    41,    42,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    -1,    -1,     4,    36,    37,
       7,    39,    -1,    41,    42,    -1,    30,    31,    32,    -1,
      -1,    35,    36,    37,    -1,    39,     4,    41,    42,     7,
      -1,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    42,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    21,    23,    54,    55,    77,     4,     7,    20,
      30,    31,    32,    36,    37,    39,    41,    42,    64,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      22,    23,    24,    29,    56,    57,    58,    27,     0,    23,
      58,    59,    65,    66,    77,    48,    50,    64,    26,    45,
      45,    45,    45,    79,    79,    26,    26,    25,    20,    80,
       4,    22,    57,     4,     7,    60,    45,     7,     4,    66,
      77,     3,     4,     6,    18,    43,    45,    64,    90,     4,
      64,    90,    90,    90,    36,    40,    90,    26,    45,    45,
      48,     4,    26,    47,    46,    45,    45,    90,    64,    90,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    49,    46,    46,    46,    46,    45,    45,
      26,    58,    61,    62,    58,    68,    69,     3,    45,     4,
       7,    51,    68,    46,    74,    90,    46,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      48,    26,    26,    33,    37,    90,    90,     4,    46,    47,
       4,     7,    46,    47,    49,    68,    45,    48,     4,    78,
      46,    46,    47,    90,    79,    79,    46,    46,     4,     7,
      63,    62,    48,     4,    69,    48,    46,    68,     3,    45,
      21,    70,    67,    90,    49,    34,    35,    38,    26,    26,
       4,    26,    47,    49,     3,    46,    49,    68,    22,    29,
      58,    71,    72,    19,    75,    51,    79,    26,    26,     4,
       7,    48,    49,    48,    46,     4,     4,     7,    73,    22,
      72,    28,    76,    79,    52,    70,    35,     4,     3,     3,
      63,    73,    26,    47,    90,    20,    76,    75,    26,    49,
      49,    26,    26,     4,    26,    20,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    67,    66,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    78,    77,    77,    77,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    83,    84,    84,    85,    86,    87,    88,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       7,     1,     1,     1,     2,     9,     7,     6,     4,     3,
       1,     4,     2,     7,     5,     6,     4,     3,     1,     2,
       3,     4,     1,     2,     1,     4,     7,     3,     2,     2,
       1,     0,    10,     3,     1,     0,     2,     3,     4,     7,
       3,     2,     2,     1,     3,     4,     4,     3,     1,     3,
       1,     4,     3,     3,     0,     9,     4,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,    10,     8,     8,     2,     2,     7,     7,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     1,     3,     4
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
#line 93 "exprtree.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 1599 "exprtree.tab.c"
    break;

  case 3:
#line 94 "exprtree.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 1605 "exprtree.tab.c"
    break;

  case 4:
#line 95 "exprtree.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 1611 "exprtree.tab.c"
    break;

  case 9:
#line 102 "exprtree.y"
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
            Install(temp->name, varType, 0, 0, 0, 0, temp->paramlist,
                    nextFunctionLabel++);
        } else {
            Install(temp->name, varType, temp->size, temp->rows, temp->cols, temp->isArray,
                    NULL, -1);
        }
        temp = temp->next;
    }
}
#line 1640 "exprtree.tab.c"
    break;

  case 10:
#line 126 "exprtree.y"
                                                        {
        int tupleType = InstallTupleType((yyvsp[-5].str), (yyvsp[-3].fieldlist));
        VarList *var = (yyvsp[-1].varlist);

        while (var != NULL) {
            int type = var->isPointer ? TuplePointerType(tupleType) : tupleType;
            Install(var->name, type, var->isPointer ? 1 : TypeSize(tupleType),
                    0, 0, 0, NULL, -1);
            var = var->next;
        }
    }
#line 1656 "exprtree.tab.c"
    break;

  case 11:
#line 138 "exprtree.y"
           {
        (yyval.num) = TYPE_INT;
    }
#line 1664 "exprtree.tab.c"
    break;

  case 12:
#line 141 "exprtree.y"
          {
        (yyval.num) = TYPE_STR;
    }
#line 1672 "exprtree.tab.c"
    break;

  case 13:
#line 146 "exprtree.y"
             { (yyval.num) = (yyvsp[0].num); }
#line 1678 "exprtree.tab.c"
    break;

  case 14:
#line 147 "exprtree.y"
                 {
          (yyval.num) = ((yyvsp[-1].num) == TYPE_INT) ? TYPE_INT_PTR : TYPE_STR_PTR;
      }
#line 1686 "exprtree.tab.c"
    break;

  case 15:
#line 159 "exprtree.y"
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
#line 1707 "exprtree.tab.c"
    break;

  case 16:
#line 175 "exprtree.y"
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
#line 1724 "exprtree.tab.c"
    break;

  case 17:
#line 187 "exprtree.y"
                                 { 
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num); // array ayond size koduk
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-5].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 1743 "exprtree.tab.c"
    break;

  case 18:
#line 201 "exprtree.y"
                     {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1758 "exprtree.tab.c"
    break;

  case 19:
#line 211 "exprtree.y"
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
#line 1779 "exprtree.tab.c"
    break;

  case 20:
#line 227 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 1794 "exprtree.tab.c"
    break;

  case 21:
#line 237 "exprtree.y"
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
#line 1812 "exprtree.tab.c"
    break;

  case 22:
#line 250 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1826 "exprtree.tab.c"
    break;

  case 23:
#line 259 "exprtree.y"
                                           {
        VarList *newVar = calloc(1, sizeof(VarList));
        VarList *temp = (yyvsp[-6].varlist);

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);

        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-6].varlist);
    }
#line 1844 "exprtree.tab.c"
    break;

  case 24:
#line 272 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 1858 "exprtree.tab.c"
    break;

  case 25:
#line 281 "exprtree.y"
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
#line 1882 "exprtree.tab.c"
    break;

  case 26:
#line 300 "exprtree.y"
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
#line 1901 "exprtree.tab.c"
    break;

  case 27:
#line 316 "exprtree.y"
                                    {
        Field *tail = (yyvsp[-2].fieldlist);
        while (tail->next != NULL) tail = tail->next;
        tail->next = (yyvsp[0].fieldlist);
        (yyval.fieldlist) = (yyvsp[-2].fieldlist);
    }
#line 1912 "exprtree.tab.c"
    break;

  case 28:
#line 322 "exprtree.y"
                { (yyval.fieldlist) = (yyvsp[0].fieldlist); }
#line 1918 "exprtree.tab.c"
    break;

  case 29:
#line 324 "exprtree.y"
                    {
        Field *field = calloc(1, sizeof(Field));
        field->name = (yyvsp[0].str);
        field->type = (yyvsp[-1].num);
        (yyval.fieldlist) = field;
    }
#line 1929 "exprtree.tab.c"
    break;

  case 30:
#line 331 "exprtree.y"
                                   {
        VarList *var = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-2].varlist);
        var->name = (yyvsp[0].str);
        while (tail->next != NULL) tail = tail->next;
        tail->next = var;
        (yyval.varlist) = (yyvsp[-2].varlist);
    }
#line 1942 "exprtree.tab.c"
    break;

  case 31:
#line 339 "exprtree.y"
                              {
        VarList *var = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-3].varlist);
        var->name = (yyvsp[0].str);
        var->isPointer = 1;
        while (tail->next != NULL) tail = tail->next;
        tail->next = var;
        (yyval.varlist) = (yyvsp[-3].varlist);
    }
#line 1956 "exprtree.tab.c"
    break;

  case 32:
#line 348 "exprtree.y"
         {
        VarList *var = calloc(1, sizeof(VarList));
        var->name = (yyvsp[0].str);
        (yyval.varlist) = var;
    }
#line 1966 "exprtree.tab.c"
    break;

  case 33:
#line 353 "exprtree.y"
             {
        VarList *var = calloc(1, sizeof(VarList));
        var->name = (yyvsp[0].str);
        var->isPointer = 1;
        (yyval.varlist) = var;
    }
#line 1977 "exprtree.tab.c"
    break;

  case 34:
#line 363 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 1985 "exprtree.tab.c"
    break;

  case 35:
#line 366 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 1994 "exprtree.tab.c"
    break;

  case 36:
#line 370 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2002 "exprtree.tab.c"
    break;

  case 37:
#line 373 "exprtree.y"
                {
        (yyval.node) = makeFieldNode((yyvsp[-2].str), (yyvsp[0].str));
    }
#line 2010 "exprtree.tab.c"
    break;

  case 38:
#line 376 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 2018 "exprtree.tab.c"
    break;

  case 41:
#line 383 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].num), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 2027 "exprtree.tab.c"
    break;

  case 42:
#line 386 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].num), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 2037 "exprtree.tab.c"
    break;

  case 43:
#line 393 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 2052 "exprtree.tab.c"
    break;

  case 44:
#line 403 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 2060 "exprtree.tab.c"
    break;

  case 45:
#line 406 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 2068 "exprtree.tab.c"
    break;

  case 46:
#line 410 "exprtree.y"
                {
        Paramstruct *p = calloc(1, sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = (yyvsp[-1].num);
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 2082 "exprtree.tab.c"
    break;

  case 47:
#line 419 "exprtree.y"
                  {
        Paramstruct *p = calloc(1, sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = ((yyvsp[-2].num) == TYPE_INT) ? TYPE_INT_PTR : TYPE_STR_PTR;
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 2096 "exprtree.tab.c"
    break;

  case 48:
#line 429 "exprtree.y"
                      {
        Paramstruct *p = calloc(1, sizeof(Paramstruct));
        p->name = (yyvsp[-2].str);
        p->type = (yyvsp[-3].num);
        p->isArray = 1;
        (yyval.paramlist) = p;
    }
#line 2108 "exprtree.tab.c"
    break;

  case 49:
#line 437 "exprtree.y"
                                  {
        Paramstruct *p = calloc(1, sizeof(Paramstruct));
        p->name = (yyvsp[-5].str);
        p->type = (yyvsp[-6].num);
        p->isArray = 1;
        p->cols = (yyvsp[-1].num);
        if (p->cols <= 0) {
            fprintf(stderr, "Error: array parameter column count must be positive\n");
            exit(1);
        }
        (yyval.paramlist) = p;
    }
#line 2125 "exprtree.tab.c"
    break;

  case 54:
#line 455 "exprtree.y"
                              {
        InstallLocalVariables((yyvsp[-1].varlist), (yyvsp[-2].num));
    }
#line 2133 "exprtree.tab.c"
    break;

  case 55:
#line 458 "exprtree.y"
                                {
        int pointerType = ((yyvsp[-3].num) == TYPE_INT) ? TYPE_INT_PTR : TYPE_STR_PTR;
        InstallLocalVariables((yyvsp[-1].varlist), pointerType);
    }
#line 2142 "exprtree.tab.c"
    break;

  case 56:
#line 462 "exprtree.y"
                                      {
        int tupleType = TupleTypeLookup((yyvsp[-2].str));
        VarList *var = (yyvsp[-1].varlist);

        if (tupleType == -1) {
            fprintf(stderr, "Error: tuple type '%s' is not declared\n", (yyvsp[-2].str));
            exit(1);
        }
        while (var != NULL) {
            InstallLocalVariables(var, var->isPointer ? TuplePointerType(tupleType) : tupleType);
            var = var->next;
        }
    }
#line 2160 "exprtree.tab.c"
    break;

  case 57:
#line 476 "exprtree.y"
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
#line 2184 "exprtree.tab.c"
    break;

  case 58:
#line 495 "exprtree.y"
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
#line 2201 "exprtree.tab.c"
    break;

  case 59:
#line 510 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2207 "exprtree.tab.c"
    break;

  case 60:
#line 511 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2213 "exprtree.tab.c"
    break;

  case 61:
#line 515 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2219 "exprtree.tab.c"
    break;

  case 62:
#line 516 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2225 "exprtree.tab.c"
    break;

  case 63:
#line 518 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2231 "exprtree.tab.c"
    break;

  case 64:
#line 522 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2239 "exprtree.tab.c"
    break;

  case 65:
#line 524 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TYPE_INT, "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2251 "exprtree.tab.c"
    break;

  case 66:
#line 532 "exprtree.y"
                                    {
        root = (yyvsp[-2].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2260 "exprtree.tab.c"
    break;

  case 67:
#line 536 "exprtree.y"
                              {
        root = NULL; // no syntax tree as T_BEGIN & T_END are non-terminals
        (yyval.node) = NULL;
    }
#line 2269 "exprtree.tab.c"
    break;

  case 68:
#line 553 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2277 "exprtree.tab.c"
    break;

  case 69:
#line 556 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2285 "exprtree.tab.c"
    break;

  case 70:
#line 560 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2293 "exprtree.tab.c"
    break;

  case 71:
#line 563 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2301 "exprtree.tab.c"
    break;

  case 72:
#line 566 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2309 "exprtree.tab.c"
    break;

  case 73:
#line 569 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2317 "exprtree.tab.c"
    break;

  case 74:
#line 572 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2325 "exprtree.tab.c"
    break;

  case 75:
#line 575 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2333 "exprtree.tab.c"
    break;

  case 76:
#line 578 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2341 "exprtree.tab.c"
    break;

  case 77:
#line 581 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2349 "exprtree.tab.c"
    break;

  case 78:
#line 584 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2357 "exprtree.tab.c"
    break;

  case 79:
#line 588 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2365 "exprtree.tab.c"
    break;

  case 80:
#line 592 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2373 "exprtree.tab.c"
    break;

  case 81:
#line 596 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2381 "exprtree.tab.c"
    break;

  case 82:
#line 600 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2389 "exprtree.tab.c"
    break;

  case 83:
#line 603 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2397 "exprtree.tab.c"
    break;

  case 84:
#line 607 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2405 "exprtree.tab.c"
    break;

  case 85:
#line 611 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2413 "exprtree.tab.c"
    break;

  case 86:
#line 615 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2421 "exprtree.tab.c"
    break;

  case 87:
#line 619 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2429 "exprtree.tab.c"
    break;

  case 88:
#line 623 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2437 "exprtree.tab.c"
    break;

  case 89:
#line 628 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2445 "exprtree.tab.c"
    break;

  case 90:
#line 631 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2453 "exprtree.tab.c"
    break;

  case 91:
#line 634 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2461 "exprtree.tab.c"
    break;

  case 92:
#line 637 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2469 "exprtree.tab.c"
    break;

  case 93:
#line 640 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2477 "exprtree.tab.c"
    break;

  case 94:
#line 643 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2485 "exprtree.tab.c"
    break;

  case 95:
#line 646 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2493 "exprtree.tab.c"
    break;

  case 96:
#line 649 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2501 "exprtree.tab.c"
    break;

  case 97:
#line 652 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2509 "exprtree.tab.c"
    break;

  case 98:
#line 655 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2517 "exprtree.tab.c"
    break;

  case 99:
#line 658 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2525 "exprtree.tab.c"
    break;

  case 100:
#line 661 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2533 "exprtree.tab.c"
    break;

  case 101:
#line 664 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2541 "exprtree.tab.c"
    break;

  case 102:
#line 667 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2549 "exprtree.tab.c"
    break;

  case 103:
#line 670 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2557 "exprtree.tab.c"
    break;

  case 104:
#line 673 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 2565 "exprtree.tab.c"
    break;

  case 105:
#line 676 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 2573 "exprtree.tab.c"
    break;

  case 106:
#line 679 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 2581 "exprtree.tab.c"
    break;

  case 107:
#line 682 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2589 "exprtree.tab.c"
    break;

  case 108:
#line 685 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 2597 "exprtree.tab.c"
    break;

  case 109:
#line 688 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2605 "exprtree.tab.c"
    break;


#line 2609 "exprtree.tab.c"

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
#line 692 "exprtree.y"


/* Parse input, print semantic tables, then generate the saved function ASTs. */
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
