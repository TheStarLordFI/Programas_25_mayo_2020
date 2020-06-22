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
DIR *structDir;
SYMTAB *TGS;
SYMTAB *TS1;
SYMTAB *tTempSimbol;
/*TGT: Tabla General de Tipos, TT1: Tabla Tipos 1*/
TYPTAB *TGT;
TYPTAB *TT1; 
TYPTAB *tTempTipos; 
CADTAB *tabCadenas;
SYM *simbol; 
ARG *argx; 
ARG *arg; 
ARG *arg2; 
TYP *newTipo; 
CODE* codigo; 
ARGS *ListaArg; 
INDEX *indiceGlobal, *indiceAux; 
LINDEX *prueba;
/*///////////////////////////Variables doc 2020-2DDS_usr1///////////////////////////////////////*/
int dir;
char *dir1, *dir2, *dirTemp; /*Dir temporales*/
int typeGBL;
int typeTemp;
int tam;
int baseGBL;
int funcType;
bool funcReturn;
char *L, *tmpLabel;
char *L1, *L2; /*L temporales*/
char IDGBL[32];
char *estTemp;/*nombre de la tabla de tipos*/
char *tmpEtq;
#line 65 "parser.y"
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
	    struct cadenas *cad;
	}cad;

	struct{
	  	struct list_index *nextlist;/*listIndex*/
	}listIndice_S; 
	
	struct{
		struct list_index *prueba;/*listIndex*/
	  	struct list_index *nextlist;/*listIndex*/
	}listIndice_C; 

	struct{
		struct list_index *prueba;/*listIndex*/
	}listIndice_P;

	struct{
	   	struct list_index *listTrue; /*En la DDS viene como truelist*/
	   	struct list_index *listFalse; /*En la DDS viene como falselist*/
	}eBool;

	struct{
	    int tipoRel; /*En la DDS viene como tipo */
	    char* dirRel;/*En la DDS viene como dir*/
	    struct list_index *listRelTrue;/*En la DDS viene como truelist*/
	    struct list_index *listRelFalse;/*En la DDS viene como falselist*/
  	}rel;
	
	struct{
    	int tipoExp;
		char *dirExp;
    }eExpr;
	
	struct{
    	int tipoVA;
    	int baseVA;
    	int tam;
    	char *idVar;
  	}var;
	
	struct{
    	struct args *listArgs;/*listParam*/
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
#line 163 "y.tab.c"

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
   26,    0,   27,   19,   28,   19,   19,   29,   30,   14,
   31,    1,    2,    2,    2,    2,    2,    3,    3,   20,
   20,   32,   33,   21,   21,   11,   11,   10,   10,   13,
   15,   16,   16,   34,    6,    6,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,   22,   35,   35,
   23,   23,   36,    7,   37,    7,    7,    7,    7,    7,
    8,    8,    8,    8,    8,    8,    8,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   17,   24,   24,
   24,   25,   25,   18,   18,   12,   12,    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    0,    5,    0,    0,    0,    6,
    0,    3,    1,    1,    1,    1,    1,    4,    0,    3,
    1,    0,    0,   13,    0,    1,    1,    3,    1,    2,
    2,    3,    0,    0,    3,    1,    5,    7,    5,    5,
    8,    4,    3,    2,    3,    2,    3,    5,    1,    0,
    3,    0,    0,    4,    0,    4,    2,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    1,    3,    3,    3,
    3,    3,    3,    1,    1,    1,    1,    2,    1,    1,
    3,    3,    0,    3,    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   13,   14,   15,   17,   16,    3,   11,
    5,    0,    8,    0,    0,    0,    0,    2,    0,   21,
    0,    0,   12,    0,    0,    9,    0,    0,    0,    0,
   22,    0,   20,    4,    0,    6,    0,   10,   18,    0,
    0,    0,    0,    0,   29,    0,    0,   31,    0,    0,
   30,    0,   28,    0,   32,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   36,    0,    0,    0,    0,
    0,   78,    0,   77,   76,   75,   59,   60,    0,    0,
    0,    0,    0,   74,    0,    0,    0,    0,   46,    0,
   44,    0,   23,    0,    0,    0,    0,    0,    0,    0,
    0,   57,    0,    0,    0,    0,    0,    0,    0,   53,
   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   47,   43,   45,    0,   35,    0,    0,   81,   84,    0,
   82,   73,    0,    0,   70,   71,   72,    0,    0,    0,
    0,    0,   61,   63,   64,   62,    0,    0,    0,   24,
   42,    0,   85,   37,    0,    0,   56,   40,   39,    0,
    0,    0,    0,   38,    0,    0,    0,    0,    0,   41,
    0,   51,   49,   48,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   23,   81,   66,   67,   82,   83,   97,   43,
   44,   98,   45,   11,   46,   48,   84,   71,   12,   21,
   18,  163,  167,   72,   73,    2,   14,   16,   19,   32,
   15,   37,  124,   94,  174,  139,  140,
};
static const YYINT yysindex[] = {                         0,
    0,  -24, -272,    0,    0,    0,    0,    0,    0,    0,
    0, -244,    0, -253, -287, -253,  119,    0,  -24,    0,
 -188, -239,    0, -179, -227,    0, -217,  -24, -252,  -24,
    0, -201,    0,    0, -287,    0, -219,    0,    0,  124,
    0, -241, -199, -223,    0, -171, -206,    0,  119, -165,
    0, -241,    0,  -24,    0,   35, -166, -232,   35, -232,
 -195,   35, -169, -255, -242,    0, -127, -111, -255, -255,
 -126,    0,  -86,    0,    0,    0,    0,    0, -232, -255,
   92, -240,   76,    0,  -89,  -60,  -90,  -70,    0,   55,
    0,   60,    0,   35, -255,   92,  -75,  -91, -157, -255,
  -53,    0,  -94, -255, -255, -255, -255, -255,   35,    0,
    0, -255, -255, -255, -255, -255, -255, -232,   35,  -88,
    0,    0,    0, -244,    0,   65, -255,    0,    0, -125,
    0,    0, -154, -154,    0,    0,    0, -271, -232, -232,
  101,  101,    0,    0,    0,    0, -214,  -47,  -38,    0,
    0,   92,    0,    0,   35,  -46,    0,    0,    0,  -37,
  -33,  -11,  -23,    0,  -27,  -21,  -16,   35,   35,    0,
  -37,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  265,    0,    0,   -2,    0,    0,    0,   -7,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,
    0,    0,    0,    0,   -2,    0,    0,    0,    0,    0,
 -259, -217,  -29,    0,    0,    0,    0,    0,    0,    0,
    0, -217,    0,   51,    0,    0, -168,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   67,    0,  -28,    0,
 -136,    0, -104,    0,    0,    0,    0,    0,    0,    0,
   -3,    0, -180,    0,    0,    0,    0,   67,    0,    0,
    0,    0,    0,    0,    0, -265,  -19,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  265,    0,    0,    0,    0,    0,    0,
    0,    0,  -72,  -43,    0,    0,    0,    0,    0,    0,
 -197,   10,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -222,    0,    0,    0, -203,    0,    0,    0,    0,
    0,    0,   16,    0,    0,    0,    0,    0,    0,    0,
 -109,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  278,  -20,  262,  -48,  -54,  236,  -52,  261,    0,    0,
    0,    0,  256,    0,    0,  257,  -56,    0,   50,  294,
  189,  143,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 397
static const YYINT yytable[] = {                         68,
    7,    7,   68,   13,   85,   68,  154,   86,   17,   74,
   75,   76,   57,   17,   20,   90,   92,   22,   89,   42,
   96,   99,   74,   75,   76,   57,  102,   29,   42,  109,
  120,  103,   74,   75,   76,   57,  155,   68,   89,  125,
   31,   77,   78,   91,   27,   17,  126,   80,  110,  111,
   33,  130,   68,   35,  138,  133,  134,  135,  136,  137,
   80,   88,   68,   47,  148,  147,   54,   54,   26,   79,
   80,  158,   65,   65,  110,  111,   38,   34,  152,   36,
   50,   88,   54,   40,   49,   54,  156,  157,   65,   58,
   58,   65,   65,   65,   65,   27,   51,   28,   68,   52,
  161,   83,   83,   56,   27,   58,   30,   87,   58,   58,
   54,   68,   68,  171,  172,   83,   89,   83,   83,   83,
   83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
   83,   83,   83,   80,   80,   83,   69,   83,   70,  104,
  105,  106,  107,  108,  106,  107,  108,   80,  129,   80,
   93,   80,   80,   80,   80,   80,   80,   80,   80,   80,
   80,   80,   80,   80,   80,   79,   79,   80,   50,   80,
   50,  104,  105,  106,  107,  108,   95,   57,  100,   79,
  153,   79,  118,   79,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   68,   68,   79,
  101,   79,  104,  105,  106,  107,  108,  121,  127,  132,
  119,   68,  128,   68,  131,  149,   68,   68,   68,   68,
   68,   68,   68,   68,   68,   68,   69,   69,  110,  111,
  159,   68,  160,   68,    3,    4,    5,    6,    7,    8,
   69,  162,   69,  111,  164,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   69,  165,  166,  168,    7,    7,
   69,  170,   69,  169,   25,   19,   67,   67,    7,    7,
    7,    7,    7,    7,   26,   87,    7,    7,    7,   66,
   66,    7,   67,    7,   86,   67,   67,   67,   67,   67,
   67,   67,   67,   52,   25,   66,   39,   88,   66,   66,
   66,   66,   57,   58,   53,   59,   60,   61,   55,   24,
   62,   63,  150,  173,    0,   64,    0,   65,    7,    7,
    0,    7,    7,    7,    0,    0,    7,    7,    0,    0,
    0,    7,    0,    7,   34,   34,    0,   34,   34,   34,
  122,    0,   34,   34,    0,  123,    0,   34,    0,   34,
  151,  104,  105,  106,  107,  108,  104,  105,  106,  107,
  108,  104,  105,  106,  107,  108,  112,  113,  114,  115,
  116,  117,  141,  142,  143,  144,  145,  146,    4,    5,
    6,    7,    8,    4,    5,    6,   41,    8,  104,  105,
  106,  107,  108,  114,  115,  116,  117,
};
static const YYINT yycheck[] = {                         56,
    0,    0,   59,  276,   59,   62,  278,   60,  268,  265,
  266,  267,  268,  258,  268,   64,   65,  305,  284,   40,
   69,   70,  265,  266,  267,  268,   79,  267,   49,  270,
   87,   80,  265,  266,  267,  268,  308,   94,  304,   94,
  268,  274,  275,  286,  304,  305,   95,  303,  289,  290,
  268,  100,  109,  306,  109,  104,  105,  106,  107,  108,
  303,  284,  119,  305,  119,  118,  270,  271,   19,  302,
  303,  286,  270,  271,  289,  290,  278,   28,  127,   30,
  304,  304,  286,  303,  284,  289,  139,  140,  286,  270,
  271,  289,  290,  291,  292,  284,  268,  286,  155,  306,
  155,  270,  271,   54,  284,  286,  286,  303,  289,  290,
  276,  168,  169,  168,  169,  284,  286,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  270,  271,  304,  303,  306,  305,  297,
  298,  299,  300,  301,  299,  300,  301,  284,  306,  286,
  278,  288,  289,  290,  291,  292,  293,  294,  295,  296,
  297,  298,  299,  300,  301,  270,  271,  304,  278,  306,
  280,  297,  298,  299,  300,  301,  288,  268,  305,  284,
  306,  286,  272,  288,  289,  290,  291,  292,  293,  294,
  295,  296,  297,  298,  299,  300,  301,  270,  271,  304,
  287,  306,  297,  298,  299,  300,  301,  278,  284,  304,
  271,  284,  304,  286,  268,  304,  289,  290,  291,  292,
  293,  294,  295,  296,  297,  298,  270,  271,  289,  290,
  278,  304,  271,  306,  259,  260,  261,  262,  263,  264,
  284,  279,  286,  290,  278,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  267,  280,  285,  258,  258,
  304,  278,  306,  285,    0,  268,  270,  271,  268,  269,
  278,  271,  272,  273,  304,  304,  276,  277,  278,  270,
  271,  281,  286,  283,  304,  289,  290,  291,  292,  293,
  294,  295,  296,  278,   17,  286,   35,   62,  289,  290,
  291,  292,  268,  269,   49,  271,  272,  273,   52,   16,
  276,  277,  124,  171,   -1,  281,   -1,  283,  268,  269,
   -1,  271,  272,  273,   -1,   -1,  276,  277,   -1,   -1,
   -1,  281,   -1,  283,  268,  269,   -1,  271,  272,  273,
  286,   -1,  276,  277,   -1,  286,   -1,  281,   -1,  283,
  286,  297,  298,  299,  300,  301,  297,  298,  299,  300,
  301,  297,  298,  299,  300,  301,  291,  292,  293,  294,
  295,  296,  112,  113,  114,  115,  116,  117,  260,  261,
  262,  263,  264,  260,  261,  262,  263,  264,  297,  298,
  299,  300,  301,  293,  294,  295,  296,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 348
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"$$2 :",
"declaraciones : tipo $$2 lista_var PYC declaraciones",
"$$3 :",
"declaraciones : tipo_registro $$3 lista_var PYC declaraciones",
"declaraciones :",
"$$4 :",
"$$5 :",
"tipo_registro : ESTRUCT INICIO $$4 declaraciones $$5 END",
"$$6 :",
"tipo : base $$6 tipo_arreglo",
"base : ENTERO",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : LCOR NUM RCOR tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"$$7 :",
"$$8 :",
"funciones : DEF tipo ID $$7 LPAR argumentos RPAR INICIO declaraciones sentencias END $$8 funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"tipo_arg : base param_arr",
"param_arr : LCOR RCOR param_arr",
"param_arr :",
"$$9 :",
"sentencias : sentencias $$9 sentencia",
"sentencias : sentencia",
"sentencia : IF e_bool THEN sentencia END",
"sentencia : IF e_bool THEN sentencia SINO sentencia END",
"sentencia : WHILE e_bool DO sentencia END",
"sentencia : DO sentencia WHILE e_bool PYC",
"sentencia : SEGUN LPAR variable RPAR DO casos predeterminado END",
"sentencia : variable IGUAL expresion PYC",
"sentencia : WRITE expresion PYC",
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
#line 499 "parser.y"

void yyerror(char *msg){
	printf("%s, linea: %d, token: %s\n",msg, yylineno, yytext);
}
#line 587 "y.tab.c"

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
#line 198 "parser.y"
	{printf("==========================P r o g r a m a==========================\n");
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
#line 209 "parser.y"
	{/*imprimirCodigo(codigo);*/}
break;
case 3:
#line 211 "parser.y"
	{typeGBL  = yystack.l_mark[0].tipo.valorTipo;}
break;
case 5:
#line 212 "parser.y"
	{typeGBL  = yystack.l_mark[0].tipo.valorTipo;}
break;
case 7:
#line 213 "parser.y"
	{}
break;
case 8:
#line 215 "parser.y"
	{TS1 = init_sym_tab();
							   	  init_type_tab(TT1);
								  structDir = crearDir();
								  structDir->info = dir;
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);}
break;
case 9:
#line 222 "parser.y"
	{
									  TT1 = pop_tt(pTipos);
								      TS1 = pop_st(pSimbolos);
									  structDir = popPDir(pDirecciones);
									  dir = structDir->info;
									  TYP* newTYP= init_type();
									  newTYP = set_typ(newTYP,"reg",0,getTopType(pTipos));
									  typeTemp = append_type(getTopType(pTipos), newTYP);}
break;
case 10:
#line 229 "parser.y"
	{
										  yyval.tipo.valorTipo=typeTemp;
									  }
break;
case 11:
#line 233 "parser.y"
	{baseGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 12:
#line 233 "parser.y"
	{yyval.tipo.valorTipo=yystack.l_mark[0].tipo.valorTipo;}
break;
case 13:
#line 235 "parser.y"
	{yyval.tipo.valorTipo=0;}
break;
case 14:
#line 236 "parser.y"
	{yyval.tipo.valorTipo=1;}
break;
case 15:
#line 237 "parser.y"
	{yyval.tipo.valorTipo=4;}
break;
case 16:
#line 238 "parser.y"
	{yyval.tipo.valorTipo=2;}
break;
case 17:
#line 239 "parser.y"
	{yyval.tipo.valorTipo=3;}
break;
case 18:
#line 241 "parser.y"
	{
					if(yystack.l_mark[-2].num.tipe==0){
                        int n = atoi(yystack.l_mark[-2].num.valor);
                                 
                        if(n>0){
                            TYP *newTYP = init_type();
                            newTYP = set_typ(newTYP,"array",yystack.l_mark[0].tipo.valorTipo,getTopType(pTipos));
                            yyval.tipo.valorTipo = append_type(getTopType(pTipos), newTYP);
							
                        }
                        else{
                            printf("El indice tiene que ser entero y mayor que cero///////////////////////////////////");
                        }
                    }
                    else{
                        printf("El indice tiene que ser entero y mayor que cero///////////////////////////////////");
                    }
				}
break;
case 19:
#line 259 "parser.y"
	{}
break;
case 20:
#line 261 "parser.y"
	{}
break;
case 21:
#line 261 "parser.y"
	{}
break;
case 22:
#line 263 "parser.y"
	{if(search_id_symbol(TGS,yystack.l_mark[0].id.lexval) == -1){
									simbol = init_sym();
									simbol = set_sym(simbol,yystack.l_mark[0].id.lexval,-1,yystack.l_mark[-1].tipo.valorTipo,"func",NULL,TGS,TGT);
									append_sym(TGS,simbol);
									structDir = crearDir();
									structDir->info = dir;
									pushPDir(structDir,pDirecciones);
									funcType = yystack.l_mark[-1].tipo.valorTipo;
									funcReturn = false;
									dir = 0;
									TS1 = init_sym_tab();
							   	  	init_type_tab(TT1);
									push_tt(pTipos,TT1);
								 	push_st(pSimbolos, TS1);
									append_new_quad(codigo,"label","-","-",yystack.l_mark[0].id.lexval);
								}

					}
break;
case 23:
#line 280 "parser.y"
	{
						tmpEtq = create_label();
						backpatch(codigo,yystack.l_mark[-1].listIndice_S.nextlist,tmpEtq);
						TT1= pop_tt(pTipos);
                        TS1= pop_st(pSimbolos);
						structDir = popPDir(pDirecciones);
						dir = structDir->info;
						simbol = init_sym();
						simbol = search_SYM(pSimbolos->top,yystack.l_mark[-8].id.lexval);
						simbol->args = yystack.l_mark[-5].eListARGS.listArgs;

						if(yystack.l_mark[-9].tipo.valorTipo != 3 && funcReturn == false){
							printf("Error la funcion no tiene valor de retorno\n");
						}
					}
break;
case 25:
#line 294 "parser.y"
	{}
break;
case 26:
#line 296 "parser.y"
	{yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;}
break;
case 27:
#line 297 "parser.y"
	{yyval.eListARGS.listArgs=NULL;}
break;
case 28:
#line 299 "parser.y"
	{
					yyval.eListARGS.listArgs = yystack.l_mark[-2].eListARGS.listArgs;
					argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
					append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 29:
#line 304 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 30:
#line 310 "parser.y"
	{
					if( search_id_symbol(pSimbolos->top,yystack.l_mark[0].id.lexval) == -1){
                          simbol = init_sym();
                          simbol= set_sym(simbol, yystack.l_mark[0].id.lexval, dir, typeGBL, "var", NULL,pSimbolos->top, getTopType(pTipos));
                          append_sym(pSimbolos->top,simbol);
                          dir = dir + getTam(getTopType(pTipos), typeGBL);
                    }
                    else
                      printf("El identificador ya fue declarado\n");
                    yyval.tipo.valorTipo = yystack.l_mark[-1].tipo.valorTipo;
				}
break;
case 31:
#line 322 "parser.y"
	{baseGBL = yystack.l_mark[-1].tipo.valorTipo;}
break;
case 32:
#line 324 "parser.y"
	{
					TYP *tp = init_type();
                    tp = set_typ(tp,"array",yystack.l_mark[0].tipo.valorTipo,getTopType(pTipos));
                    yyval.tipo.valorTipo = append_type(getTopType(pTipos), tp);
				}
break;
case 33:
#line 328 "parser.y"
	{yyval.tipo.valorTipo=baseGBL;}
break;
case 34:
#line 330 "parser.y"
	{
					tmpEtq=create_label();
                    backpatch(codigo,yystack.l_mark[0].listIndice_S.nextlist,tmpEtq);
                    append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 35:
#line 334 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 36:
#line 335 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 37:
#line 337 "parser.y"
	{tmpLabel=create_label();
												backpatch(codigo,yystack.l_mark[-3].eBool.listTrue,tmpLabel);
												append_new_quad(codigo,"label","-","-",tmpLabel);
												yyval.listIndice_S.nextlist=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[-1].listIndice_S.nextlist);
											    }
break;
case 38:
#line 342 "parser.y"
	{
															tmpLabel=create_label();
															backpatch(codigo,yystack.l_mark[-5].eBool.listTrue,tmpLabel);
															append_new_quad(codigo,"label","-","-",tmpLabel);
															tmpLabel=create_label();
															backpatch(codigo,yystack.l_mark[-5].eBool.listFalse,tmpLabel);
															append_new_quad(codigo,"label","-","-",tmpLabel);
															yyval.listIndice_S.nextlist=combinar(yystack.l_mark[-3].listIndice_S.nextlist,yystack.l_mark[-1].listIndice_S.nextlist);
															}
break;
case 39:
#line 351 "parser.y"
	{
													L1=create_label();
													L2=create_label();
													backpatch(codigo,yystack.l_mark[-1].listIndice_S.nextlist,L1);
													backpatch(codigo,yystack.l_mark[-3].eBool.listTrue,L2);
													yyval.listIndice_S.nextlist=yystack.l_mark[-3].eBool.listFalse;
													append_new_quad(codigo,"label","-","-",L1);
													append_new_quad(codigo,"label","-","-",L2);
													char *L_nextList = create_label();
													backpatch(codigo,yystack.l_mark[-1].listIndice_S.nextlist,L_nextList);
													append_new_quad(codigo,"goto","-","-",L_nextList);
												}
break;
case 40:
#line 364 "parser.y"
	{tmpLabel=create_label();
												   backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpLabel);
												   yyval.listIndice_S.nextlist=yystack.l_mark[-1].eBool.listFalse;
													}
break;
case 41:
#line 368 "parser.y"
	{
																	L1=create_label();
																	prueba = combinar(yystack.l_mark[-2].listIndice_C.prueba, yystack.l_mark[-1].listIndice_P.prueba);
																	backpatch(codigo,yystack.l_mark[-2].listIndice_C.nextlist,L1);
																	}
break;
case 42:
#line 373 "parser.y"
	{
										if(search_id_symbol(getTopSym(pSimbolos),yystack.l_mark[-3].var.idVar) != -1 || search_id_symbol(TGS,yystack.l_mark[-3].var.idVar) != -1 ){
											simbol = init_sym();
											simbol=search_SYM(getTopSym(pSimbolos),yystack.l_mark[-3].var.idVar);
											if(simbol==NULL){
												simbol=search_SYM(TGS,yystack.l_mark[-3].var.idVar);
											}
											dir1=reducir(yystack.l_mark[-1].eExpr.dirExp,yystack.l_mark[-1].eExpr.tipoExp,simbol->tipo,codigo);
											char *tmp=(char*)malloc(sizeof(char));
											char *tmp2=(char*)malloc(sizeof(char));
											sprintf(tmp, "%i", simbol->dir);
											strcpy(tmp2,yystack.l_mark[-3].var.idVar);
											strcat(tmp2,"+");
											strcat(tmp2,tmp);
											append_new_quad(codigo,"=",dir1,"-",tmp2);
									}else{
											printf("Error (el idntificador  no se ha declarado)\n");
										}
										yyval.listIndice_S.nextlist=NULL;
									}
break;
case 43:
#line 393 "parser.y"
	{}
break;
case 44:
#line 394 "parser.y"
	{}
break;
case 45:
#line 395 "parser.y"
	{}
break;
case 46:
#line 396 "parser.y"
	{}
break;
case 47:
#line 397 "parser.y"
	{}
break;
case 48:
#line 400 "parser.y"
	{}
break;
case 49:
#line 402 "parser.y"
	{}
break;
case 50:
#line 402 "parser.y"
	{}
break;
case 51:
#line 404 "parser.y"
	{}
break;
case 52:
#line 404 "parser.y"
	{}
break;
case 53:
#line 406 "parser.y"
	{
					tmpEtq = create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listFalse,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 54:
#line 410 "parser.y"
	{
					yyval.eBool.listTrue=combinar(yystack.l_mark[-3].eBool.listTrue,yystack.l_mark[0].eBool.listTrue);
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listFalse;
				}
break;
case 55:
#line 414 "parser.y"
	{
					tmpEtq=create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 56:
#line 419 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listTrue;
					yyval.eBool.listFalse=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[0].eBool.listFalse);}
break;
case 57:
#line 422 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listFalse;
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listTrue;}
break;
case 58:
#line 425 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].rel.listRelTrue;
					yyval.eBool.listFalse=yystack.l_mark[0].rel.listRelFalse;}
break;
case 59:
#line 428 "parser.y"
	{
					indiceGlobal = init_index();
					yyval.eBool.listFalse=init_list_index(NULL); 
					yyval.eBool.listTrue=init_list_index(NULL);
					append_index(yyval.eBool.listTrue, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"goto","-","-",tmp);}
break;
case 60:
#line 436 "parser.y"
	{
					indiceGlobal = init_index();
					yyval.eBool.listFalse=init_list_index(NULL); 
					yyval.eBool.listTrue=init_list_index(NULL);
					append_index(yyval.eBool.listFalse, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"goto","-","-",tmp);
				}
break;
case 61:
#line 446 "parser.y"
	{
					yyval.rel.listRelTrue = init_list_index(NULL);
					yyval.rel.listRelFalse = init_list_index(NULL);
					indiceGlobal = init_index();

					indiceAux = init_index();

					append_index(yyval.rel.listRelTrue, indiceGlobal);
					append_index(yyval.rel.listRelFalse, indiceAux);
					yyval.rel.tipoRel = max(yystack.l_mark[-2].rel.tipoRel, yystack.l_mark[0].rel.tipoRel);
					dir1 = ampliar(yystack.l_mark[-2].rel.dirRel,yystack.l_mark[-2].rel.tipoRel,yyval.rel.tipoRel, codigo);
					dir2 = ampliar(yystack.l_mark[0].rel.dirRel,yystack.l_mark[0].rel.tipoRel,yyval.rel.tipoRel, codigo);
					char *tmpIndGlobal=(char*)malloc(sizeof(char));
					char *tmpIndAux=(char*)malloc(sizeof(char));
					sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
					sprintf(tmpIndAux, "%i", indiceAux->indice);
					append_new_quad(codigo,"<", dir1, dir2, tmpIndGlobal);
					append_new_quad(codigo,"goto", "-", "-", tmpIndAux);
				}
break;
case 62:
#line 465 "parser.y"
	{}
break;
case 63:
#line 466 "parser.y"
	{}
break;
case 64:
#line 467 "parser.y"
	{}
break;
case 65:
#line 468 "parser.y"
	{}
break;
case 66:
#line 469 "parser.y"
	{}
break;
case 67:
#line 470 "parser.y"
	{}
break;
case 68:
#line 472 "parser.y"
	{}
break;
case 69:
#line 473 "parser.y"
	{}
break;
case 70:
#line 474 "parser.y"
	{}
break;
case 71:
#line 475 "parser.y"
	{}
break;
case 72:
#line 476 "parser.y"
	{}
break;
case 73:
#line 477 "parser.y"
	{}
break;
case 74:
#line 478 "parser.y"
	{}
break;
case 75:
#line 479 "parser.y"
	{}
break;
case 76:
#line 480 "parser.y"
	{}
break;
case 77:
#line 481 "parser.y"
	{}
break;
case 78:
#line 484 "parser.y"
	{}
break;
case 79:
#line 486 "parser.y"
	{}
break;
case 80:
#line 486 "parser.y"
	{}
break;
case 81:
#line 486 "parser.y"
	{}
break;
case 82:
#line 488 "parser.y"
	{}
break;
case 83:
#line 488 "parser.y"
	{}
break;
case 84:
#line 490 "parser.y"
	{}
break;
case 85:
#line 491 "parser.y"
	{}
break;
case 86:
#line 493 "parser.y"
	{}
break;
case 87:
#line 493 "parser.y"
	{}
break;
case 88:
#line 495 "parser.y"
	{}
break;
case 89:
#line 496 "parser.y"
	{}
break;
#line 1333 "y.tab.c"
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
