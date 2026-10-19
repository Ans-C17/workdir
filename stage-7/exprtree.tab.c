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

#line 87 "exprtree.tab.c"

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
#line 18 "exprtree.y"

    tnode* node;
    char* str;
    int num;
    VarList* varlist;
    Paramstruct* paramlist;
    Typetable* type;

#line 202 "exprtree.tab.c"

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
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

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
       0,    94,    94,    95,    96,    99,   100,   104,   105,   108,
     109,   112,   112,   123,   124,   127,   134,   141,   158,   159,
     162,   169,   176,   184,   191,   198,   209,   210,   213,   215,
     216,   219,   219,   229,   230,   233,   244,   245,   246,   255,
     255,   257,   257,   259,   288,   289,   290,   300,   301,   317,
     333,   345,   360,   371,   387,   397,   410,   419,   438,   452,
     465,   477,   480,   484,   487,   492,   495,   498,   503,   503,
     505,   505,   514,   524,   527,   531,   540,   553,   553,   555,
     555,   557,   561,   580,   591,   603,   611,   620,   634,   635,
     638,   639,   641,   644,   644,   666,   669,   673,   676,   679,
     682,   685,   688,   691,   694,   697,   700,   703,   706,   709,
     712,   715,   718,   721,   725,   728,   733,   737,   740,   745,
     748,   752,   756,   760,   764,   768,   772,   775,   778,   781,
     784,   787,   790,   793,   796,   799,   802,   805,   808,   811,
     814,   817,   820,   823,   826,   829,   832,   835,   838,   841,
     845,   846
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
  "ClassMethodDef", "TypeDefList", "TypeDef", "$@2", "FieldDeclList",
  "FieldDecl", "FieldType", "GDeclBlock", "GDeclList", "GDecl", "TypeName",
  "FType", "VarList", "Variable", "Field", "FDefBlock", "FDef", "$@3",
  "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl", "IdList",
  "ArgList", "Body", "ReturnStmt", "MainBlock", "$@4", "Slist", "Stmt",
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

#define YYPACT_NINF (-185)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    51,    63,    47,    31,   153,  -185,  -185,    74,   167,
    -185,  -185,  -185,  -185,     3,  -185,     8,    60,    24,  -185,
      27,   145,  -185,  -185,  -185,  -185,  -185,  -185,    17,  -185,
      11,    58,    60,   120,   175,    24,  -185,  -185,  -185,  -185,
    -185,     1,  -185,   200,   177,  -185,  -185,   133,   209,    33,
     166,  -185,   156,  -185,  -185,  -185,  -185,   181,  -185,    86,
     264,   226,  -185,   189,   179,    86,  -185,    88,   190,   208,
    -185,   213,    86,   155,   279,  -185,   212,   217,   218,   224,
    -185,    40,  -185,  -185,   283,  -185,    86,   229,   214,    86,
     289,   237,   280,  -185,    30,   296,    73,   301,   122,   310,
     225,    86,   230,   231,  -185,  -185,  -185,   314,  -185,   228,
     262,    86,    78,   299,   282,  -185,    86,   278,  -185,    86,
     285,  -185,    86,   307,   311,     4,  -185,   335,   315,   316,
     365,  -185,   395,   232,  -185,   366,    84,  -185,   483,   398,
     280,   239,    86,   246,    86,   252,    86,  -185,  -185,   399,
    -185,   453,  -185,   400,    67,  -185,  -185,   402,   251,   401,
     397,   406,   317,   424,   426,   428,   429,   589,   589,   450,
     452,   -13,    -9,   459,   483,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,   299,   455,   269,   457,
     274,   458,   286,    86,   432,   495,  -185,   499,   317,  -185,
      98,   507,   152,  -185,   205,   317,   251,  -185,  -185,   317,
     454,   -45,   658,  -185,   152,   317,   317,   317,   611,   505,
    -185,  -185,   273,   509,   312,   510,  -185,   486,  -185,   463,
    -185,   484,  -185,   489,  -185,   490,   302,  -185,   475,   477,
     125,   129,   454,   -44,  -185,    38,   113,   250,  -185,  -185,
     341,   256,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,  -185,   115,   130,   369,   394,
     407,   481,   482,   485,   487,   671,  -185,   491,   492,   703,
    -185,  -185,  -185,  -185,  -185,  -185,   465,   493,   537,   500,
     513,   522,   525,   527,  -185,   304,   716,  -185,  -185,   308,
     154,   154,  -185,  -185,  -185,   160,   160,   160,   160,   614,
     614,   435,   382,   528,   529,   531,   526,   524,   317,   317,
     514,   568,  -185,   516,   573,  -185,   280,   575,   519,   317,
    -185,  -185,  -185,  -185,  -185,   317,  -185,  -185,  -185,  -185,
     589,   589,   422,   460,   552,   533,   555,   538,   299,   532,
     539,   235,   716,   456,   535,   -22,   558,  -185,   561,  -185,
     563,   545,  -185,   601,  -185,   589,   569,   581,  -185,  -185,
    -185,  -185,  -185,   549,   562,  -185,  -185,  -185,   595,  -185
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     8,     0,     0,    30,     1,     0,     0,
      31,     5,    29,    11,     0,    10,     0,     0,     0,     4,
       0,     0,     7,     9,    46,    40,    44,    45,     0,    42,
       0,     0,    44,    47,     0,     0,    69,     3,    38,    36,
      37,     0,    34,     0,     0,    39,    41,    54,     0,     0,
       0,    48,     0,    68,     2,    32,    33,     0,    14,    74,
       0,    56,    43,     0,     0,    74,    35,     0,     0,     0,
      73,     0,    74,    53,     0,    93,     0,     0,     0,     0,
      13,     0,    19,    75,     0,    58,     0,    52,     0,    74,
       0,    55,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    76,    72,     0,    60,     0,
       0,    74,     0,     0,     0,    17,    74,     0,    15,    74,
       0,    16,    74,     0,     0,     0,    27,     0,     0,     0,
       0,    57,    51,     0,    78,     0,     0,    80,     0,     0,
       0,     0,    74,     0,    74,     0,    74,    12,    26,     0,
      50,     0,    59,    87,     0,    77,    79,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    94,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    81,     0,     0,    64,
       0,     0,     0,   141,    61,     0,     0,   143,   142,     0,
     145,   146,     0,   147,     0,     0,     0,     0,     0,     0,
     122,   123,     0,     0,     0,     0,    91,     0,    95,     0,
      22,     0,    20,     0,    21,     0,     0,    49,     0,    82,
       0,    61,     0,     0,    65,     0,     0,     0,   131,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
      67,    90,    71,    25,    23,    24,     0,    85,     0,    62,
       0,     0,     0,     0,   148,     0,    89,   132,   151,     0,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,   118,     0,     0,     0,     0,
     110,   111,   112,   113,   149,     0,   150,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    88,     0,     0,     0,     0,   106,     0,   107,
       0,     0,    86,     0,    63,     0,     0,     0,   125,   124,
     108,   109,    28,     0,     0,   120,   121,    84,     0,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,  -185,  -185,  -185,   618,  -185,  -185,  -185,  -185,
     560,  -185,   517,  -185,   638,  -185,  -185,   603,  -185,  -185,
    -185,   617,    59,   -82,  -185,  -138,  -135,  -185,   612,  -185,
     -18,   567,  -136,  -185,   512,  -185,   403,  -184,   472,   -12,
    -185,  -158,  -173,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -109,  -185
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    14,    15,    21,    67,    80,    81,
      82,   125,   126,     5,     6,    20,    41,    42,    43,    18,
      28,    29,    68,    34,    49,   210,   211,    35,    36,   114,
      69,    70,   113,   136,   137,   154,   295,   139,   173,    19,
      92,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   296,   213
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     171,   228,   229,   172,   186,    38,    37,    13,    24,   218,
     219,   251,    24,   291,   368,    47,   225,   225,    48,   127,
     199,    24,   222,    54,   341,     1,   224,    22,    24,   171,
     171,    38,   172,   172,    39,    40,   171,    26,    27,   172,
      25,    26,    27,   127,   100,   228,   228,    76,   223,    45,
      26,    27,   225,   212,    88,     4,    55,    32,    27,   147,
      39,    40,   242,     7,   245,   243,   115,   246,   249,    62,
       8,   109,   101,   102,   103,    30,   266,    33,    13,   267,
     171,   171,    24,   172,   172,    10,   116,    30,    24,   240,
      24,    63,    77,   133,    33,   292,   248,    31,   141,   223,
     250,   143,   241,   196,   145,   158,   268,   269,   270,   118,
     134,    26,    27,   275,    50,   279,   155,    26,    27,    26,
      27,    78,    79,   160,   188,   197,   190,    51,   192,   119,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   157,     4,   121,   158,
      33,   254,   255,   256,   361,   252,   253,   254,   255,   256,
     293,   135,   313,    11,   225,   236,   223,   160,   122,    52,
     228,   228,   353,   354,    33,   289,   290,   314,   198,    59,
     348,   225,    60,    73,    83,   135,    74,    84,    16,    44,
      17,   228,   171,   171,    57,   172,   172,   374,    58,   342,
     343,    89,    65,    61,    90,   171,   171,    66,   172,   172,
     351,    94,    96,    64,    95,    97,   352,   171,    98,   124,
     172,    99,    95,    75,   128,   129,   171,    97,    99,   172,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   203,   204,   157,   205,   158,   158,   203,
     204,   247,   205,   158,   198,    85,    86,    71,   206,    93,
      86,   108,    86,    87,   206,   160,   203,   204,   207,   205,
     158,   160,    72,    91,   207,   131,    86,   105,   107,   152,
      86,   206,   110,   111,   273,   364,   187,    86,   160,   274,
     117,   207,   208,   189,    86,   120,   209,   294,   208,   191,
      86,   112,   209,   298,   123,   203,   204,   130,   205,   158,
     203,   204,   132,   205,   158,   208,   231,    86,   138,   209,
     206,   233,    86,   277,   142,   206,   140,   160,   278,   149,
     207,   144,   160,   235,    86,   207,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   286,
      86,   334,   335,   146,   208,   336,   335,   116,   209,   208,
     153,   119,   122,   209,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   297,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   150,   315,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   316,   264,   185,   151,   193,   194,   200,   201,   195,
     157,   198,   202,   158,   317,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   159,   355,
     214,   160,   215,   161,   216,   217,   220,   157,   221,   226,
     158,   230,   237,   232,   234,   163,   164,   165,   238,   365,
     366,   166,   167,   239,   168,   159,   169,   170,   160,   157,
     161,   244,   158,   276,   280,   223,   281,   356,   282,   326,
     283,   162,   163,   164,   165,   284,   285,   159,   166,   167,
     160,   168,   161,   169,   170,   287,   288,   318,   319,   157,
     328,   320,   158,   321,   163,   164,   165,   323,   324,   330,
     166,   167,   327,   168,   272,   169,   170,   159,   331,   329,
     160,   332,   161,   333,   337,   338,   157,   339,   340,   158,
     341,   344,   345,   346,   163,   164,   165,   347,   349,   350,
     166,   167,   367,   168,   159,   169,   170,   160,   357,   161,
     358,   359,   362,   157,   369,   360,   158,   370,   363,   371,
     372,   163,   164,   165,   373,   375,   378,   166,   167,   377,
     168,   159,   169,   170,   160,   157,   161,   376,   158,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   163,   164,
     165,   379,    23,   159,   166,   167,   160,   168,   161,   169,
     170,   104,   148,    12,    56,    46,   227,    53,   156,     0,
     163,   164,   165,   106,   299,     0,   271,   167,     0,   168,
       0,   169,   170,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,     0,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,     0,     0,     0,     0,     0,   325
};

static const yytype_int16 yycheck[] =
{
     138,   174,   186,   138,   140,     4,    18,     4,     4,   167,
     168,    56,     4,    57,    36,     4,    61,    61,     7,   101,
     158,     4,    35,    35,    46,    19,    35,    24,     4,   167,
     168,     4,   167,   168,    33,    34,   174,    33,    34,   174,
      32,    33,    34,   125,     4,   218,   219,    65,    61,    32,
      33,    34,    61,   162,    72,     4,    55,    33,    34,    55,
      33,    34,   200,     0,   202,   200,    36,   202,   206,    36,
      23,    89,    32,    33,    34,    16,   214,    18,     4,   214,
     218,   219,     4,   218,   219,    54,    56,    28,     4,   198,
       4,    58,     4,   111,    35,    57,   205,    37,   116,    61,
     209,   119,     4,    36,   122,     7,   215,   216,   217,    36,
      32,    33,    34,   222,    56,   224,    32,    33,    34,    33,
      34,    33,    34,    25,   142,    58,   144,     7,   146,    56,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,     4,     4,    36,     7,
     101,     7,     8,     9,   348,     5,     6,     7,     8,     9,
      57,   112,    57,    20,    61,   193,    61,    25,    56,     4,
     353,   354,   340,   341,   125,    60,    57,    57,    59,    56,
     326,    61,    59,     4,     4,   136,     7,     7,    31,    54,
      33,   374,   340,   341,     4,   340,   341,   365,    31,   318,
     319,    56,    56,     4,    59,   353,   354,    36,   353,   354,
     329,     4,     4,    57,     7,     7,   335,   365,     4,     4,
     365,     7,     7,    54,     4,     4,   374,     7,     7,   374,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     3,     4,     4,     6,     7,     7,     3,
       4,    56,     6,     7,    59,    57,    58,     3,    18,    57,
      58,    57,    58,    60,    18,    25,     3,     4,    28,     6,
       7,    25,    56,     4,    28,    57,    58,     4,    59,    57,
      58,    18,     3,    56,    21,    60,    57,    58,    25,    26,
       4,    28,    52,    57,    58,     4,    56,    57,    52,    57,
      58,    31,    56,    57,     4,     3,     4,     3,     6,     7,
       3,     4,    60,     6,     7,    52,    57,    58,    29,    56,
      18,    57,    58,    21,    56,    18,    54,    25,    26,     4,
      28,    56,    25,    57,    58,    28,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    57,
      58,    57,    58,    56,    52,    57,    58,    56,    56,    52,
       4,    56,    56,    56,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    57,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    60,    57,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    57,    17,    55,    59,    56,     3,    56,    61,    59,
       4,    59,    56,     7,    57,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    22,    57,
      56,    25,    56,    27,    56,    56,    36,     4,    36,    30,
       7,    36,    60,    36,    36,    39,    40,    41,     3,    43,
      44,    45,    46,     4,    48,    22,    50,    51,    25,     4,
      27,     4,     7,     4,     4,    61,    30,    57,    55,    54,
      36,    38,    39,    40,    41,    36,    36,    22,    45,    46,
      25,    48,    27,    50,    51,    60,    59,    56,    56,     4,
       3,    56,     7,    56,    39,    40,    41,    56,    56,    36,
      45,    46,    59,    48,    49,    50,    51,    22,    36,    59,
      25,    36,    27,    36,    36,    36,     4,    36,    42,     7,
      46,    57,     4,    57,    39,    40,    41,     4,     3,    60,
      45,    46,    47,    48,    22,    50,    51,    25,    36,    27,
      57,    36,    60,     4,    36,    57,     7,    36,    59,    36,
      55,    39,    40,    41,     3,    36,    44,    45,    46,    60,
      48,    22,    50,    51,    25,     4,    27,    36,     7,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    39,    40,
      41,    36,    14,    22,    45,    46,    25,    48,    27,    50,
      51,    81,   125,     5,    41,    28,   174,    35,   136,    -1,
      39,    40,    41,    86,   251,    -1,    45,    46,    -1,    48,
      -1,    50,    51,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    63,    64,     4,    75,    76,     0,    23,    65,
      54,    20,    76,     4,    66,    67,    31,    33,    81,   101,
      77,    68,    24,    67,     4,    32,    33,    34,    82,    83,
      84,    37,    33,    84,    85,    89,    90,   101,     4,    33,
      34,    78,    79,    80,    54,    32,    83,     4,     7,    86,
      56,     7,     4,    90,   101,    55,    79,     4,    31,    56,
      59,     4,    36,    58,    57,    56,    36,    69,    84,    92,
      93,     3,    56,     4,     7,    54,    92,     4,    33,    34,
      70,    71,    72,     4,     7,    57,    58,    60,    92,    56,
      59,     4,   102,    57,     4,     7,     4,     7,     4,     7,
       4,    32,    33,    34,    72,     4,    93,    59,    57,    92,
       3,    56,    31,    94,    91,    36,    56,     4,    36,    56,
       4,    36,    56,     4,     4,    73,    74,    85,     4,     4,
       3,    57,    60,    92,    32,    84,    95,    96,    29,    99,
      54,    92,    56,    92,    56,    92,    56,    55,    74,     4,
      60,    59,    57,     4,    97,    32,    96,     4,     7,    22,
      25,    27,    38,    39,    40,    41,    45,    46,    48,    50,
      51,    87,    88,   100,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    55,    94,    57,    92,    57,
      92,    57,    92,    56,     3,    59,    36,    58,    59,    87,
      56,    61,    56,     3,     4,     6,    18,    28,    52,    56,
      87,    88,   114,   115,    56,    56,    56,    56,   103,   103,
      36,    36,    35,    61,    35,    61,    30,   100,   104,    99,
      36,    57,    36,    57,    36,    57,    92,    60,     3,     4,
     114,     4,    87,    88,     4,    87,    88,    56,   114,    87,
     114,    56,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    36,    87,    88,   114,   114,
     114,    45,    49,    21,    26,   114,     4,    21,    26,   114,
       4,    30,    55,    36,    36,    36,    57,    60,    59,    60,
      57,    57,    57,    57,    57,    98,   114,    57,    57,    98,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,    57,    57,    57,    57,    57,    56,    56,
      56,    56,    36,    56,    56,    36,    54,    59,     3,    59,
      36,    36,    36,    36,    57,    58,    57,    36,    36,    36,
      42,    46,   114,   114,    57,     4,    57,     4,    94,     3,
      60,   114,   114,   103,   103,    57,    57,    36,    57,    36,
      57,    99,    60,    59,    60,    43,    44,    47,    36,    36,
      36,    36,    55,     3,   103,    36,    36,    60,    44,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    68,    67,    69,    69,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    75,
      75,    77,    76,    78,    78,    79,    80,    80,    80,    81,
      81,    82,    82,    83,    84,    84,    84,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    89,    89,
      91,    90,    92,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,   100,   102,   101,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   110,   111,   112,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     3,     0,     2,
       1,     0,     9,     2,     0,     3,     3,     3,     2,     1,
       6,     6,     6,     7,     7,     7,     2,     1,     9,     2,
       1,     0,     5,     2,     1,     3,     1,     1,     1,     3,
       2,     2,     1,     3,     1,     1,     1,     1,     2,     9,
       7,     6,     4,     3,     1,     4,     2,     6,     4,     7,
       5,     1,     4,     7,     2,     3,     3,     3,     2,     1,
       0,    10,     3,     1,     0,     2,     3,     3,     2,     2,
       1,     3,     3,     6,     9,     4,     7,     1,     3,     1,
       4,     3,     3,     0,     9,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     6,     7,     7,
       5,     5,     5,     5,     5,     5,     5,     4,     4,    10,
       8,     8,     2,     2,     7,     7,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     1,     1,     1,     3,     4,
       4,     3
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
#line 1702 "exprtree.tab.c"
    break;

  case 3:
#line 95 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1708 "exprtree.tab.c"
    break;

  case 4:
#line 96 "exprtree.y"
                                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1714 "exprtree.tab.c"
    break;

  case 7:
#line 104 "exprtree.y"
                                            { PrintClassTable(); }
#line 1720 "exprtree.tab.c"
    break;

  case 11:
#line 112 "exprtree.y"
              {
              currentClass = CInstall((yyvsp[0].str), NULL);
              if (currentClass == NULL) {
                  fprintf(stderr, "Error: class '%s' is already defined or cannot be installed\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1732 "exprtree.tab.c"
    break;

  case 12:
#line 118 "exprtree.y"
                                                                                       {
              currentClass = NULL;
          }
#line 1740 "exprtree.tab.c"
    break;

  case 15:
#line 127 "exprtree.y"
                              {
               if (Class_Finstall(currentClass, "int", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "int", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1752 "exprtree.tab.c"
    break;

  case 16:
#line 134 "exprtree.y"
                              {
               if (Class_Finstall(currentClass, "str", (yyvsp[-1].str)) == NULL) {
                   fprintf(stderr, "Error: field '%s %s' is invalid, duplicated, or exceeds the 8-field limit in class '%s'\n",
                           "str", (yyvsp[-1].str), currentClass == NULL ? "?" : currentClass->name);
                   exit(1);
               }
           }
#line 1764 "exprtree.tab.c"
    break;

  case 17:
#line 141 "exprtree.y"
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
#line 1784 "exprtree.tab.c"
    break;

  case 20:
#line 162 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("int"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1796 "exprtree.tab.c"
    break;

  case 21:
#line 169 "exprtree.y"
                                                     {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), TLookup("str"), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1808 "exprtree.tab.c"
    break;

  case 22:
#line 176 "exprtree.y"
                                                    {
                    Typetable *returnType = TLookup((yyvsp[-5].str));
                    if (returnType == NULL || Class_Minstall(currentClass, (yyvsp[-4].str), returnType, (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1821 "exprtree.tab.c"
    break;

  case 23:
#line 184 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("int")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1833 "exprtree.tab.c"
    break;

  case 24:
#line 191 "exprtree.y"
                                                         {
                    if (Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(TLookup("str")), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' is invalid, duplicated, or exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1845 "exprtree.tab.c"
    break;

  case 25:
#line 198 "exprtree.y"
                                                        {
                    Typetable *returnType = TLookup((yyvsp[-6].str));
                    if (returnType == NULL || !IsUserDefinedType(returnType) ||
                        Class_Minstall(currentClass, (yyvsp[-4].str), PointerType(returnType), (yyvsp[-2].paramlist)) == NULL) {
                        fprintf(stderr, "Error: method '%s' has an invalid pointer return type or is duplicated/exceeds the 8-method limit in class '%s'\n",
                                (yyvsp[-4].str), currentClass == NULL ? "?" : currentClass->name);
                        exit(1);
                    }
                }
#line 1859 "exprtree.tab.c"
    break;

  case 31:
#line 219 "exprtree.y"
                 {
            if (TBeginDefinition((yyvsp[-1].str)) == NULL) {
                fprintf(stderr, "Error: type '%s' is already defined or cannot be started\n", (yyvsp[-1].str));
                exit(1);
            }
        }
#line 1870 "exprtree.tab.c"
    break;

  case 32:
#line 224 "exprtree.y"
                            {
            TFinishDefinition(TCurrentDefinition());
        }
#line 1878 "exprtree.tab.c"
    break;

  case 35:
#line 233 "exprtree.y"
                                   {
              Typetable *owner = TCurrentDefinition();
              if (owner == NULL ||
                  FInstall(owner, (yyvsp[-1].str), (yyvsp[-2].type), owner->size) == NULL) {
                  fprintf(stderr, "Error: duplicate field '%s' or invalid field declaration\n", (yyvsp[-1].str));
                  exit(1);
              }
              owner->size++;
          }
#line 1892 "exprtree.tab.c"
    break;

  case 36:
#line 244 "exprtree.y"
                { (yyval.type) = TLookup("int"); }
#line 1898 "exprtree.tab.c"
    break;

  case 37:
#line 245 "exprtree.y"
                { (yyval.type) = TLookup("str"); }
#line 1904 "exprtree.tab.c"
    break;

  case 38:
#line 246 "exprtree.y"
               {
              (yyval.type) = TLookup((yyvsp[0].str));
              if ((yyval.type) == NULL || !IsUserDefinedType((yyval.type))) {
                  fprintf(stderr, "Error: field type '%s' is undefined or not declarable here\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1916 "exprtree.tab.c"
    break;

  case 43:
#line 259 "exprtree.y"
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
#line 1949 "exprtree.tab.c"
    break;

  case 44:
#line 288 "exprtree.y"
               { (yyval.type) = TLookup("int"); }
#line 1955 "exprtree.tab.c"
    break;

  case 45:
#line 289 "exprtree.y"
               { (yyval.type) = TLookup("str"); }
#line 1961 "exprtree.tab.c"
    break;

  case 46:
#line 290 "exprtree.y"
               {
             Typetable *resolvedType = TLookup((yyvsp[0].str));
             if (resolvedType == NULL || !IsUserDefinedType(resolvedType)) {
                 fprintf(stderr, "Error: type '%s' is not defined yet\n", (yyvsp[0].str));
                 exit(1);
             }
             (yyval.type) = resolvedType;
         }
#line 1974 "exprtree.tab.c"
    break;

  case 47:
#line 300 "exprtree.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 1980 "exprtree.tab.c"
    break;

  case 48:
#line 301 "exprtree.y"
                     {
          (yyval.type) = PointerType((yyvsp[-1].type));
          if ((yyval.type) == NULL) {
              fprintf(stderr, "Error: pointer types are supported only for int and str\n");
              exit(1);
          }
      }
#line 1992 "exprtree.tab.c"
    break;

  case 49:
#line 317 "exprtree.y"
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
#line 2013 "exprtree.tab.c"
    break;

  case 50:
#line 333 "exprtree.y"
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
#line 2030 "exprtree.tab.c"
    break;

  case 51:
#line 345 "exprtree.y"
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
#line 2050 "exprtree.tab.c"
    break;

  case 52:
#line 360 "exprtree.y"
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
#line 2066 "exprtree.tab.c"
    break;

  case 53:
#line 371 "exprtree.y"
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
#line 2087 "exprtree.tab.c"
    break;

  case 54:
#line 387 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 2102 "exprtree.tab.c"
    break;

  case 55:
#line 397 "exprtree.y"
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
#line 2120 "exprtree.tab.c"
    break;

  case 56:
#line 410 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 2134 "exprtree.tab.c"
    break;

  case 57:
#line 419 "exprtree.y"
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
#line 2158 "exprtree.tab.c"
    break;

  case 58:
#line 438 "exprtree.y"
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
#line 2177 "exprtree.tab.c"
    break;

  case 59:
#line 452 "exprtree.y"
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
#line 2195 "exprtree.tab.c"
    break;

  case 60:
#line 465 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 2209 "exprtree.tab.c"
    break;

  case 61:
#line 477 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 2217 "exprtree.tab.c"
    break;

  case 62:
#line 480 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2226 "exprtree.tab.c"
    break;

  case 63:
#line 484 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2234 "exprtree.tab.c"
    break;

  case 64:
#line 487 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 2242 "exprtree.tab.c"
    break;

  case 65:
#line 492 "exprtree.y"
                    {
            (yyval.node) = makeFieldNode(makeIdNode("self"), (yyvsp[0].str));
        }
#line 2250 "exprtree.tab.c"
    break;

  case 66:
#line 495 "exprtree.y"
                       {
            (yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].str));
        }
#line 2258 "exprtree.tab.c"
    break;

  case 67:
#line 498 "exprtree.y"
                    {
            (yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].str));
        }
#line 2266 "exprtree.tab.c"
    break;

  case 70:
#line 505 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 2275 "exprtree.tab.c"
    break;

  case 71:
#line 508 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 2285 "exprtree.tab.c"
    break;

  case 72:
#line 514 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 2300 "exprtree.tab.c"
    break;

  case 73:
#line 524 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 2308 "exprtree.tab.c"
    break;

  case 74:
#line 527 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 2316 "exprtree.tab.c"
    break;

  case 75:
#line 531 "exprtree.y"
                    {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = (yyvsp[-1].type);
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 2330 "exprtree.tab.c"
    break;

  case 76:
#line 540 "exprtree.y"
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
#line 2347 "exprtree.tab.c"
    break;

  case 81:
#line 557 "exprtree.y"
                                  {
        InstallLocalVariables((yyvsp[-1].varlist), (yyvsp[-2].type));
    }
#line 2355 "exprtree.tab.c"
    break;

  case 82:
#line 561 "exprtree.y"
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
#line 2379 "exprtree.tab.c"
    break;

  case 83:
#line 580 "exprtree.y"
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
#line 2395 "exprtree.tab.c"
    break;

  case 84:
#line 591 "exprtree.y"
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
#line 2412 "exprtree.tab.c"
    break;

  case 85:
#line 603 "exprtree.y"
                     {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2425 "exprtree.tab.c"
    break;

  case 86:
#line 611 "exprtree.y"
                                 {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2439 "exprtree.tab.c"
    break;

  case 87:
#line 620 "exprtree.y"
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
#line 2456 "exprtree.tab.c"
    break;

  case 88:
#line 634 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2462 "exprtree.tab.c"
    break;

  case 89:
#line 635 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2468 "exprtree.tab.c"
    break;

  case 90:
#line 638 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2474 "exprtree.tab.c"
    break;

  case 91:
#line 639 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2480 "exprtree.tab.c"
    break;

  case 92:
#line 641 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2486 "exprtree.tab.c"
    break;

  case 93:
#line 644 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2494 "exprtree.tab.c"
    break;

  case 94:
#line 646 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TLookup("int"), "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2506 "exprtree.tab.c"
    break;

  case 95:
#line 666 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2514 "exprtree.tab.c"
    break;

  case 96:
#line 669 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2522 "exprtree.tab.c"
    break;

  case 97:
#line 673 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2530 "exprtree.tab.c"
    break;

  case 98:
#line 676 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2538 "exprtree.tab.c"
    break;

  case 99:
#line 679 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2546 "exprtree.tab.c"
    break;

  case 100:
#line 682 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2554 "exprtree.tab.c"
    break;

  case 101:
#line 685 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2562 "exprtree.tab.c"
    break;

  case 102:
#line 688 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2570 "exprtree.tab.c"
    break;

  case 103:
#line 691 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2578 "exprtree.tab.c"
    break;

  case 104:
#line 694 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2586 "exprtree.tab.c"
    break;

  case 105:
#line 697 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2594 "exprtree.tab.c"
    break;

  case 106:
#line 700 "exprtree.y"
                                              {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2602 "exprtree.tab.c"
    break;

  case 107:
#line 703 "exprtree.y"
                                           {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2610 "exprtree.tab.c"
    break;

  case 108:
#line 706 "exprtree.y"
                                               {
        (yyval.node) = makeAllocNode((yyvsp[-6].node));
    }
#line 2618 "exprtree.tab.c"
    break;

  case 109:
#line 709 "exprtree.y"
                                            {
        (yyval.node) = makeAllocNode((yyvsp[-6].node));
    }
#line 2626 "exprtree.tab.c"
    break;

  case 110:
#line 712 "exprtree.y"
                                {
        (yyval.node) = makeFreeNode(makeIdNode((yyvsp[-2].str)));
    }
#line 2634 "exprtree.tab.c"
    break;

  case 111:
#line 715 "exprtree.y"
                                   {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2642 "exprtree.tab.c"
    break;

  case 112:
#line 718 "exprtree.y"
                                        {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2650 "exprtree.tab.c"
    break;

  case 113:
#line 721 "exprtree.y"
                                     {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2658 "exprtree.tab.c"
    break;

  case 114:
#line 725 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2666 "exprtree.tab.c"
    break;

  case 115:
#line 728 "exprtree.y"
                                   {
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2674 "exprtree.tab.c"
    break;

  case 116:
#line 733 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2682 "exprtree.tab.c"
    break;

  case 117:
#line 737 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2690 "exprtree.tab.c"
    break;

  case 118:
#line 740 "exprtree.y"
                               {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2698 "exprtree.tab.c"
    break;

  case 119:
#line 745 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2706 "exprtree.tab.c"
    break;

  case 120:
#line 748 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2714 "exprtree.tab.c"
    break;

  case 121:
#line 752 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2722 "exprtree.tab.c"
    break;

  case 122:
#line 756 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2730 "exprtree.tab.c"
    break;

  case 123:
#line 760 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2738 "exprtree.tab.c"
    break;

  case 124:
#line 764 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2746 "exprtree.tab.c"
    break;

  case 125:
#line 768 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2754 "exprtree.tab.c"
    break;

  case 126:
#line 772 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2762 "exprtree.tab.c"
    break;

  case 127:
#line 775 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2770 "exprtree.tab.c"
    break;

  case 128:
#line 778 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2778 "exprtree.tab.c"
    break;

  case 129:
#line 781 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2786 "exprtree.tab.c"
    break;

  case 130:
#line 784 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2794 "exprtree.tab.c"
    break;

  case 131:
#line 787 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2802 "exprtree.tab.c"
    break;

  case 132:
#line 790 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2810 "exprtree.tab.c"
    break;

  case 133:
#line 793 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2818 "exprtree.tab.c"
    break;

  case 134:
#line 796 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2826 "exprtree.tab.c"
    break;

  case 135:
#line 799 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2834 "exprtree.tab.c"
    break;

  case 136:
#line 802 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2842 "exprtree.tab.c"
    break;

  case 137:
#line 805 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2850 "exprtree.tab.c"
    break;

  case 138:
#line 808 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2858 "exprtree.tab.c"
    break;

  case 139:
#line 811 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2866 "exprtree.tab.c"
    break;

  case 140:
#line 814 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2874 "exprtree.tab.c"
    break;

  case 141:
#line 817 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 2882 "exprtree.tab.c"
    break;

  case 142:
#line 820 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 2890 "exprtree.tab.c"
    break;

  case 143:
#line 823 "exprtree.y"
             {
        (yyval.node) = makeNullNode();
    }
#line 2898 "exprtree.tab.c"
    break;

  case 144:
#line 826 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 2906 "exprtree.tab.c"
    break;

  case 145:
#line 829 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2914 "exprtree.tab.c"
    break;

  case 146:
#line 832 "exprtree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2922 "exprtree.tab.c"
    break;

  case 147:
#line 835 "exprtree.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2930 "exprtree.tab.c"
    break;

  case 148:
#line 838 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 2938 "exprtree.tab.c"
    break;

  case 149:
#line 841 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2946 "exprtree.tab.c"
    break;

  case 150:
#line 845 "exprtree.y"
                                      { (yyval.node) = NULL; }
#line 2952 "exprtree.tab.c"
    break;

  case 151:
#line 846 "exprtree.y"
                                      { (yyval.node) = NULL; }
#line 2958 "exprtree.tab.c"
    break;


#line 2962 "exprtree.tab.c"

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
#line 849 "exprtree.y"


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
