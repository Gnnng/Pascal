/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "src/pascal.y"
{
	ast_node *a;
	int integer;
	char* debug;
}
/* Line 1529 of yacc.c.  */
#line 173 "src/parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

