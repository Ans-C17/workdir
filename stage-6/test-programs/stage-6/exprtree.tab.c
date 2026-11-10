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
    TYPE = 274,
    ENDTYPE = 275,
    ALLOC = 276,
    FREE = 277,
    T_NULL = 278,
    T_BEGIN = 279,
    T_END = 280,
    DECL = 281,
    ENDDECL = 282,
    INT = 283,
    STR = 284,
    ASSIGN = 285,
    SEMICOLON = 286,
    MAIN = 287,
    RETURN = 288,
    READ = 289,
    WRITE = 290,
    IF = 291,
    THEN = 292,
    ELSE = 293,
    ENDIF = 294,
    WHILE = 295,
    DO = 296,
    ENDWHILE = 297,
    REPEAT = 298,
    UNTIL = 299,
    BREAK = 300,
    CONTINUE = 301,
    STRING = 302,
    UMINUS = 303
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
    Typetable* type;

#line 196 "exprtree.tab.c"

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
#define YYLAST   655

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


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
      54,    55,     2,     2,    53,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    95,    96,    99,   100,   103,   104,   108,
     108,   118,   119,   123,   131,   143,   166,   167,   168,   177,
     177,   179,   179,   182,   212,   213,   214,   224,   225,   241,
     257,   269,   284,   295,   311,   321,   334,   343,   362,   376,
     389,   401,   404,   408,   411,   421,   424,   427,   430,   435,
     435,   438,   438,   447,   457,   460,   464,   473,   486,   486,
     488,   488,   491,   495,   514,   525,   537,   545,   554,   568,
     569,   572,   573,   575,   579,   579,   601,   604,   609,   612,
     615,   618,   621,   624,   627,   630,   633,   642,   645,   654,
     657,   661,   664,   669,   673,   676,   681,   684,   688,   692,
     696,   700,   704,   709,   712,   715,   718,   721,   724,   727,
     730,   733,   736,   739,   742,   745,   748,   751,   754,   757,
     760,   763,   766,   769,   772,   775
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "OR", "AND", "ADDRESS",
  "TYPE", "ENDTYPE", "ALLOC", "FREE", "T_NULL", "T_BEGIN", "T_END", "DECL",
  "ENDDECL", "INT", "STR", "ASSIGN", "SEMICOLON", "MAIN", "RETURN", "READ",
  "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "REPEAT", "UNTIL", "BREAK", "CONTINUE", "STRING", "UMINUS", "'{'", "'}'",
  "'['", "']'", "','", "'('", "')'", "'.'", "$accept", "Program",
  "TypeDefBlock", "TypeDefList", "TypeDef", "$@1", "FieldDeclList",
  "FieldDecl", "FieldType", "GDeclBlock", "GDeclList", "GDecl", "TypeName",
  "FType", "VarList", "Variable", "Field", "FDefBlock", "FDef", "$@2",
  "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl", "IdList",
  "ArgList", "Body", "ReturnStmt", "MainBlock", "$@3", "Slist", "Stmt",
  "InputStmt", "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   123,
     125,    91,    93,    44,    40,    41,    46
};
# endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   119,    59,    79,    95,    -3,  -123,  -123,    42,   129,
      15,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    71,
    -123,     8,   116,   129,   164,   174,    15,  -123,  -123,    50,
    -123,  -123,    36,   178,    35,   187,  -123,   135,  -123,  -123,
    -123,  -123,  -123,     7,  -123,   251,   183,   105,   213,  -123,
     123,   219,   105,  -123,  -123,   -23,   290,   132,   186,  -123,
     105,    91,   339,  -123,   211,  -123,   341,   294,  -123,   382,
     105,  -123,   281,   384,   105,   334,   363,  -123,   338,   388,
    -123,  -123,  -123,   340,   282,   105,    97,   369,   346,    10,
     344,   347,  -123,   285,  -123,   393,   131,  -123,   437,   349,
     363,  -123,   397,  -123,   398,  -123,   351,    55,  -123,  -123,
     352,   147,   350,   125,   354,   356,   357,   358,   522,   522,
     374,   375,   -24,   -14,   389,   437,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,   369,   361,   365,
     406,  -123,   411,   125,  -123,   149,  -123,   133,   125,   147,
    -123,  -123,   125,   362,    46,   584,   147,   125,   125,   125,
     542,   457,  -123,  -123,    27,   431,   134,   125,   432,  -123,
     413,  -123,   387,   408,  -123,   390,   392,   342,    25,   362,
     182,    49,  -123,  -123,   188,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,  -123,    38,
     202,   201,   214,   265,   386,   391,   395,   597,  -123,   400,
     624,   355,  -123,  -123,  -123,  -123,   405,   459,   409,   434,
     435,  -123,   286,   637,  -123,   227,   227,  -123,  -123,  -123,
     254,   254,   254,   254,   239,   239,   304,   317,   436,   438,
     443,   426,   444,   125,   125,   420,  -123,   421,  -123,   439,
     483,   442,   125,  -123,  -123,   125,  -123,  -123,  -123,  -123,
     522,   522,   278,   291,   456,   458,   125,   452,   445,   368,
     637,   412,   477,   -17,   464,  -123,  -123,   416,  -123,   485,
    -123,   522,   474,   476,  -123,  -123,  -123,   462,   502,  -123,
    -123,  -123,   479,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     8,     1,     0,     0,
       0,     4,     9,     5,     7,    26,    20,    24,    25,     0,
      22,     0,     0,    24,    27,     0,     0,    50,     3,     0,
      19,    21,    34,     0,     0,     0,    28,     0,    49,     2,
      18,    16,    17,     0,    12,     0,     0,    55,    36,    23,
       0,     0,    55,    10,    11,     0,     0,     0,     0,    54,
      55,    33,     0,    74,     0,    13,     0,    32,    56,     0,
       0,    38,     0,     0,    55,    35,     0,    51,     0,     0,
      57,    53,    40,     0,     0,    55,     0,     0,     0,     0,
       0,    31,    37,     0,    59,     0,     0,    61,     0,     0,
       0,    14,     0,    30,     0,    39,    68,     0,    58,    60,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    75,     0,     0,     0,
       0,    62,     0,     0,    44,     0,   118,    41,     0,     0,
     120,   119,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,    99,   100,     0,     0,     0,     0,     0,    72,
       0,    76,     0,     0,    29,     0,    63,     0,    41,     0,
       0,     0,   108,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,    46,    71,    52,    15,    66,     0,    42,     0,
       0,   124,     0,    70,   109,   103,   104,   105,   106,   107,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,    95,    47,
       0,     0,     0,    89,    90,     0,   125,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
      69,     0,     0,     0,     0,    87,    88,     0,    67,     0,
      43,     0,     0,     0,   102,   101,    48,     0,     0,    97,
      98,    65,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,   503,  -123,  -123,   472,  -123,  -123,
    -123,   497,    -1,  -123,  -123,   -98,   -96,  -123,   495,  -123,
     180,   455,   427,  -123,   454,  -123,  -123,   394,   403,     0,
    -123,  -114,  -122,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    29,    43,    44,    45,    10,
      19,    20,    57,    25,    34,   153,   154,    26,    27,    88,
      58,    59,    87,    96,    97,   107,   222,    99,   124,    11,
      76,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,     4,   123,   171,   160,   161,   164,    21,    65,    24,
      28,    40,    32,   144,   284,    33,   166,    13,    21,    15,
     122,   122,   123,   123,   261,    24,    39,   122,    66,   123,
     146,   147,   165,   148,   111,    41,    42,   167,   171,   171,
       1,   101,   168,    23,    18,   149,    15,   179,   206,   180,
     150,   183,   146,   147,    40,   148,   111,    53,   199,     7,
     200,   102,   122,   122,   123,   123,    49,   149,   177,    16,
      17,    18,   150,   182,   151,    15,   143,   184,    41,    42,
     219,   152,   201,   202,   203,    95,   141,    46,    50,   207,
      47,   210,   211,   238,   165,    95,   151,   167,    30,    17,
      18,    15,   168,   152,   221,     8,   223,     9,   142,    15,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     4,    94,    17,    18,    61,   146,   147,
      62,   148,   111,    17,    18,    15,    68,   146,   147,    69,
     148,   111,    73,   149,    12,    74,   271,   272,   150,   171,
     171,   110,   149,   178,   111,   209,   111,   150,   108,    17,
      18,    22,   122,   122,   123,   123,   171,   288,   262,   263,
      35,    36,   151,   122,   122,   123,   123,   269,    37,   152,
     270,   151,    48,   122,   143,   123,    56,   181,   152,    52,
     122,   277,   123,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    64,   167,   187,   188,   189,   220,   168,    70,
      72,    71,    51,   224,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   167,    84,    55,   240,   239,   168,   185,
     186,   187,   188,   189,    70,    93,    77,    60,    63,   241,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     242,   197,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   273,    70,    70,    82,    92,    70,   255,
     105,   256,    67,    75,    78,    79,   274,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    80,    83,    85,    86,
      89,    90,    91,    98,   218,   100,   103,   106,   104,   136,
     138,   139,   140,   143,   145,   162,   163,   249,   156,   175,
     157,   158,   159,   173,   169,   176,   110,   174,   165,   111,
     280,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   112,   208,   212,   214,   213,   215,
     243,   110,   216,   217,   111,   244,   114,   115,   116,   245,
     281,   282,   117,   118,   247,   119,   250,   120,   121,   112,
     252,   110,   251,   260,   111,   253,   254,   257,   286,   258,
     113,   114,   115,   116,   259,   264,   265,   117,   118,   112,
     119,   110,   120,   121,   111,   261,   267,   275,   287,   276,
     266,   114,   115,   116,   268,   285,   279,   117,   118,   112,
     119,   205,   120,   121,   278,   289,   110,   290,    14,   111,
     293,   114,   115,   116,   291,    54,    31,   117,   118,   283,
     119,    38,   120,   121,   112,    81,   110,   137,   170,   111,
       0,   172,     0,     0,     0,     0,   114,   115,   116,     0,
       0,   292,   117,   118,   112,   119,   110,   120,   121,   111,
     109,     0,     0,     0,     0,     0,   114,   115,   116,     0,
       0,     0,   117,   118,   112,   119,     0,   120,   121,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,     0,
       0,     0,   204,   118,     0,   119,     0,   120,   121,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   248
};

static const yytype_int16 yycheck[] =
{
      98,     4,    98,   125,   118,   119,    30,     8,    31,    10,
      10,     4,     4,   111,    31,     7,    30,    20,    19,     4,
     118,   119,   118,   119,    41,    26,    26,   125,    51,   125,
       3,     4,    56,     6,     7,    28,    29,    51,   160,   161,
      19,    31,    56,    28,    29,    18,     4,   145,    21,   145,
      23,   149,     3,     4,     4,     6,     7,    50,   156,     0,
     156,    51,   160,   161,   160,   161,    31,    18,   143,    27,
      28,    29,    23,   148,    47,     4,    51,   152,    28,    29,
      55,    54,   157,   158,   159,    86,    31,    51,    53,   164,
      54,   166,   167,    55,    56,    96,    47,    51,    27,    28,
      29,     4,    56,    54,    55,    26,   181,    28,    53,     4,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,     4,    27,    28,    29,     4,     3,     4,
       7,     6,     7,    28,    29,     4,     4,     3,     4,     7,
       6,     7,    51,    18,    49,    54,   260,   261,    23,   271,
     272,     4,    18,     4,     7,    21,     7,    23,    27,    28,
      29,    32,   260,   261,   260,   261,   288,   281,   243,   244,
      54,     7,    47,   271,   272,   271,   272,   252,     4,    54,
     255,    47,     4,   281,    51,   281,     3,    54,    54,    54,
     288,   266,   288,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    52,    51,     7,     8,     9,    55,    56,    53,
      60,    55,    55,    55,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    51,    74,     4,    55,    55,    56,     5,
       6,     7,     8,     9,    53,    85,    55,    54,    49,    55,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      55,    17,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    55,    53,    53,    55,    55,    53,    53,
      55,    55,    52,     4,     3,    51,    55,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     4,     3,    54,    26,
      52,     3,    52,    24,    52,    49,    52,     4,    51,    50,
       3,     3,    51,    51,    54,    31,    31,    52,    54,     3,
      54,    54,    54,    52,    25,     4,     4,    52,    56,     7,
      52,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    22,     4,     4,    50,    25,    31,
      54,     4,    52,    51,     7,    54,    34,    35,    36,    54,
      38,    39,    40,    41,    54,    43,    51,    45,    46,    22,
      51,     4,     3,    37,     7,    31,    31,    31,    52,    31,
      33,    34,    35,    36,    31,    55,    55,    40,    41,    22,
      43,     4,    45,    46,     7,    41,     3,    31,     3,    31,
      51,    34,    35,    36,    52,    31,    51,    40,    41,    22,
      43,    44,    45,    46,    52,    31,     4,    31,     5,     7,
      31,    34,    35,    36,    52,    43,    19,    40,    41,    42,
      43,    26,    45,    46,    22,    70,     4,   100,   125,     7,
      -1,   137,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    39,    40,    41,    22,    43,     4,    45,    46,     7,
      96,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    22,    43,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    -1,    43,    -1,    45,    46,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    58,    59,     4,    60,    61,     0,    26,    28,
      66,    86,    49,    20,    61,     4,    27,    28,    29,    67,
      68,    69,    32,    28,    69,    70,    74,    75,    86,    62,
      27,    68,     4,     7,    71,    54,     7,     4,    75,    86,
       4,    28,    29,    63,    64,    65,    51,    54,     4,    31,
      53,    55,    54,    50,    64,     4,     3,    69,    77,    78,
      54,     4,     7,    49,    77,    31,    51,    52,     4,     7,
      53,    55,    77,    51,    54,     4,    87,    55,     3,    51,
       4,    78,    55,     3,    77,    54,    26,    79,    76,    52,
       3,    52,    55,    77,    27,    69,    80,    81,    24,    84,
      49,    31,    51,    52,    51,    55,     4,    82,    27,    81,
       4,     7,    22,    33,    34,    35,    36,    40,    41,    43,
      45,    46,    72,    73,    85,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    50,    79,     3,     3,
      51,    31,    53,    51,    72,    54,     3,     4,     6,    18,
      23,    47,    54,    72,    73,    99,    54,    54,    54,    54,
      88,    88,    31,    31,    30,    56,    30,    51,    56,    25,
      85,    89,    84,    52,    52,     3,     4,    99,     4,    72,
      73,    54,    99,    72,    99,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    31,    72,
      73,    99,    99,    99,    40,    44,    21,    99,     4,    21,
      99,    99,     4,    25,    50,    31,    52,    51,    52,    55,
      55,    55,    83,    99,    55,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    55,    55,
      55,    55,    55,    54,    54,    54,    31,    54,    31,    52,
      51,     3,    51,    31,    31,    53,    55,    31,    31,    31,
      37,    41,    99,    99,    55,    55,    51,     3,    52,    99,
      99,    88,    88,    55,    55,    31,    31,    99,    52,    51,
      52,    38,    39,    42,    31,    31,    52,     3,    88,    31,
      31,    52,    39,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    62,
      61,    63,    63,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    74,
      74,    76,    75,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    87,    86,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    92,    92,    93,    93,    94,    95,
      96,    97,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     6,     9,     1,     1,     1,     3,
       2,     2,     1,     3,     1,     1,     1,     1,     2,     9,
       7,     6,     4,     3,     1,     4,     2,     6,     4,     7,
       5,     1,     4,     7,     2,     3,     3,     4,     7,     2,
       1,     0,    10,     3,     1,     0,     2,     3,     3,     2,
       2,     1,     3,     3,     6,     9,     4,     7,     1,     3,
       1,     4,     3,     3,     0,     9,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     6,     5,
       5,     5,     5,     5,     4,     4,    10,     8,     8,     2,
       2,     7,     7,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     1,     1,     3,     4
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
#line 94 "exprtree.y"
                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1641 "exprtree.tab.c"
    break;

  case 3:
#line 95 "exprtree.y"
                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1647 "exprtree.tab.c"
    break;

  case 4:
#line 96 "exprtree.y"
                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1653 "exprtree.tab.c"
    break;

  case 9:
#line 108 "exprtree.y"
                 {
            if (TBeginDefinition((yyvsp[-1].str)) == NULL) {
                fprintf(stderr, "Error: type '%s' is already defined or cannot be started\n", (yyvsp[-1].str));
                exit(1);
            }
        }
#line 1664 "exprtree.tab.c"
    break;

  case 10:
#line 113 "exprtree.y"
                            {
            TFinishDefinition(TCurrentDefinition());
        }
#line 1672 "exprtree.tab.c"
    break;

  case 13:
#line 123 "exprtree.y"
                                   {
              Typetable *owner = TCurrentDefinition();
              if (owner == NULL || FInstall(owner, (yyvsp[-1].str), (yyvsp[-2].type), owner->size) == NULL) {
                  fprintf(stderr, "Error: duplicate field '%s' or invalid field declaration\n", (yyvsp[-1].str));
                  exit(1);
              }
              owner->size++;
          }
#line 1685 "exprtree.tab.c"
    break;

  case 14:
#line 131 "exprtree.y"
                                               {
              Typetable *owner = TCurrentDefinition();
              Fieldlist *field;
              if ((yyvsp[-2].num) <= 0 || owner == NULL ||
                  (field = FInstall(owner, (yyvsp[-4].str), (yyvsp[-5].type), owner->size)) == NULL) {
                  fprintf(stderr, "Error: invalid or duplicate array field '%s'\n", (yyvsp[-4].str));
                  exit(1);
              }
              field->isArray = 1;
              field->size = (yyvsp[-2].num);
              owner->size += field->size;
          }
#line 1702 "exprtree.tab.c"
    break;

  case 15:
#line 143 "exprtree.y"
                                                           {
              Typetable *owner = TCurrentDefinition();
              Fieldlist *field;
              if ((yyvsp[-5].num) <= 0 || (yyvsp[-2].num) <= 0 || owner == NULL ||
                  (field = FInstall(owner, (yyvsp[-7].str), (yyvsp[-8].type), owner->size)) == NULL) {
                  fprintf(stderr, "Error: invalid or duplicate array field '%s'\n", (yyvsp[-7].str));
                  exit(1);
              }
              field->isArray = 1;
              field->rows = (yyvsp[-5].num);
              field->cols = (yyvsp[-2].num);
              field->size = (yyvsp[-5].num) * (yyvsp[-2].num);
              owner->size += field->size;
          }
#line 1721 "exprtree.tab.c"
    break;

  case 16:
#line 166 "exprtree.y"
                { (yyval.type) = TLookup("int"); }
#line 1727 "exprtree.tab.c"
    break;

  case 17:
#line 167 "exprtree.y"
                { (yyval.type) = TLookup("str"); }
#line 1733 "exprtree.tab.c"
    break;

  case 18:
#line 168 "exprtree.y"
               {
              (yyval.type) = TLookup((yyvsp[0].str));
              if ((yyval.type) == NULL || !IsUserDefinedType((yyval.type))) {
                  fprintf(stderr, "Error: field type '%s' is undefined or not declarable here\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1745 "exprtree.tab.c"
    break;

  case 23:
#line 182 "exprtree.y"
                                   {
    // if i have like 
    // int a, b;
    // int c, d; (in two lines)
    // the varlist gon be like two diff linked lists, and each time reduction is done, we traverse thru
    VarList* temp = (yyvsp[-1].varlist);

    while (temp != NULL) {
        Typetable *varType = (yyvsp[-2].type);
        if (temp->isPointer) {
            varType = PointerType((yyvsp[-2].type));
            if (varType == NULL) {
                fprintf(stderr, "Error: pointer declarations are supported only for int and str\n");
                exit(1);
            }
        }

        if (temp->isFunction) {
            Install(temp->name, varType, 0, 0, 0, 0, temp->paramlist,
                    nextFunctionLabel++);
        } else {
            Install(temp->name, varType, temp->size, temp->rows, temp->cols,
                    temp->isArray,
                    NULL, -1);
        }
        temp = temp->next;
    }
}
#line 1778 "exprtree.tab.c"
    break;

  case 24:
#line 212 "exprtree.y"
               { (yyval.type) = TLookup("int"); }
#line 1784 "exprtree.tab.c"
    break;

  case 25:
#line 213 "exprtree.y"
               { (yyval.type) = TLookup("str"); }
#line 1790 "exprtree.tab.c"
    break;

  case 26:
#line 214 "exprtree.y"
               {
             Typetable *resolvedType = TLookup((yyvsp[0].str));
             if (resolvedType == NULL || !IsUserDefinedType(resolvedType)) {
                 fprintf(stderr, "Error: type '%s' is not defined yet\n", (yyvsp[0].str));
                 exit(1);
             }
             (yyval.type) = resolvedType;
         }
#line 1803 "exprtree.tab.c"
    break;

  case 27:
#line 224 "exprtree.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 1809 "exprtree.tab.c"
    break;

  case 28:
#line 225 "exprtree.y"
                     {
          (yyval.type) = PointerType((yyvsp[-1].type));
          if ((yyval.type) == NULL) {
              fprintf(stderr, "Error: pointer types are supported only for int and str\n");
              exit(1);
          }
      }
#line 1821 "exprtree.tab.c"
    break;

  case 29:
#line 241 "exprtree.y"
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
#line 1842 "exprtree.tab.c"
    break;

  case 30:
#line 257 "exprtree.y"
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
#line 1859 "exprtree.tab.c"
    break;

  case 31:
#line 269 "exprtree.y"
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
#line 1879 "exprtree.tab.c"
    break;

  case 32:
#line 284 "exprtree.y"
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
#line 1895 "exprtree.tab.c"
    break;

  case 33:
#line 295 "exprtree.y"
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
#line 1916 "exprtree.tab.c"
    break;

  case 34:
#line 311 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 1931 "exprtree.tab.c"
    break;

  case 35:
#line 321 "exprtree.y"
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
#line 1949 "exprtree.tab.c"
    break;

  case 36:
#line 334 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1963 "exprtree.tab.c"
    break;

  case 37:
#line 343 "exprtree.y"
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
#line 1987 "exprtree.tab.c"
    break;

  case 38:
#line 362 "exprtree.y"
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
#line 2006 "exprtree.tab.c"
    break;

  case 39:
#line 376 "exprtree.y"
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
#line 2024 "exprtree.tab.c"
    break;

  case 40:
#line 389 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 2038 "exprtree.tab.c"
    break;

  case 41:
#line 401 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 2046 "exprtree.tab.c"
    break;

  case 42:
#line 404 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2055 "exprtree.tab.c"
    break;

  case 43:
#line 408 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2063 "exprtree.tab.c"
    break;

  case 44:
#line 411 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 2071 "exprtree.tab.c"
    break;

  case 45:
#line 421 "exprtree.y"
                        {
            (yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].str));
        }
#line 2079 "exprtree.tab.c"
    break;

  case 46:
#line 424 "exprtree.y"
                    {
            (yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].str));
        }
#line 2087 "exprtree.tab.c"
    break;

  case 47:
#line 427 "exprtree.y"
                       {
            (yyval.node) = makeFieldArrayNode((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2095 "exprtree.tab.c"
    break;

  case 48:
#line 430 "exprtree.y"
                                 {
            (yyval.node) = makeFieldArray2DNode((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));
        }
#line 2103 "exprtree.tab.c"
    break;

  case 51:
#line 438 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 2112 "exprtree.tab.c"
    break;

  case 52:
#line 441 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 2122 "exprtree.tab.c"
    break;

  case 53:
#line 447 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 2137 "exprtree.tab.c"
    break;

  case 54:
#line 457 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 2145 "exprtree.tab.c"
    break;

  case 55:
#line 460 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 2153 "exprtree.tab.c"
    break;

  case 56:
#line 464 "exprtree.y"
                    {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = (yyvsp[-1].type);
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 2167 "exprtree.tab.c"
    break;

  case 57:
#line 473 "exprtree.y"
                      {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = PointerType((yyvsp[-2].type));
        if (p->type == NULL) {
            fprintf(stderr, "Error: pointer parameters are supported only for int and str\n");
            exit(1);
        }
        p->next = NULL;
        (yyval.paramlist) = p;
    }
#line 2184 "exprtree.tab.c"
    break;

  case 62:
#line 491 "exprtree.y"
                                  {
        InstallLocalVariables((yyvsp[-1].varlist), (yyvsp[-2].type));
    }
#line 2192 "exprtree.tab.c"
    break;

  case 63:
#line 495 "exprtree.y"
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
#line 2216 "exprtree.tab.c"
    break;

  case 64:
#line 514 "exprtree.y"
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
#line 2232 "exprtree.tab.c"
    break;

  case 65:
#line 525 "exprtree.y"
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
#line 2249 "exprtree.tab.c"
    break;

  case 66:
#line 537 "exprtree.y"
                     {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2262 "exprtree.tab.c"
    break;

  case 67:
#line 545 "exprtree.y"
                                 {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2276 "exprtree.tab.c"
    break;

  case 68:
#line 554 "exprtree.y"
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
#line 2293 "exprtree.tab.c"
    break;

  case 69:
#line 568 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2299 "exprtree.tab.c"
    break;

  case 70:
#line 569 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2305 "exprtree.tab.c"
    break;

  case 71:
#line 572 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2311 "exprtree.tab.c"
    break;

  case 72:
#line 573 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2317 "exprtree.tab.c"
    break;

  case 73:
#line 575 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2323 "exprtree.tab.c"
    break;

  case 74:
#line 579 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2331 "exprtree.tab.c"
    break;

  case 75:
#line 581 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TLookup("int"), "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2343 "exprtree.tab.c"
    break;

  case 76:
#line 601 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2351 "exprtree.tab.c"
    break;

  case 77:
#line 604 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2359 "exprtree.tab.c"
    break;

  case 78:
#line 609 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2367 "exprtree.tab.c"
    break;

  case 79:
#line 612 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2375 "exprtree.tab.c"
    break;

  case 80:
#line 615 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2383 "exprtree.tab.c"
    break;

  case 81:
#line 618 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2391 "exprtree.tab.c"
    break;

  case 82:
#line 621 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2399 "exprtree.tab.c"
    break;

  case 83:
#line 624 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2407 "exprtree.tab.c"
    break;

  case 84:
#line 627 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2415 "exprtree.tab.c"
    break;

  case 85:
#line 630 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2423 "exprtree.tab.c"
    break;

  case 86:
#line 633 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2431 "exprtree.tab.c"
    break;

  case 87:
#line 642 "exprtree.y"
                                              {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2439 "exprtree.tab.c"
    break;

  case 88:
#line 645 "exprtree.y"
                                           {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2447 "exprtree.tab.c"
    break;

  case 89:
#line 654 "exprtree.y"
                                {
        (yyval.node) = makeFreeNode(makeIdNode((yyvsp[-2].str)));
    }
#line 2455 "exprtree.tab.c"
    break;

  case 90:
#line 657 "exprtree.y"
                                   {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2463 "exprtree.tab.c"
    break;

  case 91:
#line 661 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2471 "exprtree.tab.c"
    break;

  case 92:
#line 664 "exprtree.y"
                                   {
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2479 "exprtree.tab.c"
    break;

  case 93:
#line 669 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2487 "exprtree.tab.c"
    break;

  case 94:
#line 673 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2495 "exprtree.tab.c"
    break;

  case 95:
#line 676 "exprtree.y"
                               {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2503 "exprtree.tab.c"
    break;

  case 96:
#line 681 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2511 "exprtree.tab.c"
    break;

  case 97:
#line 684 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2519 "exprtree.tab.c"
    break;

  case 98:
#line 688 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2527 "exprtree.tab.c"
    break;

  case 99:
#line 692 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2535 "exprtree.tab.c"
    break;

  case 100:
#line 696 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2543 "exprtree.tab.c"
    break;

  case 101:
#line 700 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2551 "exprtree.tab.c"
    break;

  case 102:
#line 704 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2559 "exprtree.tab.c"
    break;

  case 103:
#line 709 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2567 "exprtree.tab.c"
    break;

  case 104:
#line 712 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2575 "exprtree.tab.c"
    break;

  case 105:
#line 715 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2583 "exprtree.tab.c"
    break;

  case 106:
#line 718 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2591 "exprtree.tab.c"
    break;

  case 107:
#line 721 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2599 "exprtree.tab.c"
    break;

  case 108:
#line 724 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2607 "exprtree.tab.c"
    break;

  case 109:
#line 727 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2615 "exprtree.tab.c"
    break;

  case 110:
#line 730 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2623 "exprtree.tab.c"
    break;

  case 111:
#line 733 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2631 "exprtree.tab.c"
    break;

  case 112:
#line 736 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2639 "exprtree.tab.c"
    break;

  case 113:
#line 739 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2647 "exprtree.tab.c"
    break;

  case 114:
#line 742 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2655 "exprtree.tab.c"
    break;

  case 115:
#line 745 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2663 "exprtree.tab.c"
    break;

  case 116:
#line 748 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2671 "exprtree.tab.c"
    break;

  case 117:
#line 751 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2679 "exprtree.tab.c"
    break;

  case 118:
#line 754 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 2687 "exprtree.tab.c"
    break;

  case 119:
#line 757 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 2695 "exprtree.tab.c"
    break;

  case 120:
#line 760 "exprtree.y"
             {
        (yyval.node) = makeNullNode();
    }
#line 2703 "exprtree.tab.c"
    break;

  case 121:
#line 763 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 2711 "exprtree.tab.c"
    break;

  case 122:
#line 766 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2719 "exprtree.tab.c"
    break;

  case 123:
#line 769 "exprtree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2727 "exprtree.tab.c"
    break;

  case 124:
#line 772 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 2735 "exprtree.tab.c"
    break;

  case 125:
#line 775 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2743 "exprtree.tab.c"
    break;


#line 2747 "exprtree.tab.c"

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
#line 779 "exprtree.y"


/* Create built-in type entries, parse, print type/symbol tables, and generate target code. */
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
