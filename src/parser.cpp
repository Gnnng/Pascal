/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ID = 259,
     DOT = 260,
     EQUAL = 261,
     LT = 262,
     LE = 263,
     GT = 264,
     GE = 265,
     PLUS = 266,
     MINUS = 267,
     MUL = 268,
     DIV = 269,
     RP = 270,
     LP = 271,
     ASSIGN = 272,
     COLON = 273,
     COMMA = 274,
     SEMI = 275,
     IF = 276,
     THEN = 277,
     ELSE = 278,
     WHILE = 279,
     DO = 280,
     BEGINN = 281,
     END = 282,
     CASE = 283,
     DOWNTO = 284,
     FOR = 285,
     GOTO = 286,
     INTEGER = 287,
     LB = 288,
     RB = 289,
     NOT = 290,
     OR = 291,
     AND = 292,
     MOD = 293,
     OF = 294,
     READ = 295,
     REPEAT = 296,
     TO = 297,
     UNEQUAL = 298,
     UNTIL = 299,
     NUMBER = 300,
     SYS_CON = 301,
     SYS_FUNCT = 302,
     SYS_PROC = 303,
     SYS_TYPE = 304,
     CHAR = 305,
     CONST = 306,
     STRING = 307,
     REAL = 308,
     ARRAY = 309,
     VAR = 310,
     PROCEDURE = 311,
     RECORD = 312,
     FUNCTION = 313,
     TYPE = 314
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ID 259
#define DOT 260
#define EQUAL 261
#define LT 262
#define LE 263
#define GT 264
#define GE 265
#define PLUS 266
#define MINUS 267
#define MUL 268
#define DIV 269
#define RP 270
#define LP 271
#define ASSIGN 272
#define COLON 273
#define COMMA 274
#define SEMI 275
#define IF 276
#define THEN 277
#define ELSE 278
#define WHILE 279
#define DO 280
#define BEGINN 281
#define END 282
#define CASE 283
#define DOWNTO 284
#define FOR 285
#define GOTO 286
#define INTEGER 287
#define LB 288
#define RB 289
#define NOT 290
#define OR 291
#define AND 292
#define MOD 293
#define OF 294
#define READ 295
#define REPEAT 296
#define TO 297
#define UNEQUAL 298
#define UNTIL 299
#define NUMBER 300
#define SYS_CON 301
#define SYS_FUNCT 302
#define SYS_PROC 303
#define SYS_TYPE 304
#define CHAR 305
#define CONST 306
#define STRING 307
#define REAL 308
#define ARRAY 309
#define VAR 310
#define PROCEDURE 311
#define RECORD 312
#define FUNCTION 313
#define TYPE 314




/* Copy the first part of user declarations.  */
#line 1 "src/pascal.y"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "parser.hpp"
int yydebug = 1;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "src/pascal.y"
{
	ast_node *a;
	int integer;
	char* debug;
}
/* Line 193 of yacc.c.  */
#line 230 "src/parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 243 "src/parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    17,    20,    26,
      27,    30,    31,    37,    42,    44,    46,    48,    50,    52,
      55,    56,    59,    61,    66,    68,    70,    72,    74,    76,
      80,    85,    91,    98,   103,   110,   114,   117,   119,   124,
     128,   130,   133,   134,   137,   139,   144,   147,   150,   151,
     156,   162,   167,   171,   175,   176,   180,   182,   186,   190,
     193,   195,   197,   201,   204,   208,   209,   213,   215,   217,
     219,   221,   223,   225,   227,   229,   231,   233,   237,   244,
     250,   252,   257,   259,   264,   269,   275,   278,   279,   284,
     289,   298,   300,   302,   308,   311,   313,   318,   323,   326,
     330,   332,   336,   340,   344,   348,   352,   356,   358,   362,
     366,   370,   372,   376,   380,   384,   388,   390,   392,   397,
     403,   405,   409,   412,   415,   420,   424,   428
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,     4,    -1,    63,    64,     5,    -1,     3,
       4,    20,    -1,    -1,    66,    94,    -1,    66,    94,    -1,
      67,    68,    71,    81,    84,    -1,    -1,    51,    69,    -1,
      -1,    69,    61,     6,    70,    20,    -1,    61,     6,    70,
      20,    -1,    32,    -1,    53,    -1,    50,    -1,    52,    -1,
      46,    -1,    59,    72,    -1,    -1,    72,    73,    -1,    73,
      -1,     4,     6,    74,    20,    -1,    75,    -1,    76,    -1,
      77,    -1,    49,    -1,    61,    -1,    16,    80,    15,    -1,
      70,     5,     5,    70,    -1,    12,    70,     5,     5,    70,
      -1,    12,    70,     5,     5,    12,    70,    -1,    61,     5,
       5,    61,    -1,    54,    33,    75,    34,    39,    74,    -1,
      57,    78,    27,    -1,    78,    79,    -1,    79,    -1,    80,
      18,    74,    20,    -1,    80,    19,     4,    -1,     4,    -1,
      55,    82,    -1,    -1,    82,    83,    -1,    83,    -1,    80,
      18,    74,    20,    -1,    84,    85,    -1,    84,    87,    -1,
      -1,    86,    20,    65,    20,    -1,    58,     4,    89,    18,
      75,    -1,    88,    20,    65,    20,    -1,    56,     4,    89,
      -1,    16,    90,    15,    -1,    -1,    90,    20,    91,    -1,
      91,    -1,    92,    18,    75,    -1,    93,    18,    75,    -1,
      55,    80,    -1,    80,    -1,    95,    -1,    26,    96,    27,
      -1,    96,    97,    -1,    96,    97,    20,    -1,    -1,    32,
      18,    98,    -1,    98,    -1,    99,    -1,   100,    -1,    95,
      -1,   101,    -1,   103,    -1,   104,    -1,   105,    -1,   107,
      -1,   110,    -1,     4,    17,   112,    -1,     4,    33,   112,
      34,    17,   112,    -1,     4,     5,     4,    17,   112,    -1,
       4,    -1,     4,    16,   116,    15,    -1,    48,    -1,    48,
      16,   111,    15,    -1,    40,    16,   115,    15,    -1,    21,
     112,    22,    97,   102,    -1,    23,    97,    -1,    -1,    41,
      96,    44,   112,    -1,    24,   112,    25,    97,    -1,    30,
       4,    17,   112,   106,   112,    25,    97,    -1,    42,    -1,
      29,    -1,    28,   112,    39,   108,    27,    -1,   108,   109,
      -1,   109,    -1,    70,    18,    97,    20,    -1,     4,    18,
      97,    20,    -1,    31,    32,    -1,   111,    19,   112,    -1,
     112,    -1,   112,    10,   113,    -1,   112,     9,   113,    -1,
     112,     8,   113,    -1,   112,     7,   113,    -1,   112,     6,
     113,    -1,   112,    43,   113,    -1,   113,    -1,   113,    11,
     114,    -1,   113,    12,   114,    -1,   113,    36,   114,    -1,
     114,    -1,   114,    13,   115,    -1,   114,    14,   115,    -1,
     114,    38,   115,    -1,   114,    37,   115,    -1,   115,    -1,
      61,    -1,    61,    16,   116,    15,    -1,    47,    47,    16,
     116,    15,    -1,    70,    -1,    16,   112,    15,    -1,    35,
     115,    -1,    12,   115,    -1,     4,    33,   112,    34,    -1,
       4,     5,     4,    -1,   116,    19,   112,    -1,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   104,   112,   116,   121,   125,   130,   137,
     141,   145,   149,   152,   158,   159,   160,   161,   162,   167,
     168,   172,   173,   177,   181,   182,   183,   187,   188,   189,
     190,   191,   192,   193,   197,   201,   205,   206,   210,   214,
     215,   219,   220,   224,   225,   229,   233,   234,   237,   241,
     245,   249,   253,   257,   258,   262,   263,   267,   268,   272,
     276,   281,   284,   287,   288,   289,   293,   295,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   309,   310,   311,
     314,   315,   316,   317,   319,   325,   329,   330,   334,   337,
     340,   343,   344,   347,   350,   351,   354,   355,   358,   361,
     362,   364,   365,   366,   367,   368,   369,   370,   373,   374,
     375,   376,   379,   380,   381,   382,   383,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   397,   398
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ID", "DOT", "EQUAL", "LT",
  "LE", "GT", "GE", "PLUS", "MINUS", "MUL", "DIV", "RP", "LP", "ASSIGN",
  "COLON", "COMMA", "SEMI", "IF", "THEN", "ELSE", "WHILE", "DO", "BEGINN",
  "END", "CASE", "DOWNTO", "FOR", "GOTO", "INTEGER", "LB", "RB", "NOT",
  "OR", "AND", "MOD", "OF", "READ", "REPEAT", "TO", "UNEQUAL", "UNTIL",
  "NUMBER", "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE", "CHAR",
  "CONST", "STRING", "REAL", "ARRAY", "VAR", "PROCEDURE", "RECORD",
  "FUNCTION", "TYPE", "$accept", "NAME", "program", "program_head",
  "routine", "sub_routine", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    63,    64,    65,    66,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    76,    77,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    83,    84,    84,    84,    85,
      86,    87,    88,    89,    89,    90,    90,    91,    91,    92,
      93,    94,    95,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   100,   100,   100,   101,   102,   102,   103,   104,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     2,     2,     5,     0,
       2,     0,     5,     4,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     3,
       4,     5,     6,     4,     6,     3,     2,     1,     4,     3,
       1,     2,     0,     2,     1,     4,     2,     2,     0,     4,
       5,     4,     3,     3,     0,     3,     1,     3,     3,     2,
       1,     1,     3,     2,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     5,
       1,     4,     1,     4,     4,     5,     2,     0,     4,     4,
       8,     1,     1,     5,     2,     1,     4,     4,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     4,     5,
       1,     3,     2,     2,     4,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     9,     0,     1,     0,     0,    11,     4,
       3,    65,     6,    61,     0,    20,     0,     2,     0,    10,
       0,    42,    80,     0,     0,    62,     0,     0,     0,     0,
       0,    65,    82,    70,    63,    67,    68,    69,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    19,    22,     0,
      48,     0,     0,     0,     0,     2,     0,     0,    14,     0,
      18,     0,    16,    17,    15,   117,   120,     0,   107,   111,
     116,     0,     0,     0,    98,     0,     0,     0,     0,    64,
       0,     0,     0,    21,    40,     0,    41,    44,     8,     0,
     127,     0,    77,     0,     0,     0,   123,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,   100,    13,     0,     0,     0,    27,     0,     0,
      28,     0,     0,    24,    25,    26,     0,     0,    43,     0,
       0,    46,     0,    47,     0,     0,    81,     0,     0,   125,
       0,   121,     0,     0,   105,   104,   103,   102,   101,    87,
     106,   108,   109,   110,   112,   113,   115,   114,    89,     0,
       0,     0,    95,     0,    84,    88,    83,     0,    12,     0,
       0,     0,     0,    37,     0,     0,     0,    23,     0,    39,
      54,    54,     9,     9,    79,   126,     0,   124,     0,   118,
       0,    85,     0,     0,    93,    94,    92,    91,     0,    99,
       0,    29,     0,    35,    36,     0,     0,     0,    45,     0,
      52,     0,     0,     0,     0,    78,   119,    86,     0,     0,
       0,     0,     0,     0,    33,    30,     0,    60,     0,    56,
       0,     0,     0,    49,     7,    51,    97,    96,     0,     0,
      31,     0,    38,    59,    53,     0,     0,     0,    50,    90,
      32,    34,    55,    57,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,     2,     3,     6,   222,   223,     8,    15,    19,
      66,    21,    47,    48,   132,   133,   134,   135,   182,   183,
      85,    50,    86,    87,    88,   141,   142,   143,   144,   220,
     238,   239,   240,   241,    12,    33,    16,    34,    35,    36,
      37,    38,   201,    39,    40,    41,   208,    42,   171,   172,
      43,   121,    90,    68,    69,    70,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -172
static const yytype_int16 yypact[] =
{
      25,    28,    43,  -172,    15,  -172,    33,    44,     4,  -172,
    -172,  -172,  -172,  -172,    57,    39,   199,  -172,    82,    57,
      95,    60,    13,   101,   101,  -172,   101,   114,    89,   116,
     119,  -172,   121,  -172,   120,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,   140,   135,   136,    95,  -172,   139,
    -172,   141,   101,   101,   101,    14,   101,   101,  -172,   101,
    -172,    99,  -172,  -172,  -172,   134,  -172,   248,    84,    93,
    -172,    83,   298,   142,  -172,   262,   101,   220,   101,  -172,
     132,   140,    10,  -172,  -172,    54,   139,  -172,    56,   146,
     361,     8,   361,   308,   152,   101,  -172,   313,  -172,   150,
     101,   101,   101,   101,   101,   101,   241,   101,   101,   101,
     101,   101,   101,   101,   101,   241,   166,   101,  -172,   153,
     101,    29,   361,  -172,   149,   140,   139,  -172,   138,   139,
     172,   174,   162,  -172,  -172,  -172,    10,   179,  -172,   180,
     181,  -172,   167,  -172,   171,   101,  -172,   101,   177,  -172,
     323,  -172,   101,    35,    84,    84,    84,    84,    84,   173,
      84,    93,    93,    93,  -172,  -172,  -172,  -172,  -172,   186,
     187,   128,  -172,   269,  -172,   361,  -172,   101,  -172,   190,
      38,   112,     9,  -172,    63,   192,   194,  -172,   188,  -172,
     195,   195,  -172,  -172,   361,   361,   101,  -172,    65,  -172,
     241,  -172,   241,   241,  -172,  -172,  -172,  -172,   101,   361,
     201,  -172,   176,  -172,  -172,    10,    57,   140,  -172,    11,
    -172,   203,   193,    44,   202,   361,  -172,  -172,   229,   233,
     337,    -1,   224,   239,  -172,  -172,   139,   255,     5,  -172,
     266,   267,   112,  -172,  -172,  -172,  -172,  -172,   241,   140,
    -172,    10,  -172,   255,  -172,    11,   112,   112,  -172,  -172,
    -172,  -172,  -172,  -172,  -172
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,   -14,  -172,  -172,  -172,    87,   284,  -172,  -172,  -172,
     -42,  -172,  -172,   247,  -128,  -171,  -172,  -172,  -172,   113,
    -117,  -172,  -172,   210,  -172,  -172,  -172,  -172,  -172,   106,
    -172,    45,  -172,  -172,    76,    -6,   270,   -99,   234,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,   154,
    -172,  -172,   -20,   131,     1,   -35,   -83
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      18,    13,    80,    67,    71,    45,    72,   159,   188,   180,
     212,   249,   184,    84,    17,    84,   168,   153,    51,    94,
     254,    96,   125,   146,    98,   255,   126,   147,     1,    52,
      53,    58,     4,    92,    93,     9,   213,    97,    10,   124,
     131,   119,    58,     5,   176,    60,    54,    95,   177,    62,
     199,    63,    64,   211,   147,    14,    60,   137,   122,   127,
      62,    17,    63,    64,   128,   184,   236,   129,   130,   198,
      11,   258,   136,   137,   170,   150,   164,   165,   166,   167,
     226,   215,   137,   179,   147,   263,   264,   233,    44,   101,
     102,   103,   104,   105,   131,   108,   109,   173,    20,    46,
     175,   227,   237,   228,   229,    55,   111,   112,   115,   161,
     162,   163,   139,    56,   140,    49,    17,    57,    73,   253,
     110,    74,   130,   261,   125,   194,   107,   195,   126,   170,
     113,   114,   169,    58,    75,    76,    59,    78,   237,   131,
      79,    81,    82,    84,    58,    89,    99,    60,    61,   259,
     100,    62,   123,    63,    64,   204,   149,   209,    60,   117,
      58,   127,    62,   145,    63,    64,   152,   130,   174,   178,
     169,   181,    58,   131,    60,   235,   225,   185,    62,   186,
      63,    64,   187,   189,   190,   191,    60,   192,   230,   250,
      62,   193,    63,    64,   196,   210,   200,   216,    58,   217,
     131,   130,   234,    22,   202,   203,   231,   260,   218,   131,
     232,   219,    60,   243,   131,   131,    62,    13,    63,    64,
      23,   242,   245,    24,    22,    11,    25,    26,   130,    27,
      28,    29,   154,   155,   156,   157,   158,   130,   160,    30,
      31,    23,   130,   130,    24,    22,    11,    32,    26,   246,
      27,    28,    29,   247,   101,   102,   103,   104,   105,   252,
      30,    31,    23,   251,   120,    24,    22,    11,    32,    26,
     106,    27,    28,    29,   137,   101,   102,   103,   104,   105,
     224,    30,    31,    23,   256,   257,    24,     7,    11,    32,
      26,   107,    27,    28,    83,   214,   138,   221,   206,   244,
     262,    77,    30,    31,   101,   102,   103,   104,   105,   118,
      32,   207,   107,     0,   101,   102,   103,   104,   105,   101,
     102,   103,   104,   105,     0,   205,     0,     0,   151,   101,
     102,   103,   104,   105,     0,     0,     0,   116,     0,     0,
       0,   107,   148,   101,   102,   103,   104,   105,     0,     0,
       0,   107,     0,     0,     0,     0,   107,   197,     0,     0,
       0,     0,   248,     0,     0,     0,   107,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107
};

static const yytype_int16 yycheck[] =
{
      14,     7,    44,    23,    24,    19,    26,   106,   136,   126,
     181,    12,   129,     4,     4,     4,   115,   100,     5,     5,
      15,    56,    12,    15,    59,    20,    16,    19,     3,    16,
      17,    32,     4,    53,    54,    20,    27,    57,     5,    81,
      82,    76,    32,     0,    15,    46,    33,    33,    19,    50,
      15,    52,    53,    15,    19,    51,    46,    19,    78,    49,
      50,     4,    52,    53,    54,   182,    55,    57,    82,   152,
      26,   242,    18,    19,   116,    95,   111,   112,   113,   114,
      15,    18,    19,   125,    19,   256,   257,   215,     6,     6,
       7,     8,     9,    10,   136,    11,    12,   117,    59,     4,
     120,   200,   219,   202,   203,     4,    13,    14,    25,   108,
     109,   110,    56,    12,    58,    55,     4,    16,     4,   236,
      36,    32,   136,   251,    12,   145,    43,   147,    16,   171,
      37,    38,     4,    32,    18,    16,    35,    16,   255,   181,
      20,     6,     6,     4,    32,     4,    47,    46,    47,   248,
      16,    50,    20,    52,    53,    27,     4,   177,    46,    17,
      32,    49,    50,    17,    52,    53,    16,   181,    15,    20,
       4,    33,    32,   215,    46,   217,   196,     5,    50,     5,
      52,    53,    20,     4,     4,     4,    46,    20,   208,   231,
      50,    20,    52,    53,    17,     5,    23,     5,    32,     5,
     242,   215,   216,     4,    18,    18,     5,   249,    20,   251,
      34,    16,    46,    20,   256,   257,    50,   223,    52,    53,
      21,    18,    20,    24,     4,    26,    27,    28,   242,    30,
      31,    32,   101,   102,   103,   104,   105,   251,   107,    40,
      41,    21,   256,   257,    24,     4,    26,    48,    28,    20,
      30,    31,    32,    20,     6,     7,     8,     9,    10,    20,
      40,    41,    21,    39,    44,    24,     4,    26,    48,    28,
      22,    30,    31,    32,    19,     6,     7,     8,     9,    10,
     193,    40,    41,    21,    18,    18,    24,     3,    26,    48,
      28,    43,    30,    31,    47,   182,    86,   191,    29,   223,
     255,    31,    40,    41,     6,     7,     8,     9,    10,    75,
      48,    42,    43,    -1,     6,     7,     8,     9,    10,     6,
       7,     8,     9,    10,    -1,   171,    -1,    -1,    15,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    43,    34,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    43,    34,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    43,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    62,    63,     4,     0,    64,    66,    67,    20,
       5,    26,    94,    95,    51,    68,    96,     4,    61,    69,
      59,    71,     4,    21,    24,    27,    28,    30,    31,    32,
      40,    41,    48,    95,    97,    98,    99,   100,   101,   103,
     104,   105,   107,   110,     6,    61,     4,    72,    73,    55,
      81,     5,    16,    17,    33,     4,    12,    16,    32,    35,
      46,    47,    50,    52,    53,    61,    70,   112,   113,   114,
     115,   112,   112,     4,    32,    18,    16,    96,    16,    20,
      70,     6,     6,    73,     4,    80,    82,    83,    84,     4,
     112,   116,   112,   112,     5,    33,   115,   112,   115,    47,
      16,     6,     7,     8,     9,    10,    22,    43,    11,    12,
      36,    13,    14,    37,    38,    25,    39,    17,    98,   115,
      44,   111,   112,    20,    70,    12,    16,    49,    54,    57,
      61,    70,    74,    75,    76,    77,    18,    19,    83,    56,
      58,    85,    86,    87,    88,    17,    15,    19,    34,     4,
     112,    15,    16,   116,   113,   113,   113,   113,   113,    97,
     113,   114,   114,   114,   115,   115,   115,   115,    97,     4,
      70,   108,   109,   112,    15,   112,    15,    19,    20,    70,
      80,    33,    78,    79,    80,     5,     5,    20,    74,     4,
       4,     4,    20,    20,   112,   112,    17,    34,   116,    15,
      23,   102,    18,    18,    27,   109,    29,    42,   106,   112,
       5,    15,    75,    27,    79,    18,     5,     5,    20,    16,
      89,    89,    65,    66,    65,   112,    15,    97,    97,    97,
     112,     5,    34,    74,    61,    70,    55,    80,    90,    91,
      92,    93,    18,    20,    94,    20,    20,    20,    25,    12,
      70,    39,    20,    80,    15,    20,    18,    18,    75,    97,
      70,    74,    91,    75,    75
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 98 "src/pascal.y"
    {
		(yyval.debug) = (yyvsp[(1) - (1)].debug);
	;}
    break;

  case 3:
#line 104 "src/pascal.y"
    { 
		(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a), (yyvsp[(2) - (3)].a), ast_dbg((yyvsp[(3) - (3)].debug)));
		(yyval.a)->debug = "Start point";
		ast_travel((yyval.a));
	;}
    break;

  case 4:
#line 112 "src/pascal.y"
    { 
		(yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)), ast_dbg((yyvsp[(2) - (3)].debug)), ast_dbg((yyvsp[(3) - (3)].debug)));
		(yyval.a)->debug = "program_head";
	;}
    break;

  case 5:
#line 116 "src/pascal.y"
    {(yyval.a) = ast_dbg("empty program_head");;}
    break;

  case 6:
#line 121 "src/pascal.y"
    {(yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->debug = "routine";;}
    break;

  case 7:
#line 125 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->debug = "sub_routine";;}
    break;

  case 8:
#line 130 "src/pascal.y"
    { 
		(yyval.a) = ast_newNode5((yyvsp[(1) - (5)].a), (yyvsp[(2) - (5)].a), (yyvsp[(3) - (5)].a), (yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));
		(yyval.a)->debug = "routine_head";
	;}
    break;

  case 9:
#line 137 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty label_part"); ;}
    break;

  case 10:
#line 141 "src/pascal.y"
    {
		(yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)), (yyvsp[(2) - (2)].a));
		(yyval.a)->debug = "const_part";
	;}
    break;

  case 11:
#line 145 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty const_part"); ;}
    break;

  case 12:
#line 149 "src/pascal.y"
    { 
		// printf("in const_expr_list recursively\n");
		(yyval.a) = ast_newNode5((yyvsp[(1) - (5)].a), ast_dbg((yyvsp[(2) - (5)].debug)), ast_dbg((yyvsp[(3) - (5)].debug)), (yyvsp[(4) - (5)].a), ast_dbg((yyvsp[(5) - (5)].debug))); (yyval.a)->debug = "const_expr_list";;}
    break;

  case 13:
#line 152 "src/pascal.y"
    {
		// printf("in const_expr_list\n");
		(yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)), ast_dbg((yyvsp[(2) - (4)].debug)), (yyvsp[(3) - (4)].a), ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "const_expr_list"; ;}
    break;

  case 14:
#line 158 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));;}
    break;

  case 15:
#line 159 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));;}
    break;

  case 16:
#line 160 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));;}
    break;

  case 17:
#line 161 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));;}
    break;

  case 18:
#line 162 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));;}
    break;

  case 19:
#line 167 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (2)].debug)); (yyval.a)->debug = "type_part";;}
    break;

  case 20:
#line 168 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty type_part");;}
    break;

  case 21:
#line 172 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));(yyval.a)->debug = "type_decl_list";;}
    break;

  case 22:
#line 173 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "type_decl_list";;}
    break;

  case 23:
#line 177 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)), ast_dbg((yyvsp[(2) - (4)].debug)), (yyvsp[(3) - (4)].a), ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "type_definition";;}
    break;

  case 24:
#line 181 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "type_decl";;}
    break;

  case 25:
#line 182 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "type_decl";;}
    break;

  case 26:
#line 183 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "type_decl";;}
    break;

  case 27:
#line 187 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug)); (yyval.a)->debug = "simple_type_decl";;}
    break;

  case 28:
#line 188 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug)); (yyval.a)->debug = "simple_type_decl";;}
    break;

  case 29:
#line 189 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)), (yyvsp[(2) - (3)].a), ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "simple_type_decl";;}
    break;

  case 30:
#line 190 "src/pascal.y"
    { (yyval.a) = ast_newNode4((yyvsp[(1) - (4)].a), ast_dbg((yyvsp[(2) - (4)].debug)), ast_dbg((yyvsp[(3) - (4)].debug)), (yyvsp[(4) - (4)].a));(yyval.a)->debug = "simple_type_decl";;}
    break;

  case 31:
#line 191 "src/pascal.y"
    { (yyval.a) = ast_newNode5(ast_dbg((yyvsp[(1) - (5)].debug)), (yyvsp[(2) - (5)].a), ast_dbg((yyvsp[(3) - (5)].debug)), ast_dbg((yyvsp[(4) - (5)].debug)), (yyvsp[(5) - (5)].a));(yyval.a)->debug = "simple_type_decl";;}
    break;

  case 32:
#line 192 "src/pascal.y"
    { (yyval.a) = ast_newNode6(ast_dbg((yyvsp[(1) - (6)].debug)), (yyvsp[(2) - (6)].a), ast_dbg((yyvsp[(3) - (6)].debug)), ast_dbg((yyvsp[(4) - (6)].debug)), ast_dbg((yyvsp[(5) - (6)].debug)), (yyvsp[(6) - (6)].a));(yyval.a)->debug = "simple_type_decl";;}
    break;

  case 33:
#line 193 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)), ast_dbg((yyvsp[(2) - (4)].debug)), ast_dbg((yyvsp[(3) - (4)].debug)), ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "simple_type_decl";;}
    break;

  case 34:
#line 197 "src/pascal.y"
    { (yyval.a) = ast_newNode6(ast_dbg((yyvsp[(1) - (6)].debug)), ast_dbg((yyvsp[(2) - (6)].debug)), (yyvsp[(3) - (6)].a), ast_dbg((yyvsp[(4) - (6)].debug)), ast_dbg((yyvsp[(5) - (6)].debug)), (yyvsp[(6) - (6)].a)); (yyval.a)->debug = "array_type_decl";;}
    break;

  case 35:
#line 201 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)), (yyvsp[(2) - (3)].a), ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "record_type_decl";;}
    break;

  case 36:
#line 205 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));(yyval.a)->debug = "field_decl_list";;}
    break;

  case 37:
#line 206 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a)); (yyval.a)->debug = "field_decl_list";;}
    break;

  case 38:
#line 210 "src/pascal.y"
    { (yyval.a) = ast_newNode4((yyvsp[(1) - (4)].a), ast_dbg((yyvsp[(2) - (4)].debug)), (yyvsp[(3) - (4)].a), ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "field_decl";;}
    break;

  case 39:
#line 214 "src/pascal.y"
    { (yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a), ast_dbg((yyvsp[(2) - (3)].debug)), ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "name_list";;}
    break;

  case 40:
#line 215 "src/pascal.y"
    { (yyval.a) = ast_newNode1(ast_dbg((yyvsp[(1) - (1)].debug)));(yyval.a)->debug = "name_list";;}
    break;

  case 41:
#line 219 "src/pascal.y"
    { (yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)), (yyvsp[(2) - (2)].a)); (yyval.a)->debug = "var_part";;}
    break;

  case 42:
#line 220 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty var_part");;}
    break;

  case 43:
#line 224 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));(yyval.a)->debug = "var_decl_list";;}
    break;

  case 44:
#line 225 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "var_decl_list"; ;}
    break;

  case 45:
#line 229 "src/pascal.y"
    { (yyval.a) = ast_newNode4((yyvsp[(1) - (4)].a), ast_dbg((yyvsp[(2) - (4)].debug)), (yyvsp[(3) - (4)].a), ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "var_decl";;}
    break;

  case 46:
#line 233 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));(yyval.a)->debug = "routine_part";;}
    break;

  case 47:
#line 234 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a), (yyvsp[(2) - (2)].a));(yyval.a)->debug = "routine_part";;}
    break;

  case 48:
#line 237 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty routine_part");;}
    break;

  case 49:
#line 241 "src/pascal.y"
    { (yyval.a) = ast_newNode4((yyvsp[(1) - (4)].a), ast_dbg((yyvsp[(2) - (4)].debug)), (yyvsp[(3) - (4)].a), ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "function_decl";;}
    break;

  case 50:
#line 245 "src/pascal.y"
    { (yyval.a) = ast_newNode5(ast_dbg((yyvsp[(1) - (5)].debug)), ast_dbg((yyvsp[(2) - (5)].debug)), (yyvsp[(3) - (5)].a), ast_dbg((yyvsp[(4) - (5)].debug)), (yyvsp[(5) - (5)].a)); (yyval.a)->debug = "function_head";;}
    break;

  case 51:
#line 249 "src/pascal.y"
    { (yyval.a) = ast_newNode4((yyvsp[(1) - (4)].a), ast_dbg((yyvsp[(2) - (4)].debug)), (yyvsp[(3) - (4)].a), ast_dbg((yyvsp[(4) - (4)].debug))); (yyval.a)->debug = "procedure_decl";;}
    break;

  case 52:
#line 253 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)), ast_dbg((yyvsp[(2) - (3)].debug)), (yyvsp[(3) - (3)].a));(yyval.a)->debug = "procedure_head";;}
    break;

  case 53:
#line 257 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)), (yyvsp[(2) - (3)].a), ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "parameters";;}
    break;

  case 54:
#line 258 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty parameters"); ;}
    break;

  case 55:
#line 262 "src/pascal.y"
    { (yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a), ast_dbg((yyvsp[(2) - (3)].debug)), (yyvsp[(3) - (3)].a));(yyval.a)->debug = "para_decl_list";;}
    break;

  case 56:
#line 263 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "para_decl_list";;}
    break;

  case 57:
#line 267 "src/pascal.y"
    { (yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a), ast_dbg((yyvsp[(2) - (3)].debug)), (yyvsp[(3) - (3)].a)); (yyval.a)->debug = "para_type_list";;}
    break;

  case 58:
#line 268 "src/pascal.y"
    { (yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a), ast_dbg((yyvsp[(2) - (3)].debug)), (yyvsp[(3) - (3)].a)); (yyval.a)->debug = "para_type_list";;}
    break;

  case 59:
#line 272 "src/pascal.y"
    { (yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)), (yyvsp[(2) - (2)].a)); (yyval.a)->debug = "var_para_list";;}
    break;

  case 60:
#line 276 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a)); (yyval.a)->debug = "val_para_list";;}
    break;

  case 61:
#line 281 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "routine_body";;}
    break;

  case 62:
#line 284 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)),(yyvsp[(2) - (3)].a),ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "compound_stmt";;}
    break;

  case 63:
#line 287 "src/pascal.y"
    {yyerror("SEMI error");;}
    break;

  case 64:
#line 288 "src/pascal.y"
    { (yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "stmt_list";;}
    break;

  case 65:
#line 289 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty stmt_list");;}
    break;

  case 66:
#line 293 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "stmt";;}
    break;

  case 67:
#line 295 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "stmt";;}
    break;

  case 68:
#line 298 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 69:
#line 299 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 70:
#line 300 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 71:
#line 301 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 72:
#line 302 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 73:
#line 303 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 74:
#line 304 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 75:
#line 305 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 76:
#line 306 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "non_label_stmt";;}
    break;

  case 77:
#line 309 "src/pascal.y"
    { (yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "assign_stmt";;}
    break;

  case 78:
#line 310 "src/pascal.y"
    { (yyval.a) = ast_newNode6(ast_dbg((yyvsp[(1) - (6)].debug)),ast_dbg((yyvsp[(2) - (6)].debug)),(yyvsp[(3) - (6)].a),ast_dbg((yyvsp[(4) - (6)].debug)),ast_dbg((yyvsp[(5) - (6)].debug)),(yyvsp[(6) - (6)].a));(yyval.a)->debug = "assign_stmt";;}
    break;

  case 79:
#line 311 "src/pascal.y"
    { (yyval.a) = ast_newNode5(ast_dbg((yyvsp[(1) - (5)].debug)),ast_dbg((yyvsp[(2) - (5)].debug)),ast_dbg((yyvsp[(3) - (5)].debug)),ast_dbg((yyvsp[(4) - (5)].debug)),(yyvsp[(5) - (5)].a));(yyval.a)->debug = "assign_stmt";;}
    break;

  case 80:
#line 314 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));(yyval.a)->debug = "proc_stmt";;}
    break;

  case 81:
#line 315 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),ast_dbg((yyvsp[(2) - (4)].debug)),(yyvsp[(3) - (4)].a),ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "proc_stmt";;}
    break;

  case 82:
#line 316 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));(yyval.a)->debug = "proc_stmt";;}
    break;

  case 83:
#line 317 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),ast_dbg((yyvsp[(2) - (4)].debug)),(yyvsp[(3) - (4)].a),ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "proc_stmt";;}
    break;

  case 84:
#line 319 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),ast_dbg((yyvsp[(2) - (4)].debug)),(yyvsp[(3) - (4)].a),ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "proc_stmt";;}
    break;

  case 85:
#line 325 "src/pascal.y"
    { (yyval.a) = ast_newNode5(ast_dbg((yyvsp[(1) - (5)].debug)),(yyvsp[(2) - (5)].a),ast_dbg((yyvsp[(3) - (5)].debug)),(yyvsp[(4) - (5)].a), (yyvsp[(5) - (5)].a));(yyval.a)->debug = "if_stmt";;}
    break;

  case 86:
#line 329 "src/pascal.y"
    { (yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)),(yyvsp[(2) - (2)].a));(yyval.a)->debug = "else_clause";;}
    break;

  case 87:
#line 330 "src/pascal.y"
    { (yyval.a) = ast_dbg("empty else_clause");;}
    break;

  case 88:
#line 334 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),(yyvsp[(2) - (4)].a),ast_dbg((yyvsp[(3) - (4)].debug)),(yyvsp[(4) - (4)].a));(yyval.a)->debug = "repeat_stmt";;}
    break;

  case 89:
#line 337 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),(yyvsp[(2) - (4)].a),ast_dbg((yyvsp[(3) - (4)].debug)),(yyvsp[(4) - (4)].a));(yyval.a)->debug = "while_stmt";;}
    break;

  case 90:
#line 340 "src/pascal.y"
    { (yyval.a) = ast_newNode8(ast_dbg((yyvsp[(1) - (8)].debug)),ast_dbg((yyvsp[(2) - (8)].debug)),ast_dbg((yyvsp[(3) - (8)].debug)),(yyvsp[(4) - (8)].a),(yyvsp[(5) - (8)].a),(yyvsp[(6) - (8)].a),ast_dbg((yyvsp[(7) - (8)].debug)),(yyvsp[(8) - (8)].a));(yyval.a)->debug = "for_stmt";;}
    break;

  case 91:
#line 343 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));(yyval.a)->debug = "direction";;}
    break;

  case 92:
#line 344 "src/pascal.y"
    { (yyval.a) = ast_dbg((yyvsp[(1) - (1)].debug));(yyval.a)->debug = "direction";;}
    break;

  case 93:
#line 347 "src/pascal.y"
    { (yyval.a) = ast_newNode5(ast_dbg((yyvsp[(1) - (5)].debug)),(yyvsp[(2) - (5)].a),ast_dbg((yyvsp[(3) - (5)].debug)),(yyvsp[(4) - (5)].a),ast_dbg((yyvsp[(5) - (5)].debug)));(yyval.a)->debug = "case_stmt";;}
    break;

  case 94:
#line 350 "src/pascal.y"
    { (yyval.a) = ast_newNode2((yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));(yyval.a)->debug = "case_expr_list";;}
    break;

  case 95:
#line 351 "src/pascal.y"
    { (yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "case_expr_list";;}
    break;

  case 96:
#line 354 "src/pascal.y"
    { (yyval.a) = ast_newNode4((yyvsp[(1) - (4)].a),ast_dbg((yyvsp[(2) - (4)].debug)),(yyvsp[(3) - (4)].a),ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "case_expr";;}
    break;

  case 97:
#line 355 "src/pascal.y"
    { (yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),ast_dbg((yyvsp[(2) - (4)].debug)),(yyvsp[(3) - (4)].a),ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "case_expr";;}
    break;

  case 98:
#line 358 "src/pascal.y"
    {(yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)),ast_dbg((yyvsp[(2) - (2)].debug)));(yyval.a)->debug = "goto_stmt";;}
    break;

  case 99:
#line 361 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression_list";;}
    break;

  case 100:
#line 362 "src/pascal.y"
    {(yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "expression_list";;}
    break;

  case 101:
#line 364 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression";;}
    break;

  case 102:
#line 365 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression";;}
    break;

  case 103:
#line 366 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression";;}
    break;

  case 104:
#line 367 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression";;}
    break;

  case 105:
#line 368 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression";;}
    break;

  case 106:
#line 369 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expression";;}
    break;

  case 107:
#line 370 "src/pascal.y"
    {(yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "expression";;}
    break;

  case 108:
#line 373 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expr";;}
    break;

  case 109:
#line 374 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expr";;}
    break;

  case 110:
#line 375 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "expr";;}
    break;

  case 111:
#line 376 "src/pascal.y"
    {(yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "expr";;}
    break;

  case 112:
#line 379 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "term";;}
    break;

  case 113:
#line 380 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "term";;}
    break;

  case 114:
#line 381 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "term";;}
    break;

  case 115:
#line 382 "src/pascal.y"
    {(yyval.a) = ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "term";;}
    break;

  case 116:
#line 383 "src/pascal.y"
    {(yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "term";;}
    break;

  case 117:
#line 386 "src/pascal.y"
    {(yyval.a) = ast_newNode1(ast_dbg((yyvsp[(1) - (1)].debug)));(yyval.a)->debug = "factor";;}
    break;

  case 118:
#line 387 "src/pascal.y"
    {(yyval.a) = ast_newNode1(ast_dbg((yyvsp[(1) - (4)].debug)));(yyval.a)->debug = "factor";;}
    break;

  case 119:
#line 388 "src/pascal.y"
    {(yyval.a) = ast_newNode5(ast_dbg((yyvsp[(1) - (5)].debug)),ast_dbg((yyvsp[(2) - (5)].debug)),ast_dbg((yyvsp[(3) - (5)].debug)),(yyvsp[(4) - (5)].a),ast_dbg((yyvsp[(5) - (5)].debug)));(yyval.a)->debug = "factor";;}
    break;

  case 120:
#line 389 "src/pascal.y"
    {(yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "factor";;}
    break;

  case 121:
#line 390 "src/pascal.y"
    {(yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)),(yyvsp[(2) - (3)].a),ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "factor";;}
    break;

  case 122:
#line 391 "src/pascal.y"
    {(yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)),(yyvsp[(2) - (2)].a));(yyval.a)->debug = "factor";;}
    break;

  case 123:
#line 392 "src/pascal.y"
    {(yyval.a) = ast_newNode2(ast_dbg((yyvsp[(1) - (2)].debug)),(yyvsp[(2) - (2)].a));(yyval.a)->debug = "factor";;}
    break;

  case 124:
#line 393 "src/pascal.y"
    {(yyval.a) = ast_newNode4(ast_dbg((yyvsp[(1) - (4)].debug)),ast_dbg((yyvsp[(2) - (4)].debug)),(yyvsp[(3) - (4)].a),ast_dbg((yyvsp[(4) - (4)].debug)));(yyval.a)->debug = "factor";;}
    break;

  case 125:
#line 394 "src/pascal.y"
    {(yyval.a) = ast_newNode3(ast_dbg((yyvsp[(1) - (3)].debug)),ast_dbg((yyvsp[(2) - (3)].debug)),ast_dbg((yyvsp[(3) - (3)].debug)));(yyval.a)->debug = "factor";;}
    break;

  case 126:
#line 397 "src/pascal.y"
    {(yyval.a) =ast_newNode3((yyvsp[(1) - (3)].a),ast_dbg((yyvsp[(2) - (3)].debug)),(yyvsp[(3) - (3)].a));(yyval.a)->debug = "args_list";;}
    break;

  case 127:
#line 398 "src/pascal.y"
    {(yyval.a) = ast_newNode1((yyvsp[(1) - (1)].a));(yyval.a)->debug = "args_list";;}
    break;


/* Line 1267 of yacc.c.  */
#line 2358 "src/parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 400 "src/pascal.y"

int main(int argc, char** argv) {
	yyparse();
	return 0;
}


