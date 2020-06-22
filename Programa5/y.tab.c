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

/*///////////////////////////Variables doc 2020-2DDS_usr1///////////////////////////////////////*/
int dir;
int dir1, dir2, dirTemp; /*Dir temporales*/
int typeGBL;
int tam;
int baseGBL;
char *L;
char *L1, *L2; /*L temporales*/
char IDGBL[32];
char *estTemp;/*nombre de la tabla de tipos*/
#line 61 "parser.y"
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
	    struct CAD *cad;
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
#line 159 "y.tab.c"

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
   20,   21,   21,   11,   11,   10,   10,   13,   15,   16,
   16,    6,    6,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,   22,   32,   32,   23,   23,
    7,    7,    7,    7,    7,    7,    8,    8,    8,    8,
    8,    8,    8,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,   17,   24,   24,   24,   25,   25,   18,
   18,   12,   12,    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    0,    5,    0,    0,    0,    6,
    0,    3,    1,    1,    1,    1,    1,    4,    0,    3,
    1,   11,    0,    1,    1,    3,    1,    2,    2,    3,
    0,    2,    1,    5,    7,    5,    5,    8,    4,    3,
    3,    2,    3,    2,    3,    5,    1,    0,    3,    0,
    3,    3,    2,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    1,    3,    3,    3,    3,    3,    3,    1,
    1,    1,    1,    2,    1,    1,    3,    3,    0,    3,
    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   13,   14,   15,   17,   16,    3,   11,
    5,    0,    8,    0,    0,    0,    0,    2,    0,   21,
    0,    0,   12,    0,    0,    9,    0,    0,    0,    0,
    0,    0,   20,    4,    0,    6,    0,   10,   18,    0,
    0,    0,    0,   27,    0,    0,   29,    0,    0,   28,
    0,   26,    0,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   33,    0,    0,    0,    0,
    0,   74,    0,   73,   72,   71,   55,   56,    0,    0,
    0,    0,    0,   70,    0,    0,    0,    0,   44,    0,
    0,   42,    0,    0,   32,    0,    0,    0,    0,    0,
    0,    0,   53,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,   40,   41,   43,   22,    0,    0,   77,   80,
    0,   78,   69,    0,    0,   66,   67,   68,    0,    0,
   52,    0,    0,   57,   59,   60,   58,    0,    0,    0,
   39,    0,   81,   34,    0,   37,   36,    0,    0,    0,
    0,   35,    0,    0,    0,    0,    0,   38,    0,   49,
   47,   46,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   23,   81,   66,   67,   82,   83,   98,   42,
   43,   99,   44,   11,   45,   47,   84,   71,   12,   21,
   18,  161,  165,   72,   73,    2,   14,   16,   19,   32,
   15,  172,
};
static const YYINT yysindex[] = {                         0,
    0,  -23, -266,    0,    0,    0,    0,    0,    0,    0,
    0, -243,    0, -234, -280, -234,  139,    0,  -23,    0,
 -273, -228,    0, -178, -216,    0, -212,  -23, -196,  -23,
 -237, -215,    0,    0, -280,    0,  144,    0,    0,    0,
 -190, -132, -134,    0,  -96, -128,    0,  139,  -97,    0,
 -190,    0,  -23,    0,   71, -187, -244,   71, -244, -123,
   71, -102, -220,  -66, -249,    0,   39,  -79, -220, -220,
  -95,    0,  -75,    0,    0,    0,    0,    0, -244, -220,
  112, -263,   96,    0,  -58, -201,  -66,   55,    0,   75,
  -70,    0,   80, -243,    0, -220,  112,  -67,  -74, -156,
 -220,  -37,    0,  -93, -220, -220, -220, -220, -220,   71,
 -244, -244, -220, -220, -220, -220, -220, -220, -244,   71,
  -72,    0,    0,    0,    0,    0,   85, -220,    0,    0,
 -124,    0,    0, -153, -153,    0,    0,    0, -258,  -56,
    0,  121,  121,    0,    0,    0,    0, -213,  -33,  -25,
    0,  112,    0,    0,   71,    0,    0,  -24,  -22,  -10,
  -15,    0,  -19,  -18,   -7,   71,   71,    0,  -24,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  268,    0,    0,   12,    0,    0,    0,    3,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,
    0,    0,    0,    0,   12,    0,    0,    0,    0, -264,
 -216,  -14,    0,    0,    0,    0,    0,    0,    0,    0,
 -216,    0,   87,    0,    0, -167,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -12,    0,
 -135,    0, -103,    0,    0,    0,    0,    0,    0,    0,
  -42,    0,   15,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  268,    0,    0, -255,  -11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -199,  -71,    0,    0,    0,    0,   17,
    0,  -28,    5,    0,    0,    0,    0,    0,    0,    0,
    0, -240,    0,    0,    0,    0,    0,    0,    0,    0,
   11,    0,    0,    0,    0,    0,    0,    0, -140,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
  281,   14,  264,  -27,  -53,  239,  -51,  280,    0,    0,
    0,    0,  254,    0,    0,  258,  -55,    0,   56,  297,
  220,  149,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 417
static const YYINT yytable[] = {                         68,
    7,    7,   68,   17,   85,   68,  110,   86,   91,   13,
   27,   68,   28,   95,   17,   74,   75,   76,   56,  154,
   74,   75,   76,   56,   22,  111,  112,  103,   85,   77,
   78,  121,   68,   20,   95,   90,   92,   93,   29,   25,
   17,   97,  100,   84,   74,   75,   76,   56,   85,  155,
   41,   31,  104,   80,   68,   33,  139,   79,   80,  140,
  141,   41,   38,   84,   68,   37,  149,  148,  127,  120,
   64,   64,  156,  131,   26,  111,  112,  134,  135,  136,
  137,  138,   80,   34,   64,   36,   64,  111,  112,   64,
   64,   64,   64,   64,   64,   64,   64,   64,   64,   68,
  152,  159,   79,   79,   64,   27,   64,   30,   55,   35,
   68,   68,  169,  170,   46,   69,   79,   70,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   76,   76,   79,   48,   79,   48,
  105,  106,  107,  108,  109,  107,  108,  109,   76,  130,
   76,   48,   76,   76,   76,   76,   76,   76,   76,   76,
   76,   76,   76,   76,   76,   76,   75,   75,   76,   49,
   76,   50,  105,  106,  107,  108,  109,   51,   53,   87,
   75,  153,   75,   89,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   75,   65,   65,
   75,   56,   75,  105,  106,  107,  108,  109,   96,  101,
  133,  102,   65,  119,   65,  124,  128,   65,   65,   65,
   65,   65,   65,   65,   65,   65,   65,   63,   63,  129,
  132,  150,   65,  112,   65,    3,    4,    5,    6,    7,
    8,   61,   61,   63,  157,  158,   63,   63,   63,   63,
   63,   63,   63,   63,  160,  162,  163,   61,    7,    7,
   61,   61,   61,   61,  164,  166,  167,   23,    7,    7,
  168,    7,    7,    7,   62,   62,    7,    7,    7,   19,
    7,    7,    7,    7,   54,   54,   51,   51,   50,   24,
   62,   83,   82,   62,   62,   62,   62,   25,   39,   88,
   54,   52,   51,   54,   54,   51,   56,   57,   54,   58,
   59,   60,   24,  126,   61,   62,   94,  171,    0,   63,
   64,   65,   56,   57,    0,   58,   59,   60,    0,    0,
   61,   62,  122,    0,    0,   63,   64,   65,   56,   57,
    0,   58,   59,   60,    0,    0,   61,   62,    0,    0,
    0,   63,   64,   65,    7,    7,    0,    7,    7,    7,
  123,    0,    7,    7,    0,  125,    0,    7,    7,    7,
  151,  105,  106,  107,  108,  109,  105,  106,  107,  108,
  109,  105,  106,  107,  108,  109,  113,  114,  115,  116,
  117,  118,  142,  143,  144,  145,  146,  147,    4,    5,
    6,    7,    8,    4,    5,    6,   40,    8,  105,  106,
  107,  108,  109,  115,  116,  117,  118,
};
static const YYINT yycheck[] = {                         55,
    0,    0,   58,  268,   58,   61,  270,   59,   64,  276,
  284,   67,  286,   67,  258,  265,  266,  267,  268,  278,
  265,  266,  267,  268,  305,  289,  290,   79,  284,  274,
  275,   87,   88,  268,   88,   63,  286,   65,  267,  304,
  305,   69,   70,  284,  265,  266,  267,  268,  304,  308,
   37,  268,   80,  303,  110,  268,  110,  302,  303,  111,
  112,   48,  278,  304,  120,  303,  120,  119,   96,  271,
  270,  271,  286,  101,   19,  289,  290,  105,  106,  107,
  108,  109,  303,   28,  284,   30,  286,  289,  290,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  298,  155,
  128,  155,  270,  271,  304,  284,  306,  286,   53,  306,
  166,  167,  166,  167,  305,  303,  284,  305,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  270,  271,  304,  278,  306,  280,
  297,  298,  299,  300,  301,  299,  300,  301,  284,  306,
  286,  284,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  270,  271,  304,  304,
  306,  268,  297,  298,  299,  300,  301,  306,  276,  303,
  284,  306,  286,  286,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  270,  271,
  304,  268,  306,  297,  298,  299,  300,  301,  288,  305,
  304,  287,  284,  272,  286,  286,  284,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  270,  271,  304,
  268,  304,  304,  290,  306,  259,  260,  261,  262,  263,
  264,  270,  271,  286,  278,  271,  289,  290,  291,  292,
  293,  294,  295,  296,  279,  278,  267,  286,  258,  258,
  289,  290,  291,  292,  280,  285,  285,    0,  268,  269,
  278,  271,  272,  273,  270,  271,  276,  277,  278,  268,
  278,  281,  282,  283,  270,  271,  270,  271,  278,  304,
  286,  304,  304,  289,  290,  291,  292,   17,   35,   61,
  286,   48,  286,  289,  290,  289,  268,  269,   51,  271,
  272,  273,   16,   94,  276,  277,  278,  169,   -1,  281,
  282,  283,  268,  269,   -1,  271,  272,  273,   -1,   -1,
  276,  277,  278,   -1,   -1,  281,  282,  283,  268,  269,
   -1,  271,  272,  273,   -1,   -1,  276,  277,   -1,   -1,
   -1,  281,  282,  283,  268,  269,   -1,  271,  272,  273,
  286,   -1,  276,  277,   -1,  286,   -1,  281,  282,  283,
  286,  297,  298,  299,  300,  301,  297,  298,  299,  300,
  301,  297,  298,  299,  300,  301,  291,  292,  293,  294,
  295,  296,  113,  114,  115,  116,  117,  118,  260,  261,
  262,  263,  264,  260,  261,  262,  263,  264,  297,  298,
  299,  300,  301,  293,  294,  295,  296,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 343
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
#line 355 "parser.y"

void yyerror(char *msg){
	printf("%s, linea: %d, token: %s\n",msg, yylineno, yytext);
}
#line 582 "y.tab.c"

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
#line 194 "parser.y"
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
#line 205 "parser.y"
	{/*imprimirCodigo(codigo);*/}
break;
case 3:
#line 207 "parser.y"
	{typeGBL  = yystack.l_mark[0].tipo.valorTipo;}
break;
case 5:
#line 208 "parser.y"
	{typeGBL  = yystack.l_mark[0].tipo.valorTipo;}
break;
case 7:
#line 209 "parser.y"
	{}
break;
case 8:
#line 211 "parser.y"
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
#line 218 "parser.y"
	{
									  TT1 = pop_tt(pTipos);
								      TS1 = pop_st(pSimbolos);
									  structDir = popPDir(pDirecciones);
									  dir = structDir->info;
									  TYP* newTYP= init_type();
									  newTYP = set_typ(newTYP,"reg",0,getTopType(pTipos));
									 typeGBL = append_type(getTopType(pTipos), newTYP);}
break;
case 10:
#line 225 "parser.y"
	{
										  yyval.tipo.valorTipo=typeGBL;
									  }
break;
case 11:
#line 229 "parser.y"
	{baseGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 12:
#line 229 "parser.y"
	{yyval.tipo.valorTipo=yystack.l_mark[-1].tipo.valorTipo;}
break;
case 13:
#line 231 "parser.y"
	{
						yyval.tipo.valorTipo=0;}
break;
case 14:
#line 233 "parser.y"
	{
						yyval.tipo.valorTipo=1;}
break;
case 15:
#line 235 "parser.y"
	{
						yyval.tipo.valorTipo=4;}
break;
case 16:
#line 237 "parser.y"
	{
						yyval.tipo.valorTipo=2;}
break;
case 17:
#line 239 "parser.y"
	{
						yyval.tipo.valorTipo=3;}
break;
case 18:
#line 242 "parser.y"
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
						};}
break;
case 19:
#line 256 "parser.y"
	{yyval.tipo.valorTipo=baseGBL;}
break;
case 20:
#line 258 "parser.y"
	{
									if(search_id_symbol(getTopSym(pSimbolos),yystack.l_mark[0].id.lexval) == -1){
									simbol = init_sym();
									simbol=set_sym(simbol, yystack.l_mark[0].id.lexval, dir, typeGBL, "var", NULL, getTopSym(pSimbolos), getTopType(pTipos));
									append_sym(getTopSym(pSimbolos),simbol);
									dir = dir + getTam(getTopType(pTipos), typeGBL);
                                      }
                                      else{
										  printf("El identificador ya fue declarado\n");
									  };
									  }
break;
case 21:
#line 268 "parser.y"
	{
										  		if( search_id_symbol(getTopSym(pSimbolos),yystack.l_mark[0].id.lexval) == -1){
												simbol = init_sym(); 
												simbol= set_sym(simbol, yystack.l_mark[0].id.lexval, dir, typeGBL, "var", NULL, getTopSym(pSimbolos), getTopType(pTipos));
												append_sym(getTopSym(pSimbolos),simbol);
												dir = dir + getTam(getTopType(pTipos), typeGBL);
												}
												else{
													printf("El identificador ya fue declarado\n");
												};
									  		}
break;
case 22:
#line 280 "parser.y"
	{}
break;
case 23:
#line 280 "parser.y"
	{}
break;
case 24:
#line 282 "parser.y"
	{}
break;
case 25:
#line 282 "parser.y"
	{}
break;
case 26:
#line 284 "parser.y"
	{}
break;
case 27:
#line 284 "parser.y"
	{}
break;
case 28:
#line 286 "parser.y"
	{}
break;
case 29:
#line 288 "parser.y"
	{}
break;
case 30:
#line 290 "parser.y"
	{}
break;
case 31:
#line 290 "parser.y"
	{}
break;
case 32:
#line 292 "parser.y"
	{}
break;
case 33:
#line 292 "parser.y"
	{}
break;
case 34:
#line 294 "parser.y"
	{}
break;
case 35:
#line 295 "parser.y"
	{}
break;
case 36:
#line 296 "parser.y"
	{}
break;
case 37:
#line 297 "parser.y"
	{}
break;
case 38:
#line 298 "parser.y"
	{}
break;
case 39:
#line 299 "parser.y"
	{}
break;
case 40:
#line 300 "parser.y"
	{}
break;
case 41:
#line 301 "parser.y"
	{}
break;
case 42:
#line 302 "parser.y"
	{}
break;
case 43:
#line 303 "parser.y"
	{}
break;
case 44:
#line 304 "parser.y"
	{}
break;
case 45:
#line 305 "parser.y"
	{}
break;
case 46:
#line 307 "parser.y"
	{}
break;
case 47:
#line 309 "parser.y"
	{}
break;
case 48:
#line 309 "parser.y"
	{}
break;
case 49:
#line 311 "parser.y"
	{}
break;
case 50:
#line 311 "parser.y"
	{}
break;
case 51:
#line 313 "parser.y"
	{}
break;
case 52:
#line 314 "parser.y"
	{}
break;
case 53:
#line 315 "parser.y"
	{}
break;
case 54:
#line 316 "parser.y"
	{}
break;
case 55:
#line 317 "parser.y"
	{}
break;
case 56:
#line 318 "parser.y"
	{}
break;
case 57:
#line 320 "parser.y"
	{}
break;
case 58:
#line 321 "parser.y"
	{}
break;
case 59:
#line 322 "parser.y"
	{}
break;
case 60:
#line 323 "parser.y"
	{}
break;
case 61:
#line 324 "parser.y"
	{}
break;
case 62:
#line 325 "parser.y"
	{}
break;
case 63:
#line 326 "parser.y"
	{}
break;
case 64:
#line 328 "parser.y"
	{}
break;
case 65:
#line 329 "parser.y"
	{}
break;
case 66:
#line 330 "parser.y"
	{}
break;
case 67:
#line 331 "parser.y"
	{}
break;
case 68:
#line 332 "parser.y"
	{}
break;
case 69:
#line 333 "parser.y"
	{}
break;
case 70:
#line 334 "parser.y"
	{}
break;
case 71:
#line 335 "parser.y"
	{}
break;
case 72:
#line 336 "parser.y"
	{}
break;
case 73:
#line 337 "parser.y"
	{}
break;
case 74:
#line 340 "parser.y"
	{}
break;
case 75:
#line 342 "parser.y"
	{}
break;
case 76:
#line 342 "parser.y"
	{}
break;
case 77:
#line 342 "parser.y"
	{}
break;
case 78:
#line 344 "parser.y"
	{}
break;
case 79:
#line 344 "parser.y"
	{}
break;
case 80:
#line 346 "parser.y"
	{}
break;
case 81:
#line 347 "parser.y"
	{}
break;
case 82:
#line 349 "parser.y"
	{}
break;
case 83:
#line 349 "parser.y"
	{}
break;
case 84:
#line 351 "parser.y"
	{}
break;
case 85:
#line 352 "parser.y"
	{}
break;
#line 1182 "y.tab.c"
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
