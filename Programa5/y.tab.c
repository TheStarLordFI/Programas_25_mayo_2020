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
TYP *newTYP; 
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
#line 67 "parser.y"
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
#line 165 "y.tab.c"

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
   28,    0,   29,   30,   19,   31,   32,   19,   19,   33,
   14,   34,    1,    2,    2,    2,    2,    2,    3,    3,
   20,   21,   21,   35,   36,   22,   22,   11,   11,   10,
   10,   13,   15,   16,   16,   37,    6,    6,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
   23,   24,   24,   25,   25,   38,    7,   39,    7,    7,
    7,    7,    7,    8,    8,    8,    8,    8,    8,    8,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
   17,   26,   26,   26,   27,   27,   18,   18,   12,   12,
    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    0,    6,    0,    0,    6,    0,    0,
    5,    0,    3,    1,    1,    1,    1,    1,    4,    0,
    2,    3,    0,    0,    0,   13,    0,    1,    1,    3,
    1,    2,    2,    3,    0,    0,    3,    1,    5,    7,
    5,    5,    8,    4,    3,    3,    2,    3,    2,    3,
    5,    1,    0,    3,    0,    0,    4,    0,    4,    2,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    1,
    3,    3,    3,    3,    3,    3,    1,    1,    1,    1,
    2,    1,    1,    3,    3,    0,    3,    4,    1,    0,
    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   14,   15,   16,   18,   17,    3,   12,
    6,    0,   10,    0,    0,    0,    0,    2,    0,    0,
    0,    0,   13,    0,    0,    0,    0,   21,    4,    0,
    7,   24,   11,    0,    0,    0,    0,    0,   22,    5,
   19,    8,    0,    0,    0,    0,    0,   31,    0,    0,
   33,    0,    0,   32,    0,   30,    0,   34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   38,
    0,    0,    0,   63,   62,   80,   79,   78,    0,    0,
    0,    0,    0,   77,    0,    0,    0,    0,   47,    0,
    0,   49,    0,    0,    0,   81,    0,   25,    0,    0,
   50,   60,    0,    0,    0,    0,    0,    0,    0,   56,
   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   45,   48,   46,    0,    0,    0,    0,    0,    0,    0,
   37,    0,   76,    0,    0,   73,   74,   75,    0,    0,
    0,   68,   69,   64,   66,   67,   65,    0,    0,    0,
   87,    0,   84,    0,   85,   26,   44,   39,    0,    0,
   59,   41,   42,    0,    0,   88,    0,    0,    0,   40,
    0,    0,    0,    0,    0,   43,    0,   54,   52,   51,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   23,   81,   70,   71,   82,   83,  126,   46,
   47,  127,   48,   11,   49,   51,   84,   95,   12,   21,
   28,   18,  169,  180,  173,   96,   97,    2,   14,   35,
   16,   37,   19,   15,   38,  130,   99,  140,  141,
};
static const YYINT yysindex[] = {                         0,
    0,  -77, -252,    0,    0,    0,    0,    0,    0,    0,
    0, -248,    0, -266, -282, -266,   16,    0,  -77, -262,
 -230, -228,    0, -225, -214, -184, -198,    0,    0, -218,
    0,    0,    0, -262,  -77, -282,  -77, -213,    0,    0,
    0,    0,   36,    0, -207, -187, -211,    0, -179, -190,
    0,   16, -145,    0, -207,    0,  -77,    0,  -76,  -76,
  -27,  -27,  -76, -189, -124, -245, -167, -140, -286,    0,
 -120, -146, -116,    0,    0,    0,    0,    0,  -27, -124,
  -46, -254,   72,    0, -246, -119, -167, -217,    0, -191,
 -111,    0, -124, -124, -142,    0, -138,    0,  -76, -124,
    0,    0, -143, -124, -124, -124, -124, -124,  -76,    0,
    0, -124, -124, -124, -124, -124, -124,  -76,  -27, -110,
    0,    0,    0,  -57,  -46,  -89, -108, -124,  -58, -248,
    0, -148,    0, -209, -209,    0,    0,    0, -258,  -27,
  -27,    0,    0,    0,    0,    0,    0,  -34, -237,  -43,
    0, -124,    0,  -12,    0,    0,    0,    0,  -76,  -44,
    0,    0,    0,  -13,  -46,    0,    2,  -10,    4,    0,
    6,    8,   29,  -76,  -76,    0,  -13,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  276,    0,    0, -266,    0,    0,    0,   30,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   41,    1, -266,    1,    0,    0,    0,
    0,    0,    0, -229,   20,   13,    0,    0,    0,    0,
    0,    0,    0,    0,   20,    0,   71,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -164,    0,
   89,    0,   89,    0,    0,    0,    0,    0,    0,    0,
   34,    0, -241,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   14, -121,    0,  -78,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -208,   25,    0,    0,    0,  276,
    0,    0,    0,  -59,   15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -202,
    0,    0,    0,    0, -185,    0,    0,    0,   73,    0,
    0,    0,    0,    0,    0,    0, -199,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  315,  -37,  299,  -35,  -63,  283,  -53,  260,    0,    0,
    0,    0,  292,    0,    0,  290,  -55,    0,   -8,  330,
  313,  219,  173,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 377
static const YYINT yytable[] = {                         86,
    9,  158,    9,   72,   72,   45,   13,   72,   85,  109,
   26,   91,   89,   17,   45,   20,   61,   93,   94,  118,
  163,   22,   61,   27,   61,  102,   40,   29,   42,   88,
   90,  120,   31,  110,  111,  131,   69,   76,   77,   78,
  121,  110,  111,   72,  103,  139,   61,   61,   59,  159,
  110,  111,   18,   72,  148,   57,   30,  124,  125,   80,
   53,   57,   72,   57,  132,  149,  122,   32,  134,  135,
  136,  137,  138,   53,   18,   33,   29,   92,  104,  105,
  106,  107,  108,   34,   36,   57,  160,  161,  106,  107,
  108,   43,  154,   86,   53,  167,   50,   92,   52,   86,
   91,   86,   54,   72,  104,  105,  106,  107,  108,  157,
  177,  178,   55,   57,   69,   87,  165,   92,   72,   72,
   91,   86,   86,   86,   86,   86,   86,   86,   86,   86,
   86,   86,   86,   86,   86,   86,   83,   86,   86,   98,
  100,   86,   83,  101,   83,  119,  123,  104,  105,  106,
  107,  108,  104,  105,  106,  107,  108,   69,   76,   77,
   78,  128,  133,  129,   83,   83,   83,   83,   83,   83,
   83,   83,   83,   83,   83,   83,   83,   83,   83,   82,
   80,   83,   60,    3,   83,   82,   61,   82,   62,   63,
   64,   65,   66,   67,   68,  150,  152,  153,   71,    4,
    5,    6,    7,    8,   71,   69,   71,   82,   82,   82,
   82,   82,   82,   82,   82,   82,   82,   82,   82,   82,
   82,   82,  164,  155,   82,  162,   71,   82,   71,   71,
   71,   71,   71,   71,   71,   71,   71,   71,  104,  105,
  106,  107,  108,   71,  111,  151,   71,   74,   75,  104,
  105,  106,  107,  108,   69,   76,   77,   78,  168,    9,
    9,  170,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,   72,   79,  171,   27,  172,   80,   72,  174,
   72,  175,    9,  104,  105,  106,  107,  108,  176,    9,
  166,   70,    4,    5,    6,    7,    8,   70,   23,   70,
   72,   35,   72,   72,   72,   72,   72,   72,   72,   72,
   72,   72,    4,    5,    6,   44,    8,   72,   28,   90,
   72,   70,   70,   70,   70,   70,   70,   70,   70,    9,
   89,   25,   55,    9,   41,    9,    9,    9,    9,    9,
    9,    9,   73,   56,   58,   24,   39,   36,  156,  179,
    0,   36,    9,   36,   36,   36,   36,   36,   36,   36,
    0,  112,  113,  114,  115,  116,  117,    0,    0,    0,
   36,  142,  143,  144,  145,  146,  147,
};
static const YYINT yycheck[] = {                         63,
    0,  260,    0,   59,   60,   43,  259,   63,   62,  264,
   19,   67,  258,  262,   52,  282,  258,  304,  305,  266,
  258,  304,  264,  286,  266,   79,   35,  258,   37,   65,
   66,   87,  258,  288,  289,   99,  282,  283,  284,  285,
  258,  288,  289,   99,   80,  109,  288,  289,   57,  308,
  288,  289,  282,  109,  118,  258,  285,   93,   94,  305,
  260,  264,  118,  266,  100,  119,  258,  282,  104,  105,
  106,  107,  108,  273,  304,  260,  306,  286,  296,  297,
  298,  299,  300,  282,  303,  288,  140,  141,  298,  299,
  300,  305,  128,  258,  306,  159,  304,  306,  286,  264,
  286,  266,  282,  159,  296,  297,  298,  299,  300,  258,
  174,  175,  303,  259,  282,  305,  152,  258,  174,  175,
  306,  286,  287,  288,  289,  290,  291,  292,  293,  294,
  295,  296,  297,  298,  299,  300,  258,  302,  303,  260,
  287,  306,  264,  260,  266,  265,  258,  296,  297,  298,
  299,  300,  296,  297,  298,  299,  300,  282,  283,  284,
  285,  304,  306,  302,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  258,
  305,  303,  259,  261,  306,  264,  263,  266,  265,  266,
  267,  268,  269,  270,  271,  306,  286,  306,  258,  277,
  278,  279,  280,  281,  264,  282,  266,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  266,  282,  303,  260,  286,  306,  288,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  296,  297,
  298,  299,  300,  303,  289,  303,  306,  275,  276,  296,
  297,  298,  299,  300,  282,  283,  284,  285,  272,  259,
  260,  260,  262,  263,  262,  265,  266,  267,  268,  269,
  270,  271,  258,  301,  285,    0,  273,  305,  264,  274,
  266,  274,  282,  296,  297,  298,  299,  300,  260,  260,
  303,  258,  277,  278,  279,  280,  281,  264,  258,  266,
  286,  282,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  277,  278,  279,  280,  281,  303,  306,  306,
  306,  288,  289,  290,  291,  292,  293,  294,  295,  259,
  306,   17,  260,  263,   36,  265,  266,  267,  268,  269,
  270,  271,   60,   52,   55,   16,   34,  259,  130,  177,
   -1,  263,  282,  265,  266,  267,  268,  269,  270,  271,
   -1,  290,  291,  292,  293,  294,  295,   -1,   -1,   -1,
  282,  112,  113,  114,  115,  116,  117,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 350
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"$$2 :",
"$$3 :",
"declaraciones : tipo $$2 lista_var PYC $$3 declaraciones",
"$$4 :",
"$$5 :",
"declaraciones : tipo_registro $$4 lista_var PYC $$5 declaraciones",
"declaraciones :",
"$$6 :",
"tipo_registro : ESTRUCT INICIO $$6 declaraciones END",
"$$7 :",
"tipo : base $$7 tipo_arreglo",
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
#line 733 "parser.y"

void yyerror(char *msg){
	printf("%s, token: %s\n",msg, yytext);
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
#line 600 "y.tab.c"

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
#line 208 "parser.y"
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
                  push_st(pSimbolos,TGS);
                  push_tt(pTipos,TGT);
                  tabCadenas = crearTablaCadenas();
                  }
break;
case 2:
#line 221 "parser.y"
	{print_code(codigo);}
break;
case 3:
#line 223 "parser.y"
	{typeGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 4:
#line 223 "parser.y"
	{
                                                            print_tab_sym(getTopSym(pSimbolos));
                                                            print_tab_type(getTopType(pTipos));															
															}
break;
case 6:
#line 227 "parser.y"
	{typeGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 7:
#line 227 "parser.y"
	{
																		print_tab_sym(getTopSym(pSimbolos));
                                                            			print_tab_type(getTopType(pTipos));	
																	}
break;
case 9:
#line 231 "parser.y"
	{}
break;
case 10:
#line 233 "parser.y"
	{TS1 = init_sym_tab();
							   	  TT1 = init_type_tab(TT1);
								  structDir = crearDir();
								  /*structDir->info = dir;*/
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);}
break;
case 11:
#line 240 "parser.y"
	{
									TT1 = pop_tt(pTipos);
									TS1 = pop_st(pSimbolos);
									structDir = popPDir(pDirecciones);
									dir = structDir->info;
									newTYP = set_typ_struct(init_type(),"struct",0,TT1, TS1);
									typeTemp = append_type(TT1, newTYP);
									yyval.tipo.valorTipo=typeTemp;
									}
break;
case 12:
#line 250 "parser.y"
	{baseGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 13:
#line 250 "parser.y"
	{yyval.tipo.valorTipo=yystack.l_mark[0].tipo.valorTipo;}
break;
case 14:
#line 252 "parser.y"
	{
				yyval.tipo.valorTipo=0;
				printf("Tipo entero\n");
			}
break;
case 15:
#line 256 "parser.y"
	{
				yyval.tipo.valorTipo=1;}
break;
case 16:
#line 258 "parser.y"
	{
				yyval.tipo.valorTipo=4;}
break;
case 17:
#line 260 "parser.y"
	{
				yyval.tipo.valorTipo=2;}
break;
case 18:
#line 262 "parser.y"
	{
				yyval.tipo.valorTipo=3;}
break;
case 19:
#line 265 "parser.y"
	{
				printf("prueba tipo_arreglo\n");
				if(yystack.l_mark[-2].num.tipe==0){
					const char *tmp=yystack.l_mark[-2].num.valor;
					int n = atoi(tmp);		
					if(n>0){
						newTYP = init_type();
						newTYP = set_typ(newTYP,"array",yystack.l_mark[0].tipo.valorTipo,n*getTam(getTopType(pTipos),yystack.l_mark[0].tipo.valorTipo),getTopType(pTipos));
						yyval.tipo.valorTipo = append_type(getTopType(pTipos), newTYP);
					}
					else{
						printf("El tam del arreglo tiene que ser entero y mayor que cero\n");
					}
				}else{
					printf("El tam del arreglo tiene que ser entero y mayor que cero\n");
				}
				}
break;
case 20:
#line 281 "parser.y"
	{yyval.tipo.valorTipo=baseGBL;}
break;
case 21:
#line 283 "parser.y"
	{
							printf("Agregando var\n");
							if( search_id_symbol(getTopSym(pSimbolos),yystack.l_mark[-1].id.lexval) == -1){
								simbol = init_sym();
								simbol = set_sym(simbol, yystack.l_mark[-1].id.lexval, dir, typeGBL, "var", NULL, pSimbolos->top, getTopType(pTipos));
								append_sym(pSimbolos->top,simbol);
								dir = dir + getTam(getTopType(pTipos), typeGBL);
							}
							else{
								printf("El identificador ya fue declarado\n");
							}
				}
break;
case 22:
#line 296 "parser.y"
	{
									printf("Agregando var\n");
									if( search_id_symbol(getTopSym(pSimbolos),yystack.l_mark[-1].id.lexval) == -1){
										simbol = init_sym(); 
										simbol=set_sym(simbol, yystack.l_mark[-1].id.lexval, dir, typeGBL, "var", NULL, pSimbolos->top, getTopType(pTipos));
										append_sym(pSimbolos->top,simbol);
										dir = dir + getTam(getTopType(pTipos), typeGBL);
									}
									else{
										printf("El identificador ya fue declarado\n");
									}  
							}
break;
case 23:
#line 308 "parser.y"
	{}
break;
case 24:
#line 310 "parser.y"
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
case 25:
#line 327 "parser.y"
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
case 27:
#line 341 "parser.y"
	{}
break;
case 28:
#line 343 "parser.y"
	{yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;}
break;
case 29:
#line 344 "parser.y"
	{yyval.eListARGS.listArgs=NULL;}
break;
case 30:
#line 346 "parser.y"
	{
					yyval.eListARGS.listArgs = yystack.l_mark[-2].eListARGS.listArgs;
					argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
					append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 31:
#line 351 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].tipo.valorTipo);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
				}
break;
case 32:
#line 357 "parser.y"
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
case 33:
#line 369 "parser.y"
	{baseGBL = yystack.l_mark[-1].tipo.valorTipo;}
break;
case 34:
#line 371 "parser.y"
	{
					TYP *tp = init_type();
					/*newTYP = set_typ(init_type(),"array",$4.valorTipo,n*getTam(getTopType(pTipos),$4.valorTipo),getTopType(pTipos));*/
                    tp = set_typ(tp,"array",yystack.l_mark[0].tipo.valorTipo,0,getTopType(pTipos));
                    yyval.tipo.valorTipo = append_type(getTopType(pTipos), tp);
				}
break;
case 35:
#line 376 "parser.y"
	{yyval.tipo.valorTipo=baseGBL;}
break;
case 36:
#line 378 "parser.y"
	{
					tmpEtq=create_label();
                    backpatch(codigo,yystack.l_mark[0].listIndice_S.nextlist,tmpEtq);
                    append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 37:
#line 382 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 38:
#line 383 "parser.y"
	{yyval.listIndice_S.nextlist=yystack.l_mark[0].listIndice_S.nextlist;}
break;
case 39:
#line 385 "parser.y"
	{tmpLabel=create_label();
												backpatch(codigo,yystack.l_mark[-3].eBool.listTrue,tmpLabel);
												append_new_quad(codigo,"label","-","-",tmpLabel);
												yyval.listIndice_S.nextlist=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[-1].listIndice_S.nextlist);
											    }
break;
case 40:
#line 390 "parser.y"
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
case 41:
#line 399 "parser.y"
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
case 42:
#line 412 "parser.y"
	{tmpLabel=create_label();
												   backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpLabel);
												   yyval.listIndice_S.nextlist=yystack.l_mark[-1].eBool.listFalse;
													}
break;
case 43:
#line 416 "parser.y"
	{
					  												int i;
																	L1=create_label();
																	prueba = combinar(yystack.l_mark[-2].listIndice_C.prueba, yystack.l_mark[-1].listIndice_P.prueba);
																	backpatch(codigo,yystack.l_mark[-2].listIndice_C.nextlist,L1);
																	sustituir("??",yystack.l_mark[-5].var.idVar,prueba,codigo);
																	}
break;
case 44:
#line 423 "parser.y"
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
case 45:
#line 443 "parser.y"
	{
									append_new_quad(codigo,"print",yystack.l_mark[-1].eExpr.dirExp,"-","-");
									yyval.listIndice_S.nextlist = NULL;
								}
break;
case 46:
#line 447 "parser.y"
	{
									append_new_quad(codigo,"scan","-","-",yystack.l_mark[-1].var.idVar); 
									yyval.listIndice_S.nextlist = NULL;
								}
break;
case 47:
#line 451 "parser.y"
	{	
						if(funcType==3){
							append_new_quad(codigo,"return","-","-","-");
						}else{
							printf("la funcion debe retornar  algun valor de tipo ==> %d",funcType);
						}
						yyval.listIndice_S.nextlist=NULL;
					}
break;
case 48:
#line 459 "parser.y"
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
case 49:
#line 469 "parser.y"
	{	
					  				indiceGlobal = init_index();
									char *tmp3=(char*)malloc(sizeof(char));
									sprintf(tmp3, "%i", indiceGlobal->indice);
									append_new_quad(codigo, "goto", "-", "-", tmp3);
									yyval.listIndice_S.nextlist = init_list_index(indiceGlobal);
									append_index(yyval.listIndice_S.nextlist, indiceGlobal);
								}
break;
case 50:
#line 477 "parser.y"
	{ 
					  						yyval.listIndice_S.nextlist=yystack.l_mark[-1].listIndice_S.nextlist;
										}
break;
case 51:
#line 481 "parser.y"
	{
										yyval.listIndice_C.nextlist = combinar(yyval.listIndice_C.nextlist, yystack.l_mark[-1].listIndice_S.nextlist);
										char *label_C = create_label();
										/*Indica el inicio del código para la sentencia*/
										yyval.listIndice_C.prueba = yystack.l_mark[0].listIndice_C.prueba;
										/*sustituir_c()*/
										/*(if ”??” ”==” num.dir ”goto” L )*/
									}
break;
case 52:
#line 490 "parser.y"
	{
						/*casos.prueba = newCode()*/
						char *LT = create_label();
						/*Indica el inicio del código para la sentencia*/
						/*genCode(”label” L)*/
						/*casos.prueba.append(if ”??” ”==” num.dir ”goto” L )*/
						}
break;
case 53:
#line 497 "parser.y"
	{}
break;
case 54:
#line 499 "parser.y"
	{
									/*predeterminado.prueba = newCode()*/
									char *lll = create_label();
									/*Indica el inicio del código para la sentencia*/
									/*genCode(”label” L)*/
									/*predeterminado.prueba.append(”goto” L )*/
									}
break;
case 55:
#line 505 "parser.y"
	{}
break;
case 56:
#line 507 "parser.y"
	{
					tmpEtq = create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listFalse,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 57:
#line 511 "parser.y"
	{
					yyval.eBool.listTrue=combinar(yystack.l_mark[-3].eBool.listTrue,yystack.l_mark[0].eBool.listTrue);
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listFalse;
				}
break;
case 58:
#line 515 "parser.y"
	{
					tmpEtq=create_label();
					backpatch(codigo,yystack.l_mark[-1].eBool.listTrue,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				}
break;
case 59:
#line 520 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listTrue;
					yyval.eBool.listFalse=combinar(yystack.l_mark[-3].eBool.listFalse,yystack.l_mark[0].eBool.listFalse);}
break;
case 60:
#line 523 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].eBool.listFalse;
					yyval.eBool.listFalse=yystack.l_mark[0].eBool.listTrue;}
break;
case 61:
#line 526 "parser.y"
	{
					yyval.eBool.listTrue=yystack.l_mark[0].rel.listRelTrue;
					yyval.eBool.listFalse=yystack.l_mark[0].rel.listRelFalse;}
break;
case 62:
#line 529 "parser.y"
	{
					indiceGlobal = init_index();
					yyval.eBool.listFalse=init_list_index(NULL); 
					yyval.eBool.listTrue=init_list_index(NULL);
					append_index(yyval.eBool.listTrue, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"goto","-","-",tmp);}
break;
case 63:
#line 537 "parser.y"
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
case 64:
#line 547 "parser.y"
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
case 65:
#line 566 "parser.y"
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
case 66:
#line 583 "parser.y"
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
case 67:
#line 600 "parser.y"
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
case 68:
#line 617 "parser.y"
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
case 69:
#line 634 "parser.y"
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
case 70:
#line 651 "parser.y"
	{yyval.rel.tipoRel=yystack.l_mark[0].eExpr.tipoExp;
	                          yyval.rel.dirRel=yystack.l_mark[0].eExpr.dirExp;}
break;
case 71:
#line 654 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp,codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp,codigo);
                    append_new_quad(codigo, "+", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 72:
#line 661 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "-", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 73:
#line 668 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                	dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "*", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 74:
#line 675 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                	dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "/", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 75:
#line 682 "parser.y"
	{
					yyval.eExpr.tipoExp = max(yystack.l_mark[-2].eExpr.tipoExp, yystack.l_mark[0].eExpr.tipoExp);
                    yyval.eExpr.dirExp = newTemp();
                    dir1 = ampliar(yystack.l_mark[-2].eExpr.dirExp,yystack.l_mark[-2].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    dir2 = ampliar(yystack.l_mark[0].eExpr.dirExp,yystack.l_mark[0].eExpr.tipoExp,yyval.eExpr.tipoExp, codigo);
                    append_new_quad(codigo, "%", dir1, dir2,yyval.eExpr.dirExp);
				}
break;
case 76:
#line 689 "parser.y"
	{
					yyval.eExpr.dirExp = yystack.l_mark[-1].eExpr.dirExp;
                    yyval.eExpr.tipoExp = yystack.l_mark[-1].eExpr.tipoExp;
				}
break;
case 77:
#line 693 "parser.y"
	{}
break;
case 78:
#line 694 "parser.y"
	{
					yyval.eExpr.dirExp = yystack.l_mark[0].num.valor;
                    yyval.eExpr.tipoExp = yystack.l_mark[0].num.tipe;
				}
break;
case 79:
#line 698 "parser.y"
	{}
break;
case 80:
#line 699 "parser.y"
	{}
break;
case 81:
#line 702 "parser.y"
	{}
break;
case 82:
#line 704 "parser.y"
	{}
break;
case 83:
#line 705 "parser.y"
	{}
break;
case 84:
#line 706 "parser.y"
	{}
break;
case 85:
#line 708 "parser.y"
	{}
break;
case 86:
#line 709 "parser.y"
	{}
break;
case 87:
#line 711 "parser.y"
	{}
break;
case 88:
#line 712 "parser.y"
	{}
break;
case 89:
#line 714 "parser.y"
	{
					yyval.eListARGS.listArgs=yystack.l_mark[0].eListARGS.listArgs;
				}
break;
case 90:
#line 717 "parser.y"
	{yyval.eListARGS.listArgs = NULL;}
break;
case 91:
#line 719 "parser.y"
	{
					yyval.eListARGS.listArgs=yystack.l_mark[-2].eListARGS.listArgs;
                    ARG* argx = init_arg(yystack.l_mark[0].eExpr.tipoExp);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
                    append_new_quad(codigo,"param",yystack.l_mark[0].eExpr.dirExp," ", " ");
				}
break;
case 92:
#line 725 "parser.y"
	{
					yyval.eListARGS.listArgs = init_args();
                    ARG* argx = init_arg(yystack.l_mark[0].eExpr.tipoExp);
                    append_arg(yyval.eListARGS.listArgs, argx->arg);
                    append_new_quad(codigo,"param",yystack.l_mark[0].eExpr.dirExp," ", " ");
				}
break;
#line 1575 "y.tab.c"
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
