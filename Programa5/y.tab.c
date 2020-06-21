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
extern int yylineno;
extern int yylex();
extern char* yytext;

/*Se deben declarar las estructuras que para nuestro proyecto se tienen.
* Estas estructuras estan dentro de Data.h, cuadruplas.h, backpatch.h y tipos.h
*/
SSTACK *pSimbolos; 
TSTACK *pTipos; 
DSTACK *pDirecciones; 
SYMTAB *TGS, *TS1, *tTempSimbol;
/*TGT: Tabla General de Tipos, TT1: Tabla Tipos 1*/
TYPTAB *TGT, *TT1, *tTempTipos; 
CADTAB *tabCadenas;
SYM *simbol; 
ARG *argx; 
ARG *arg; 
ARG *arg2; 
TYP *newTipo; 
CODE* codigo; 
ARGS *ListaArg; 
INDEX *indiceGlobal, *indiceAux; 

/*///////////////////////////Variables doc 2020-2DDS_usr1///////////////////////////////////////*/
int dir;
int dir1, dir2, dirTemp; /*Dir temporales*/
int typeGBL;
int typeTemp;
int tam;
int baseGBL;
char *L;
char *L1, *L2; /*L temporales*/
char IDGBL[32];
char *estTemp;/*nombre de la tabla de tipos*/
#line 57 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	struct{
    	int valorTipo;
  	}tipo;

	struct{
	    int tipe;
	    char* valor;
	}num;

	struct{
	   char *lexval;
	}id;
		
	struct{
	    int tipoCad;
	    char *lexval;
	    struct CAD *cad;/*FALTA IMPLEMENTACION DE LA ESTRUCTURA CADENAS*/
	}cad;

	struct{
	  	struct LINDEX *nextlist;/*listIndex*/
	}listIndice_S; 
	
	struct{
		struct LINDEX *prueba;/*listIndex*/
	  	struct LINDEX *nextlist;/*listIndex*/
	}listIndice_C; 

	struct{
		struct LINDEX *prueba;/*listIndex*/
	}listIndice_P;

	struct{
	   	struct LINDEX *listTrue; /*En la DDS viene como truelist*/
	   	struct LINDEX *listFalse; /*En la DDS viene como falselist*/
	}eBool;

	struct{
	    int tipoRel; /*En la DDS viene como tipo */
	    char* dirRel;/*En la DDS viene como dir*/
	    struct LINDEX *listRelTrue;/*En la DDS viene como truelist*/
	    struct LINDEX *listRelFalse;/*En la DDS viene como falselist*/
  	}rel;
	
	struct{
    	int tipoExp;
		char *dirExp;
    }eExpr;
	
	struct{
    	int tipoVA;
    	int baseVA;
    	int tam;
    	char *dirVA;
  	}var;
	
	struct{
    	struct ARGS *listArgs;/*listParam*/
  	}eListARGS;

	struct{
		int tipoVaComp;
		char *des;
		int code_est;
	}varComp;

	struct{
		int estructura;
		struct SYMTAB *tabla;
		int type;
		char *des;
		int code_est;
	}datoEst;
	

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 155 "y.tab.c"

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
#define DEF 258
#define ESTRUCT 259
#define ENTERO 260
#define REAL 261
#define DREAL 262
#define SIN 263
#define CAR 264
#define CARACTER 265
#define CADENA 266
#define NUM 267
#define ID 268
#define IF 269
#define THEN 270
#define DO 271
#define WHILE 272
#define SEGUN 273
#define TRUE 274
#define FALSE 275
#define INICIO 276
#define TERMINAR 277
#define END 278
#define CASO 279
#define PRED 280
#define WRITE 281
#define READ 282
#define DEV 283
#define COMA 284
#define DOSP 285
#define PYC 286
#define PUNTO 287
#define IGUAL 288
#define OR 289
#define AND 290
#define IDENTICO 291
#define DIFERENTE 292
#define MENORQUE 293
#define MENORIGUAL 294
#define MAYORIGUAL 295
#define MAYORQUE 296
#define MAS 297
#define MENOS 298
#define MUL 299
#define DIV 300
#define MODULO 301
#define NOT 302
#define LPAR 303
#define RPAR 304
#define LCOR 305
#define RCOR 306
#define SITEMP 307
#define SINO 308
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   26,    0,   19,   19,   19,   14,    1,    2,    2,    2,
    2,    2,    3,    3,   20,   20,   21,   21,   11,   11,
   10,   10,   13,   15,   16,   16,    6,    6,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
   22,   27,   27,   23,   23,    7,    7,    7,    7,    7,
    7,    8,    8,    8,    8,    8,    8,    8,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,   17,   24,
   24,   24,   25,   25,   18,   18,   12,   12,    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    3,    4,    4,    0,    4,    2,    1,    1,    1,
    1,    1,    4,    0,    3,    1,   11,    0,    1,    1,
    3,    1,    2,    2,    3,    0,    2,    1,    5,    7,
    5,    5,    8,    4,    3,    3,    2,    3,    2,    3,
    5,    1,    0,    3,    0,    3,    3,    2,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    1,    3,    3,
    3,    3,    3,    3,    1,    1,    1,    1,    2,    1,
    1,    3,    3,    0,    3,    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    8,    9,   10,   12,   11,    0,    0,
    0,    0,    0,   16,    0,    0,    7,    0,    0,    2,
    0,    0,    0,    0,    0,    0,    6,   15,    3,    0,
    4,    0,   13,    0,    0,    0,    0,    0,   22,    0,
    0,   24,    0,    0,   23,    0,   21,    0,   25,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    0,    0,    0,    0,    0,   69,    0,   68,   67,
   66,   50,   51,    0,    0,    0,    0,    0,   65,    0,
    0,    0,    0,   39,    0,    0,   37,    0,    0,   27,
    0,    0,    0,    0,    0,    0,    0,   48,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   40,   35,   36,   38,
   17,    0,    0,   72,   75,    0,   73,   64,    0,    0,
   61,   62,   63,    0,    0,   47,    0,    0,   52,   54,
   55,   53,    0,    0,    0,   34,    0,   76,   29,    0,
   32,   31,    0,    0,    0,    0,   30,    0,    0,    0,
    0,    0,   33,    0,   44,   42,   41,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   76,   61,   62,   77,   78,   93,   37,
   38,   94,   39,   11,   40,   42,   79,   66,   12,   15,
   20,  156,  160,   67,   68,    2,  167,
};
static const YYINT yysindex[] = {                         0,
    0,  -23, -266,    0,    0,    0,    0,    0, -253, -254,
 -253, -219,  -23,    0, -273, -215,    0, -200,  139,    0,
 -222, -206,  -23, -243,  -23, -202,    0,    0,    0, -254,
    0, -228,    0,  144,    0, -190, -142, -134,    0,  -96,
 -128,    0,  139,  -97,    0, -190,    0,  -23,    0,   71,
 -165, -244,   71, -244, -123,   71, -102, -220,  -66, -249,
    0,   39,  -79, -220, -220,  -95,    0,  -75,    0,    0,
    0,    0,    0, -244, -220,  112, -263,   96,    0,  -58,
 -201,  -66,   55,    0,   75,  -70,    0,   80, -219,    0,
 -220,  112,  -67,  -74, -154, -220,  -37,    0,  -93, -220,
 -220, -220, -220, -220,   71, -244, -244, -220, -220, -220,
 -220, -220, -220, -244,   71,  -72,    0,    0,    0,    0,
    0,   85, -220,    0,    0, -124,    0,    0, -191, -191,
    0,    0,    0, -258,  -56,    0,  121,  121,    0,    0,
    0,    0, -213,  -33,  -25,    0,  112,    0,    0,   71,
    0,    0,  -24,  -21,  -11,  -15,    0,  -19,  -18,  -10,
   71,   71,    0,  -24,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0, -253,
    0,  271,    3,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,    1,    0,    0,    0,    0, -253,
    0,    0,    0,    0, -264,   12,  -14,    0,    0,    0,
    0,    0,    0,    0,    0,   12,    0,   87,    0,    0,
 -167,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -12,    0, -135,    0, -103,    0,    0,
    0,    0,    0,    0,    0,  -42,    0,   15,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  271,    0,
    0, -255,   -6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -199,  -71,
    0,    0,    0,    0,   17,    0,  -28,    5,    0,    0,
    0,    0,    0,    0,    0,    0, -240,    0,    0,    0,
    0,    0,    0,    0,    0,   11,    0,    0,    0,    0,
    0,    0,    0, -130,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  274,   -9,  269,  -22,  -48,  244,  -46,  285,    0,    0,
    0,    0,  259,    0,    0,  263,  -50,    0,   93,  302,
  225,  154,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 417
static const YYINT yytable[] = {                         63,
    5,    5,   63,   12,   80,   63,  105,   81,   86,   13,
   22,   63,   23,   90,   14,   69,   70,   71,   51,  149,
   69,   70,   71,   51,   36,  106,  107,   98,   80,   72,
   73,  116,   63,   36,   90,   85,   87,   88,   19,   20,
   12,   92,   95,   79,   69,   70,   71,   51,   80,  150,
   16,   24,   99,   75,   63,   27,  134,   74,   75,  135,
  136,   28,   30,   79,   63,   32,  144,  143,  122,  115,
   59,   59,  151,  126,   34,  106,  107,  129,  130,  131,
  132,  133,   75,   22,   59,   25,   59,  106,  107,   59,
   59,   59,   59,   59,   59,   59,   59,   59,   59,   63,
  147,  154,   74,   74,   59,   21,   59,  102,  103,  104,
   63,   63,  164,  165,   41,   29,   74,   31,   74,   74,
   74,   74,   74,   74,   74,   74,   74,   74,   74,   74,
   74,   74,   74,   74,   71,   71,   74,   64,   74,   65,
   50,   43,  100,  101,  102,  103,  104,   43,   71,   43,
   71,  125,   71,   71,   71,   71,   71,   71,   71,   71,
   71,   71,   71,   71,   71,   71,   70,   70,   71,   44,
   71,   45,  100,  101,  102,  103,  104,   46,   48,   82,
   70,  148,   70,   84,   70,   70,   70,   70,   70,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   60,   60,
   70,   51,   70,  100,  101,  102,  103,  104,   91,   96,
  128,   97,   60,  114,   60,  119,  123,   60,   60,   60,
   60,   60,   60,   60,   60,   60,   60,   58,   58,  124,
  127,  145,   60,  107,   60,    3,    4,    5,    6,    7,
    8,   56,   56,   58,  152,  153,   58,   58,   58,   58,
   58,   58,   58,   58,  155,  158,  157,   56,    5,    5,
   56,   56,   56,   56,  159,  161,  162,  163,    5,    5,
   18,    5,    5,    5,   57,   57,    5,    5,    5,   26,
    5,    5,    5,    5,   49,   49,   46,   46,   45,   19,
   57,   78,   26,   57,   57,   57,   57,   77,   33,   83,
   49,   47,   46,   49,   49,   46,   51,   52,   49,   53,
   54,   55,   18,  121,   56,   57,   89,  166,    0,   58,
   59,   60,   51,   52,    0,   53,   54,   55,    0,    0,
   56,   57,  117,    0,    0,   58,   59,   60,   51,   52,
    0,   53,   54,   55,    0,    0,   56,   57,    0,    0,
    0,   58,   59,   60,    5,    5,    0,    5,    5,    5,
  118,    0,    5,    5,    0,  120,    0,    5,    5,    5,
  146,  100,  101,  102,  103,  104,  100,  101,  102,  103,
  104,  100,  101,  102,  103,  104,  108,  109,  110,  111,
  112,  113,  137,  138,  139,  140,  141,  142,    4,    5,
    6,    7,    8,    4,    5,    6,   35,    8,  100,  101,
  102,  103,  104,  110,  111,  112,  113,
};
static const YYINT yycheck[] = {                         50,
    0,    0,   53,  268,   53,   56,  270,   54,   59,  276,
  284,   62,  286,   62,  268,  265,  266,  267,  268,  278,
  265,  266,  267,  268,   34,  289,  290,   74,  284,  274,
  275,   82,   83,   43,   83,   58,  286,   60,  258,  304,
  305,   64,   65,  284,  265,  266,  267,  268,  304,  308,
  305,  267,   75,  303,  105,  278,  105,  302,  303,  106,
  107,  268,  306,  304,  115,  268,  115,  114,   91,  271,
  270,  271,  286,   96,  303,  289,  290,  100,  101,  102,
  103,  104,  303,  284,  284,  286,  286,  289,  290,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  298,  150,
  123,  150,  270,  271,  304,   13,  306,  299,  300,  301,
  161,  162,  161,  162,  305,   23,  284,   25,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  270,  271,  304,  303,  306,  305,
   48,  284,  297,  298,  299,  300,  301,  278,  284,  280,
  286,  306,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  270,  271,  304,  304,
  306,  268,  297,  298,  299,  300,  301,  306,  276,  303,
  284,  306,  286,  286,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  270,  271,
  304,  268,  306,  297,  298,  299,  300,  301,  288,  305,
  304,  287,  284,  272,  286,  286,  284,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  270,  271,  304,
  268,  304,  304,  290,  306,  259,  260,  261,  262,  263,
  264,  270,  271,  286,  278,  271,  289,  290,  291,  292,
  293,  294,  295,  296,  279,  267,  278,  286,  258,  258,
  289,  290,  291,  292,  280,  285,  285,  278,  268,  269,
    0,  271,  272,  273,  270,  271,  276,  277,  278,  268,
  278,  281,  282,  283,  270,  271,  270,  271,  278,  304,
  286,  304,   19,  289,  290,  291,  292,  304,   30,   56,
  286,   43,  286,  289,  290,  289,  268,  269,   46,  271,
  272,  273,   11,   89,  276,  277,  278,  164,   -1,  281,
  282,  283,  268,  269,   -1,  271,  272,  273,   -1,   -1,
  276,  277,  278,   -1,   -1,  281,  282,  283,  268,  269,
   -1,  271,  272,  273,   -1,   -1,  276,  277,   -1,   -1,
   -1,  281,  282,  283,  268,  269,   -1,  271,  272,  273,
  286,   -1,  276,  277,   -1,  286,   -1,  281,  282,  283,
  286,  297,  298,  299,  300,  301,  297,  298,  299,  300,
  301,  297,  298,  299,  300,  301,  291,  292,  293,  294,
  295,  296,  108,  109,  110,  111,  112,  113,  260,  261,
  262,  263,  264,  260,  261,  262,  263,  264,  297,  298,
  299,  300,  301,  293,  294,  295,  296,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 338
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ERROR","DEF","ESTRUCT","ENTERO",
"REAL","DREAL","SIN","CAR","CARACTER","CADENA","NUM","ID","IF","THEN","DO",
"WHILE","SEGUN","TRUE","FALSE","INICIO","TERMINAR","END","CASO","PRED","WRITE",
"READ","DEV","COMA","DOSP","PYC","PUNTO","IGUAL","OR","AND","IDENTICO",
"DIFERENTE","MENORQUE","MENORIGUAL","MAYORIGUAL","MAYORQUE","MAS","MENOS","MUL",
"DIV","MODULO","NOT","LPAR","RPAR","LCOR","RCOR","SITEMP","SINO",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"declaraciones : tipo lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"tipo_registro : ESTRUCT INICIO declaraciones END",
"tipo : base tipo_arreglo",
"base : ENTERO",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : LCOR NUM RCOR tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"funciones : DEF tipo ID LPAR argumentos RPAR INICIO declaraciones sentencias END funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"tipo_arg : base param_arr",
"param_arr : LCOR RCOR param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencias : sentencia",
"sentencia : IF e_bool THEN sentencia END",
"sentencia : IF e_bool THEN sentencia SINO sentencia END",
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
"e_bool : e_bool OR e_bool",
"e_bool : e_bool AND e_bool",
"e_bool : NOT e_bool",
"e_bool : relacional",
"e_bool : TRUE",
"e_bool : FALSE",
"relacional : relacional MENORQUE relacional",
"relacional : relacional MAYORQUE relacional",
"relacional : relacional MENORIGUAL relacional",
"relacional : relacional MAYORIGUAL relacional",
"relacional : relacional IDENTICO relacional",
"relacional : relacional DIFERENTE relacional",
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
"variable : ID variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"variable_comp : LPAR parametros RPAR",
"dato_est_sim : dato_est_sim PUNTO ID",
"dato_est_sim :",
"arreglo : LCOR expresion RCOR",
"arreglo : arreglo LCOR expresion RCOR",
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
#line 299 "parser.y"

void yyerror(char *msg){
	printf("%s, linea: %d, token: %s\n",msg, yylineno, yytext);
}
#line 566 "y.tab.c"

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
#line 193 "parser.y"
	{printf("=> Inicio: programa\n");
                  dir = 0;
                  codigo = init_code();
                  pDirecciones = crearPilaDir();
                  pSimbolos = init_sym_tab_stack();
                  pTipos = init_type_tab_stack();
                  init_type_tab(TGT);
                  TGS = init_sym_tab();
                  push_st(pSimbolos,TGS);
                  push_tt(pTipos,TGT);
                  tabCadenas = crearTablaCadenas();
                  }
break;
case 2:
#line 204 "parser.y"
	{/*imprimirCodigo(codigo);*/}
break;
case 3:
#line 206 "parser.y"
	{}
break;
case 4:
#line 207 "parser.y"
	{}
break;
case 5:
#line 208 "parser.y"
	{}
break;
case 6:
#line 210 "parser.y"
	{}
break;
case 7:
#line 212 "parser.y"
	{}
break;
case 8:
#line 214 "parser.y"
	{}
break;
case 9:
#line 215 "parser.y"
	{}
break;
case 10:
#line 216 "parser.y"
	{}
break;
case 11:
#line 217 "parser.y"
	{}
break;
case 12:
#line 218 "parser.y"
	{}
break;
case 13:
#line 220 "parser.y"
	{}
break;
case 14:
#line 220 "parser.y"
	{}
break;
case 15:
#line 222 "parser.y"
	{}
break;
case 16:
#line 222 "parser.y"
	{}
break;
case 17:
#line 224 "parser.y"
	{}
break;
case 18:
#line 224 "parser.y"
	{}
break;
case 19:
#line 226 "parser.y"
	{}
break;
case 20:
#line 226 "parser.y"
	{}
break;
case 21:
#line 228 "parser.y"
	{}
break;
case 22:
#line 228 "parser.y"
	{}
break;
case 23:
#line 230 "parser.y"
	{}
break;
case 24:
#line 232 "parser.y"
	{}
break;
case 25:
#line 234 "parser.y"
	{}
break;
case 26:
#line 234 "parser.y"
	{}
break;
case 27:
#line 236 "parser.y"
	{}
break;
case 28:
#line 236 "parser.y"
	{}
break;
case 29:
#line 238 "parser.y"
	{}
break;
case 30:
#line 239 "parser.y"
	{}
break;
case 31:
#line 240 "parser.y"
	{}
break;
case 32:
#line 241 "parser.y"
	{}
break;
case 33:
#line 242 "parser.y"
	{}
break;
case 34:
#line 243 "parser.y"
	{}
break;
case 35:
#line 244 "parser.y"
	{}
break;
case 36:
#line 245 "parser.y"
	{}
break;
case 37:
#line 246 "parser.y"
	{}
break;
case 38:
#line 247 "parser.y"
	{}
break;
case 39:
#line 248 "parser.y"
	{}
break;
case 40:
#line 249 "parser.y"
	{}
break;
case 41:
#line 251 "parser.y"
	{}
break;
case 42:
#line 253 "parser.y"
	{}
break;
case 43:
#line 253 "parser.y"
	{}
break;
case 44:
#line 255 "parser.y"
	{}
break;
case 45:
#line 255 "parser.y"
	{}
break;
case 46:
#line 257 "parser.y"
	{}
break;
case 47:
#line 258 "parser.y"
	{}
break;
case 48:
#line 259 "parser.y"
	{}
break;
case 49:
#line 260 "parser.y"
	{}
break;
case 50:
#line 261 "parser.y"
	{}
break;
case 51:
#line 262 "parser.y"
	{}
break;
case 52:
#line 264 "parser.y"
	{}
break;
case 53:
#line 265 "parser.y"
	{}
break;
case 54:
#line 266 "parser.y"
	{}
break;
case 55:
#line 267 "parser.y"
	{}
break;
case 56:
#line 268 "parser.y"
	{}
break;
case 57:
#line 269 "parser.y"
	{}
break;
case 58:
#line 270 "parser.y"
	{}
break;
case 59:
#line 272 "parser.y"
	{}
break;
case 60:
#line 273 "parser.y"
	{}
break;
case 61:
#line 274 "parser.y"
	{}
break;
case 62:
#line 275 "parser.y"
	{}
break;
case 63:
#line 276 "parser.y"
	{}
break;
case 64:
#line 277 "parser.y"
	{}
break;
case 65:
#line 278 "parser.y"
	{}
break;
case 66:
#line 279 "parser.y"
	{}
break;
case 67:
#line 280 "parser.y"
	{}
break;
case 68:
#line 281 "parser.y"
	{}
break;
case 69:
#line 284 "parser.y"
	{}
break;
case 70:
#line 286 "parser.y"
	{}
break;
case 71:
#line 286 "parser.y"
	{}
break;
case 72:
#line 286 "parser.y"
	{}
break;
case 73:
#line 288 "parser.y"
	{}
break;
case 74:
#line 288 "parser.y"
	{}
break;
case 75:
#line 290 "parser.y"
	{}
break;
case 76:
#line 291 "parser.y"
	{}
break;
case 77:
#line 293 "parser.y"
	{}
break;
case 78:
#line 293 "parser.y"
	{}
break;
case 79:
#line 295 "parser.y"
	{}
break;
case 80:
#line 296 "parser.y"
	{}
break;
#line 1099 "y.tab.c"
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
