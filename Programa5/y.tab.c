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
void print_code(CODE *c);

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
CODE *codigo; 
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
#line 66 "parser.y"
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
#line 164 "y.tab.c"

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
   27,    0,   28,   19,   29,   19,   19,   30,   31,   14,
   32,    1,    2,    2,    2,    2,    2,    3,    3,   20,
   20,   33,   34,   21,   21,   11,   11,   10,   10,   13,
   15,   16,   16,   35,    6,    6,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,   22,   23,
   23,   24,   24,   36,    7,   37,    7,    7,    7,    7,
    7,    8,    8,    8,    8,    8,    8,    8,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,   17,   25,
   25,   25,   26,   26,   18,   18,   12,   12,    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    0,    5,    0,    0,    0,    6,
    0,    3,    1,    1,    1,    1,    1,    4,    0,    3,
    1,    0,    0,   13,    0,    1,    1,    3,    1,    2,
    2,    3,    0,    0,    3,    1,    5,    7,    5,    5,
    8,    4,    3,    3,    2,    3,    2,    3,    5,    1,
    0,    3,    0,    0,    4,    0,    4,    2,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    1,    3,    3,
    3,    3,    3,    3,    1,    1,    1,    1,    2,    1,
    1,    3,    3,    0,    3,    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   13,   14,   15,   17,   16,    3,   11,
    5,    0,    8,    0,    0,    0,    0,    2,    0,   21,
    0,    0,   12,    0,    0,    9,    0,    0,    0,    0,
   22,    0,   20,    4,    0,    6,    0,   10,   18,    0,
    0,    0,    0,    0,   29,    0,    0,   31,    0,    0,
   30,    0,   28,    0,   32,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,    0,    0,    0,
    0,    0,   79,    0,   78,   77,   76,   60,   61,    0,
    0,    0,    0,    0,   75,    0,    0,    0,    0,   47,
    0,    0,   45,    0,   23,    0,    0,    0,    0,    0,
    0,    0,    0,   58,    0,    0,    0,    0,    0,    0,
    0,   54,   56,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   43,   44,   46,    0,   35,    0,    0,
   82,   85,    0,   83,   74,    0,    0,   71,   72,   73,
    0,    0,    0,    0,    0,   62,   64,   65,   63,    0,
    0,    0,   24,   42,    0,   86,   37,    0,    0,   57,
   40,   39,    0,    0,    0,    0,   38,    0,    0,    0,
    0,    0,   41,    0,   52,   50,   49,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   23,   82,   67,   68,   83,   84,   99,   43,
   44,  100,   45,   11,   46,   48,   85,   72,   12,   21,
   18,  166,  177,  170,   73,   74,    2,   14,   16,   19,
   32,   15,   37,  127,   96,  142,  143,
};
static const YYINT yysindex[] = {                         0,
    0,  -21, -259,    0,    0,    0,    0,    0,    0,    0,
    0, -237,    0, -243, -253, -243,  125,    0,  -21,    0,
 -245, -214,    0, -185, -197,    0, -193,  -21, -226,  -21,
    0, -202,    0,    0, -253,    0, -216,    0,    0,  130,
    0, -205, -181, -221,    0, -158, -186,    0,  125, -128,
    0, -205,    0,  -21,    0,   41, -196, -255,   41, -255,
 -153,   41, -137, -222, -114, -230,    0, -106, -108, -222,
 -222, -131,    0, -105,    0,    0,    0,    0,    0, -255,
 -222,   98, -263,   82,    0,  -86, -194, -114,  -97,    0,
   61,  -82,    0,   66,    0,   41, -222,   98,  -73,  -92,
 -154, -222,  -50,    0,  -91, -222, -222, -222, -222, -222,
   41,    0,    0, -222, -222, -222, -222, -222, -222, -255,
   41,  -90,    0,    0,    0,    0, -237,    0,   71, -222,
    0,    0, -122,    0,    0, -270, -270,    0,    0,    0,
 -274, -255, -255,  107,  107,    0,    0,    0,    0,   -1,
  -62,  -39,    0,    0,   98,    0,    0,   41,  -71,    0,
    0,    0,  -46,  -44,  -31,  -35,    0,  -38,  -37,  -17,
   41,   41,    0,  -46,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  262,    0,    0,   -5,    0,    0,    0,  -13,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,
    0,    0,    0,    0,   -5,    0,    0,    0,    0,    0,
 -254, -193,  -36,    0,    0,    0,    0,    0,    0,    0,
    0, -193,    0,   57,    0,    0, -165,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   73,    0,  -33,
    0, -133,    0, -101,    0,    0,    0,    0,    0,    0,
    0,    5,    0, -201,    0,    0,    0,    0,   73,    0,
    0,    0,    0,    0,    0,    0,    0, -220,  -24,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  262,    0,    0,    0,
    0,    0,    0,    0,    0,  -69,  -40,    0,    0,    0,
    0,    0,    0, -178,   16,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -218,    0,    0,    0, -192,    0,
    0,    0,    0,    0,    0,  -11,    0,    0,    0,    0,
    0,    0,    0, -138,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  264,  -25,  255,  -48,  -54,  230,  -52,  265,    0,    0,
    0,    0,  244,    0,    0,  251,  -56,    0,   44,  288,
  184,  141,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 403
static const YYINT yytable[] = {                         69,
    7,    7,   69,  157,   86,   69,  111,   87,   92,   75,
   76,   77,   57,   17,   42,   91,   13,   94,   78,   79,
   17,   98,  101,   42,   20,  112,  113,  104,  108,  109,
  110,  122,  105,  158,   75,   76,   77,   57,   27,   69,
   28,  128,   75,   76,   77,   57,   80,   81,  129,   27,
   17,   22,   29,  133,   69,   93,  141,  136,  137,  138,
  139,  140,   26,   90,   69,   89,  151,  150,   59,   59,
   31,   34,   81,   36,   33,   38,  121,   55,   55,   35,
   81,  155,   50,   90,   59,   89,   40,   59,   59,  159,
  160,   66,   66,   55,  112,  113,   55,   56,   27,   47,
   30,   69,   49,  164,   84,   84,   70,   66,   71,   51,
   66,   66,   66,   66,   69,   69,  174,  175,   84,   52,
   84,   84,   84,   84,   84,   84,   84,   84,   84,   84,
   84,   84,   84,   84,   84,   84,   81,   81,   84,   51,
   84,   51,  106,  107,  108,  109,  110,   54,   90,   88,
   81,  132,   81,   57,   81,   81,   81,   81,   81,   81,
   81,   81,   81,   81,   81,   81,   81,   81,   80,   80,
   81,   95,   81,  102,  106,  107,  108,  109,  110,   97,
  123,  103,   80,  156,   80,  120,   80,   80,   80,   80,
   80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
   69,   69,   80,  125,   80,  106,  107,  108,  109,  110,
  130,  131,  135,  152,   69,  162,   69,  134,  113,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   70,
   70,  163,  165,  167,   69,  168,   69,    3,    4,    5,
    6,    7,    8,   70,  169,   70,  171,  172,   70,   70,
   70,   70,   70,   70,   70,   70,   70,   70,    7,    7,
  173,   25,   19,   70,    7,   70,   53,   26,    7,    7,
   88,    7,    7,    7,   68,   68,    7,    7,    7,   87,
   25,    7,    7,    7,  161,   67,   67,  112,  113,   39,
   68,   89,   53,   68,   68,   68,   68,   68,   68,   68,
   68,   67,   55,   24,   67,   67,   67,   67,   57,   58,
  153,   59,   60,   61,  176,    0,   62,   63,    0,    0,
    0,   64,   65,   66,    7,    7,    0,    7,    7,    7,
    0,    0,    7,    7,    0,    0,    0,    7,    7,    7,
   34,   34,    0,   34,   34,   34,  124,    0,   34,   34,
    0,  126,    0,   34,   34,   34,  154,  106,  107,  108,
  109,  110,  106,  107,  108,  109,  110,  106,  107,  108,
  109,  110,  114,  115,  116,  117,  118,  119,  144,  145,
  146,  147,  148,  149,    4,    5,    6,    7,    8,    4,
    5,    6,   41,    8,  106,  107,  108,  109,  110,  116,
  117,  118,  119,
};
static const YYINT yycheck[] = {                         56,
    0,    0,   59,  278,   59,   62,  270,   60,   65,  265,
  266,  267,  268,  268,   40,   64,  276,   66,  274,  275,
  258,   70,   71,   49,  268,  289,  290,   80,  299,  300,
  301,   88,   81,  308,  265,  266,  267,  268,  284,   96,
  286,   96,  265,  266,  267,  268,  302,  303,   97,  304,
  305,  305,  267,  102,  111,  286,  111,  106,  107,  108,
  109,  110,   19,  284,  121,  284,  121,  120,  270,  271,
  268,   28,  303,   30,  268,  278,  271,  270,  271,  306,
  303,  130,  304,  304,  286,  304,  303,  289,  290,  142,
  143,  270,  271,  286,  289,  290,  289,   54,  284,  305,
  286,  158,  284,  158,  270,  271,  303,  286,  305,  268,
  289,  290,  291,  292,  171,  172,  171,  172,  284,  306,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  270,  271,  304,  278,
  306,  280,  297,  298,  299,  300,  301,  276,  286,  303,
  284,  306,  286,  268,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  270,  271,
  304,  278,  306,  305,  297,  298,  299,  300,  301,  288,
  278,  287,  284,  306,  286,  272,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  270,  271,  304,  286,  306,  297,  298,  299,  300,  301,
  284,  304,  304,  304,  284,  278,  286,  268,  290,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  298,  270,
  271,  271,  279,  278,  304,  267,  306,  259,  260,  261,
  262,  263,  264,  284,  280,  286,  285,  285,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  258,  258,
  278,    0,  268,  304,  278,  306,  278,  304,  268,  269,
  304,  271,  272,  273,  270,  271,  276,  277,  278,  304,
   17,  281,  282,  283,  286,  270,  271,  289,  290,   35,
  286,   62,   49,  289,  290,  291,  292,  293,  294,  295,
  296,  286,   52,   16,  289,  290,  291,  292,  268,  269,
  127,  271,  272,  273,  174,   -1,  276,  277,   -1,   -1,
   -1,  281,  282,  283,  268,  269,   -1,  271,  272,  273,
   -1,   -1,  276,  277,   -1,   -1,   -1,  281,  282,  283,
  268,  269,   -1,  271,  272,  273,  286,   -1,  276,  277,
   -1,  286,   -1,  281,  282,  283,  286,  297,  298,  299,
  300,  301,  297,  298,  299,  300,  301,  297,  298,  299,
  300,  301,  291,  292,  293,  294,  295,  296,  114,  115,
  116,  117,  118,  119,  260,  261,  262,  263,  264,  260,
  261,  262,  263,  264,  297,  298,  299,  300,  301,  293,
  294,  295,  296,
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
#line 686 "parser.y"

void yyerror(char *msg){
	printf("%s, linea: %d, token: %s\n",msg, yylineno, yytext);
}

void print_code(CODE *c){
	QUAD *q;
	int i;
	printf("=========================CODIGO DE 3 DIRECCIONES=========================\n");
	q=c->head;
	for(i=0; i < c->num_instru; i++){
		printf("|%s\t|%s\t|%s\t|%s\t|\n",q->op,q->arg1,q->arg2,q->res);
		q=q->next;
	}
}
#line 602 "y.tab.c"

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
#line 199 "parser.y"
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
#line 210 "parser.y"
	{print_code(codigo);}
break;
case 3:
#line 212 "parser.y"
	{typeGBL  = yystack.l_mark[0].tipo.valorTipo;}
break;
case 5:
#line 213 "parser.y"
	{typeGBL  = yystack.l_mark[0].tipo.valorTipo;}
break;
case 7:
#line 214 "parser.y"
	{}
break;
case 8:
#line 216 "parser.y"
	{TS1 = init_sym_tab();
							   	  TT1 = init_type_tab(TT1);
								  structDir = crearDir();
								  structDir->info = dir;
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);}
break;
case 9:
#line 223 "parser.y"
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
#line 230 "parser.y"
	{
										  yyval.tipo.valorTipo=typeTemp;
									  }
break;
case 11:
#line 234 "parser.y"
	{baseGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 12:
#line 234 "parser.y"
	{yyval.tipo.valorTipo=yystack.l_mark[0].tipo.valorTipo;}
break;
case 13:
#line 236 "parser.y"
	{yyval.tipo.valorTipo=0;}
break;
case 14:
#line 237 "parser.y"
	{yyval.tipo.valorTipo=1;}
break;
case 15:
#line 238 "parser.y"
	{yyval.tipo.valorTipo=4;}
break;
case 16:
#line 239 "parser.y"
	{yyval.tipo.valorTipo=2;}
break;
case 17:
#line 240 "parser.y"
	{yyval.tipo.valorTipo=3;}
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
                    }
				}
break;
case 19:
#line 260 "parser.y"
	{}
break;
case 20:
#line 262 "parser.y"
	{}
break;
case 21:
#line 262 "parser.y"
	{}
break;
case 22:
#line 264 "parser.y"
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
							   	  	TT1 = init_type_tab(TT1);
									push_tt(pTipos,TT1);
								 	push_st(pSimbolos, TS1);
									append_new_quad(codigo,"label","-","-",yystack.l_mark[0].id.lexval);
								}

					}
break;
case 23:
#line 281 "parser.y"
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
#line 295 "parser.y"
	{}
break;
case 26:
#line 297 "parser.y"
	{yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;}
break;
case 27:
#line 298 "parser.y"
	{yyval.eListARGS.listArgs=NULL;}
break;
case 28:
#line 300 "parser.y"
	{
					yyval.eListARGS.listArgs = yystack.l_mark[-2].eListARGS.listArgs;
					argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
					append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 29:
#line 305 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 30:
#line 311 "parser.y"
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
#line 323 "parser.y"
	{baseGBL = yystack.l_mark[-1].tipo.valorTipo;}
break;
case 32:
#line 325 "parser.y"
	{
					TYP *tp = init_type();
                    tp = set_typ(tp,"array",yystack.l_mark[0].tipo.valorTipo,getTopType(pTipos));
                    yyval.tipo.valorTipo = append_type(getTopType(pTipos), tp);
				}
break;
case 33:
#line 329 "parser.y"
	{yyval.tipo.valorTipo=baseGBL;}
break;
case 34:
#line 331 "parser.y"
	{
					tmpEtq=create_label();
                    backpatch(codigo,yystack.l_mark[0].listIndice_S.nextlist,tmpEtq);
                    append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 35:
#line 335 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 36:
#line 336 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 37:
#line 338 "parser.y"
	{tmpLabel=create_label();
												backpatch(codigo,yystack.l_mark[-3].eBool.listTrue,tmpLabel);
												append_new_quad(codigo,"label","-","-",tmpLabel);
												yyval.listIndice_S.nextlist=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[-1].listIndice_S.nextlist);
											    }
break;
case 38:
#line 343 "parser.y"
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
#line 352 "parser.y"
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
#line 365 "parser.y"
	{tmpLabel=create_label();
												   backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpLabel);
												   yyval.listIndice_S.nextlist=yystack.l_mark[-1].eBool.listFalse;
													}
break;
case 41:
#line 369 "parser.y"
	{
					  												int i;
																	L1=create_label();
																	prueba = combinar(yystack.l_mark[-2].listIndice_C.prueba, yystack.l_mark[-1].listIndice_P.prueba);
																	backpatch(codigo,yystack.l_mark[-2].listIndice_C.nextlist,L1);
																	sustituir("??",yystack.l_mark[-5].var.idVar,prueba,codigo);
																	}
break;
case 42:
#line 376 "parser.y"
	{
										if((search_id_symbol(getTopSym(pSimbolos),yystack.l_mark[-3].var.idVar) != -1) || (search_id_symbol(TGS,yystack.l_mark[-3].var.idVar) != -1 )){
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
											printf("Error => El idntificador  no se ha declarado\n");
										}
										yyval.listIndice_S.nextlist=NULL;
									}
break;
case 43:
#line 396 "parser.y"
	{
									append_new_quad(codigo,"print",yystack.l_mark[-1].eExpr.dirExp,"-","-");
									yyval.listIndice_S.nextlist = NULL;
								}
break;
case 44:
#line 400 "parser.y"
	{
									append_new_quad(codigo,"scan","-","-",yystack.l_mark[-1].var.idVar); 
									yyval.listIndice_S.nextlist = NULL;
								}
break;
case 45:
#line 404 "parser.y"
	{	
						if(funcType==3){
							append_new_quad(codigo,"return","-","-","-");
						}else{
							printf("la funcion debe retornar  algun valor de tipo ==> %d",funcType);
						}
						yyval.listIndice_S.nextlist=NULL;
					}
break;
case 46:
#line 412 "parser.y"
	{ 
					  					if(funcType!=3){
											dir1= reducir(yystack.l_mark[-1].eExpr.dirExp,yystack.l_mark[-1].eExpr.tipoExp,funcType,codigo);
											append_new_quad(codigo,"return",yystack.l_mark[-1].eExpr.dirExp,"-","-");
											funcReturn=true;
										}else{
                    						 printf("la funcion debe retornar  algun valor de tipo ==>%d",funcType);
                      					}
										yyval.listIndice_S.nextlist=NULL;
									}
break;
case 47:
#line 422 "parser.y"
	{	
					  				indiceGlobal = init_index();
									char *tmp3=(char*)malloc(sizeof(char));
									sprintf(tmp3, "%i", indiceGlobal->indice);
									append_new_quad(codigo, "goto", "-", "-", tmp3);
									yyval.listIndice_S.nextlist = init_list_index(indiceGlobal);
									append_index(yyval.listIndice_S.nextlist, indiceGlobal);
								}
break;
case 48:
#line 430 "parser.y"
	{ 
					  						yyval.listIndice_S.nextlist=yystack.l_mark[-1].listIndice_S.nextlist;
										}
break;
case 49:
#line 434 "parser.y"
	{
										yyval.listIndice_C.nextlist = combinar(yyval.listIndice_C.nextlist, yystack.l_mark[-1].listIndice_S.nextlist);
										char *label_C = create_label();
										/*Indica el inicio del código para la sentencia*/
										yyval.listIndice_C.prueba = yystack.l_mark[0].listIndice_C.prueba;
										/*sustituir_c()*/
										/*(if ”??” ”==” num.dir ”goto” L )*/
									}
break;
case 50:
#line 443 "parser.y"
	{
						/*casos.prueba = newCode()*/
						char *LT = create_label();
						/*Indica el inicio del código para la sentencia*/
						/*genCode(”label” L)*/
						/*casos.prueba.append(if ”??” ”==” num.dir ”goto” L )*/
						}
break;
case 51:
#line 450 "parser.y"
	{}
break;
case 52:
#line 452 "parser.y"
	{
									/*predeterminado.prueba = newCode()*/
									char *lll = create_label();
									/*Indica el inicio del código para la sentencia*/
									/*genCode(”label” L)*/
									/*predeterminado.prueba.append(”goto” L )*/
									}
break;
case 53:
#line 458 "parser.y"
	{}
break;
case 54:
#line 460 "parser.y"
	{
					tmpEtq = create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listFalse,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 55:
#line 464 "parser.y"
	{
					yyval.eBool.listTrue=combinar(yystack.l_mark[-3].eBool.listTrue,yystack.l_mark[0].eBool.listTrue);
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listFalse;
				}
break;
case 56:
#line 468 "parser.y"
	{
					tmpEtq=create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 57:
#line 473 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listTrue;
					yyval.eBool.listFalse=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[0].eBool.listFalse);}
break;
case 58:
#line 476 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listFalse;
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listTrue;}
break;
case 59:
#line 479 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].rel.listRelTrue;
					yyval.eBool.listFalse=yystack.l_mark[0].rel.listRelFalse;}
break;
case 60:
#line 482 "parser.y"
	{
					indiceGlobal = init_index();
					yyval.eBool.listFalse=init_list_index(NULL); 
					yyval.eBool.listTrue=init_list_index(NULL);
					append_index(yyval.eBool.listTrue, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"goto","-","-",tmp);}
break;
case 61:
#line 490 "parser.y"
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
case 62:
#line 500 "parser.y"
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
case 63:
#line 519 "parser.y"
	{
									indiceGlobal = init_index();
									indiceAux = init_index();
									yyval.rel.listRelTrue = init_list_index(indiceGlobal);
									yyval.rel.listRelFalse = init_list_index(indiceAux);
									append_index(yyval.rel.listRelTrue, indiceGlobal);
									append_index(yyval.rel.listRelFalse, indiceAux);
									yyval.rel.tipoRel = max(yystack.l_mark[-2].rel.tipoRel, yystack.l_mark[0].rel.tipoRel);
									dir1 = ampliar(yystack.l_mark[-2].rel.dirRel,yystack.l_mark[-2].rel.tipoRel,yyval.rel.tipoRel, codigo);
									dir2 = ampliar(yystack.l_mark[0].rel.dirRel,yystack.l_mark[0].rel.tipoRel,yyval.rel.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, ">", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
break;
case 64:
#line 536 "parser.y"
	{
									indiceGlobal = init_index();
									indiceAux = init_index();
									yyval.rel.listRelTrue = init_list_index(indiceGlobal);
									yyval.rel.listRelFalse = init_list_index(indiceAux);
									append_index(yyval.rel.listRelTrue, indiceGlobal);
									append_index(yyval.rel.listRelFalse, indiceAux);
									yyval.rel.tipoRel = max(yystack.l_mark[-2].rel.tipoRel, yystack.l_mark[0].rel.tipoRel);
									dir1 = ampliar(yystack.l_mark[-2].rel.dirRel,yystack.l_mark[-2].rel.tipoRel,yyval.rel.tipoRel, codigo);
									dir2 = ampliar(yystack.l_mark[0].rel.dirRel,yystack.l_mark[0].rel.tipoRel,yyval.rel.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, "<=", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
break;
case 65:
#line 553 "parser.y"
	{
									indiceGlobal = init_index();
									indiceAux = init_index();
									yyval.rel.listRelTrue = init_list_index(indiceGlobal);
									yyval.rel.listRelFalse = init_list_index(indiceAux);
									append_index(yyval.rel.listRelTrue, indiceGlobal);
									append_index(yyval.rel.listRelFalse, indiceAux);
									yyval.rel.tipoRel = max(yystack.l_mark[-2].rel.tipoRel, yystack.l_mark[0].rel.tipoRel);
									dir1 = ampliar(yystack.l_mark[-2].rel.dirRel,yystack.l_mark[-2].rel.tipoRel,yyval.rel.tipoRel, codigo);
									dir2 = ampliar(yystack.l_mark[0].rel.dirRel,yystack.l_mark[0].rel.tipoRel,yyval.rel.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, ">=", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
break;
case 66:
#line 570 "parser.y"
	{
									indiceGlobal = init_index();
									indiceAux = init_index();
									yyval.rel.listRelTrue = init_list_index(indiceGlobal);
									yyval.rel.listRelFalse = init_list_index(indiceAux);
									append_index(yyval.rel.listRelTrue, indiceGlobal);
									append_index(yyval.rel.listRelFalse, indiceAux);
									yyval.rel.tipoRel = max(yystack.l_mark[-2].rel.tipoRel, yystack.l_mark[0].rel.tipoRel);
									dir1 = ampliar(yystack.l_mark[-2].rel.dirRel,yystack.l_mark[-2].rel.tipoRel,yyval.rel.tipoRel, codigo);
									dir2 = ampliar(yystack.l_mark[0].rel.dirRel,yystack.l_mark[0].rel.tipoRel,yyval.rel.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, "==", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
break;
case 67:
#line 587 "parser.y"
	{
									indiceGlobal = init_index();
									indiceAux = init_index();
									yyval.rel.listRelTrue = init_list_index(indiceGlobal);
									yyval.rel.listRelFalse = init_list_index(indiceAux);
									append_index(yyval.rel.listRelTrue, indiceGlobal);
									append_index(yyval.rel.listRelFalse, indiceAux);
									yyval.rel.tipoRel = max(yystack.l_mark[-2].rel.tipoRel, yystack.l_mark[0].rel.tipoRel);
									dir1 = ampliar(yystack.l_mark[-2].rel.dirRel,yystack.l_mark[-2].rel.tipoRel,yyval.rel.tipoRel, codigo);
									dir2 = ampliar(yystack.l_mark[0].rel.dirRel,yystack.l_mark[0].rel.tipoRel,yyval.rel.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, "<>", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
break;
case 68:
#line 604 "parser.y"
	{yyval.rel.tipoRel=yystack.l_mark[0].eExpr.tipoExp;
	                          yyval.rel.dirRel=yystack.l_mark[0].eExpr.dirExp;}
break;
case 69:
#line 607 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp,codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp,codigo);
                    append_new_quad(codigo, "+", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 70:
#line 614 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "-", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 71:
#line 621 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                	dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "*", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 72:
#line 628 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                	dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "/", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 73:
#line 635 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "%", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 74:
#line 642 "parser.y"
	{
					yyval.eExpr.dirExp = yystack.l_mark[-1].eExpr.dirExp;
                    yyval.eExpr.tipoExp = yystack.l_mark[-1].eExpr.tipoExp;
				}
break;
case 75:
#line 646 "parser.y"
	{}
break;
case 76:
#line 647 "parser.y"
	{
					yyval.eExpr.dirExp = yystack.l_mark[0].num.valor;
                    yyval.eExpr.tipoExp = yystack.l_mark[0].num.tipe;
				}
break;
case 77:
#line 651 "parser.y"
	{}
break;
case 78:
#line 652 "parser.y"
	{}
break;
case 79:
#line 655 "parser.y"
	{}
break;
case 80:
#line 657 "parser.y"
	{}
break;
case 81:
#line 658 "parser.y"
	{}
break;
case 82:
#line 659 "parser.y"
	{}
break;
case 83:
#line 661 "parser.y"
	{}
break;
case 84:
#line 662 "parser.y"
	{}
break;
case 85:
#line 664 "parser.y"
	{}
break;
case 86:
#line 665 "parser.y"
	{}
break;
case 87:
#line 667 "parser.y"
	{
					yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;
				}
break;
case 88:
#line 670 "parser.y"
	{yyval.eListARGS.listArgs = NULL;}
break;
case 89:
#line 672 "parser.y"
	{
					yyval.eListARGS.listArgs=yystack.l_mark[-2].eListARGS.listArgs;
                    ARG* argx = init_arg(yystack.l_mark[0].eExpr.tipoExp);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
                    append_new_quad(codigo,"param",yystack.l_mark[0].eExpr.dirExp," ", " ");
				}
break;
case 90:
#line 678 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].eExpr.tipoExp);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
                    append_new_quad(codigo,"param",yystack.l_mark[0].eExpr.dirExp," ", " ");
				}
break;
#line 1533 "y.tab.c"
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
