/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 7 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "tabla_tipos.h"
#include "cuadruplas.h"
#include "backpatch.h"
#include "tipos.h"
#include "tabla_cadenas.h"
#include "pila_direcciones.h"

void yyerror(char *s);
extern int yylex();
extern char* yytext;
void print_code(struct code *c);
/*///////////////////////////estructuras/////////////////////////////////////*/
CODE *codigo;
SYM *simbol;
SYMTAB *new_ST;
TYPTAB *new_TT;
SSTACK *stack_sym;
TSTACK *stack_type;
SYMTAB *tab_sym;
SYMTAB *tab_symGBL;
SYMTAB *tab_sym_struct;
TYPTAB *tab_type_struct;
TYPTAB *tab_type;
TYPTAB *tab_typeGBL;
DSTACK *stack_dir;
DIR *structDir;
ARG *argx;
INDEX *indiceGlobal;
/*///////////////////////////Variables///////////////////////////////////////*/
int tipoGBL;
int baseGBL;
int tamTSGBL;
int address;
int funcType;
bool funcReturn;
ARGS *listaRET;
char idGBL[32];
#line 52 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	char dir[32];
	
	int base;
	
	struct{
		struct list_index *nextList;
		char label[15];
		char final_label[15];
	}tSentencia;

	struct{
		int tipo;
		int num;
		char dir[32];
	}num;

	struct{
		int num;
		struct args *listArgs;
	}list;

	struct{
		char dir[20];
		char base[20];
		int des;
		int tipo;
		int estruct;
		int code_struct;
		struct sym_tab *tab_sym;
	}var;

	struct{
		int tipo;
		char *dir;
		int valor;
	}exp;

	struct{
		char dir[32];
		int tipo;
		struct list_index *listTrue;
		struct list_index *listFalse;
	}e_b;

	struct{
		struct code *prueba;
		struct list_index *nextList;
	}casosPred;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 123 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ERROR 257
#define PYC 258
#define INICIO 259
#define END 260
#define ESTRUCT 261
#define DEF 262
#define IF 263
#define THEN 264
#define WHILE 265
#define DO 266
#define SEGUN 267
#define WRITE 268
#define DEV 269
#define READ 270
#define TERMINAR 271
#define CASO 272
#define PRED 273
#define DOSP 274
#define FALSE 275
#define TRUE 276
#define ENTERO 277
#define REAL 278
#define DREAL 279
#define SIN 280
#define CAR 281
#define ID 282
#define CARACTER 283
#define CADENA 284
#define NUM 285
#define COMA 286
#define IGUAL 287
#define OR 288
#define AND 289
#define IDENTICO 290
#define DIFERENTE 291
#define MENORQUE 292
#define MENORIGUAL 293
#define MAYORIGUAL 294
#define MAYORQUE 295
#define MAS 296
#define MENOS 297
#define MUL 298
#define DIV 299
#define MODULO 300
#define NOT 301
#define PUNTO 302
#define RCOR 303
#define LCOR 304
#define LPAR 305
#define RPAR 306
#define SITEMP 307
#define SINO 308
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   28,   29,    0,   30,   19,   19,   19,   31,   13,   32,
    1,    2,    2,    2,    2,    2,    3,    3,   20,   21,
   21,   33,   34,   22,   22,   11,   11,   10,   10,   16,
   35,   14,   15,   15,    6,    6,    5,   36,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,   23,
   24,   24,   25,   25,   37,    7,   38,    7,    7,    7,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,   39,
   17,   26,   26,   40,   26,   27,   27,   18,   18,   12,
   12,    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    0,    4,    0,    5,    4,    0,    0,    5,    0,
    3,    1,    1,    1,    1,    1,    4,    0,    2,    3,
    0,    0,    0,   13,    0,    1,    1,    3,    1,    2,
    0,    3,    3,    0,    2,    0,    5,    0,    8,    5,
    5,    8,    4,    3,    3,    2,    3,    2,    3,    5,
    1,    0,    3,    0,    0,    4,    0,    4,    2,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    1,    3,
    3,    3,    3,    3,    3,    1,    1,    1,    1,    0,
    3,    1,    1,    0,    4,    3,    0,    3,    4,    1,
    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   12,   13,   14,   16,   15,    4,   10,
    0,    2,    8,    0,    0,    0,    0,    0,    0,    0,
    0,   11,    0,   19,    0,    0,    3,    0,    0,    0,
    0,    6,    0,    9,    5,    0,   20,   22,   17,    0,
    0,    0,   31,    0,    0,    0,   29,    0,    0,    0,
   30,    0,   32,   28,    0,    0,   36,   33,    0,   36,
   23,    0,    0,    0,    0,    0,    0,    0,    0,   80,
   35,    0,    0,    0,   62,   61,   79,   78,   77,    0,
    0,    0,    0,    0,   76,    0,    0,    0,    0,   46,
    0,    0,   48,    0,    0,   49,   24,   59,    0,    0,
    0,    0,    0,    0,    0,   55,   57,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   44,   47,   45,    0,
   84,   83,   81,    0,    0,   75,    0,    0,   72,   73,
   74,    0,    0,    0,    0,   68,   67,   64,   65,   66,
   63,    0,    0,    0,    0,    0,    0,   43,   37,    0,
    0,   58,   40,   41,    0,    0,    0,    0,    0,   86,
   36,    0,    0,   89,    0,   85,    0,    0,    0,    0,
    0,   39,    0,    0,   42,    0,   53,   51,   50,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   22,   82,   71,   59,   83,   84,  158,   44,
   45,  159,   11,   46,   53,   47,   85,  122,   12,   17,
   24,   27,  163,  179,  170,  123,  124,    2,   18,   14,
   19,   15,   40,   74,   48,  150,  134,  135,   94,  146,
};
static const YYINT yysindex[] = {                         0,
    0,  -37, -240,    0,    0,    0,    0,    0,    0,    0,
 -275,    0,    0, -275, -243, -232, -190, -191,  -37, -185,
 -181,    0, -188,    0,  -37, -161,    0, -164,  -37, -197,
 -232,    0, -175,    0,    0, -243,    0,    0,    0, -196,
  -76,    0,    0, -176, -184, -119,    0, -139, -161,  -61,
    0, -106,    0,    0,  -37, -139,    0,    0, -118,    0,
    0,   12,   12,  107,  -80, -123, -252,  -83,  -31,    0,
    0,  -41,  -75, -191,    0,    0,    0,    0,    0,   12,
 -123, -142, -248,   90,    0, -253,  -18,  -83, -233,    0,
 -213,   -4,    0, -207, -123,    0,    0,    0,  -47, -123,
 -123, -123, -123, -123,  107,    0,    0, -123, -123, -123,
 -123, -123, -123,  107,   12,  -51,    0,    0,    0, -123,
    0,    0,    0,  -46, -208,    0, -220, -220,    0,    0,
    0,   -3,  107,   12,   12,    0,    0,    0,    0,    0,
    0,   -2, -250,    8,   47, -123,  -20,    0,    0,  -33,
  -13,    0,    0,    0,    5,  -26, -142,   -6,  -24,    0,
    0,   -1,   13,    0, -123,    0,   71,   11,   16,   29,
 -142,    0,  107,  107,    0,    5,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,   35,    0,  299,   42,    0,
    0,    0,    0,    0,    1,    0,    0,    0,    1,    0,
   35,    0,    0,    0,    0,    9,    0,    0,    0,    0,
    0, -234,    0,   10,    0,    0,    0,   32,    0,    0,
    0,    0,    0,    0,   89,   32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  299,    0,    0,    0,    0,    0,    0,
    0,   34,    0, -189,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -163,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -120,    0,    0,  -58,   15,    0,    0,
    0,    0,   24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,    0,    0,    0,    0,
 -246,    0,    0,    0,    0,  -77, -262,   27,    0,    0,
    0,    0,   59,    0,    0,    0,    0,    0,    0,    0,
 -193,    0,    0,    0,    0, -245,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  309,  -15,  315,  -44,  -62,  -56,  -53,  282,    0,    0,
    0,    0,    0,    0,  305,  313,  -59,  207,   -8,  350,
  334,  293,  192,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 395
static const YYINT yytable[] = {                         72,
    7,   87,    7,   73,   72,   90,   16,  154,   92,   86,
   28,   56,  114,   72,   52,  105,   32,   56,   13,   56,
   35,   89,   91,   93,  117,   43,   98,   52,  116,   70,
   77,   78,   79,   43,  106,  107,   99,  106,  107,  106,
  107,   56,  132,   93,  118,   72,   57,   16,  133,  148,
  125,  142,   81,   23,   72,  127,  128,  129,  130,  131,
   21,  143,  100,  101,  102,  103,  104,   25,   60,   16,
   26,   27,   29,   72,   60,  145,   60,  102,  103,  104,
  151,  152,  100,  101,  102,  103,  104,  100,  101,  102,
  103,  104,   92,   31,   87,   34,  120,  121,   60,   60,
   87,  157,   87,   30,  167,   36,   38,   72,   41,   49,
  176,  177,   92,   72,   72,    4,    5,    6,    7,    8,
  171,   50,   87,   87,   87,   87,   87,   87,   87,   87,
   87,   87,   87,   87,   87,   87,   87,   82,   87,   87,
   60,   61,   87,   82,   62,   82,   63,   64,   65,   66,
   67,   68,   69,  100,  101,  102,  103,  104,   70,   77,
   78,   79,   51,   70,   52,   82,   82,   82,   82,   82,
   82,   82,   82,   82,   82,   82,   82,   82,   82,   82,
   88,   81,   82,   60,   96,   82,   88,   62,   88,   63,
   64,   65,   66,   67,   68,   69,   56,   55,   70,   70,
    4,    5,    6,   42,    8,   70,   70,   70,   88,   88,
   88,   88,   88,   88,   88,   88,   88,   88,   88,   88,
   88,   88,   88,    3,   88,   88,   93,   70,   88,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,    4,
    5,    6,    7,    8,   70,   95,  115,   70,  100,  101,
  102,  103,  104,  119,  144,  147,  149,  153,  126,    7,
    7,  160,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,   71,  155,  161,  107,  162,  120,   71,  165,
   71,  166,    7,  168,  173,  169,   75,   76,  175,  174,
   18,   69,   21,   70,   77,   78,   79,   69,   25,   69,
   71,    7,   71,   71,   71,   71,   71,   71,   71,   71,
   71,   71,   80,   34,   36,   26,   81,   71,   54,   91,
   71,   69,   69,   69,   69,   69,   69,   69,   69,   60,
  172,   38,   90,   62,   33,   63,   64,   65,   66,   67,
   68,   69,  100,  101,  102,  103,  104,    7,    7,  156,
   39,    7,   70,    7,    7,    7,    7,    7,    7,    7,
   58,   54,  164,   20,   37,   60,   97,  178,    0,   62,
    7,   63,   64,   65,   66,   67,   68,   69,    0,  108,
  109,  110,  111,  112,  113,    0,    0,    0,   70,  136,
  137,  138,  139,  140,  141,
};
static const YYINT yycheck[] = {                         59,
    0,   64,    0,   60,   64,  258,  282,  258,   68,   63,
   19,  258,  266,   73,  260,  264,   25,  264,  259,  266,
   29,   66,   67,  286,  258,   41,   80,  273,   88,  282,
  283,  284,  285,   49,  288,  289,   81,  288,  289,  288,
  289,  288,  105,  306,  258,  105,   55,  282,  105,  258,
   95,  114,  305,  286,  114,  100,  101,  102,  103,  104,
  304,  115,  296,  297,  298,  299,  300,  258,  258,  304,
  262,  306,  258,  133,  264,  120,  266,  298,  299,  300,
  134,  135,  296,  297,  298,  299,  300,  296,  297,  298,
  299,  300,  286,  282,  258,  260,  304,  305,  288,  289,
  264,  146,  266,  285,  161,  303,  282,  167,  305,  286,
  173,  174,  306,  173,  174,  277,  278,  279,  280,  281,
  165,  306,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  258,  302,  303,
  259,  260,  306,  264,  263,  266,  265,  266,  267,  268,
  269,  270,  271,  296,  297,  298,  299,  300,  282,  283,
  284,  285,  282,  282,  304,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  299,  300,
  258,  305,  303,  259,  260,  306,  264,  263,  266,  265,
  266,  267,  268,  269,  270,  271,  303,  259,  282,  258,
  277,  278,  279,  280,  281,  264,  282,  266,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  261,  305,  303,  258,  286,  306,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  277,
  278,  279,  280,  281,  303,  287,  265,  306,  296,  297,
  298,  299,  300,  258,  306,  302,  260,  260,  306,  259,
  260,  282,  262,  263,  262,  265,  266,  267,  268,  269,
  270,  271,  258,  266,  308,  289,  272,  304,  264,  286,
  266,  306,  282,  285,  274,  273,  275,  276,  260,  274,
  282,  258,  258,  282,  283,  284,  285,  264,    0,  266,
  286,  260,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  301,  282,  308,  306,  305,  303,  260,  306,
  306,  288,  289,  290,  291,  292,  293,  294,  295,  259,
  260,  308,  306,  263,   26,  265,  266,  267,  268,  269,
  270,  271,  296,  297,  298,  299,  300,  259,  260,  303,
   36,  263,  282,  265,  266,  267,  268,  269,  270,  271,
   56,   49,  156,   14,   31,  259,   74,  176,   -1,  263,
  282,  265,  266,  267,  268,  269,  270,  271,   -1,  290,
  291,  292,  293,  294,  295,   -1,   -1,   -1,  282,  108,
  109,  110,  111,  112,  113,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 351
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ERROR","PYC","INICIO","END",
"ESTRUCT","DEF","IF","THEN","WHILE","DO","SEGUN","WRITE","DEV","READ",
"TERMINAR","CASO","PRED","DOSP","FALSE","TRUE","ENTERO","REAL","DREAL","SIN",
"CAR","ID","CARACTER","CADENA","NUM","COMA","IGUAL","OR","AND","IDENTICO",
"DIFERENTE","MENORQUE","MENORIGUAL","MAYORIGUAL","MAYORQUE","MAS","MENOS","MUL",
"DIV","MODULO","NOT","PUNTO","RCOR","LCOR","LPAR","RPAR","SITEMP","SINO",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"$$2 :",
"programa : $$1 declaraciones $$2 funciones",
"$$3 :",
"declaraciones : tipo $$3 lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"$$4 :",
"tipo_registro : ESTRUCT INICIO $$4 declaraciones END",
"$$5 :",
"tipo : base $$5 tipo_arreglo",
"base : ENTERO",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : LCOR NUM RCOR tipo_arreglo",
"tipo_arreglo :",
"lista_var : ID lista_var2",
"lista_var2 : COMA ID lista_var2",
"lista_var2 :",
"$$6 :",
"$$7 :",
"funciones : DEF tipo ID $$6 LPAR argumentos RPAR INICIO declaraciones sentencias END $$7 funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"$$8 :",
"tipo_arg : base $$8 param_arr",
"param_arr : LCOR RCOR param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencias :",
"sentencia : IF e_bool THEN sentencia END",
"$$9 :",
"sentencia : IF e_bool THEN sentencias $$9 SINO sentencias END",
"sentencia : WHILE e_bool DO sentencia END",
"sentencia : DO sentencia WHILE e_bool PYC",
"sentencia : SEGUN LPAR variable RPAR DO casos predeterminado END",
"sentencia : variable IGUAL expresion PYC",
"sentencia : WRITE expresion PYC",
"sentencia : READ variable PYC",
"sentencia : DEV PYC",
"sentencia : DEV expresion PYC",
"sentencia : TERMINAR PYC",
"sentencia : INICIO sentencias END",
"casos : CASO NUM DOSP sentencia casos2",
"casos2 : casos",
"casos2 :",
"predeterminado : PRED DOSP sentencia",
"predeterminado :",
"$$10 :",
"e_bool : e_bool OR $$10 e_bool",
"$$11 :",
"e_bool : e_bool AND $$11 e_bool",
"e_bool : NOT e_bool",
"e_bool : relacional",
"e_bool : TRUE",
"e_bool : FALSE",
"relacional : relacional MAYORQUE relacional",
"relacional : relacional MENORQUE relacional",
"relacional : relacional MENORIGUAL relacional",
"relacional : relacional MAYORIGUAL relacional",
"relacional : relacional DIFERENTE relacional",
"relacional : relacional IDENTICO relacional",
"relacional : expresion",
"expresion : expresion MAS expresion",
"expresion : expresion MENOS expresion",
"expresion : expresion MUL expresion",
"expresion : expresion DIV expresion",
"expresion : expresion MODULO expresion",
"expresion : LPAR expresion RPAR",
"expresion : variable",
"expresion : NUM",
"expresion : CADENA",
"expresion : CARACTER",
"$$12 :",
"variable : ID $$12 variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"$$13 :",
"variable_comp : LPAR $$13 parametros RPAR",
"dato_est_sim : dato_est_sim PUNTO ID",
"dato_est_sim :",
"arreglo : LCOR expresion RCOR",
"arreglo : LCOR expresion RCOR arreglo",
"parametros : lista_param",
"parametros :",
"lista_param : lista_param COMA expresion",
"lista_param : expresion",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 873 "parser.y"

void yyerror(char *msg){
	printf("%s, token: %s\n",msg, yytext);
}

void print_code(struct code *c){
	struct cuad *q =(struct cuad *)malloc(sizeof(struct cuad)); 
	printf("=========================CODIGO DE 3 DIRECCIONES=========================\n");
	q=c->head;
	while(q!=NULL){
		printf("	|%s\t|%s\t|%s\t|%s\t|\n	",q->op,q->arg1,q->arg2,q->res);
		q=q->next;
	}
}
#line 563 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 167 "parser.y"
	{
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>P R O G R A M A>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			codigo = init_code();
			stack_dir = crearPilaDir();
			stack_sym = init_sym_tab_stack();
			stack_type = init_type_tab_stack();
			tab_typeGBL = init_type_tab(tab_typeGBL);
			printf(">>>>>>>>>>T A B   G E N E R A L    D E   T I P O S>>>>>>>>>>\n");
			print_tab_type(tab_typeGBL);
			tab_symGBL = init_sym_tab();
			push_st(stack_sym,tab_symGBL);
			push_tt(stack_type,tab_typeGBL);
			address=0;
			stack_sym->top->tt_asoc = stack_type->top; 
		}
break;
case 2:
#line 181 "parser.y"
	{ /*print_tab_sym(getTopSym(stack_sym));*/
						  /*print_tab_type(getTopType(stack_type));*/
						   }
break;
case 3:
#line 183 "parser.y"
	{ print_code(codigo); }
break;
case 4:
#line 185 "parser.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 5:
#line 185 "parser.y"
	{}
break;
case 6:
#line 186 "parser.y"
	{}
break;
case 7:
#line 187 "parser.y"
	{}
break;
case 8:
#line 189 "parser.y"
	{
							tab_sym_struct = init_sym_tab();
							tab_type_struct = init_type_tab(tab_type_struct);
							structDir = crearDir();
							structDir->info = address;
							pushPDir(structDir, stack_dir);
							push_tt(stack_type,tab_type_struct);
							push_st(stack_sym, tab_sym_struct);
						
						}
break;
case 9:
#line 198 "parser.y"
	{
								/*printf(">>>>>>>>>>>>>Tablas de tipos y simbolos generales>>>>>>>>>>>>>\n");*/
								/*print_tab_sym(tab_symGBL);*/
								/*print_tab_type(getTopType(stack_type));*/
								tab_typeGBL = pop_tt(stack_type);
								tab_symGBL = pop_st(stack_sym);
								print_tab_sym(tab_sym_struct);
								print_tab_type(tab_type_struct);
								structDir = popPDir(stack_dir);
								address = structDir->info;
								TYP *newTYP = set_typ_struct(init_type(),"struct",0,tab_type_struct,tab_sym_struct);
								tipoGBL = append_type(tab_type_struct, newTYP);
						}
break;
case 10:
#line 212 "parser.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 11:
#line 212 "parser.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 12:
#line 214 "parser.y"
	{ 
			yyval.base = 0; }
break;
case 13:
#line 216 "parser.y"
	{ 
		  yyval.base = 1; }
break;
case 14:
#line 218 "parser.y"
	{ 
		  yyval.base = 4; }
break;
case 15:
#line 220 "parser.y"
	{ 
		  yyval.base = 2; }
break;
case 16:
#line 222 "parser.y"
	{ 
		  yyval.base = 3; }
break;
case 17:
#line 225 "parser.y"
	{
				if (yystack.l_mark[-2].num.tipo == 0){
					if(yystack.l_mark[-2].num.num > 0 ){
						TYP *newTYP = init_type();
						newTYP = set_typ(newTYP,"array",yystack.l_mark[0].base,yystack.l_mark[-2].num.num*getTam(getTopType(stack_type),yystack.l_mark[0].base),getTopType(stack_type));
						yyval.base = append_type(getTopType(stack_type), newTYP);
					}else{ printf("ERROR >>> El tam del arreglo debe ser mayo a cero\n"); }
				}else { printf("ERROR >>> El tam del arreglo debe ser un numero entero\n"); }
			}
break;
case 18:
#line 234 "parser.y"
	{ yyval.base = baseGBL; }
break;
case 19:
#line 236 "parser.y"
	{
					if(search_id_symbol(getTopSym(stack_sym),yystack.l_mark[-1].dir)==-1){
						SYM *new_sym = init_sym();
						new_sym= set_sym(new_sym, yystack.l_mark[-1].dir, address, tipoGBL, "var", NULL, getTopSym(stack_sym), getTopType(stack_type));
						append_sym(getTopSym(stack_sym),new_sym);
						address = address + getTam(getTopType(stack_type), tipoGBL);
					}else{
						printf("ERROR >>> El ID ya fue declarado \n");
					}
				}
break;
case 20:
#line 247 "parser.y"
	{
						if(search_id_symbol(getTopSym(stack_sym),yystack.l_mark[-1].dir)==-1){
							SYM *new_sym = init_sym();
							new_sym= set_sym(new_sym, yystack.l_mark[-1].dir, address, tipoGBL, "var", NULL, getTopSym(stack_sym), getTopType(stack_type));
							append_sym(getTopSym(stack_sym),new_sym);
							address = address + getTam(getTopType(stack_type), tipoGBL);
						}else{
							printf("ERROR >>> El ID ya fue declarado \n");
						}
					}
break;
case 21:
#line 257 "parser.y"
	{}
break;
case 22:
#line 259 "parser.y"
	{
					if(search_id_symbol(getTopSym(stack_sym),yystack.l_mark[0].dir)==-1){
							simbol = init_sym();
							simbol = set_sym(simbol,yystack.l_mark[0].dir,-1,yystack.l_mark[-1].base,"func",NULL,tab_symGBL,tab_typeGBL);
							append_sym(tab_symGBL,simbol);
							structDir = crearDir();
							structDir->info = address;
							pushPDir(structDir,stack_dir);
							funcType = yystack.l_mark[-1].base;
							funcReturn = false;
							address = 0;
							new_ST = init_sym_tab();
							new_TT = init_type_tab(new_TT);
							push_tt(stack_type,new_TT);
							push_st(stack_sym, new_ST);
							append_new_quad(codigo,"label","-","-",yystack.l_mark[0].dir);
					}else{
						printf("ERROR >>> El ID ya fue declarado \n");
					}
				}
break;
case 23:
#line 278 "parser.y"
	{
					simbol = init_sym();
					simbol = search_SYM(getTopSym(stack_sym),yystack.l_mark[-8].dir);
					simbol->args = yystack.l_mark[-5].list.listArgs;
					char *tmpEtq = create_label();
					backpatch(codigo,yystack.l_mark[-1].tSentencia.nextList,tmpEtq);
					new_TT= pop_tt(stack_type);
					new_ST= pop_st(stack_sym);
					structDir = popPDir(stack_dir);
					address = structDir->info;
					if(yystack.l_mark[-9].base != 3 && funcReturn == false){
						printf("ERROR >>> la funcion no tiene valor de retorno\n");
					}
				}
break;
case 24:
#line 291 "parser.y"
	{}
break;
case 25:
#line 292 "parser.y"
	{}
break;
case 26:
#line 294 "parser.y"
	{ yyval.list.listArgs = yystack.l_mark[0].list.listArgs; yyval.list.num = yystack.l_mark[0].list.num; }
break;
case 27:
#line 295 "parser.y"
	{  yyval.list.listArgs = NULL; yyval.list.num = 0; }
break;
case 28:
#line 297 "parser.y"
	{
					yyval.list.listArgs = yystack.l_mark[-2].list.listArgs;
					yyval.list.num = yystack.l_mark[-2].list.num+1;
					/*argx = init_arg($3);*/
					append_arg(yyval.list.listArgs, yystack.l_mark[0].base);
				}
break;
case 29:
#line 303 "parser.y"
	{
					yyval.list.listArgs = init_args();
                    /*argx = init_arg($1);*/
                    append_arg(yyval.list.listArgs, yystack.l_mark[0].base);
					yyval.list.num = 1;
				}
break;
case 30:
#line 310 "parser.y"
	{
				if( search_id_symbol(getTopSym(stack_sym),yystack.l_mark[0].dir) == -1){
					simbol = init_sym();
					simbol= set_sym(simbol, yystack.l_mark[0].dir, address, tipoGBL, "var", NULL,getTopSym(stack_sym), getTopType(stack_type));
					append_sym(getTopSym(stack_sym),simbol);
					address = address + getTam(getTopType(stack_type), tipoGBL);
					yyval.base = yystack.l_mark[-1].base;
				}else
					printf("ERROR >>> El ID ya fue declarado\n");
			}
break;
case 31:
#line 321 "parser.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 32:
#line 321 "parser.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 33:
#line 323 "parser.y"
	{
					TYP *tp = init_type();
                    tp = set_typ(tp,"array",yystack.l_mark[0].base,0,getTopType(stack_type));
                    yyval.base = append_type(getTopType(stack_type), tp);
				}
break;
case 34:
#line 327 "parser.y"
	{ yyval.base = baseGBL; }
break;
case 35:
#line 329 "parser.y"
	{
							if (strcmp(yystack.l_mark[0].tSentencia.final_label,"") == 0){ 
								strcpy(yyval.tSentencia.final_label,yystack.l_mark[-1].tSentencia.final_label);
    						} else { strcpy(yyval.tSentencia.final_label,yystack.l_mark[0].tSentencia.final_label); }
						}
break;
case 36:
#line 334 "parser.y"
	{
				yyval.tSentencia.nextList= init_list_index(init_index());
				char *tmpEtq=create_label();
				strcpy(yyval.tSentencia.label,tmpEtq);
				backpatch(codigo,yyval.tSentencia.nextList,tmpEtq);
				append_new_quad(codigo,"label","-","-",tmpEtq);
			}
break;
case 37:
#line 342 "parser.y"
	{
						char *tmpLabel=create_label();
						strcpy(yyval.tSentencia.label,tmpLabel);
						backpatch(codigo,yystack.l_mark[-3].e_b.listTrue,tmpLabel);
						append_index( yystack.l_mark[-1].tSentencia.nextList, init_index());
						yyval.tSentencia.nextList=combinar(yystack.l_mark[-3].e_b.listFalse,yystack.l_mark[-1].tSentencia.nextList);
						backpatch(codigo,yyval.tSentencia.nextList,tmpLabel);
						append_new_quad(codigo,"label","-","-",tmpLabel);
						strcpy(yyval.tSentencia.final_label,yystack.l_mark[-1].tSentencia.final_label);
				}
break;
case 38:
#line 352 "parser.y"
	{
						char *L1=create_label();
						char *L2=create_label();
						char *tmpLabel=create_label();
						strcpy(tmpLabel,yystack.l_mark[0].tSentencia.label);
						backpatch(codigo,yystack.l_mark[-2].e_b.listTrue,tmpLabel);
						append_index(yystack.l_mark[-2].e_b.listFalse,init_index());
						append_new_quad(codigo,"goto","-","-",L2);
						append_index(yystack.l_mark[0].tSentencia.nextList,init_index());
						append_new_quad(codigo,"label","-","-",L1);
				}
break;
case 39:
#line 362 "parser.y"
	{
						char *L3=create_label();
						char *L4=create_label();
						append_index(yystack.l_mark[-6].e_b.listFalse,init_index());
						backpatch(codigo,yystack.l_mark[-6].e_b.listTrue,L4);
						backpatch(codigo,yystack.l_mark[-4].tSentencia.nextList,L3);
						append_new_quad(codigo,"label","-","-",L3);
				}
break;
case 40:
#line 370 "parser.y"
	{
						char *L1=create_label();
						char *L2=create_label();
						backpatch(codigo,yystack.l_mark[-1].tSentencia.nextList,L1);
						backpatch(codigo,yystack.l_mark[-3].e_b.listTrue,L2);
						yyval.tSentencia.nextList=yystack.l_mark[-3].e_b.listFalse;
						append_new_quad(codigo,"label","-","-",L1);
						append_new_quad(codigo,"label","-","-",L2);
						char *L_nextList = create_label();
						backpatch(codigo,yystack.l_mark[-1].tSentencia.nextList,L_nextList);
						append_new_quad(codigo,"goto","-","-",L_nextList);
					}
break;
case 41:
#line 382 "parser.y"
	{
						char *tmpLabel=create_label();
						char *tmpLabel2=create_label();
						strcpy(tmpLabel2,yystack.l_mark[-3].tSentencia.label);
						backpatch(codigo,yystack.l_mark[-1].e_b.listTrue,tmpLabel2);
						backpatch(codigo,yystack.l_mark[-1].e_b.listFalse,tmpLabel);
						append_new_quad(codigo,"label","-","-",tmpLabel);
					}
break;
case 42:
#line 390 "parser.y"
	{
						char *L1=create_label();
						LINDEX *prueba  =  (LINDEX *)malloc(sizeof(LINDEX));
						prueba = combinar(yystack.l_mark[-2].casosPred.nextList, yystack.l_mark[-1].casosPred.nextList);
						backpatch(codigo,yystack.l_mark[-2].casosPred.nextList,L1);
						sustituir("??",yystack.l_mark[-5].var.dir,prueba,codigo);
					}
break;
case 43:
#line 397 "parser.y"
	{
						if((search_id_symbol(getTopSym(stack_sym),yystack.l_mark[-3].var.dir) != -1) || (search_id_symbol(tab_symGBL,yystack.l_mark[-3].var.dir) != -1 )){
							simbol = init_sym();
							simbol = search_SYM(getTopSym(stack_sym),yystack.l_mark[-3].var.dir);
							if(simbol==NULL){
								simbol=search_SYM(tab_symGBL,yystack.l_mark[-3].var.dir);
							}
							char *dir1 = (char*)malloc(sizeof(char)*15);
							dir1 = reducir(yystack.l_mark[-1].exp.dir,yystack.l_mark[-1].exp.tipo,yystack.l_mark[-3].var.tipo,codigo);
							char *tmp2=(char*)malloc(sizeof(char)*15);
							strcpy(tmp2,yystack.l_mark[-3].var.dir);
							append_new_quad(codigo,"=",dir1,"-",tmp2);
						}else{
							printf("ERROR >>> La variable  no se ha declarado\n");
						}
					}
break;
case 44:
#line 413 "parser.y"
	{
						char *e_dir = (char*)malloc(sizeof(char)*15);
      					strcpy(e_dir,yystack.l_mark[-1].exp.dir);
						append_new_quad(codigo,"write",e_dir,"-","-");
					}
break;
case 45:
#line 418 "parser.y"
	{
						char *v_dir = (char*)malloc(sizeof(char)*15);
      					strcpy(v_dir,yystack.l_mark[-1].var.dir);
						append_new_quad(codigo,"read","-","-",v_dir); 
					}
break;
case 46:
#line 423 "parser.y"
	{	
						if(funcType==3){
							append_new_quad(codigo,"return","-","-","-");
						}else{
							printf("ERROR >>> La funcion debe retornar  algun valor de tipo => %d",funcType);
						}
					}
break;
case 47:
#line 430 "parser.y"
	{ 
						if(funcType!=3){
							char *new_dir = (char*)malloc(sizeof(char)*15);
							new_dir= reducir(yystack.l_mark[-1].exp.dir,yystack.l_mark[-1].exp.tipo,funcType,codigo);
							append_new_quad(codigo,"return",yystack.l_mark[-1].exp.dir,"-","-");
							funcReturn=true;
						}else{
								printf("ERROR >>> La funcion debe retornar  algun valor de tipo ==>%d",funcType);
						}
					}
break;
case 48:
#line 440 "parser.y"
	{	
						indiceGlobal = init_index();
						char *tmp3=(char*)malloc(sizeof(char)*15);
						sprintf(tmp3, "%i", indiceGlobal->indice);
						append_new_quad(codigo, "goto", "-", "-", tmp3);
						yyval.tSentencia.nextList = init_list_index(indiceGlobal);
						append_index(yyval.tSentencia.nextList, indiceGlobal);
					}
break;
case 49:
#line 448 "parser.y"
	{ 
						yyval.tSentencia.nextList=yystack.l_mark[-1].tSentencia.nextList;
					}
break;
case 50:
#line 452 "parser.y"
	{
						/*$$.nextList = combinar($$.nextList, $4.nextList);*/
						/*char *label_C = create_label();*/
						/*Indica el inicio del código para la sentencia*/
						/*$$.prueba = $5.prueba;*/
						/*sustituir_cc()*/
						/*(if ”??” ”==” num.dir ”goto” L )*/
					}
break;
case 51:
#line 461 "parser.y"
	{
			/*casos.prueba = newCode()*/
			/*char *LT = create_label();*/
			/*Indica el inicio del código para la sentencia*/
			/*genCode(”label” L)*/
			/*casos.prueba.append(if ”??” ”==” num.dir ”goto” L )*/
		}
break;
case 52:
#line 468 "parser.y"
	{}
break;
case 53:
#line 470 "parser.y"
	{
					/*predeterminado.prueba = newCode()*/
					/*char *lll = create_label();*/
					/*Indica el inicio del código para la sentencia*/
					/*genCode(”label” L)*/
					/*predeterminado.prueba.append(”goto” L )*/
				}
break;
case 54:
#line 477 "parser.y"
	{}
break;
case 55:
#line 479 "parser.y"
	{
			char *tmpEtq = create_label();
			backpatch(codigo,yystack.l_mark[-1].e_b.listFalse,tmpEtq);
			append_new_quad(codigo,"label","-","-",tmpEtq);
		}
break;
case 56:
#line 483 "parser.y"
	{
			yyval.e_b.listTrue=combinar(yystack.l_mark[-3].e_b.listTrue,yystack.l_mark[0].e_b.listTrue);
			yyval.e_b.listFalse=yystack.l_mark[0].e_b.listFalse;
		}
break;
case 57:
#line 487 "parser.y"
	{
			char *tmpEtq=create_label();
			backpatch(codigo,yystack.l_mark[-1].e_b.listTrue,tmpEtq);
			append_new_quad(codigo,"label","-","-",tmpEtq);
		}
break;
case 58:
#line 491 "parser.y"
	{
			yyval.e_b.listTrue=yystack.l_mark[0].e_b.listTrue;
			yyval.e_b.listFalse=combinar(yystack.l_mark[-3].e_b.listFalse,yystack.l_mark[0].e_b.listFalse);}
break;
case 59:
#line 494 "parser.y"
	{
			yyval.e_b.listTrue=yystack.l_mark[0].e_b.listFalse;
			yyval.e_b.listFalse=yystack.l_mark[0].e_b.listTrue;}
break;
case 60:
#line 497 "parser.y"
	{
			printf("relacional\n");
			yyval.e_b.listTrue=yystack.l_mark[0].e_b.listTrue;
			yyval.e_b.listFalse=yystack.l_mark[0].e_b.listFalse;}
break;
case 61:
#line 501 "parser.y"
	{
			indiceGlobal = init_index();
			yyval.e_b.listFalse=init_list_index(NULL); 
			yyval.e_b.listTrue=init_list_index(NULL);
			append_index(yyval.e_b.listTrue, indiceGlobal);
			char *tmp=(char*)malloc(sizeof(char)*15);
			sprintf(tmp, "%i", indiceGlobal->indice);
			append_new_quad(codigo,"goto","-","-",tmp);}
break;
case 62:
#line 509 "parser.y"
	{
			indiceGlobal = init_index();
			yyval.e_b.listFalse=init_list_index(NULL); 
			yyval.e_b.listTrue=init_list_index(NULL);
			append_index(yyval.e_b.listFalse, indiceGlobal);
			char *tmp=(char*)malloc(sizeof(char)*15);
			sprintf(tmp, "%i", indiceGlobal->indice);
			append_new_quad(codigo,"goto","-","-",tmp);
		}
break;
case 63:
#line 519 "parser.y"
	{
				/*printf("relacional > \n");*/
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				yyval.e_b.listTrue = init_list_index(NULL);
				yyval.e_b.listFalse = init_list_index(NULL);
				strcpy(tmpR1,yystack.l_mark[-2].e_b.dir);
    			strcpy(tmpR2,yystack.l_mark[0].e_b.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index(yyval.e_b.listTrue,tmpI1);
				append_index(yyval.e_b.listFalse,tmpI2);
				append_quad(codigo,init_quad(">",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
break;
case 64:
#line 539 "parser.y"
	{	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				yyval.e_b.listTrue = init_list_index(NULL);
				yyval.e_b.listFalse = init_list_index(NULL);
				strcpy(tmpR1,yystack.l_mark[-2].e_b.dir);
    			strcpy(tmpR2,yystack.l_mark[0].e_b.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index(yyval.e_b.listTrue,tmpI1);
				append_index(yyval.e_b.listFalse,tmpI2);
				append_quad(codigo,init_quad("<",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
break;
case 65:
#line 558 "parser.y"
	{	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				yyval.e_b.listTrue = init_list_index(NULL);
				yyval.e_b.listFalse = init_list_index(NULL);
				strcpy(tmpR1,yystack.l_mark[-2].e_b.dir);
    			strcpy(tmpR2,yystack.l_mark[0].e_b.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index(yyval.e_b.listTrue,tmpI1);
				append_index(yyval.e_b.listFalse,tmpI2);
				append_quad(codigo,init_quad("<=",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
break;
case 66:
#line 577 "parser.y"
	{	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				yyval.e_b.listTrue = init_list_index(NULL);
				yyval.e_b.listFalse = init_list_index(NULL);
				strcpy(tmpR1,yystack.l_mark[-2].e_b.dir);
    			strcpy(tmpR2,yystack.l_mark[0].e_b.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index(yyval.e_b.listTrue,tmpI1);
				append_index(yyval.e_b.listFalse,tmpI2);
				append_quad(codigo,init_quad(">=",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
break;
case 67:
#line 596 "parser.y"
	{	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				yyval.e_b.listTrue = init_list_index(NULL);
				yyval.e_b.listFalse = init_list_index(NULL);
				strcpy(tmpR1,yystack.l_mark[-2].e_b.dir);
    			strcpy(tmpR2,yystack.l_mark[0].e_b.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index(yyval.e_b.listTrue,tmpI1);
				append_index(yyval.e_b.listFalse,tmpI2);
				append_quad(codigo,init_quad("<>",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
break;
case 68:
#line 615 "parser.y"
	{	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				yyval.e_b.listTrue = init_list_index(NULL);
				yyval.e_b.listFalse = init_list_index(NULL);
				strcpy(tmpR1,yystack.l_mark[-2].e_b.dir);
    			strcpy(tmpR2,yystack.l_mark[0].e_b.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index(yyval.e_b.listTrue,tmpI1);
				append_index(yyval.e_b.listFalse,tmpI2);
				append_quad(codigo,init_quad("=",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
break;
case 69:
#line 634 "parser.y"
	{
				strcpy(yyval.e_b.dir,yystack.l_mark[0].exp.dir);
				yyval.e_b.tipo = yystack.l_mark[0].exp.tipo;
			}
break;
case 70:
#line 639 "parser.y"
	{
				yyval.exp.tipo = max(yystack.l_mark[-2].exp.tipo, yystack.l_mark[0].exp.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				yyval.exp.dir = nuevaTemp();
				strcpy(dirTmp,yyval.exp.dir);
				dir1 = ampliar(yystack.l_mark[-2].exp.dir,yystack.l_mark[-2].exp.tipo,yyval.exp.tipo,codigo);
				dir2 = ampliar(yystack.l_mark[0].exp.dir,yystack.l_mark[0].exp.tipo,yyval.exp.tipo,codigo);
				append_new_quad(codigo,"+", dir1, dir2, dirTmp);
			}
break;
case 71:
#line 650 "parser.y"
	{
				yyval.exp.tipo = max(yystack.l_mark[-2].exp.tipo, yystack.l_mark[0].exp.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				yyval.exp.dir = nuevaTemp();
				strcpy(dirTmp,yyval.exp.dir);
				dir1 = ampliar(yystack.l_mark[-2].exp.dir,yystack.l_mark[-2].exp.tipo,yyval.exp.tipo,codigo);
				dir2 = ampliar(yystack.l_mark[0].exp.dir,yystack.l_mark[0].exp.tipo,yyval.exp.tipo,codigo);
				append_new_quad(codigo,"-", dir1, dir2, dirTmp);
			}
break;
case 72:
#line 661 "parser.y"
	{
				yyval.exp.tipo = max(yystack.l_mark[-2].exp.tipo, yystack.l_mark[0].exp.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				yyval.exp.dir = nuevaTemp();
				strcpy(dirTmp,yyval.exp.dir);
				dir1 = ampliar(yystack.l_mark[-2].exp.dir,yystack.l_mark[-2].exp.tipo,yyval.exp.tipo,codigo);
				dir2 = ampliar(yystack.l_mark[0].exp.dir,yystack.l_mark[0].exp.tipo,yyval.exp.tipo,codigo);
				append_new_quad(codigo,"*", dir1, dir2, dirTmp);
			}
break;
case 73:
#line 672 "parser.y"
	{
				yyval.exp.tipo = max(yystack.l_mark[-2].exp.tipo, yystack.l_mark[0].exp.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				yyval.exp.dir = nuevaTemp();
				strcpy(dirTmp,yyval.exp.dir);
				dir1 = ampliar(yystack.l_mark[-2].exp.dir,yystack.l_mark[-2].exp.tipo,yyval.exp.tipo,codigo);
				dir2 = ampliar(yystack.l_mark[0].exp.dir,yystack.l_mark[0].exp.tipo,yyval.exp.tipo,codigo);
				append_new_quad(codigo,"/", dir1, dir2, dirTmp);
			}
break;
case 74:
#line 683 "parser.y"
	{
				if (yystack.l_mark[-2].exp.tipo==1 && yystack.l_mark[0].exp.tipo==1){
					yyval.exp.tipo = max(yystack.l_mark[-2].exp.tipo, yystack.l_mark[0].exp.tipo);
					char *dir1 = (char *)malloc(sizeof(char)*10);
					char *dir2 = (char *)malloc(sizeof(char)*10);
					char *dirTmp = (char *)malloc(sizeof(char)*10);
					yyval.exp.dir = nuevaTemp();
					strcpy(dirTmp,yyval.exp.dir);
					dir1 = ampliar(yystack.l_mark[-2].exp.dir,yystack.l_mark[-2].exp.tipo,yyval.exp.tipo,codigo);
					dir2 = ampliar(yystack.l_mark[0].exp.dir,yystack.l_mark[0].exp.tipo,yyval.exp.tipo,codigo);
					append_new_quad(codigo,"%", dir1, dir2, dirTmp);
				}else{
					printf("ERROR >>> La operacion modulo no se puede aplicar\n");
				}
			}
break;
case 75:
#line 698 "parser.y"
	{
				yyval.exp.tipo = yystack.l_mark[-1].exp.tipo;
				strcpy(yyval.exp.dir,yystack.l_mark[-1].exp.dir);
				}
break;
case 76:
#line 702 "parser.y"
	{
				yyval.exp.tipo = yystack.l_mark[0].var.tipo;
				strcpy(yyval.exp.dir,yystack.l_mark[0].var.dir);
				}
break;
case 77:
#line 706 "parser.y"
	{
				yyval.exp.tipo = yystack.l_mark[0].num.tipo;
				strcpy(yyval.exp.dir,yystack.l_mark[0].num.dir);
				yyval.exp.valor = yystack.l_mark[0].num.num;
			}
break;
case 78:
#line 711 "parser.y"
	{}
break;
case 79:
#line 712 "parser.y"
	{}
break;
case 80:
#line 714 "parser.y"
	{
			if ((search_id_symbol(stack_sym->top,yystack.l_mark[0].dir) == -1|| search_id_symbol(stack_sym->tail,yystack.l_mark[0].dir) == -1)) { 
				strcpy(idGBL,yystack.l_mark[0].dir);
			} else {
				printf("ERROR >>> No se ha declarado variable %s\n",yystack.l_mark[0].dir);
			}
		}
break;
case 81:
#line 720 "parser.y"
	{
			if (yystack.l_mark[0].var.estruct == 1) {
				char *tmp = (char *)malloc(sizeof(char)*10);
				char *tmp2 = (char *)malloc(sizeof(char)*20);
				tmp = nuevaTemp();
				strcpy(yyval.var.dir,tmp);
				yyval.var.tipo = yystack.l_mark[0].var.tipo;
				sprintf(tmp2,"%s[%s]",yystack.l_mark[-2].dir,yystack.l_mark[0].var.dir);
				append_quad(codigo,init_quad("=",tmp2,"-",tmp));
				strcpy(yyval.var.base,yystack.l_mark[-2].dir);
				yyval.var.estruct = 1;
				yyval.var.des = yystack.l_mark[0].var.des;
			} else if (yystack.l_mark[0].var.estruct == 2){
				strcpy(yyval.var.dir,yystack.l_mark[0].var.dir);
				yyval.var.tipo = getTipo(stack_sym->top,yystack.l_mark[-2].dir);
				yyval.var.estruct = 0;
			} else {
				strcpy(yyval.var.dir,yystack.l_mark[-2].dir);
				yyval.var.tipo = getTipo(stack_sym->top,yystack.l_mark[-2].dir);
				yyval.var.estruct = 0;
			}
		}
break;
case 82:
#line 743 "parser.y"
	{
					yyval.var.tipo = yystack.l_mark[0].var.tipo;
					yyval.var.des = yystack.l_mark[0].var.des;
					yyval.var.estruct = yystack.l_mark[0].var.estruct;
					if (yystack.l_mark[0].var.estruct == 1) {
					char *tmp = (char *)malloc(sizeof(char)*10);
					char *tmp2 = (char *)malloc(sizeof(char)*10);
					tmp = nuevaTemp();
					sprintf(tmp2,"%d",yystack.l_mark[0].var.des);
					append_quad(codigo,init_quad("=",tmp2,"-",tmp));
					strcpy(yyval.var.dir,tmp);
					}
				}
break;
case 83:
#line 756 "parser.y"
	{
					yyval.var.tipo = yystack.l_mark[0].var.tipo;
					yyval.var.des = yystack.l_mark[0].var.des;
					yyval.var.estruct = 1;
					strcpy(yyval.var.dir,yystack.l_mark[0].var.dir);
				}
break;
case 84:
#line 762 "parser.y"
	{strcpy(yystack.l_mark[0].dir,idGBL);}
break;
case 85:
#line 762 "parser.y"
	{
					char *tmp = (char *)malloc(sizeof(char)*10);
					char *tmp2 = (char *)malloc(sizeof(char)*10);
					strcpy(tmp,yystack.l_mark[-3].dir);
					tmp2 = nuevaTemp();
					strcpy(yyval.var.dir,tmp2);
					yyval.var.estruct = 2;
					if (strcmp(getVar(stack_sym->top,tmp),"func") == 0) {
						ARGS *lista = getArgs(stack_sym->top,tmp);
						int num = lista->num;
						if (num != yystack.l_mark[-1].list.num) { printf("ERROR >>> El numero de parametros no coinciden con la funcion\n"); }
						if (compare_args(lista,yystack.l_mark[-1].list.listArgs) == 0) { printf("ERROR >>> El numero de parametros no coinciden con la funcion\n"); }
					} else { printf("ERROR >>> La variable no es una funcion\n"); }
					append_quad(codigo,init_quad("call",tmp,"-",tmp2));
				}
break;
case 86:
#line 778 "parser.y"
	{
					if (yystack.l_mark[-2].var.code_struct == 1) {
						if (search_id_symbol(yystack.l_mark[-2].var.tab_sym,yystack.l_mark[0].dir) != -1) {
							yyval.var.des = yystack.l_mark[-2].var.des + getDir(yystack.l_mark[-2].var.tab_sym,yystack.l_mark[0].dir);
							char *idDir =(char *)malloc(sizeof(char)*32);
							strcpy(idDir,yystack.l_mark[0].dir);
							int tipoTmp= getTipo(yystack.l_mark[-2].var.tab_sym,idDir);
							yyval.var.tipo = tipoTmp;
							char est[15];
							strcpy(est,getNombre(yystack.l_mark[-2].var.tab_sym->tt_asoc,tipoTmp));
							if (strcmp(est,"struct") == 0) {
								yyval.var.code_struct = 1;
								yyval.var.tab_sym = get_TS_asoc(yystack.l_mark[-2].var.tab_sym->tt_asoc,tipoTmp);
							} else {
								yyval.var.code_struct = 0;
								yyval.var.tab_sym = NULL;
							}
						} else {
							printf("ERROR >>> La variable no ha sido declarada\n");
						}
					} else{ 
						printf("ERROR >>> La variable no es una estructura\n");
						}
				}
break;
case 87:
#line 802 "parser.y"
	{
				int tipoTmp = getTipo(getTopSym(stack_sym),idGBL);
				if (strcmp(getNombre(getTopType(stack_type),tipoTmp),"struct") == 0) {
					yyval.var.estruct = 1;
					yyval.var.code_struct = 1;
					yyval.var.tab_sym = get_TS_asoc(getTopType(stack_type),tipoTmp);
					yyval.var.des = 0;
				} else {
					yyval.var.estruct = 0;
					yyval.var.code_struct = 0;
					yyval.var.tipo = tipoTmp;
				}
			}
break;
case 88:
#line 816 "parser.y"
	{
				yyval.var.tipo = getTipo(getTopSym(stack_sym),idGBL);
				if (strcmp(getNombre(getTopType(stack_type),yyval.var.tipo),"array") == 0) {
					if (yystack.l_mark[-1].exp.tipo == 1) {
						int tmp3 = getTipoBase(getTopType(stack_type),yyval.var.tipo);
						int tam = getTam(getTopType(stack_type),tmp3);
						char *tmp5 = (char *)malloc(sizeof(char)*10);
						char *tmp7 = (char *)malloc(sizeof(char)*10);
						char *tmp4 = nuevaTemp();
						strcpy(yyval.var.dir,tmp4);
						sprintf(tmp5,"%d",tam);
						strcpy(tmp7,yystack.l_mark[-1].exp.dir);
						append_quad(codigo,init_quad("*",tmp7,tmp5,tmp4));
					} else { printf("ERROR >>> El numero del arreglo no es un numero entero\n"); }
				} else { printf("ERROR >>> La variable asociada no es de tipo arreglo\n"); }
			}
break;
case 89:
#line 832 "parser.y"
	{
			yyval.var.tipo = getTipoBase(getTopType(stack_type),yystack.l_mark[0].var.tipo);
			if (strcmp(getNombre(getTopType(stack_type),yyval.var.tipo),"array") == 0) {
				if (yystack.l_mark[-2].exp.tipo == 1) {
					int tmp = getTipoBase(getTopType(stack_type),yyval.var.tipo);
					int tam = getTam(getTopType(stack_type),tmp);
					char *tmp3 = (char *)malloc(sizeof(char)*10);
					char *tmp4 = (char *)malloc(sizeof(char)*10);
					char *tmp6 = (char *)malloc(sizeof(char)*10);
					char *tmp2 = nuevaTemp();
					char *tmp5 = nuevaTemp();
					strcpy(yyval.var.dir,tmp5);
					sprintf(tmp3,"%d",tam);
					strcpy(tmp4,yystack.l_mark[-2].exp.dir);
					strcpy(tmp6,yystack.l_mark[0].var.dir);
					append_quad(codigo,init_quad("*",tmp4,tmp3,tmp2));
					append_quad(codigo,init_quad("+",tmp2,tmp6,tmp5));
					yyval.var.des = yystack.l_mark[-2].exp.valor * atoi(tmp3);
				} else { printf("ERROR >>> El numero del arreglo no es un numero entero\n"); }
			} else { printf("ERROR >>> La variable asociada no es de tipo arreglo\n"); }
			}
break;
case 90:
#line 854 "parser.y"
	{
				yyval.list.listArgs = yystack.l_mark[0].list.listArgs;
				yyval.list.num = yystack.l_mark[0].list.num;
			}
break;
case 91:
#line 858 "parser.y"
	{
				yyval.list.listArgs = NULL;
				yyval.list.num = 0;
			}
break;
case 92:
#line 863 "parser.y"
	{
				yyval.list.listArgs = yystack.l_mark[-2].list.listArgs;
				append_arg(yyval.list.listArgs,yystack.l_mark[0].exp.tipo);
				yyval.list.num = yyval.list.num + 1;
			}
break;
case 93:
#line 868 "parser.y"
	{
				yyval.list.listArgs = init_args();
				append_arg(yyval.list.listArgs,yystack.l_mark[0].exp.tipo);
				yyval.list.num = 1;
			}
break;
#line 1737 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
