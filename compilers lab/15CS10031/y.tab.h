/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 22 "ass5_15CS10031.y" /* yacc.c:1909  */

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

#line 245 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
