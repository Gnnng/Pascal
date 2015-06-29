/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "pascal.y"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "ast.h"
#include "utils.h"
#include "parser.hpp"

using namespace std;

int yydebug = 1;
ast::Node* ast_root;

/* Line 371 of yacc.c  */
#line 85 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     IDD = 259,
     DOT = 260,
     EQUAL = 261,
     LTHAN = 262,
     LEQU = 263,
     GT = 264,
     GE = 265,
     PLUS = 266,
     MINUS = 267,
     MUL = 268,
     DIV = 269,
     RIGHTP = 270,
     LEFTP = 271,
     ASSIGN = 272,
     COLON = 273,
     COMMA = 274,
     SEMI = 275,
     UNTIL = 276,
     OR = 277,
     AND = 278,
     MOD = 279,
     OF = 280,
     READ = 281,
     REPEAT = 282,
     TO = 283,
     UNEQUAL = 284,
     IF = 285,
     THEN = 286,
     ELSE = 287,
     WHILE = 288,
     DO = 289,
     BEGINN = 290,
     END = 291,
     CASE = 292,
     DOWNTO = 293,
     FOR = 294,
     GOTO = 295,
     INTEGER = 296,
     LB = 297,
     RB = 298,
     NOT = 299,
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


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 18 "pascal.y"

	char* 					debug;

    ast::Node* 				ast_Node; 
    ast::Statement* 		ast_Statement;
    ast::Expression* 		ast_Expression;
    ast::Program* 			ast_Program;
    ast::Routine* 			ast_Routine;
    ast::TypeDecl* 			ast_TypeDecl;
    ast::VarDecl* 			ast_VarDecl;
    ast::Identifier* 		ast_Identifier;
    ast::AssignmentStmt* 	ast_AssignmentStmt;

    ast::StatementList* 	ast_StatementList;
    ast::VarDeclList* 		ast_VarDeclList;
    ast::IdentifierList* 	ast_IdentifierList;
    ast::RoutineList* 		ast_RoutineList;
    ast::NameList* 			ast_NameList;
    ast::ExpressionList* 	ast_ExpressionList;
    ast::IfStmt* 			ast_IfStmt;


/* Line 387 of yacc.c  */
#line 210 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 238 "parser.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   86

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

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
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    17,    20,    23,
      25,    27,    29,    33,    35,    38,    39,    42,    44,    49,
      52,    55,    56,    61,    67,    72,    76,    80,    83,    84,
      88,    90,    95,    99,   101,   105,   108,   112,   113,   115,
     117,   119,   121,   125,   127,   132,   134,   139,   145,   148,
     149,   153,   155,   157,   161,   165,   167,   169,   171,   176,
     178,   183
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,     4,    -1,    63,    64,     5,    -1,     3,
       4,    20,    -1,    -1,    66,    82,    -1,    66,    82,    -1,
      71,    74,    -1,    41,    -1,    69,    -1,    49,    -1,    70,
      19,     4,    -1,     4,    -1,    55,    72,    -1,    -1,    72,
      73,    -1,    73,    -1,    70,    18,    68,    20,    -1,    74,
      75,    -1,    74,    77,    -1,    -1,    76,    20,    65,    20,
      -1,    58,     4,    79,    18,    69,    -1,    78,    20,    65,
      20,    -1,    56,     4,    79,    -1,    16,    80,    15,    -1,
      16,    15,    -1,    -1,    80,    20,    81,    -1,    81,    -1,
      55,    70,    18,    69,    -1,    70,    18,    69,    -1,    83,
      -1,    35,    84,    36,    -1,    84,    85,    -1,    84,    85,
      20,    -1,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,     4,    17,    92,    -1,     4,    -1,     4,    16,    91,
      15,    -1,    48,    -1,    48,    16,    91,    15,    -1,    30,
      92,    31,    85,    90,    -1,    32,    85,    -1,    -1,    91,
      19,    92,    -1,    92,    -1,    93,    -1,    92,     6,    93,
      -1,    93,    11,    94,    -1,    94,    -1,    95,    -1,    61,
      -1,    61,    16,    91,    15,    -1,    47,    -1,    47,    16,
      91,    15,    -1,    67,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    79,    80,    80,    83,    87,    92,   118,
     141,   147,   174,   175,   179,   180,   184,   185,   189,   193,
     194,   197,   201,   205,   209,   213,   217,   218,   219,   223,
     224,   228,   229,   243,   247,   251,   252,   253,   257,   263,
     264,   266,   275,   281,   282,   283,   284,   289,   293,   294,
     326,   327,   330,   335,   340,   343,   347,   355,   356,   357,
     358,   359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "IDD", "DOT", "EQUAL",
  "LTHAN", "LEQU", "GT", "GE", "PLUS", "MINUS", "MUL", "DIV", "RIGHTP",
  "LEFTP", "ASSIGN", "COLON", "COMMA", "SEMI", "UNTIL", "OR", "AND", "MOD",
  "OF", "READ", "REPEAT", "TO", "UNEQUAL", "IF", "THEN", "ELSE", "WHILE",
  "DO", "BEGINN", "END", "CASE", "DOWNTO", "FOR", "GOTO", "INTEGER", "LB",
  "RB", "NOT", "NUMBER", "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE",
  "CHAR", "CONST", "STRING", "REAL", "ARRAY", "VAR", "PROCEDURE", "RECORD",
  "FUNCTION", "TYPE", "$accept", "NAME", "program", "program_head",
  "routine", "sub_routine", "routine_head", "const_value", "type_decl",
  "simple_type_decl", "name_list", "var_part", "var_decl_list", "var_decl",
  "routine_part", "function_decl", "function_head", "procedure_decl",
  "procedure_head", "parameters", "para_decl_list", "para_type_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "expression_list",
  "expression", "expr", "term", "factor", YY_NULL
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
      68,    69,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    74,    75,    76,    77,    78,    79,    79,    79,    80,
      80,    81,    81,    82,    83,    84,    84,    84,    85,    86,
      86,    86,    87,    88,    88,    88,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    95,    95,    95,
      95,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     2,     2,     2,     1,
       1,     1,     3,     1,     2,     0,     2,     1,     4,     2,
       2,     0,     4,     5,     4,     3,     3,     2,     0,     3,
       1,     4,     3,     1,     3,     2,     3,     0,     1,     1,
       1,     1,     3,     1,     4,     1,     4,     5,     2,     0,
       3,     1,     1,     3,     3,     1,     1,     1,     4,     1,
       4,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    15,     0,     1,     0,     0,     0,    21,
       4,    13,     0,    14,    17,     3,    37,     6,    33,     8,
       0,     0,    16,     0,     0,     0,    19,     0,    20,     0,
      11,     0,    10,    12,    43,     0,    34,    45,    35,    38,
      39,    40,    41,    28,    28,    15,    15,    18,     0,     0,
       2,     9,    59,    57,    61,     0,    52,    55,    56,     0,
      36,     0,    25,     0,     0,     0,     0,     0,    51,    42,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      30,     0,    22,     7,    24,    44,     0,     0,     0,    53,
      49,    54,    46,     0,     0,    26,     0,    23,    50,    60,
      58,     0,    47,     0,    32,    29,    48,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    53,     2,     3,     7,    64,    65,    54,    31,    32,
      12,     9,    13,    14,    19,    26,    27,    28,    29,    62,
      79,    80,    17,    18,    23,    38,    39,    40,    41,    42,
     102,    67,    68,    56,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int8 yypact[] =
{
      10,    13,    28,   -36,    22,   -73,    35,    45,     9,   -73,
     -73,   -73,     8,    35,   -73,   -73,   -73,   -73,   -73,   -40,
      -3,    52,   -73,    -1,    57,    58,   -73,    43,   -73,    44,
     -73,    46,   -73,   -73,    38,     2,   -73,    49,    47,   -73,
     -73,   -73,   -73,    53,    53,   -36,   -36,   -73,     2,     2,
     -73,   -73,    54,    55,   -73,     1,    61,   -73,   -73,     2,
     -73,    -4,   -73,    50,    56,     9,    59,    -5,    67,    67,
       2,     2,     2,     0,     2,    18,   -73,    35,    39,     5,
     -73,    -3,   -73,   -73,   -73,   -73,     2,    19,    26,    61,
      42,   -73,   -73,    41,    -3,   -73,    -2,   -73,    67,   -73,
     -73,     0,   -73,    -3,   -73,   -73,   -73,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   -73,   -73,    29,    74,   -73,   -73,   -72,
     -56,   -73,   -73,    65,   -73,   -73,   -73,   -73,   -73,    36,
     -73,   -15,    17,   -73,   -73,   -65,   -73,   -73,   -73,   -73,
     -73,   -47,   -34,    11,    12,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      11,    55,    11,    34,    34,    78,    50,    72,    90,    97,
      85,    76,    75,     1,    86,    69,    24,     4,    25,     6,
      95,    93,   104,    87,    88,    96,    20,    21,     5,    35,
      35,   107,    73,    92,    99,    36,   106,    86,    86,    11,
      78,   100,    10,    51,    16,    86,    30,    37,    37,    52,
      15,    77,    98,    77,    48,    49,    33,    94,    21,   103,
      21,    43,    44,    45,    46,    59,    47,    60,    81,    61,
      70,    71,    74,    72,   101,    66,    82,     8,    22,    84,
      63,   105,    83,    89,     0,     0,    91
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       4,    35,     4,     4,     4,    61,     4,     6,    73,    81,
      15,    15,    59,     3,    19,    49,    56,     4,    58,    55,
      15,    77,    94,    70,    71,    20,    18,    19,     0,    30,
      30,   103,    31,    15,    15,    36,   101,    19,    19,     4,
      96,    15,    20,    41,    35,    19,    49,    48,    48,    47,
       5,    55,    86,    55,    16,    17,     4,    18,    19,    18,
      19,     4,     4,    20,    20,    16,    20,    20,    18,    16,
      16,    16,    11,     6,    32,    46,    20,     3,    13,    20,
      44,    96,    65,    72,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    62,    63,     4,     0,    55,    64,    66,    71,
      20,     4,    70,    72,    73,     5,    35,    82,    83,    74,
      18,    19,    73,    84,    56,    58,    75,    76,    77,    78,
      49,    68,    69,     4,     4,    30,    36,    48,    85,    86,
      87,    88,    89,     4,     4,    20,    20,    20,    16,    17,
       4,    41,    47,    61,    67,    92,    93,    94,    95,    16,
      20,    16,    79,    79,    65,    66,    65,    91,    92,    92,
      16,    16,     6,    31,    11,    91,    15,    55,    70,    80,
      81,    18,    20,    82,    20,    15,    19,    91,    91,    93,
      85,    94,    15,    70,    18,    15,    20,    69,    92,    15,
      15,    32,    90,    18,    69,    81,    85,    69
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1787 of yacc.c  */
#line 77 "pascal.y"
    { (yyval.debug) = (yyvsp[(1) - (1)].debug); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 79 "pascal.y"
    { ast_root = (yyvsp[(2) - (3)].ast_Program); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 80 "pascal.y"
    {}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 80 "pascal.y"
    {}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 83 "pascal.y"
    { (yyval.ast_Program) = (yyvsp[(1) - (2)].ast_Program); (yyval.ast_Program)->routine_body = (yyvsp[(2) - (2)].ast_StatementList); (yyval.ast_Program)->print_node("", true, true); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 87 "pascal.y"
    { (yyval.ast_Program) = (yyvsp[(1) - (2)].ast_Program); (yyval.ast_Program)->routine_body = (yyvsp[(2) - (2)].ast_StatementList); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 92 "pascal.y"
    { 
		(yyval.ast_Program) = new ast::Program(nullptr, nullptr, nullptr, (yyvsp[(1) - (2)].ast_VarDeclList), (yyvsp[(2) - (2)].ast_RoutineList), nullptr); 
	}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 118 "pascal.y"
    { (yyval.ast_Node) = new ast::IntegerType(atoi((yyvsp[(1) - (1)].debug))); (yyval.ast_Node)->debug = (yyvsp[(1) - (1)].debug); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 141 "pascal.y"
    { (yyval.ast_TypeDecl) = (yyvsp[(1) - (1)].ast_TypeDecl); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 147 "pascal.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl((yyvsp[(1) - (1)].debug)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 174 "pascal.y"
    { (yyval.ast_NameList) = (yyvsp[(1) - (3)].ast_NameList); (yyval.ast_NameList)->push_back((yyvsp[(3) - (3)].debug)); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 175 "pascal.y"
    { (yyval.ast_NameList) = new ast::NameList(); (yyval.ast_NameList)->push_back((yyvsp[(1) - (1)].debug)); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 179 "pascal.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(2) - (2)].ast_VarDeclList); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 180 "pascal.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 184 "pascal.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (2)].ast_VarDeclList); (yyvsp[(1) - (2)].ast_VarDeclList)->insert((yyvsp[(1) - (2)].ast_VarDeclList)->end(), (yyvsp[(1) - (2)].ast_VarDeclList)->begin(), (yyvsp[(1) - (2)].ast_VarDeclList)->end()); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 185 "pascal.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (1)].ast_VarDeclList); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 189 "pascal.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); for(auto name : *((yyvsp[(1) - (4)].ast_NameList))) (yyval.ast_VarDeclList)->push_back(new ast::VarDecl(new ast::Identifier(name), (yyvsp[(3) - (4)].ast_TypeDecl))); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 193 "pascal.y"
    { (yyval.ast_RoutineList) = (yyvsp[(1) - (2)].ast_RoutineList); (yyvsp[(1) - (2)].ast_RoutineList)->push_back((yyvsp[(2) - (2)].ast_Routine)); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 194 "pascal.y"
    { (yyval.ast_RoutineList) = (yyvsp[(1) - (2)].ast_RoutineList); (yyvsp[(1) - (2)].ast_RoutineList)->push_back((yyvsp[(2) - (2)].ast_Routine)); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 197 "pascal.y"
    { (yyval.ast_RoutineList) = new ast::RoutineList(); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 201 "pascal.y"
    { (yyval.ast_Routine) = new ast::Routine((yyvsp[(1) - (4)].ast_Routine), (yyvsp[(3) - (4)].ast_Program)); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 205 "pascal.y"
    { (yyval.ast_Routine) = new ast::Routine(ast::Routine::RoutineType::function, new ast::Identifier((yyvsp[(2) - (5)].debug)), (yyvsp[(3) - (5)].ast_VarDeclList), (yyvsp[(5) - (5)].ast_TypeDecl)); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 209 "pascal.y"
    { (yyval.ast_Routine) = new ast::Routine((yyvsp[(1) - (4)].ast_Routine), (yyvsp[(3) - (4)].ast_Program)); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 213 "pascal.y"
    { (yyval.ast_Routine) = new ast::Routine(ast::Routine::RoutineType::procedure, new ast::Identifier((yyvsp[(2) - (3)].debug)), (yyvsp[(3) - (3)].ast_VarDeclList), nullptr); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 217 "pascal.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(2) - (3)].ast_VarDeclList); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 218 "pascal.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 219 "pascal.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 223 "pascal.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (3)].ast_VarDeclList); (yyvsp[(1) - (3)].ast_VarDeclList)->insert((yyvsp[(1) - (3)].ast_VarDeclList)->end(), (yyvsp[(3) - (3)].ast_VarDeclList)->begin(), (yyvsp[(3) - (3)].ast_VarDeclList)->end()); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 224 "pascal.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (1)].ast_VarDeclList); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 228 "pascal.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); for(auto name: *((yyvsp[(2) - (4)].ast_NameList))) (yyval.ast_VarDeclList)->push_back(new ast::VarDecl(new ast::Identifier(name), (yyvsp[(4) - (4)].ast_TypeDecl))); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 229 "pascal.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); for(auto name: *((yyvsp[(1) - (3)].ast_NameList))) (yyval.ast_VarDeclList)->push_back(new ast::VarDecl(new ast::Identifier(name), (yyvsp[(3) - (3)].ast_TypeDecl))); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 243 "pascal.y"
    { (yyval.ast_StatementList) = (yyvsp[(1) - (1)].ast_StatementList); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 247 "pascal.y"
    { (yyval.ast_StatementList) = (yyvsp[(2) - (3)].ast_StatementList); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 251 "pascal.y"
    {/*yyerror("SEMI error");}*/ }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 252 "pascal.y"
    { (yyval.ast_StatementList) = (yyvsp[(1) - (3)].ast_StatementList); (yyvsp[(1) - (3)].ast_StatementList)->push_back((yyvsp[(2) - (3)].ast_Statement)); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 253 "pascal.y"
    { (yyval.ast_StatementList) = new ast::StatementList(); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 257 "pascal.y"
    { (yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 263 "pascal.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_AssignmentStmt); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 264 "pascal.y"
    { (yyval.ast_Statement) = (ast::Statement *) (yyvsp[(1) - (1)].ast_Statement); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 266 "pascal.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_IfStmt);}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 275 "pascal.y"
    { (yyval.ast_AssignmentStmt) = new ast::AssignmentStmt(new ast::Identifier((yyvsp[(1) - (3)].debug)), (yyvsp[(3) - (3)].ast_Expression)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 281 "pascal.y"
    { (yyval.ast_Statement) = new ast::ProcCall(new ast::Identifier((yyvsp[(1) - (1)].debug))); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 282 "pascal.y"
    { (yyval.ast_Statement) = new ast::ProcCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 283 "pascal.y"
    { (yyval.ast_Statement) = new ast::SysProcCall(new ast::Identifier((yyvsp[(1) - (1)].debug))); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 284 "pascal.y"
    { (yyval.ast_Statement) = new ast::SysProcCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 289 "pascal.y"
    { (yyval.ast_IfStmt) = new ast::IfStmt((yyvsp[(2) - (5)].ast_Expression),(yyvsp[(4) - (5)].ast_Statement),(yyvsp[(5) - (5)].ast_Statement));}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 293 "pascal.y"
    { (yyval.ast_Statement) = (yyvsp[(2) - (2)].ast_Statement);}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 294 "pascal.y"
    { (yyval.ast_Statement) = NULL;}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 326 "pascal.y"
    { (yyval.ast_ExpressionList) = (yyvsp[(1) - (3)].ast_ExpressionList); (yyvsp[(1) - (3)].ast_ExpressionList)->push_back((yyvsp[(3) - (3)].ast_Expression)); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 327 "pascal.y"
    { (yyval.ast_ExpressionList) = new ast::ExpressionList(); (yyval.ast_ExpressionList)->push_back((yyvsp[(1) - (1)].ast_Expression)); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 330 "pascal.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 335 "pascal.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::eq, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 340 "pascal.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::plus, (yyvsp[(3) - (3)].ast_Expression)); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 343 "pascal.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 347 "pascal.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 355 "pascal.y"
    { (yyval.ast_Expression) = new ast::Identifier((yyvsp[(1) - (1)].debug)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 356 "pascal.y"
    { (yyval.ast_Expression) = new ast::FuncCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 357 "pascal.y"
    { (yyval.ast_Expression) = new ast::SysFuncCall(new ast::Identifier((yyvsp[(1) - (1)].debug))); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 358 "pascal.y"
    { (yyval.ast_Expression) = new ast::SysFuncCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 359 "pascal.y"
    { (yyval.ast_Expression) = (ast::Expression *)(yyvsp[(1) - (1)].ast_Node); }
    break;


/* Line 1787 of yacc.c  */
#line 1893 "parser.cpp"
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


/* Line 2050 of yacc.c  */
#line 371 "pascal.y"



