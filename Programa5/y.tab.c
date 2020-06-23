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
void print_code(struct code *c);

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
   27,   28,    0,   29,   19,   30,   19,   19,   31,   32,
   14,   33,    1,    2,    2,    2,    2,    2,    3,    3,
   20,   20,   34,   35,   21,   21,   11,   11,   10,   10,
   13,   15,   16,   16,   36,    6,    6,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,   22,
   23,   23,   24,   24,   37,    7,   38,    7,    7,    7,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,   17,
   25,   25,   25,   26,   26,   18,   18,   12,   12,    9,
    9,
};
static const YYINT yylen[] = {                            2,
    0,    0,    4,    0,    5,    0,    5,    0,    0,    0,
    6,    0,    3,    1,    1,    1,    1,    1,    4,    0,
    3,    1,    0,    0,   13,    0,    1,    1,    3,    1,
    2,    2,    3,    0,    0,    3,    1,    5,    7,    5,
    5,    8,    4,    3,    3,    2,    3,    2,    3,    5,
    1,    0,    3,    0,    0,    4,    0,    4,    2,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    1,    3,
    3,    3,    3,    3,    3,    1,    1,    1,    1,    2,
    1,    1,    3,    3,    0,    3,    4,    1,    0,    3,
    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   14,   15,   16,   18,   17,    4,   12,
    6,    2,    9,    0,    0,    0,    0,    0,   22,    0,
    0,   13,    0,    0,    3,   10,    0,    0,    0,    0,
    0,    0,   21,    5,    0,    7,   23,   11,   19,    0,
    0,    0,    0,    0,    0,   30,    0,    0,   32,    0,
    0,   31,    0,   29,    0,   33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,    0,    0,
    0,    0,    0,   80,    0,   79,   78,   77,   61,   62,
    0,    0,    0,    0,    0,   76,    0,    0,    0,    0,
   48,    0,    0,   46,    0,   24,    0,    0,    0,    0,
    0,    0,    0,    0,   59,    0,    0,    0,    0,    0,
    0,    0,   55,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   49,   44,   45,   47,    0,   36,    0,
    0,   83,   86,    0,   84,   75,    0,    0,   72,   73,
   74,    0,    0,    0,    0,    0,   63,   65,   66,   64,
    0,    0,    0,   25,   43,    0,   87,   38,    0,    0,
   58,   41,   40,    0,    0,    0,    0,   39,    0,    0,
    0,    0,    0,   42,    0,   53,   51,   50,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   22,   83,   68,   69,   84,   85,  100,   44,
   45,  101,   46,   11,   47,   49,   86,   73,   12,   20,
   25,  167,  178,  171,   74,   75,    2,   17,   14,   16,
   18,   32,   15,   40,  128,   97,  143,  144,
};
static const YYINT yysindex[] = {                         0,
    0,  114, -251,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -261, -266, -261, -205,  114,    0, -269,
 -193,    0, -176,  -22,    0,    0, -190,  114, -227,  114,
 -182, -191,    0,    0, -266,    0,    0,    0,    0, -196,
  131,    0, -202, -170, -184,    0, -128, -164,    0,  -22,
 -127,    0, -202,    0,  114,    0,   41, -192, -255,   41,
 -255, -155,   41, -136, -222, -114, -230,    0, -106, -108,
 -222, -222, -131,    0, -105,    0,    0,    0,    0,    0,
 -255, -222,   99, -218,   88,    0,  -86,  -28, -114,  -97,
    0,   61,  -82,    0,   66,    0,   41, -222,   99,  -73,
  -92, -154, -222,  -54,    0,  -91, -222, -222, -222, -222,
 -222,   41,    0,    0, -222, -222, -222, -222, -222, -222,
 -255,   41,  -88,    0,    0,    0,    0, -205,    0,   71,
 -222,    0,    0, -122,    0,    0, -200, -200,    0,    0,
    0, -274, -255, -255,  108,  108,    0,    0,    0,    0,
 -206,  -60,  -52,    0,    0,   99,    0,    0,   41,  -58,
    0,    0,    0,  -46,  -44,  -31,  -35,    0,  -38,  -37,
  -15,   41,   41,    0,  -46,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -3,    0,  267,  -10,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,
    0,    0,    0,    0,   -3,    0,    0,    0,    0,    0,
    0, -241,    3,  -24,    0,    0,    0,    0,    0,    0,
    0,    0,    3,    0,   57,    0,    0, -165,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   73,    0,
  -23,    0, -133,    0, -101,    0,    0,    0,    0,    0,
    0,    0,    5,    0, -201,    0,    0,    0,    0,   73,
    0,    0,    0,    0,    0,    0,    0,    0, -263,  -19,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  267,    0,    0,
    0,    0,    0,    0,    0,    0,  -69,  -40,    0,    0,
    0,    0,    0,    0, -194,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -254,    0,    0,    0, -177,
    0,    0,    0,    0,    0,    0,   10,    0,    0,    0,
    0,    0,    0,    0, -249,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  265,   25,  255,  -49,  -55,  229,  -53,  270,    0,    0,
    0,    0,  243,    0,    0,  250,  -57,    0,   -4,  288,
  183,  140,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 404
static const YYINT yytable[] = {                         70,
    8,    8,   70,  158,   87,   70,   19,   88,   93,   76,
   77,   78,   58,   26,   27,   92,   28,   95,   79,   80,
   91,   99,  102,   34,   13,   36,   18,  105,   52,   90,
   52,  123,  106,  159,   76,   77,   78,   58,   21,   70,
   91,  129,   76,   77,   78,   58,   81,   82,  130,   90,
   57,  112,   24,  134,   70,   94,  142,  137,  138,  139,
  140,  141,   28,   18,   70,   43,  152,  151,   60,   60,
  113,  114,   82,   29,   43,   67,   67,   33,   35,  162,
   82,  156,  113,  114,   60,   37,   38,   60,   60,  160,
  161,   67,   56,   56,   67,   67,   67,   67,  109,  110,
  111,   70,   48,  165,   85,   85,   41,   27,   56,   30,
   71,   56,   72,   50,   70,   70,  175,  176,   85,   51,
   85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
   85,   85,   85,   85,   85,   85,   82,   82,   85,   52,
   85,   53,  107,  108,  109,  110,  111,   89,   55,   91,
   82,  133,   82,   58,   82,   82,   82,   82,   82,   82,
   82,   82,   82,   82,   82,   82,   82,   82,   81,   81,
   82,   96,   82,  103,  107,  108,  109,  110,  111,   98,
  124,  104,   81,  157,   81,  121,   81,   81,   81,   81,
   81,   81,   81,   81,   81,   81,   81,   81,   81,   81,
   70,   70,   81,  126,   81,  107,  108,  109,  110,  111,
  131,  132,  136,  135,   70,  153,   70,  163,  164,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,   71,
   71,  114,  166,  168,   70,  169,   70,    4,    5,    6,
    7,    8,  122,   71,  170,   71,  172,  173,   71,   71,
   71,   71,   71,   71,   71,   71,   71,   71,    8,    8,
  113,  114,  174,   71,   20,   71,   26,    8,    8,    8,
   34,    8,    8,    8,   69,   69,    8,    8,    8,   27,
   89,    8,    8,    8,   88,   68,   68,   54,   31,   39,
   69,   90,   54,   69,   69,   69,   69,   69,   69,   69,
   69,   68,   56,   23,   68,   68,   68,   68,   58,   59,
  154,   60,   61,   62,  177,    0,   63,   64,    0,    0,
    0,   65,   66,   67,    8,    8,    0,    8,    8,    8,
    0,    0,    8,    8,    0,    0,    0,    8,    8,    8,
   35,   35,    0,   35,   35,   35,  125,    0,   35,   35,
    0,  127,    0,   35,   35,   35,  155,  107,  108,  109,
  110,  111,  107,  108,  109,  110,  111,  107,  108,  109,
  110,  111,    3,    4,    5,    6,    7,    8,  115,  116,
  117,  118,  119,  120,  145,  146,  147,  148,  149,  150,
    4,    5,    6,   42,    8,  107,  108,  109,  110,  111,
  117,  118,  119,  120,
};
static const YYINT yycheck[] = {                         57,
    0,    0,   60,  278,   60,   63,  268,   61,   66,  265,
  266,  267,  268,   18,  284,   65,  286,   67,  274,  275,
  284,   71,   72,   28,  276,   30,  268,   81,  278,  284,
  280,   89,   82,  308,  265,  266,  267,  268,  305,   97,
  304,   97,  265,  266,  267,  268,  302,  303,   98,  304,
   55,  270,  258,  103,  112,  286,  112,  107,  108,  109,
  110,  111,  304,  305,  122,   41,  122,  121,  270,  271,
  289,  290,  303,  267,   50,  270,  271,  268,  306,  286,
  303,  131,  289,  290,  286,  268,  278,  289,  290,  143,
  144,  286,  270,  271,  289,  290,  291,  292,  299,  300,
  301,  159,  305,  159,  270,  271,  303,  284,  286,  286,
  303,  289,  305,  284,  172,  173,  172,  173,  284,  304,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  270,  271,  304,  268,
  306,  306,  297,  298,  299,  300,  301,  303,  276,  286,
  284,  306,  286,  268,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  270,  271,
  304,  278,  306,  305,  297,  298,  299,  300,  301,  288,
  278,  287,  284,  306,  286,  272,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  270,  271,  304,  286,  306,  297,  298,  299,  300,  301,
  284,  304,  304,  268,  284,  304,  286,  278,  271,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  298,  270,
  271,  290,  279,  278,  304,  267,  306,  260,  261,  262,
  263,  264,  271,  284,  280,  286,  285,  285,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  258,  258,
  289,  290,  278,  304,  268,  306,    0,  278,  268,  269,
  268,  271,  272,  273,  270,  271,  276,  277,  278,  304,
  304,  281,  282,  283,  304,  270,  271,  278,   24,   35,
  286,   63,   50,  289,  290,  291,  292,  293,  294,  295,
  296,  286,   53,   16,  289,  290,  291,  292,  268,  269,
  128,  271,  272,  273,  175,   -1,  276,  277,   -1,   -1,
   -1,  281,  282,  283,  268,  269,   -1,  271,  272,  273,
   -1,   -1,  276,  277,   -1,   -1,   -1,  281,  282,  283,
  268,  269,   -1,  271,  272,  273,  286,   -1,  276,  277,
   -1,  286,   -1,  281,  282,  283,  286,  297,  298,  299,
  300,  301,  297,  298,  299,  300,  301,  297,  298,  299,
  300,  301,  259,  260,  261,  262,  263,  264,  291,  292,
  293,  294,  295,  296,  115,  116,  117,  118,  119,  120,
  260,  261,  262,  263,  264,  297,  298,  299,  300,  301,
  293,  294,  295,  296,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 349
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"$$2 :",
"programa : $$1 declaraciones $$2 funciones",
"$$3 :",
"declaraciones : tipo $$3 lista_var PYC declaraciones",
"$$4 :",
"declaraciones : tipo_registro $$4 lista_var PYC declaraciones",
"declaraciones :",
"$$5 :",
"$$6 :",
"tipo_registro : ESTRUCT INICIO $$5 declaraciones $$6 END",
"$$7 :",
"tipo : base $$7 tipo_arreglo",
"base : ENTERO",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : LCOR NUM RCOR tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"$$8 :",
"$$9 :",
"funciones : DEF tipo ID $$8 LPAR argumentos RPAR INICIO declaraciones sentencias END $$9 funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"tipo_arg : base param_arr",
"param_arr : LCOR RCOR param_arr",
"param_arr :",
"$$10 :",
"sentencias : sentencias $$10 sentencia",
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
"$$11 :",
"e_bool : e_bool OR $$11 e_bool",
"$$12 :",
"e_bool : e_bool AND $$12 e_bool",
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
#line 693 "parser.y"

void yyerror(char *msg){
	printf("%s, linea: %d, token: %s\n",msg, yylineno, yytext);
}

void print_code(struct code *c){
	struct cuad *q =(struct cuad *)malloc(sizeof(struct cuad)); 
	printf("=========================CODIGO DE 3 DIRECCIONES=========================\n");
	q=c->head;
	while(q!=NULL){
		printf("|%s\t|%s\t|%s\t|%s\t|\n",q->op,q->arg1,q->arg2,q->res);
		q=q->next;
	}
}
#line 604 "y.tab.c"

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
                  TGT = init_type_tab(TGT);
				  printf(">>>>>>Tabla general de tipos>>>>>>\n");
				  print_tab_type(TGT);
                  TGS = init_sym_tab();
				  print_tab_sym(TGS);
                  push_st(pSimbolos,TGS);
                  push_tt(pTipos,TGT);
                  tabCadenas = crearTablaCadenas();
				  print_tab_sym(TGS);
                  }
break;
case 2:
#line 214 "parser.y"
	{
					  			print_tab_sym(TGS);
								print_tab_type(TGT);
				  }
break;
case 3:
#line 217 "parser.y"
	{print_code(codigo);}
break;
case 4:
#line 219 "parser.y"
	{typeGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 6:
#line 220 "parser.y"
	{typeGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 8:
#line 221 "parser.y"
	{}
break;
case 9:
#line 223 "parser.y"
	{TS1 = init_sym_tab();
							   	  TT1 = init_type_tab(TT1);
								  structDir = crearDir();
								  structDir->info = dir;
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);}
break;
case 10:
#line 230 "parser.y"
	{
									  TT1 = pop_tt(pTipos);
								      TS1 = pop_st(pSimbolos);
									  structDir = popPDir(pDirecciones);
									  dir = structDir->info;
									  TYP* newTYP= init_type();
									  newTYP = set_typ(newTYP,"reg",0,getTopType(pTipos));
									  typeTemp = append_type(getTopType(pTipos), newTYP);}
break;
case 11:
#line 237 "parser.y"
	{
										  yyval.tipo.valorTipo=typeTemp;
									  }
break;
case 12:
#line 241 "parser.y"
	{baseGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 13:
#line 241 "parser.y"
	{yyval.tipo.valorTipo=yystack.l_mark[0].tipo.valorTipo;}
break;
case 14:
#line 243 "parser.y"
	{yyval.tipo.valorTipo=0;}
break;
case 15:
#line 244 "parser.y"
	{yyval.tipo.valorTipo=1;}
break;
case 16:
#line 245 "parser.y"
	{yyval.tipo.valorTipo=4;}
break;
case 17:
#line 246 "parser.y"
	{yyval.tipo.valorTipo=2;}
break;
case 18:
#line 247 "parser.y"
	{yyval.tipo.valorTipo=3;}
break;
case 19:
#line 249 "parser.y"
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
case 20:
#line 267 "parser.y"
	{}
break;
case 21:
#line 269 "parser.y"
	{}
break;
case 22:
#line 269 "parser.y"
	{}
break;
case 23:
#line 271 "parser.y"
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
case 24:
#line 288 "parser.y"
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
case 26:
#line 302 "parser.y"
	{}
break;
case 27:
#line 304 "parser.y"
	{yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;}
break;
case 28:
#line 305 "parser.y"
	{yyval.eListARGS.listArgs=NULL;}
break;
case 29:
#line 307 "parser.y"
	{
					yyval.eListARGS.listArgs = yystack.l_mark[-2].eListARGS.listArgs;
					argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
					append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 30:
#line 312 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 31:
#line 318 "parser.y"
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
case 32:
#line 330 "parser.y"
	{baseGBL = yystack.l_mark[-1].tipo.valorTipo;}
break;
case 33:
#line 332 "parser.y"
	{
					TYP *tp = init_type();
                    tp = set_typ(tp,"array",yystack.l_mark[0].tipo.valorTipo,getTopType(pTipos));
                    yyval.tipo.valorTipo = append_type(getTopType(pTipos), tp);
				}
break;
case 34:
#line 336 "parser.y"
	{yyval.tipo.valorTipo=baseGBL;}
break;
case 35:
#line 338 "parser.y"
	{
					tmpEtq=create_label();
                    backpatch(codigo,yystack.l_mark[0].listIndice_S.nextlist,tmpEtq);
                    append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 36:
#line 342 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 37:
#line 343 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 38:
#line 345 "parser.y"
	{tmpLabel=create_label();
												backpatch(codigo,yystack.l_mark[-3].eBool.listTrue,tmpLabel);
												append_new_quad(codigo,"label","-","-",tmpLabel);
												yyval.listIndice_S.nextlist=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[-1].listIndice_S.nextlist);
											    }
break;
case 39:
#line 350 "parser.y"
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
case 40:
#line 359 "parser.y"
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
case 41:
#line 372 "parser.y"
	{tmpLabel=create_label();
												   backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpLabel);
												   yyval.listIndice_S.nextlist=yystack.l_mark[-1].eBool.listFalse;
													}
break;
case 42:
#line 376 "parser.y"
	{
					  												int i;
																	L1=create_label();
																	prueba = combinar(yystack.l_mark[-2].listIndice_C.prueba, yystack.l_mark[-1].listIndice_P.prueba);
																	backpatch(codigo,yystack.l_mark[-2].listIndice_C.nextlist,L1);
																	sustituir("??",yystack.l_mark[-5].var.idVar,prueba,codigo);
																	}
break;
case 43:
#line 383 "parser.y"
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
case 44:
#line 403 "parser.y"
	{
									append_new_quad(codigo,"print",yystack.l_mark[-1].eExpr.dirExp,"-","-");
									yyval.listIndice_S.nextlist = NULL;
								}
break;
case 45:
#line 407 "parser.y"
	{
									append_new_quad(codigo,"scan","-","-",yystack.l_mark[-1].var.idVar); 
									yyval.listIndice_S.nextlist = NULL;
								}
break;
case 46:
#line 411 "parser.y"
	{	
						if(funcType==3){
							append_new_quad(codigo,"return","-","-","-");
						}else{
							printf("la funcion debe retornar  algun valor de tipo ==> %d",funcType);
						}
						yyval.listIndice_S.nextlist=NULL;
					}
break;
case 47:
#line 419 "parser.y"
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
case 48:
#line 429 "parser.y"
	{	
					  				indiceGlobal = init_index();
									char *tmp3=(char*)malloc(sizeof(char));
									sprintf(tmp3, "%i", indiceGlobal->indice);
									append_new_quad(codigo, "goto", "-", "-", tmp3);
									yyval.listIndice_S.nextlist = init_list_index(indiceGlobal);
									append_index(yyval.listIndice_S.nextlist, indiceGlobal);
								}
break;
case 49:
#line 437 "parser.y"
	{ 
					  						yyval.listIndice_S.nextlist=yystack.l_mark[-1].listIndice_S.nextlist;
										}
break;
case 50:
#line 441 "parser.y"
	{
										yyval.listIndice_C.nextlist = combinar(yyval.listIndice_C.nextlist, yystack.l_mark[-1].listIndice_S.nextlist);
										char *label_C = create_label();
										/*Indica el inicio del código para la sentencia*/
										yyval.listIndice_C.prueba = yystack.l_mark[0].listIndice_C.prueba;
										/*sustituir_c()*/
										/*(if ”??” ”==” num.dir ”goto” L )*/
									}
break;
case 51:
#line 450 "parser.y"
	{
						/*casos.prueba = newCode()*/
						char *LT = create_label();
						/*Indica el inicio del código para la sentencia*/
						/*genCode(”label” L)*/
						/*casos.prueba.append(if ”??” ”==” num.dir ”goto” L )*/
						}
break;
case 52:
#line 457 "parser.y"
	{}
break;
case 53:
#line 459 "parser.y"
	{
									/*predeterminado.prueba = newCode()*/
									char *lll = create_label();
									/*Indica el inicio del código para la sentencia*/
									/*genCode(”label” L)*/
									/*predeterminado.prueba.append(”goto” L )*/
									}
break;
case 54:
#line 465 "parser.y"
	{}
break;
case 55:
#line 467 "parser.y"
	{
					tmpEtq = create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listFalse,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 56:
#line 471 "parser.y"
	{
					yyval.eBool.listTrue=combinar(yystack.l_mark[-3].eBool.listTrue,yystack.l_mark[0].eBool.listTrue);
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listFalse;
				}
break;
case 57:
#line 475 "parser.y"
	{
					tmpEtq=create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 58:
#line 480 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listTrue;
					yyval.eBool.listFalse=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[0].eBool.listFalse);}
break;
case 59:
#line 483 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listFalse;
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listTrue;}
break;
case 60:
#line 486 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].rel.listRelTrue;
					yyval.eBool.listFalse=yystack.l_mark[0].rel.listRelFalse;}
break;
case 61:
#line 489 "parser.y"
	{
					indiceGlobal = init_index();
					yyval.eBool.listFalse=init_list_index(NULL); 
					yyval.eBool.listTrue=init_list_index(NULL);
					append_index(yyval.eBool.listTrue, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"goto","-","-",tmp);}
break;
case 62:
#line 497 "parser.y"
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
case 63:
#line 507 "parser.y"
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
case 64:
#line 526 "parser.y"
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
case 65:
#line 543 "parser.y"
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
case 66:
#line 560 "parser.y"
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
case 67:
#line 577 "parser.y"
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
case 68:
#line 594 "parser.y"
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
case 69:
#line 611 "parser.y"
	{yyval.rel.tipoRel=yystack.l_mark[0].eExpr.tipoExp;
	                          yyval.rel.dirRel=yystack.l_mark[0].eExpr.dirExp;}
break;
case 70:
#line 614 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp,codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp,codigo);
                    append_new_quad(codigo, "+", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 71:
#line 621 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "-", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 72:
#line 628 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                	dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "*", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 73:
#line 635 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                	dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "/", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 74:
#line 642 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "%", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 75:
#line 649 "parser.y"
	{
					yyval.eExpr.dirExp = yystack.l_mark[-1].eExpr.dirExp;
                    yyval.eExpr.tipoExp = yystack.l_mark[-1].eExpr.tipoExp;
				}
break;
case 76:
#line 653 "parser.y"
	{}
break;
case 77:
#line 654 "parser.y"
	{
					yyval.eExpr.dirExp = yystack.l_mark[0].num.valor;
                    yyval.eExpr.tipoExp = yystack.l_mark[0].num.tipe;
				}
break;
case 78:
#line 658 "parser.y"
	{}
break;
case 79:
#line 659 "parser.y"
	{}
break;
case 80:
#line 662 "parser.y"
	{}
break;
case 81:
#line 664 "parser.y"
	{}
break;
case 82:
#line 665 "parser.y"
	{}
break;
case 83:
#line 666 "parser.y"
	{}
break;
case 84:
#line 668 "parser.y"
	{}
break;
case 85:
#line 669 "parser.y"
	{}
break;
case 86:
#line 671 "parser.y"
	{}
break;
case 87:
#line 672 "parser.y"
	{}
break;
case 88:
#line 674 "parser.y"
	{
					yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;
				}
break;
case 89:
#line 677 "parser.y"
	{yyval.eListARGS.listArgs = NULL;}
break;
case 90:
#line 679 "parser.y"
	{
					yyval.eListARGS.listArgs=yystack.l_mark[-2].eListARGS.listArgs;
                    ARG* argx = init_arg(yystack.l_mark[0].eExpr.tipoExp);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
                    append_new_quad(codigo,"param",yystack.l_mark[0].eExpr.dirExp," ", " ");
				}
break;
case 91:
#line 685 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].eExpr.tipoExp);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
                    append_new_quad(codigo,"param",yystack.l_mark[0].eExpr.dirExp," ", " ");
				}
break;
#line 1546 "y.tab.c"
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
