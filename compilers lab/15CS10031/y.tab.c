/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ass5_15CS10031.y" /* yacc.c:339  */
 
/*	
*	  parser.y
* 	  Author: PANKAJ DHURVE
*/
 	/* C Declarations and Definitions */
	#include <string.h>

	#include <stdio.h>
	#include "ass5_15CS10031_translator.h"
	extern	int yylex();
	void yyerror(const char *s);
	extern type_e TYPE;
	//extern int gDebug;
	extern bool gDebug;
	vector <string> allstrings;
	//sym* temporary = gentemp(_DOUBLE);


#line 86 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPEDEF = 258,
    EXTERN = 259,
    STATIC = 260,
    AUTO = 261,
    REGISTER = 262,
    INLINE = 263,
    RESTRICT = 264,
    MATRIX = 265,
    HAS = 266,
    POW = 267,
    UOR = 268,
    CHAR = 269,
    SHORT = 270,
    INT = 271,
    LONG = 272,
    SIGNED = 273,
    UNSIGNED = 274,
    FLOAT = 275,
    DOUBLE = 276,
    CONST = 277,
    VOLATILE = 278,
    VOID = 279,
    EQ = 280,
    COM = 281,
    BOOL = 282,
    COMPLEX = 283,
    IMAGINARY = 284,
    DCOMM = 285,
    STRUCT = 286,
    UNION = 287,
    ENUM = 288,
    DOT = 289,
    LET = 290,
    GET = 291,
    Q = 292,
    POL = 293,
    SECOL = 294,
    BREAK = 295,
    CASE = 296,
    CONTINUE = 297,
    DEFAULT = 298,
    DO = 299,
    IF = 300,
    ELSE = 301,
    FOR = 302,
    GOTO = 303,
    WHILE = 304,
    SWITCH = 305,
    SIZEOF = 306,
    RETURN = 307,
    BRO = 308,
    BRC = 309,
    CO = 310,
    CC = 311,
    BO = 312,
    BC = 313,
    LEFT_ASSIGN = 314,
    ADD_ASSIGN = 315,
    SUB_ASSIGN = 316,
    MUL_ASSIGN = 317,
    INC_OP = 318,
    DEC_OP = 319,
    PTR_OP = 320,
    GE_OP = 321,
    EQ_OP = 322,
    NE_OP = 323,
    ELLIPSIS = 324,
    RIGHT_ASSIGN = 325,
    DIV_ASSIGN = 326,
    MOD_ASSIGN = 327,
    AND_ASSIGN = 328,
    XOR_ASSIGN = 329,
    OR_ASSIGN = 330,
    RIGHT_OP = 331,
    LEFT_OP = 332,
    AND_OP = 333,
    OR_OP = 334,
    LE_OP = 335,
    IDENTIFIER = 336,
    PUNCTUATORS = 337,
    COMMENT = 338,
    INT_CONSTANT = 339,
    STRING_LITERAL = 340,
    FLOAT_CONSTANT = 341,
    ENU_CONSTANT = 342,
    CHAR_CONSTANT = 343
  };
#endif
/* Tokens.  */
#define TYPEDEF 258
#define EXTERN 259
#define STATIC 260
#define AUTO 261
#define REGISTER 262
#define INLINE 263
#define RESTRICT 264
#define MATRIX 265
#define HAS 266
#define POW 267
#define UOR 268
#define CHAR 269
#define SHORT 270
#define INT 271
#define LONG 272
#define SIGNED 273
#define UNSIGNED 274
#define FLOAT 275
#define DOUBLE 276
#define CONST 277
#define VOLATILE 278
#define VOID 279
#define EQ 280
#define COM 281
#define BOOL 282
#define COMPLEX 283
#define IMAGINARY 284
#define DCOMM 285
#define STRUCT 286
#define UNION 287
#define ENUM 288
#define DOT 289
#define LET 290
#define GET 291
#define Q 292
#define POL 293
#define SECOL 294
#define BREAK 295
#define CASE 296
#define CONTINUE 297
#define DEFAULT 298
#define DO 299
#define IF 300
#define ELSE 301
#define FOR 302
#define GOTO 303
#define WHILE 304
#define SWITCH 305
#define SIZEOF 306
#define RETURN 307
#define BRO 308
#define BRC 309
#define CO 310
#define CC 311
#define BO 312
#define BC 313
#define LEFT_ASSIGN 314
#define ADD_ASSIGN 315
#define SUB_ASSIGN 316
#define MUL_ASSIGN 317
#define INC_OP 318
#define DEC_OP 319
#define PTR_OP 320
#define GE_OP 321
#define EQ_OP 322
#define NE_OP 323
#define ELLIPSIS 324
#define RIGHT_ASSIGN 325
#define DIV_ASSIGN 326
#define MOD_ASSIGN 327
#define AND_ASSIGN 328
#define XOR_ASSIGN 329
#define OR_ASSIGN 330
#define RIGHT_OP 331
#define LEFT_OP 332
#define AND_OP 333
#define OR_OP 334
#define LE_OP 335
#define IDENTIFIER 336
#define PUNCTUATORS 337
#define COMMENT 338
#define INT_CONSTANT 339
#define STRING_LITERAL 340
#define FLOAT_CONSTANT 341
#define ENU_CONSTANT 342
#define CHAR_CONSTANT 343

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "ass5_15CS10031.y" /* yacc.c:355  */

	int instr;
	float floatval;
	sym* symp;
	//expr* exp;
	int intval;
	unary* A;
	lint* nl;
	symtype* st;
	char* strval;
	matrixinit *mat;
	statement* stat;
	char uop;	//unary operator

#line 317 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 334 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   630

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  307

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    94,    92,     2,
       2,     2,    89,    90,     2,    91,     2,    93,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   103,   110,   119,   126,   130,   137,   144,
     149,   154,   165,   188,   203,   204,   210,   211,   215,   240,
     248,   270,   275,   284,   303,   429,   453,   463,   467,   470,
     473,   479,   484,   494,   516,   529,   545,   556,   569,   573,
     575,   586,   599,   615,   631,   632,   647,   666,   686,   714,
     719,   721,   736,   738,   758,   759,   779,   780,   798,   799,
     819,   842,   848,   885,   891,   893,   894,   895,   896,   897,
     898,   899,   901,   902,   903,   907,   911,   917,   925,   928,
     936,   937,   943,   946,   950,   970,   978,   981,   982,   985,
     988,   989,   990,   993,   994,   995,   996,   997,  1003,  1004,
    1014,  1019,  1023,  1048,  1071,  1087,  1090,  1112,  1116,  1127,
    1132,  1133,  1139,  1143,  1148,  1149,  1155,  1175,  1181,  1191,
    1202,  1212,  1213,  1218,  1223,  1228,  1230,  1235,  1236,  1243,
    1247,  1252,  1256,  1260,  1262,  1269,  1270,  1271,  1275,  1276,
    1282,  1300,  1308,  1317,  1330,  1333,  1337,  1348,  1357,  1380,
    1392,  1400,  1412,  1426,  1427,  1428,  1432,  1440,  1445,  1448,
    1452,  1453,  1460,  1467,  1473,  1475
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "RESTRICT", "MATRIX", "HAS", "POW", "UOR", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "EQ", "COM", "BOOL", "COMPLEX", "IMAGINARY", "DCOMM",
  "STRUCT", "UNION", "ENUM", "DOT", "LET", "GET", "Q", "POL", "SECOL",
  "BREAK", "CASE", "CONTINUE", "DEFAULT", "DO", "IF", "ELSE", "FOR",
  "GOTO", "WHILE", "SWITCH", "SIZEOF", "RETURN", "BRO", "BRC", "CO", "CC",
  "BO", "BC", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "INC_OP", "DEC_OP", "PTR_OP", "GE_OP", "EQ_OP", "NE_OP", "ELLIPSIS",
  "RIGHT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "RIGHT_OP", "LEFT_OP", "AND_OP", "OR_OP", "LE_OP",
  "IDENTIFIER", "PUNCTUATORS", "COMMENT", "INT_CONSTANT", "STRING_LITERAL",
  "FLOAT_CONSTANT", "ENU_CONSTANT", "CHAR_CONSTANT", "'*'", "'+'", "'-'",
  "'&'", "'/'", "'%'", "$accept", "M", "N", "CST", "primary_expression",
  "constant", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "pointer",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "initializer", "initializer_row_list",
  "initializer_row", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,    42,
      43,    45,    38,    47,    37
};
# endif

#define YYPACT_NINF -205

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-205)))

#define YYTABLE_NINF -5

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     208,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,   -20,   208,   602,  -205,  -205,  -205,
     -38,  -205,    19,     8,  -205,   460,   -13,   -33,  -205,  -205,
    -205,     0,  -205,   -38,  -205,   457,    51,  -205,   -20,   208,
      25,   469,   -13,  -205,  -205,    85,   310,   519,   519,   519,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,    56,
    -205,   146,   444,   519,  -205,    18,   -59,   -39,    64,    50,
      31,   114,   120,    65,   -29,  -205,  -205,  -205,   243,  -205,
      51,  -205,  -205,   121,    15,    98,   102,    87,   519,  -205,
      -9,   143,   457,   -11,  -205,  -205,    68,  -205,  -205,   519,
    -205,    89,   507,  -205,  -205,    91,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,   519,  -205,  -205,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,    95,   -26,  -205,   140,
     519,   147,   144,  -205,   130,   132,   107,  -205,   135,   376,
    -205,   153,    10,  -205,  -205,  -205,  -205,   142,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,   -38,   150,   172,  -205,   119,
    -205,   145,   156,  -205,  -205,   157,   310,  -205,   310,  -205,
    -205,  -205,   519,  -205,     1,  -205,  -205,    69,  -205,  -205,
    -205,  -205,  -205,  -205,    18,    18,   -59,   -59,   -39,   -39,
     -39,   -39,    64,    64,    50,    31,   114,  -205,  -205,  -205,
    -205,   164,  -205,   364,   364,   519,   408,   177,   165,   519,
    -205,    77,   364,  -205,  -205,   298,  -205,  -205,   208,  -205,
    -205,   519,   173,   143,  -205,   457,  -205,   174,   519,  -205,
     519,   519,   519,   364,  -205,  -205,   212,  -205,  -205,   519,
     212,  -205,  -205,  -205,  -205,   176,   519,  -205,   519,  -205,
     120,   212,    65,  -205,   192,   186,   408,    72,   187,  -205,
     188,     2,   206,   190,  -205,   191,  -205,  -205,  -205,  -205,
    -205,   519,   364,  -205,   519,   364,   364,   519,    76,  -205,
     364,   212,  -205,  -205,  -205,   210,   204,  -205,   195,  -205,
    -205,  -205,  -205,   364,   364,  -205,  -205
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    86,    87,    88,    90,    93,    94,    91,    92,
      89,    95,    96,   161,     0,    81,     0,   159,   160,    79,
       0,   100,   108,     0,    83,    85,    98,     0,    80,     1,
     158,     0,   107,     0,    78,     0,     0,   165,     0,     4,
       4,     0,    99,   101,    82,    85,     0,     0,     0,     0,
       5,     9,     7,    11,    10,    27,    28,    29,    30,    19,
       8,    26,    31,     0,    33,    38,    39,    44,    49,    50,
      52,    54,    56,    58,    61,    63,   117,    84,     0,   162,
       0,   164,   114,     0,     0,     0,     0,     0,     0,   120,
       0,   118,     0,     0,   126,    75,     0,    25,    23,     0,
      13,     0,     0,    20,    12,     0,    64,    70,    68,    69,
      65,    71,    66,    67,    72,    73,    74,     0,    31,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     2,     0,     0,     0,     2,     0,     0,
     138,     5,     0,   143,   142,   133,   129,     2,   141,   130,
     132,   131,   134,   163,   106,   113,     0,   109,   110,     0,
     105,     0,     0,   128,    77,     0,     0,   116,     0,   121,
     124,   125,     0,     6,     0,    16,    14,     0,    22,    17,
      62,    32,    34,    35,    36,    37,    40,    41,    42,    45,
      43,    46,    47,    48,    51,    53,    55,     2,     2,     2,
     154,     0,   153,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,   144,   139,     0,   112,   104,     0,   115,
     103,     0,     0,   119,   122,     0,    76,     0,     0,    15,
       0,     0,     0,     0,   137,     2,     3,     2,   157,     0,
       3,   156,   135,   140,   111,     0,     0,   123,     0,    21,
      57,     3,    59,   136,     0,     0,     0,     0,     0,   102,
       0,     0,     0,     0,     2,     2,     2,     2,   127,    18,
       2,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       0,     3,   151,     3,    60,     0,   147,   150,     0,   146,
     149,     2,     2,     0,     0,   148,   152
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -118,   -72,    81,  -205,  -205,  -205,  -205,   -48,  -205,
     -54,    23,    38,    24,    35,   123,   131,   133,    14,    27,
    -205,   -75,    17,  -205,   -44,  -134,   -21,     5,  -205,   233,
    -205,    -4,   245,   251,  -205,  -205,    46,  -205,   -28,  -205,
      99,   100,  -205,   183,  -189,  -205,   -10,  -205,    52,  -204,
    -205,  -205,  -205,  -205,   263,  -205,  -205
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   214,   136,    36,    59,    60,    61,   187,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    95,   117,   152,   175,    13,    38,    23,    24,
      15,    45,    26,    27,   166,   167,   168,    84,    89,    90,
      91,    92,    93,    94,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    16,    17,    18,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,    98,   137,    96,    37,    14,   211,    77,    -3,   119,
      25,   208,   247,   174,   180,   118,    31,    20,    81,    19,
      28,    14,    20,    87,   244,   245,    79,   182,   182,   218,
     176,   123,   124,   252,    33,    20,   182,   125,   126,   225,
     118,   169,    40,    21,    41,   177,    88,    34,    21,   223,
      -3,    22,    76,   209,   263,   184,    43,   153,    86,   237,
     279,    21,   275,    76,   179,   174,   191,   192,   193,    22,
     163,   170,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   165,   240,
     241,   242,   118,   289,   182,   238,   292,   293,   182,   127,
     128,   297,   182,   182,    78,   221,    82,   120,    22,    76,
      35,   121,   122,    99,   305,   306,   251,   131,   132,   188,
      80,    83,   270,   133,   183,   239,   134,   264,   276,   266,
     129,     1,   295,   135,   190,     2,     3,     4,     5,     6,
       7,     8,     9,    -3,   130,    10,   194,   195,    11,    12,
     234,   198,   199,   200,   201,   171,   282,   284,   285,   286,
     172,   226,   287,   196,   197,   290,   202,   203,   173,   178,
     185,   246,   189,   207,   265,   250,   100,   164,   268,   210,
     101,   174,   213,   303,   304,   215,   212,   216,   217,   272,
     219,   222,   118,    76,   118,    76,   224,   261,   228,   236,
     229,   102,   243,   230,   153,   267,   227,   257,   118,   103,
     104,   105,   294,   231,   271,   232,   248,   296,     1,   298,
     249,   299,     2,     3,     4,     5,     6,     7,     8,     9,
     256,   258,    10,   165,   269,    11,    12,   288,   182,   118,
     291,   273,   274,   277,   280,   281,   278,   283,   255,   300,
     301,   302,    76,     1,   260,   259,   204,     2,     3,     4,
       5,     6,     7,     8,     9,   205,    44,    10,   206,   262,
      11,    12,    42,    32,   254,   233,   181,   253,   235,    30,
       0,     0,   138,   139,   140,   141,   142,   143,   144,     0,
     145,   146,   147,   148,     0,   149,    78,   150,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,     1,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    10,     0,   151,    11,    12,    51,    52,    53,
       0,    54,    55,    56,    57,    58,     0,   138,   139,   140,
     141,   142,   143,   144,    87,   145,   146,   147,   148,     0,
     149,    78,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    46,     0,    47,     0,    88,     0,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,   151,
       0,     0,    51,    52,    53,     0,    54,    55,    56,    57,
      58,    50,     0,     0,    51,    52,    53,     0,    54,    55,
      56,    57,    58,   138,   139,   140,   141,   142,   143,   144,
       0,   145,   146,   147,   148,   220,   149,    78,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,   151,     0,   138,    51,    52,
      53,     0,    54,    55,    56,    57,    58,    50,     0,     0,
      51,    52,    53,    47,    54,    55,    56,    57,    58,   106,
       1,    48,    49,     0,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,    35,     0,    11,    12,    50,
       0,     0,    51,    52,    53,     0,    54,    55,    56,    57,
      58,     0,     0,   107,   108,   109,   110,     0,     0,     0,
      46,     0,    47,    -4,   111,   112,   113,   114,   115,   116,
      48,    49,     0,     0,    47,     0,     0,    85,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,    50,     0,
       0,    51,    52,    53,     0,    54,    55,    56,    57,    58,
      50,     0,     0,    51,    52,    53,     0,    54,    55,    56,
      57,    58,    47,   186,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,    50,     0,
       0,    51,    52,    53,     0,    54,    55,    56,    57,    58,
      50,     0,    29,    51,    52,    53,     0,    54,    55,    56,
      57,    58,     1,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    10,     0,     0,    11,
      12
};

static const yytype_int16 yycheck[] =
{
      48,    49,    74,    47,    25,     0,   140,    35,    37,    63,
      14,    37,   216,    88,    25,    63,    20,    55,    39,    39,
      15,    16,    55,    34,   213,   214,    36,    26,    26,   147,
      39,    90,    91,   222,    26,    55,    26,    76,    77,   157,
      88,    26,    55,    81,    57,    54,    57,    39,    81,    39,
      79,    89,    35,    79,   243,    99,    56,    78,    41,    58,
      58,    81,   266,    46,    92,   140,   120,   121,   122,    89,
      80,    56,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    83,   207,
     208,   209,   140,   282,    26,    26,   285,   286,    26,    35,
      36,   290,    26,    26,    53,   149,    81,    89,    89,    92,
      25,    93,    94,    57,   303,   304,    39,    67,    68,   102,
      39,    40,   256,    92,    56,    56,    12,   245,    56,   247,
      66,    10,    56,    13,   117,    14,    15,    16,    17,    18,
      19,    20,    21,    78,    80,    24,   123,   124,    27,    28,
     178,   127,   128,   129,   130,    57,   274,   275,   276,   277,
      58,   165,   280,   125,   126,   283,   131,   132,    81,    26,
      81,   215,    81,    78,   246,   219,    30,    56,   250,    39,
      34,   256,    38,   301,   302,    55,    39,    55,    81,   261,
      55,    38,   240,   176,   242,   178,    54,   241,    26,   182,
      81,    55,    38,    58,   225,   249,    56,   235,   256,    63,
      64,    65,   287,    57,   258,    58,    39,   289,    10,   291,
      55,   293,    14,    15,    16,    17,    18,    19,    20,    21,
      57,    57,    24,   228,    58,    27,    28,   281,    26,   287,
     284,    49,    56,    56,    38,    55,    58,    56,   231,    39,
      46,    56,   235,    10,   240,   238,   133,    14,    15,    16,
      17,    18,    19,    20,    21,   134,    33,    24,   135,   242,
      27,    28,    27,    22,   228,   176,    93,   225,   178,    16,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    10,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    -1,    81,    27,    28,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    -1,    39,    40,    41,
      42,    43,    44,    45,    34,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    53,    -1,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    81,    -1,    -1,    84,    85,    86,    -1,    88,    89,
      90,    91,    92,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    50,    39,    52,    53,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    81,    -1,    39,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    81,    -1,    -1,
      84,    85,    86,    55,    88,    89,    90,    91,    92,    25,
      10,    63,    64,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    27,    28,    81,
      -1,    -1,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      53,    -1,    55,    53,    70,    71,    72,    73,    74,    75,
      63,    64,    -1,    -1,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      81,    -1,    -1,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      81,    -1,     0,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    -1,    -1,    27,
      28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    14,    15,    16,    17,    18,    19,    20,    21,
      24,    27,    28,   121,   122,   125,   148,   149,   150,    39,
      55,    81,    89,   123,   124,   126,   127,   128,   122,     0,
     149,   126,   128,    26,    39,    25,    98,   121,   122,   151,
      55,    57,   127,    56,   124,   126,    53,    55,    63,    64,
      81,    84,    85,    86,    88,    89,    90,    91,    92,    99,
     100,   101,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   133,    53,   141,
      98,   121,    81,    98,   132,    58,   117,    34,    57,   133,
     134,   135,   136,   137,   138,   117,   119,   103,   103,    57,
      30,    34,    55,    63,    64,    65,    25,    59,    60,    61,
      62,    70,    71,    72,    73,    74,    75,   118,   103,   105,
      89,    93,    94,    90,    91,    76,    77,    35,    36,    66,
      80,    67,    68,    92,    12,    13,    97,    97,    39,    40,
      41,    42,    43,    44,    45,    47,    48,    49,    50,    52,
      54,    81,   119,   121,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   141,    56,   122,   129,   130,   131,    26,
      56,    57,    58,    81,   116,   120,    39,    54,    26,   133,
      25,   138,    26,    56,   119,    81,    56,   102,   117,    81,
     117,   105,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   109,   109,   110,   111,   112,    78,    37,    79,
      39,   120,    39,    38,    96,    55,    55,    81,    96,    55,
      39,   119,    38,    39,    54,    96,   126,    56,    26,    81,
      58,    57,    58,   135,   133,   136,   117,    58,    26,    56,
      96,    96,    96,    38,   139,   139,   119,   144,    39,    55,
     119,    39,   139,   143,   131,   117,    57,   133,    57,   117,
     113,   119,   114,   139,    96,    97,    96,   119,    97,    58,
     120,   119,    97,    49,    56,   144,    56,    56,    58,    58,
      38,    55,    96,    56,    96,    96,    96,    96,   119,   139,
      96,   119,   139,   139,   116,    56,    97,   139,    97,    97,
      39,    46,    56,    96,    96,   139,   139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    98,    99,    99,    99,    99,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   103,   103,   103,   103,   104,   104,   104,
     104,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   135,   135,   136,   137,   137,   138,   138,   139,
     139,   139,   139,   139,   139,   140,   140,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   145,   146,
     146,   146,   146,   147,   147,   147,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     1,     3,     1,     1,     1,
       1,     1,     2,     2,     3,     4,     3,     3,     7,     1,
       2,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     5,
       9,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     7,     5,     5,     4,     4,     2,     1,     1,
       1,     3,     2,     1,     1,     3,     3,     1,     1,     3,
       1,     2,     3,     4,     2,     2,     1,     6,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       3,     1,     1,     1,     2,     1,     8,     8,    11,     9,
       8,     7,    11,     2,     2,     2,     3,     3,     2,     1,
       1,     1,     4,     5,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 99 "ass5_15CS10031.y" /* yacc.c:1646  */
    {	// To store the address of the next instruction for further use.
		(yyval.instr) = nextinstr();
	}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "ass5_15CS10031.y" /* yacc.c:1646  */
    { 	// Non terminal to prevent fallthrough by emitting a goto
		debug ("n");
		(yyval.A)  = new unary();
		(yyval.A)->nextlist = makelist(nextinstr());
		emit (GOTOOP,"");
		debug ("n2");
}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "ass5_15CS10031.y" /* yacc.c:1646  */
    { // Used for changing to symbol table for a function
		if (currsym->nest==NULL) changeTable(new symtab(""));	// Function symbol table doesn't already exist
		else {
			changeTable (currsym ->nest);						// Function symbol table already exists
			emit (FUNC, table->tname);
		}
	}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		//cout<<"primary_expression=> Identifier"<<endl;
		(yyval.A) = new unary();
		(yyval.A)->symp = (yyvsp[0].symp);
		(yyval.A)->isbool = false;
	}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[-1].A);
	}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		(yyval.A)->symp = gentemp(PTR, (yyvsp[0].strval));      // temp variable of type PTR
		(yyval.A)->symp->initialize((yyvsp[0].strval));         // initialise
		(yyval.A)->symp->type->ptr = new symtype(_CHAR);
	}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		(yyval.A)->symp = (yyvsp[0].symp);
	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 144 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = gentemp(_INT, NumberToString((yyvsp[0].intval)));                 
		emit(EQUAL, (yyval.symp)->name, (yyvsp[0].intval));                                // $$-name = $1
	}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = gentemp(_CHAR);
		emit(EQUAL, (yyval.symp)->name, "a");                               // $$->name = a
	}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 154 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = gentemp(_DOUBLE, *new string ((yyvsp[0].strval)));
		emit(EQUAL, (yyval.symp)->name, *new string((yyvsp[0].strval)));
	}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 165 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
	  //cout<<"post_fix++"<<endl;
		(yyval.A) = new unary();
		
		if((yyvsp[-1].A)->ismatrix ){
			(yyval.A)->symp = gentemp(_DOUBLE);
			sym *temp = gentemp(_DOUBLE);
			
			emit(ARRR, temp->name , (yyvsp[-1].A)->symp->name , (yyvsp[-1].A)->loc->name);    // temp->name = $1->symp->name[$1->symp->loc]
			emit(EQUAL,(yyval.A)->symp->name,temp->name);                      // $$->symp->name = temp->name
			emit( SUB, temp->name , temp->name , "1");	                // temp->name = temp->name -1 
			emit(ARRL, (yyvsp[-1].A)->symp->name,(yyvsp[-1].A)->loc->name,temp->name);	      // $1->symp->name[$1->symp->loc] = temp->name
		}
		else{
		                                                              // copy $1 to $$
			(yyval.A)->symp = gentemp((yyvsp[-1].A)->symp->type->cat);
			string ss = (yyval.A)->symp->name ; 
			emit (EQUAL, (yyval.A)->symp->name, (yyvsp[-1].A)->symp->name);               // $$->symp->name = $1->symp->name

		                                                                // Decrement $1
			emit (SUB, (yyvsp[-1].A)->symp->name, (yyvsp[-1].A)->symp->name, "1");            // $1->symp->name = $1->symp->name - 1
		}
	}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 188 "ass5_15CS10031.y" /* yacc.c:1646  */
    {                                     // calculate transpose
		(yyval.A) = new unary();
		(yyval.A)->symp = gentemp(_DOUBLE);
		sym *temp = gentemp(_DOUBLE);
			
			emit(ARRR, temp->name , (yyvsp[-1].A)->symp->name , (yyvsp[-1].A)->loc->name);
			emit(EQUAL,(yyval.A)->symp->name,temp->name);
		//$$->symp = gentemp(_DOUBLE);
		sym* t = gentemp(_DOUBLE);

		emit(MULT,t->name,NumberToString((yyvsp[-1].A)->symp->type->length),NumberToString((yyvsp[-1].A)->symp->type->width));    // calculate new offset
		emit(SUB,t->name,t->name,(yyvsp[-1].A)->loc->name);
		emit(ARRR,t->name,(yyvsp[-1].A)->symp->name,t->name);                    // t->name = $1->symp->name[t->name]
		emit(ARRL,(yyvsp[-1].A)->symp->name,(yyvsp[-1].A)->loc->name,t->name);              // $1->symp->name[$$->loc->name] = t->name
	}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 204 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		(yyval.A)->symp = gentemp((yyvsp[-3].A)->type->cat);
		string ss = (yyval.A)->symp->name;
		emit(CALL, (yyval.A)->symp->name, (yyvsp[-3].A)->symp->name, tostr((yyvsp[-1].intval)));
	}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
	  //	cout<<"postfix_expression => primary_expression [expression] [expression]\n";
    //int i=0;
    //cout<<i<<endl; i++;
		(yyval.A) = new unary();
    //cout<<i<<endl; i++;
		(yyval.A)->ismatrix = true;
    //cout<<i<<endl; i++;
		(yyval.A)->symp = (yyvsp[-6].A)->symp;
    //cout<<i<<endl; i++;
		sym* t = gentemp(_DOUBLE);
    //cout<<i<<endl; i++;
		emit(MULT, t->name, (yyvsp[-4].A)->symp->name, NumberToString(8));       // offset = rownumber * totalcolumns *8 
    //cout<<i<<endl; i++;
    	emit(MULT,t->name,t->name,NumberToString((yyvsp[-6].A)->symp->type->length));
    sym* temp = gentemp(_DOUBLE);
    	emit(MULT,temp->name, (yyvsp[-1].A)->symp->name, NumberToString(8));
 		emit(ADD, t->name, temp->name, t->name);                      // offset = offset + column * 8
    //cout<<i<<endl; i++;
    (yyval.A)->loc=gentemp(_DOUBLE);
 		emit (EQUAL, (yyval.A)->loc->name, t->name );                        // $$->loc = offset
 		//emit (EQUAL, temporary->name,$$->loc->name );
    //$$->loc->init = $3->symp->init * $3->symp->size * $6->symp->init;
    //cout<<"postfix_expression => primary_expression [expression] [expression]\n";
	}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 240 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary ();
		//string ss = "null";
		(yyval.A)->symp = (yyvsp[0].A)->symp;
		(yyval.A)->loc = (yyval.A)->symp;
		//ss = "local";
		(yyval.A)->type = (yyvsp[0].A)->symp->type;
	}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		if((yyvsp[-1].A)->ismatrix){
			(yyval.A)->symp = gentemp(_DOUBLE);
			sym *temp = gentemp(_DOUBLE);
			emit(ARRR , temp->name , (yyvsp[-1].A)->symp->name , (yyvsp[-1].A)->loc->name);   // temp->name = $1->symp->name[$1->symp->loc]
			emit(EQUAL,(yyval.A)->symp->name,temp->name);                      // $$->symp->name = temp->name
			emit (ADD, temp->name, temp->name, "1");	                  // temp->name = temp->name + 1 
			emit(ARRL , (yyvsp[-1].A)->symp->name,(yyvsp[-1].A)->loc->name,temp->name);       // $1->symp->name[$1->symp->loc] = temp->name
		}else{
		                                                                // copy $1 to $$
		(yyval.A)->symp = gentemp((yyvsp[-1].A)->symp->type->cat);                      
		string ss = (yyval.A)->symp->name;
		emit (EQUAL, (yyval.A)->symp->name, (yyvsp[-1].A)->symp->name);                 // $$->symp->name = $1->symp->name

		                                                                // Increment $1
		emit (ADD, (yyvsp[-1].A)->symp->name, (yyvsp[-1].A)->symp->name, "1"); }          // $1->symp->name = $1->symp->name + 1
	}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 270 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		string ss = (yyvsp[0].A)->symp->name;
		emit (PARAM, (yyvsp[0].A)->symp->name);                               //param$3->symp->name
		(yyval.intval) = (yyvsp[-2].intval)+1;
	}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 275 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		string ss = (yyvsp[0].A)->symp->name;
		emit (PARAM, (yyvsp[0].A)->symp->name);                                   //param $1->symp->name
		(yyval.intval) = 1;
	}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 284 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].A)->ismatrix){
			(yyval.A) = new unary();
			(yyval.A)->symp = gentemp(_DOUBLE);
			emit(ARRR, (yyval.A)->symp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);      // $$->symp->name = $2->symp->name[$2->loc->name]
			emit( SUB, (yyval.A)->symp->name , (yyval.A)->symp->name , "1");	              // $$->symp->name = $$->symp->name -1
			emit(ARRL, (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name  , (yyval.A)->symp->name);     // $2->symp->name[$2->loc->name] =  $$->symp->name 

		}
		                                                                                    // Decrement $1
		else{
			(yyval.A) = new unary();
			string ss = (yyvsp[0].A)->symp->name;
			emit (SUB, (yyvsp[0].A)->symp->name, (yyvsp[0].A)->symp->name, "1");                    // $2->symp->name = $2->symp->name - 1
			ss += "null";
			                                                                                    // Use the same value
			(yyval.A) = (yyvsp[0].A);
		}
	}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 303 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = new unary();
		switch ((yyvsp[-1].uop)) {
			case '~':
				if((yyvsp[0].A)->ismatrix){

					(yyval.A)->symp = gentemp(_DOUBLE);
					emit(ARRR, (yyval.A)->symp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);      // $$->symp->name = $2->symp->name [$2->loc->name ]
					emit(BNOT, (yyval.A)->symp->name , (yyval.A)->symp->name);	                    //  $$->symp->name ~= $$->symp->name
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);

					break;
				}
				else{
					(yyval.A)->symp = gentemp((yyvsp[0].A)->symp->type->cat);
					int offs;
					emit (BNOT, (yyval.A)->symp->name, (yyvsp[0].A)->symp->name);                        //  $$->symp->name ~= $$->symp->name
					break;
				}
			case '+':
				if((yyvsp[0].A)->ismatrix){
				//	cout << "im herre\n";
					(yyval.A)->symp = gentemp(_DOUBLE);
					emit(ARRR, (yyval.A)->symp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);          // $$->symp->name = $2->symp->name [$2->loc->name ]
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);

					break;	
				}
				else{
					(yyval.A) = (yyvsp[0].A);
					break;
				}
			case '*':
					if((yyvsp[0].A)->ismatrix){
						(yyval.A)->symp = gentemp(_DOUBLE);
						(yyval.A)->symp->type->ptr = (yyvsp[0].A)->symp->type;
						sym* temp = gentemp(_DOUBLE);
						emit(ARRR, temp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);         // $$->symp->name = $2->symp->name [$2->loc->name ]
						emit (PTRR, (yyval.A)->symp->name, temp->name);
					//offset++;                                                             //  $$->symp->name = *$$->symp->name
						break;
					}
					else{
						debug ("got pointer");
						(yyval.A)->cat = PTR;
						debug ((yyvsp[0].A)->symp->name);
						(yyval.A)->loc = gentemp ((yyvsp[0].A)->symp->type->ptr);                    // temp of type ptr
						int offset;
						emit (PTRR, (yyval.A)->loc->name, (yyvsp[0].A)->symp->name);                   // $$->symp->name = *$$->symp->name 
						offset++;
						(yyval.A)->symp = (yyvsp[0].A)->symp;                                          
						debug ("here pointer");
						break;
					}
			
			case '&':
				if((yyvsp[0].A)->ismatrix){
					(yyval.A)->symp = gentemp(PTR);
					(yyval.A)->symp->type->ptr = (yyvsp[0].A)->symp->type;
					sym* temp = gentemp(_DOUBLE);                                         // $$->symp->name = $2->symp->name [$2->loc->name ]
					emit(ARRR, temp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);                  // $$->symp->name = &$$->symp->name 
					emit (ADDRESS, (yyval.A)->symp->name, temp->name);
					//offset++;
					break;
				}
				else{
					(yyval.A)->symp = gentemp(PTR);
					(yyval.A)->symp->type->ptr = (yyvsp[0].A)->symp->type; 
					int size;
					emit (ADDRESS, (yyval.A)->symp->name, (yyvsp[0].A)->symp->name);                       // $$->symp->name = &$2->symp->name 
					//offset++;
					break;
				}
			
			case '!':

				if((yyvsp[0].A)->ismatrix){
					int i=10;
					//cout << i++ << endl;
					(yyval.A)->symp = gentemp(_DOUBLE);
					//cout << i++ << endl;
					emit(ARRR, (yyval.A)->symp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);          // $$->symp->name = $2->symp->name [$2->loc->name ]
					//cout << i++ << endl;
					emit(LNOT, (yyval.A)->symp->name , (yyval.A)->symp->name);	                // $$->symp->name = !$$->symp->name 
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);
					cout << i++ << endl;
					break;

				}
				else{
					(yyval.A)->symp = gentemp((yyvsp[0].A)->symp->type->cat);
				
					emit (LNOT, (yyval.A)->symp->name, (yyvsp[0].A)->symp->name);                          // $$->symp->name = !$2->symp->name 
					
					break;
				}
			case '-':
				//cout << " - " << endl;
				if((yyvsp[0].A)->ismatrix){
					int i = 12;
					//cout << i++ << endl;
					sym* temp = gentemp(_DOUBLE);
					(yyval.A)->symp = gentemp(_DOUBLE);
					//cout << i++ << endl;
					emit(ARRR, temp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);    // $$->symp->name = $2->symp->name [$2->loc->name ]
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);
					//cout << i++ << endl;
					emit (UMINUS, (yyval.A)->symp->name, temp->name);                    // $$->symp->name = -$$->symp->name 
					//cout << i++ << endl;	
					break;	
				}
				else{

					(yyval.A)->symp = gentemp((yyvsp[0].A)->symp->type->cat);
				
					emit (UMINUS, (yyval.A)->symp->name, (yyvsp[0].A)->symp->name);                // $$->symp->name = -$2->symp->name 
				
					break;
				}
			
			default:
				break;
		}
	}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 429 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		
		if((yyvsp[0].A)->ismatrix){
			(yyval.A) = new unary();
			int i = 10;
			//cout << i++ << endl;
			(yyval.A)->symp = gentemp(_DOUBLE);
			//cout << i++ << endl;
			emit(ARRR, (yyval.A)->symp->name , (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name);    // $$->symp->name = $2->symp->name [$2->loc->name ]
			//cout << i++ << endl;
			emit(ADD , (yyval.A)->symp->name , (yyval.A)->symp->name , "1");	               // $$->symp->name = $$->symp->name - 1 
			//cout << i++ << endl;
			emit(ARRL, (yyvsp[0].A)->symp->name , (yyvsp[0].A)->loc->name  , (yyval.A)->symp->name);     // $2->symp->name[$2->loc->name] =  $$->symp->name 
			//cout << i++ << endl;
		}
		else{
			(yyval.A) = new unary();
		                                                                                            	// Increment $1
			emit (ADD, (yyvsp[0].A)->symp->name, (yyvsp[0].A)->symp->name, "1");
			                                                                                          // Use the same value
			(yyval.A) = (yyvsp[0].A);
		}
	}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 453 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[0].A);
		                                                                                    //cout << "as\n";
                                                                                 //		debug ($$->symp);
	}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 463 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.uop) = '*';
	}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 467 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.uop) = '+';
	}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 470 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.uop) = '-';
	}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 473 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.uop) = '&';
	}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 479 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[0].A);
	}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 484 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {                      // check for compatible types
			int x; 
			(yyval.A) = new unary();
			(yyval.A)->symp = gentemp((yyvsp[-2].A)->symp->type->cat);
			x = x + 1;
			emit (MULT, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);    // $$->symp->name = $1->symp->name * $3->symp->name
		}
		else cout << "Type Error"<< endl;
	}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 494 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		                                                    // Now the cast expression can't go to LHS of assignment_expression
		                                                    // So we can safely store the rvalues of pointer and arrays in temporary
		                                                    // We don't need to carry lvalues anymore
		(yyval.A) = new unary();
		if ((yyvsp[0].A)->cat==ARR) {                                       // Array
			string ss;
			(yyval.A)->symp = gentemp((yyvsp[0].A)->loc->type);
			ss = (yyval.A)->symp->name;
			emit(ARRR, (yyval.A)->symp->name, (yyvsp[0].A)->symp->name, (yyvsp[0].A)->loc->name);       // $$->symp->name = $1->symp->name[$1->loc->name]
		}
		else if ((yyvsp[0].A)->cat==PTR) {                                            // Pointer
			int z;
			(yyval.A)->symp = (yyvsp[0].A)->loc;
		}
		else {                                                              // otherwise
			int k;
			(yyval.A)->symp = (yyvsp[0].A)->symp;
		}
	}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 516 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		int z;
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {                          // check for compatible types
			(yyval.A) = new unary();
			int size;
			(yyval.A)->symp = gentemp((yyvsp[-2].A)->symp->type->cat);
			string ss = (yyval.A)->symp->name;
			size++;
			emit (DIVIDE, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);     // $$->symp->name = $1->symp->name / $3->symp->name
			size = size*size;
		}
		else cout << "Type Error"<< endl;
	}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 529 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {                        // check for compatible types
			(yyval.A) = new unary();
			int width;
			width--;
			(yyval.A)->symp = gentemp((yyvsp[-2].A)->symp->type->cat);
			string s1 = (yyval.A)->symp->name;
			emit (MODOP, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);    // $$->symp->name = $1->symp->name / $3->symp->name
		}
		else cout << "Type Error"<< endl;
	}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 545 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp)) {                       // check for compatible types
			(yyval.A) = new unary();
			int addint = 4;
			(yyval.A)->symp = gentemp((yyvsp[-2].A)->symp->type->cat);
			string ss = (yyval.A)->symp->name;
			emit (ADD, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);   // $$->symp->name = $1->symp->name + $3->symp->name
			addint+=4;
		}
		else cout << "Type Error"<< endl;
	}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 556 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp)) {                      // check for compatible types
			(yyval.A) = new unary();
			int addinteger = 4;
			(yyval.A)->symp = gentemp((yyvsp[-2].A)->symp->type->cat);
			int size;
			string ss = (yyval.A)->symp->name;
			size = 4;
			emit (SUB, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);   // $$->symp->name = $1->symp->name - $3->symp->name
			addinteger+=1;
		}
		else cout << "Type Error"<< endl;
	}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 569 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 573 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 575 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].A)->symp->type->cat == _INT) {
			(yyval.A) = new unary();
			int expression = 1;
			(yyval.A)->symp = gentemp (_INT);
			string ss = (yyval.A)->symp->name;
			emit (RIGHTOP, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);  // $$->symp->name = $1->symp->name >> $3->symp->name
			expression--;
		}
		else cout << "Type Error"<< endl;
	}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 586 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].A)->symp->type->cat == _INT) {
			(yyval.A) = new unary();
			int val = 1;
			(yyval.A)->symp = gentemp (_INT);
			string ss = (yyval.A)->symp->name;
			emit (LEFTOP, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);      // $$->symp->name = $1->symp->name << $3->symp->name
		}
		else cout << "Type Error"<< endl;
	}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 599 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			// New bool
			(yyval.A) = new unary();
			int val = 1;
			(yyval.A)->isbool = true;

			(yyval.A)->truelist = makelist (nextinstr());
			(yyval.A)->falselist = makelist (nextinstr()+1);
			int width;
			emit(LT, "", (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);             // $1->symp->name <= $3->symp->name goto truelist , else falselist
			val++;
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 615 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			// New bool
			(yyval.A) = new unary();
			int nval = 4;
			(yyval.A)->isbool = true;
			(yyval.A)->truelist = makelist (nextinstr());
			(yyval.A)->falselist = makelist (nextinstr()+1);
			int width;
			nval++;
			emit(LE, "", (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);                 // $1->symp->name >= $3->symp->name goto truelist , else falselist
			emit (GOTOOP, "");
			nval++;
		}
		else cout << "Type Error"<< endl;
	}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 631 "ass5_15CS10031.y" /* yacc.c:1646  */
    { (yyval.A) = (yyvsp[0].A);}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 632 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			// New bool
			(yyval.A) = new unary();
			(yyval.A)->isbool = true;

			(yyval.A)->truelist = makelist (nextinstr());
			(yyval.A)->falselist = makelist (nextinstr()+1);
			int width ;
			emit(GT, "", (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);             // $1->symp->name > $3->symp->name goto truelist , else falselist
			emit (GOTOOP, "");
			width = 4;
		}
		else cout << "Type Error"<< endl;
	}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 647 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			// New bool
			(yyval.A) = new unary();
			(yyval.A)->isbool = true;
			int address = 0;
			(yyval.A)->truelist = makelist (nextinstr()); 
			(yyval.A)->falselist = makelist (nextinstr()+1);
			int width;
			emit(LE, "", (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);          // $1->symp->name < $3->symp->name goto truelist , else falselist
			emit (GOTOOP, "");
			address++;
		}
		else cout << "Type Error"<< endl;
	}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 666 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			                                                                                // If any is bool get its value
		
			convertfrombool ((yyvsp[-2].A));
			convertfrombool ((yyvsp[0].A));
			int eqal = 1;
			(yyval.A) = new unary();
			(yyval.A)->isbool = true;
			eqal++;
			(yyval.A)->truelist = makelist (nextinstr());
			(yyval.A)->falselist = makelist (nextinstr()+1);
			int width;
			emit (EQOP, "", (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);
			eqal++;
			emit (GOTOOP, "");
			eqal++;
		}
		else cout << "Type Error"<< endl;
	}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 686 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			                                                                            // If any is bool get its value
			int i=11;
			//cout << i++ << endl;
			convertfrombool ((yyvsp[-2].A));
			//cout << i++ << endl;
			convertfrombool ((yyvsp[0].A));
			//cout << i++ << endl;
			string str = "null";
			(yyval.A) = new unary();
			//cout << i++ << endl;
			(yyval.A)->isbool = true;
			//cout << i++ << endl;
			str+="temp";
			(yyval.A)->truelist = makelist (nextinstr());                      // truelist
			//cout << i++ << endl;
			(yyval.A)->falselist = makelist (nextinstr()+1);                           // falselist
			//cout << i++ << endl;
			int width;
			str+="local";
			emit (NEOP, "", (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);      // $1->symp->name!=$3->symp->name goto truelist, else goto falselist
			//cout << i++ << endl;
			emit (GOTOOP,"");
			str+="local";
		}
		else cout << "Type Error"<< endl;
	}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 714 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 719 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 721 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			(yyval.A) = new unary();
			(yyval.A)->isbool = false;
			string typeinit = "null";
			(yyval.A)->symp = gentemp (_INT);
			string ss = (yyval.A)->symp->name;
			emit (BAND, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);    // $$->symp->name = $1->symp->name & $3->symp->name
			typeinit += "temp";
		}
		else cout << "Type Error"<< endl;
	}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 736 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 738 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			                                                                            // If any is bool get its value
			convertfrombool ((yyvsp[-2].A));
			string ssx = "null";
			convertfrombool ((yyvsp[0].A));
			ssx+="temp";
			(yyval.A) = new unary();
			(yyval.A)->isbool = false;
			ssx+="local";
			(yyval.A)->symp = gentemp (_INT);
			string ss = (yyval.A)->symp->name;
			emit (XOR, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);     // $$->symp->name = $1->symp->name ^ $3->symp->name
			ssx+="empty";
		}
		else cout << "Type Error"<< endl;
	}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 758 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 759 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		if (typecheck ((yyvsp[-2].A)->symp, (yyvsp[0].A)->symp) ) {
			                                                                                  // If any is bool get its value
			convertfrombool ((yyvsp[-2].A));
			string uniq= "null";
			convertfrombool ((yyvsp[0].A));
			uniq+="local";
			(yyval.A) = new unary();
			(yyval.A)->isbool = false;
			uniq+="temp";
			(yyval.A)->symp = gentemp (_INT);
			string ss = (yyval.A)->symp->name;
			emit (INOR, (yyval.A)->symp->name, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);
			uniq+="temp";
		}
		else cout << "Type Error"<< endl;
	}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 779 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 780 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		convert2bool((yyvsp[0].A));
		string convboo = "null";
		                                                                                // N to convert $1 to bool
		backpatch((yyvsp[-3].A)->nextlist, nextinstr());
		convert2bool((yyvsp[-4].A));
		convboo+="temp";
		(yyval.A) = new unary();
		(yyval.A)->isbool = true;
		convboo+="local";
		backpatch((yyvsp[-4].A)->truelist, (yyvsp[-1].instr));
		(yyval.A)->truelist = (yyvsp[0].A)->truelist;
		(yyval.A)->falselist = merge ((yyvsp[-4].A)->falselist, (yyvsp[0].A)->falselist);
		convboo+="null";
	}
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 798 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 799 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		convert2bool((yyvsp[0].A));
		string convbool = "null";
		                                                                                // N to convert $1 to bool
		backpatch((yyvsp[-3].A)->nextlist, nextinstr());
		convert2bool((yyvsp[-4].A));
		convbool+="temp";
		(yyval.A) = new unary();
		(yyval.A)->isbool = true;
		convbool+="true";
		backpatch ((yyval.A)->falselist, (yyvsp[-1].instr));
		(yyval.A)->truelist = merge ((yyvsp[-4].A)->truelist, (yyvsp[0].A)->truelist);
		(yyval.A)->falselist = (yyvsp[0].A)->falselist;
		convbool+= "true";
	}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 819 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
                                                                                              //		convert2bool($5);
		(yyval.A)->symp = gentemp();
		(yyval.A)->symp->update((yyvsp[-4].A)->symp->type);
		string sss = "null";
		emit(EQUAL, (yyval.A)->symp->name, (yyvsp[0].A)->symp->name);
		lint l = makelist(nextinstr());
		emit (GOTOOP, "");
		sss+="local";
		backpatch((yyvsp[-3].A)->nextlist, nextinstr());
		emit(EQUAL, (yyval.A)->symp->name, (yyvsp[-4].A)->symp->name);
		lint m = makelist(nextinstr());
		l = merge (l, m);
		string s = "";
		emit (GOTOOP, "");
		sss+="temp";
		backpatch((yyvsp[-7].A)->nextlist, nextinstr());
		convert2bool ((yyvsp[-8].A));
		backpatch ((yyvsp[-8].A)->truelist, (yyvsp[-5].instr));
		backpatch ((yyvsp[-8].A)->falselist, (yyvsp[-1].instr));
		backpatch (l, nextinstr());
		sss+="null";
	}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 842 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.A) = (yyvsp[0].A);}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 848 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		switch ((yyvsp[-2].A)->cat) {
			                                                                                            //cout << "IM HERE" << endl;
			case ARR:
				//cout << "ARR" << endl;
				emit(ARRL,(yyvsp[-2].A)->symp->name,(yyvsp[-2].A)->loc->name,(yyvsp[0].A)->symp->name);
				(yyval.A) = (yyvsp[0].A);
				break;
			case PTR:
				int off;
				emit(PTRL, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);
				(yyval.A) = (yyvsp[0].A);	
				break;
			default:
				//cout << "def\n";
				if((yyvsp[-2].A)->ismatrix){
					//cout << "MATRIX" << endl;
					emit(ARRL,(yyvsp[-2].A)->symp->name,(yyvsp[-2].A)->loc->name,(yyvsp[0].A)->symp->name);         // $1->symp->name = $1->loc->name[$3->symp->name]
				(yyval.A) = (yyvsp[0].A);
				break;
				}
				else{
						 
							//cout << "default" << endl;
							(yyvsp[0].A)->symp = conv((yyvsp[0].A)->symp, (yyvsp[-2].A)->symp->type->cat);
							string s = (yyvsp[-2].A)->symp->name;
							emit(EQUAL, (yyvsp[-2].A)->symp->name, (yyvsp[0].A)->symp->name);
							(yyval.A) = (yyvsp[0].A);
							break;
						
				}	
				
		}
		//cout << "out switch" << endl;
		
	}
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 885 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[0].A);
	}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 907 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		//cout << "exp ==> assignment_expression\n";
		(yyval.A) = (yyvsp[0].A);
	}
#line 2715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 913 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("expression\n");}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 918 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("constant_expression\n");}
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 925 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		debug ("declaration");
	}
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 928 "ass5_15CS10031.y" /* yacc.c:1646  */
    {

	}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 936 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("declaration_specifiers\n");}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 943 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		debug("init_declarator_list");
	}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 950 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		//int i =111;
		//cout << i++ << endl;
		debug ((yyvsp[-2].symp)->name);
		//cout << i++ << endl;
		debug ((yyvsp[0].symp)->name);
		//cout << i++ << endl;
		debug ((yyvsp[0].symp)->init);
		//cout << i++ << endl;
		//cout << $3->init << endl;
		//cout << "declarator EQ initializer1" << endl;
		if ((yyvsp[0].symp)->init!="") {//cout << i++ << endl;
			(yyvsp[-2].symp)->initialize((yyvsp[0].symp)->init);}
			//cout << "declarator EQ initializer2" << endl;
		//cout << i++ << endl;
		emit (EQUAL, (yyvsp[-2].symp)->name, (yyvsp[0].symp)->name);
		//cout << "declarator EQ initializer3" << endl;                                                    // $1->name = $3->name
		//cout << i++ << endl;
		debug ("here init");
	}
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 970 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = (yyvsp[0].symp);
	}
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 978 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		TYPE = _CHAR;
	}
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 982 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		TYPE = _INT;
	}
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 985 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		TYPE = _VOID;
	}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 990 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		TYPE = _DOUBLE;
	}
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1004 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		symtype * t = (yyvsp[-1].st);
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = (yyvsp[0].symp)->type;
		(yyval.symp) = (yyvsp[0].symp)->update((yyvsp[-1].st));
	}
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1014 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = (yyvsp[0].symp)->update(TYPE);
		debug ("currsym: "<< (yyval.symp)->name);
		currsym = (yyval.symp);
	}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1019 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = (yyvsp[-1].symp);
	}
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1023 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		symtype * t = (yyvsp[-6].symp) -> type;
		string decre = "null";
		symtype * prev = NULL;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}
		decre+="temp";
		if (prev==NULL) {
			int x = atoi((yyvsp[-4].A)->symp->init.c_str());                                                                  // width
			int y = atoi((yyvsp[-1].A)->symp->init.c_str());                                                                  // length
			symtype* s = new symtype(ARR, (yyvsp[-6].symp)->type, x ,y);
			 y = sizeoftype(s);
			(yyval.symp) = (yyvsp[-6].symp)->update(s);
		}
		
		else {
			decre+="temp";
			prev->ptr =  new symtype(ARR, t, atoi((yyvsp[-4].A)->symp->init.c_str()) , atoi((yyvsp[-1].A)->symp->init.c_str())); // set dim
			(yyval.symp) = (yyvsp[-6].symp)->update ((yyvsp[-6].symp)->type);
			decre+="temp";
		}
		
	}
#line 2881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1048 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		symtype * t = (yyvsp[-4].symp) -> type;
		symtype * prev = NULL;
		string decar = "null";
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}
		decar+="null";
		if (prev==NULL) {
			symtype* s = new symtype(ARR, (yyvsp[-4].symp)->type, 0);
			int y = sizeoftype(s);
			(yyval.symp) = (yyvsp[-4].symp)->update(s);
		}
		else {
			int sizofint = 4;
			prev->ptr =  new symtype(ARR, t, 0);
			(yyval.symp) = (yyvsp[-4].symp)->update ((yyvsp[-4].symp)->type);
			sizofint+=1;
		}
		
	}
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1071 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		table->tname = (yyvsp[-4].symp)->name;
		int zero = 0;
		if ((yyvsp[-4].symp)->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");
			s->update((yyvsp[-4].symp)->type);		
		}
		zero+=4;
		(yyvsp[-4].symp) = (yyvsp[-4].symp)->linkst(table);
		zero++;
		table->parent = gTable;
		changeTable (gTable);				                                                // Come back to globalsymbol table
		zero++;
		debug ("currsym: "<< (yyval.symp)->name);
		currsym = (yyval.symp);						
	}
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1087 "ass5_15CS10031.y" /* yacc.c:1646  */
    {                                     /* Ignored */

	}
#line 2937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1090 "ass5_15CS10031.y" /* yacc.c:1646  */
    {		
		table->tname = (yyvsp[-3].symp)->name;			                                          // Update function symbol table name
		int sint = 4;
		if ((yyvsp[-3].symp)->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");                                   // Update type of return value
			s->update((yyvsp[-3].symp)->type);
		}
		sint++;
		(yyvsp[-3].symp) = (yyvsp[-3].symp)->linkst(table);		                                              // Update type of function in global table
		sint--;
		table->parent = gTable;
		changeTable (gTable);				                                            // Come back to globalsymbol table
		sint--;
		debug ("currsym: "<< (yyval.symp)->name);
		currsym = (yyval.symp);
		sint++;
	}
#line 2959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1112 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.st) = new symtype(PTR, (yyvsp[0].st));
	}
#line 2967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1116 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.st) = new symtype(PTR);
	}
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1133 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		debug("parameter_list");
	}
#line 2983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1139 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		debug ("here");
		(yyvsp[0].symp)->category = "param";
	}
#line 2992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1144 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("parameter_declaration\n");}
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1150 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("identifier_list\n");}
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1155 "ass5_15CS10031.y" /* yacc.c:1646  */
    {

		//cout << "error here1\n";
		string str = "{";
		for(int i=0; i< (yyvsp[-1].mat)->initmat.size();i++){
			
			str+=(yyvsp[-1].mat)->initmat[i];
			str+=",";
		}
		str+="}";
		//cout << str << endl;
		debug((yyval.symp)->init);
		//cout << "error here2\n";
		
		(yyvsp[-1].mat)->symp->init = str;
		//cout << "error here3\n";
		(yyval.symp) = (yyvsp[-1].mat)->symp;
		//cout << "error here4\n";
		//cout << "error here\n";
	}
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1175 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.symp) = (yyvsp[0].A)->symp;
	}
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1181 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
	(yyval.mat) = new matrixinit();
	(yyval.mat)->symp = gentemp((yyvsp[0].mat)->symp->type->cat);           //////////////////////////////////////////////////////////////////////////////////
	//cout << "initializer_row_list -> initializer_row 1" << endl;
	for(int i=0; i < (yyvsp[0].mat)->initmat.size(); i++){
		//cout << i << endl;
		(yyval.mat)->initmat.push_back((yyvsp[0].mat)->initmat[i]);
	}
	//cout << "initializer_row_list -> initializer_row 2" << endl;
}
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1191 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
	//cout << "initializer_row_list -> initializer_row 12" << endl;
	for(int i=0; i < (yyvsp[0].mat)->initmat.size(); i++){
		//cout << i << endl;
		(yyval.mat)->initmat.push_back((yyvsp[0].mat)->initmat[i]);
	}
	//$$->initmat.push_back(";");
	//cout << "initializer_row_list -> initializer_row 22" << endl;
}
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1202 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
	(yyval.mat) = new matrixinit();
	(yyval.mat)->symp = gentemp((yyvsp[0].symp)->type->cat);
	//cout << "initializer_row -> initializer1\n";
	//cout << "1\n";
	//string str = $1->init;
	//cout << str << endl;
	(yyval.mat)->initmat.push_back((yyvsp[0].symp)->init);
	//cout << "initializer_row -> initializer2\n";
}
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1213 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
	//cout << "initializer_row -> initializer_row COM initializer1\n";
	(yyval.mat)->initmat.push_back(((yyvsp[0].symp)->init));
	//cout << "initializer_row -> initializer_row COM initializer2\n";
}
#line 3091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1219 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("initializer_row\n");}
#line 3097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1224 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("designation\n");}
#line 3103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1231 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("designator_list\n");}
#line 3109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1235 "ass5_15CS10031.y" /* yacc.c:1646  */
    {cout << "here\n";}
#line 3115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1237 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("designator\n");}
#line 3121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1243 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);
		debug("Compound Statement");
	}
#line 3130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1247 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = new statement();
		(yyval.stat)->nextlist = (yyvsp[0].A)->nextlist;
		debug("Expression Statement");
	}
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1252 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);
		debug("iteration statement");
	}
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1256 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);
		debug("selection statement\n");
	}
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1262 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);
		debug("jump statement");
	}
#line 3167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1269 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.stat) = new statement();}
#line 3173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1270 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.stat) = new statement();}
#line 3179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1271 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.stat) = new statement();}
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1275 "ass5_15CS10031.y" /* yacc.c:1646  */
    { (yyval.stat) = new statement();}
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1276 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[-1].stat);
	}
#line 3199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1282 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);
	/*	
		debug ("M.instruction = " << $2);

		if (gDebug) {
			debug ("1 contains: ");
			printlist($1->nextlist);
		} 

		if (gDebug) {
			debug ("3 contains: ");
			printlist($3->nextlist);
		} 
	*/
		backpatch ((yyvsp[-2].stat)->nextlist, (yyvsp[-1].instr));
	//	debug ("backpatching 1 done");
	}
#line 3222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1300 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);		
	}
#line 3230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1308 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = (yyvsp[0].stat);
	/*	debug ("-------------------------------------------------");
		debug ("statement next instruction");
		if (gDebug) {
			printlist($$->nextlist);
		} 
	*/
	}
#line 3244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1317 "ass5_15CS10031.y" /* yacc.c:1646  */
    { 
		(yyval.stat) = new statement();
	/*	debug ("-------------------------------------------------");
		debug ("declaration next instruction");
		if (gDebug) {
			printlist($$->nextlist);
		} 
	*/
	}
#line 3258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1330 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.A) = (yyvsp[-1].A);
	}
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1333 "ass5_15CS10031.y" /* yacc.c:1646  */
    {	(yyval.A) = new unary();}
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1338 "ass5_15CS10031.y" /* yacc.c:1646  */
    {	
		(yyvsp[-5].A)->isswitch= true;
		backpatch ((yyvsp[-4].A)->nextlist, nextinstr());
		convert2bool((yyvsp[-5].A));
		(yyval.stat) = new statement();
		backpatch ((yyvsp[-5].A)->truelist, (yyvsp[-2].instr));
		lint temp = merge ((yyvsp[-5].A)->falselist, (yyvsp[-1].stat)->nextlist);
		(yyval.stat)->nextlist = merge ((yyvsp[0].A)->nextlist, temp);
		//printf("selection_statement\n");
	}
#line 3287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1348 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		backpatch ((yyvsp[-4].A)->nextlist, nextinstr());
		convert2bool((yyvsp[-5].A));
		(yyval.stat) = new statement();
		backpatch ((yyvsp[-5].A)->truelist, (yyvsp[-2].instr));
		lint temp = merge ((yyvsp[-5].A)->falselist, (yyvsp[-1].stat)->nextlist);
		(yyval.stat)->nextlist = merge ((yyvsp[0].A)->nextlist, temp);
		
	}
#line 3301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1357 "ass5_15CS10031.y" /* yacc.c:1646  */
    {  
		//cout << "in here" << endl;									                        // 100 if f==0, goto m1, //101  goto m2
		int i=0;
		(yyval.stat) = new statement();
		//cout << i++ << endl;
		backpatch ((yyvsp[-7].A)->nextlist, nextinstr());
		//cout << i++ << endl;
		convert2bool((yyvsp[-8].A));
		//cout << i++ << endl;
		backpatch ((yyvsp[-8].A)->truelist, (yyvsp[-5].instr));
		//cout << i++ << endl;
		backpatch ((yyvsp[-8].A)->falselist, (yyvsp[-1].instr));
		//cout << i++ << endl;
		lint temp = merge ((yyvsp[-4].stat)->nextlist, (yyvsp[-3].A)->nextlist);
		//cout << i++ << "k"<< endl;		
		(yyval.stat)->nextlist = merge (temp, (yyvsp[0].stat)->nextlist);
	
		//cout << i++ << endl;
	}
#line 3325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1380 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = new statement();
		convert2bool((yyvsp[-2].A));
		                                                                        // M1 to go back to statement if expression is true
	                                                              	// M2 to go to check expression if statement is complete
		backpatch ((yyvsp[-2].A)->truelist, (yyvsp[-7].instr));
		backpatch ((yyvsp[-6].stat)->nextlist, (yyvsp[-5].instr));

		                                                                    // Some bug in the next statement
		(yyval.stat)->nextlist = (yyvsp[-2].A)->falselist;

	}
#line 3342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1392 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = new statement();
		convert2bool((yyvsp[-3].A));
		backpatch ((yyvsp[-3].A)->truelist, (yyvsp[-1].instr));
		backpatch ((yyvsp[0].stat)->nextlist, (yyvsp[-4].instr));
		emit (GOTOOP, tostr((yyvsp[-4].instr)));
		(yyval.stat)->nextlist = (yyvsp[-3].A)->falselist;
	}
#line 3355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1400 "ass5_15CS10031.y" /* yacc.c:1646  */
    { 
		(yyval.stat) = new statement();
		convert2bool((yyvsp[-3].A));
		                                                                            // M1 to go back to boolean again
		                                                    // M2 to go to statement if the boolean is true
		backpatch((yyvsp[0].stat)->nextlist, (yyvsp[-5].instr));
		backpatch((yyvsp[-3].A)->truelist, (yyvsp[-1].instr));
		(yyval.stat)->nextlist = (yyvsp[-3].A)->falselist;
		                                                  // Emit to prevent fallthrough
		emit (GOTOOP, tostr((yyvsp[-5].instr)));
	}
#line 3371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1412 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = new statement();
		convert2bool((yyvsp[-6].A));
		backpatch ((yyvsp[-6].A)->truelist, (yyvsp[-1].instr));
		backpatch ((yyvsp[-3].A)->nextlist, (yyvsp[-7].instr));
		backpatch ((yyvsp[0].stat)->nextlist, (yyvsp[-5].instr));
		emit (GOTOOP, tostr((yyvsp[-5].instr)));
		(yyval.stat)->nextlist = (yyvsp[-6].A)->falselist;
	                                                                            //	debug ("for done");
	}
#line 3386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1426 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.stat) = new statement();}
#line 3392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1427 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.stat) = new statement();}
#line 3398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1428 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = new statement();
		emit(_RETURN,"");
	}
#line 3407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1432 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
		(yyval.stat) = new statement();
	//	if (table->lookup("retVal")->type->cat==$2->symp->type->cat) {
			emit(_RETURN,(yyvsp[-1].A)->symp->name);
	//	}
	//	else yyerror("Wrong return type\n");			

	}
#line 3420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1440 "ass5_15CS10031.y" /* yacc.c:1646  */
    {(yyval.stat) = new statement();}
#line 3426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1445 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
                                                                          //		if (gDebug) table->printall();
	}
#line 3434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1460 "ass5_15CS10031.y" /* yacc.c:1646  */
    {
                                                                    //		table->tname = $2->name;
		
                                                                    //		$2 = $2->update(FUNC, table);
		table->parent = gTable;
		changeTable (gTable);
	}
#line 3446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1467 "ass5_15CS10031.y" /* yacc.c:1646  */
    {

	}
#line 3454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1474 "ass5_15CS10031.y" /* yacc.c:1646  */
    {printf("declaration_list\n");}
#line 3460 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3464 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1478 "ass5_15CS10031.y" /* yacc.c:1906  */


void yyerror(const char *s) {
	printf ("ERROR: %s",s);
}
