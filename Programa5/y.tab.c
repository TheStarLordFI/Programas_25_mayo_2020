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

#line 8 "parser_pruebas.y"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "tabla_tipos.h"
/*#include "cuadruplas.h"*/
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
/*TGT: Tabla General de Tipos, TT1: Tabla Tipos 1*/
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
/*///////////////////////////Variables doc 2020-2DDS_usr1///////////////////////////////////////*/
int dir;
char *dir1, *dir2, *dirTemp; /*Dir temporales*/
int typeGBL;
int typeTemp;
int tam;
int baseGBL;
int funcType;
bool funcReturn;
char *L, *tmpLabel;
char *L1, *L2; /*L temporales*/
char IDGBL[32];
char *estTemp;/*nombre de la tabla de tipos*/
char *tmpEtq;
#line 67 "parser_pruebas.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	int valExt;
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
	  	struct list_index *nextlist;/*listIndex*/
	}listIndice_S; 
	
	struct{
		struct list_index *prueba;/*listIndex*/
	  	struct list_index *nextlist;/*listIndex*/
	}listIndice_C; 

	struct{
		struct list_index *prueba;/*listIndex*/
	}listIndice_P;

	struct{
	   	struct list_index *listTrue; /*En la DDS viene como truelist*/
	   	struct list_index *listFalse; /*En la DDS viene como falselist*/
	}eBool;

	struct{
	    int tipoRel; /*En la DDS viene como tipo */
	    char* dirRel;/*En la DDS viene como dir*/
	    struct list_index *listRelTrue;/*En la DDS viene como truelist*/
	    struct list_index *listRelFalse;/*En la DDS viene como falselist*/
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
    	struct args *listArgs;/*listParam*/
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
#define expresion 309
#define sentencia 310
#define sentencias 311
#define e_bool 312
#define relacional 313
#define lista_param 314
#define lista_arg 315
#define argumentos 316
#define parametros 317
#define arg 318
#define tipo_arg 319
#define param_arr 320
#define variable 321
#define arreglo 322
#define funciones 323
#define casos 324
#define casos2 325
#define predeterminado 326
#define variable_comp 327
#define dato_est_sim 328
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    8,    0,    9,   10,    5,   11,   12,    5,    5,   13,
    4,   14,    1,    2,    2,    2,    2,    2,   15,    3,
    3,   16,    6,   17,    7,    7,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    0,    6,    0,    0,    6,    0,    0,
    5,    0,    3,    1,    1,    1,    1,    1,    0,    5,
    0,    0,    3,    0,    4,    0,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   14,   15,   16,   18,   17,    3,   12,
    6,    0,   10,    0,    0,    0,    2,    0,   22,    0,
    0,   13,    0,    0,    0,    4,   19,    7,   11,    0,
   23,    0,    0,    0,   24,    5,    0,    8,    0,   20,
   25,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   22,   11,   12,   20,   31,    2,   14,   32,
   16,   34,   18,   15,   33,   25,   39,
};
static const YYINT yysindex[] = {                         0,
    0, -259, -256,    0,    0,    0,    0,    0,    0,    0,
    0, -319,    0, -277, -298, -277,    0, -259,    0, -251,
 -276,    0, -250, -249, -274,    0,    0,    0,    0, -272,
    0, -259, -290, -259,    0,    0, -298,    0, -274,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0, -309,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -266,    0,    0, -237,    0,    0,
    0,    0,    0,    0, -251,    0,    0,    0,    0,    0,
    0, -260,    0, -260,    0,    0, -266,    0, -251,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -13,    0,  -17,    9,  -12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 63
static const YYINT yytable[] = {                          9,
   24,    3,   13,   17,   19,   21,   26,   28,   27,   35,
   29,   30,   37,    9,   36,   21,   38,    4,    5,    6,
    7,    8,    9,   40,   23,    0,   41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    9,
};
static const YYINT yycheck[] = {                        260,
   18,  261,  259,  323,  282,  304,  258,  258,  285,  282,
  260,  286,  303,  323,   32,  282,   34,  277,  278,  279,
  280,  281,  260,   37,   16,   -1,   39,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  323,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 328
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ERROR","PYC","INICIO","END",
"ESTRUCT","DEF","IF","THEN","WHILE","DO","SEGUN","WRITE","DEV","READ",
"TERMINAR","CASO","PRED","DOSP","FALSE","TRUE","ENTERO","REAL","DREAL","SIN",
"CAR","ID","CARACTER","CADENA","NUM","COMA","IGUAL","OR","AND","IDENTICO",
"DIFERENTE","MENORQUE","MENORIGUAL","MAYORIGUAL","MAYORQUE","MAS","MENOS","MUL",
"DIV","MODULO","NOT","PUNTO","RCOR","LCOR","LPAR","RPAR","SITEMP","SINO",
"expresion","sentencia","sentencias","e_bool","relacional","lista_param",
"lista_arg","argumentos","parametros","arg","tipo_arg","param_arr","variable",
"arreglo","funciones","casos","casos2","predeterminado","variable_comp",
"dato_est_sim",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"$$8 :",
"tipo_arreglo : LCOR NUM $$8 RCOR tipo_arreglo",
"tipo_arreglo :",
"$$9 :",
"lista_var : ID $$9 lista_var2",
"$$10 :",
"lista_var2 : COMA ID $$10 lista_var2",
"lista_var2 :",

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
#line 297 "parser_pruebas.y"
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
#line 436 "y.tab.c"

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
#line 206 "parser_pruebas.y"
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
#line 219 "parser_pruebas.y"
	{print_code(codigo);}
break;
case 3:
#line 221 "parser_pruebas.y"
	{typeGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 4:
#line 221 "parser_pruebas.y"
	{
                                                            print_tab_sym(getTopSym(pSimbolos));
                                                            print_tab_type(getTopType(pTipos));															
															}
break;
case 6:
#line 225 "parser_pruebas.y"
	{typeGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 7:
#line 225 "parser_pruebas.y"
	{
																		print_tab_sym(getTopSym(pSimbolos));
                                                            			print_tab_type(getTopType(pTipos));	
																	}
break;
case 9:
#line 229 "parser_pruebas.y"
	{}
break;
case 10:
#line 231 "parser_pruebas.y"
	{TS1 = init_sym_tab();
							   	  TT1 = init_type_tab(TT1);
								  structDir = crearDir();
								  /*structDir->info = dir;*/
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);
								}
break;
case 11:
#line 239 "parser_pruebas.y"
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
#line 249 "parser_pruebas.y"
	{baseGBL=yystack.l_mark[0].tipo.valorTipo;}
break;
case 13:
#line 249 "parser_pruebas.y"
	{yyval.tipo.valorTipo=yystack.l_mark[0].tipo.valorTipo;}
break;
case 14:
#line 252 "parser_pruebas.y"
	{
				yyval.tipo.valorTipo=0;
				printf("entero\n");
			}
break;
case 15:
#line 256 "parser_pruebas.y"
	{
				yyval.tipo.valorTipo=1;
				printf("real\n");
				}
break;
case 16:
#line 260 "parser_pruebas.y"
	{
				yyval.tipo.valorTipo=4;
				printf("dreal\n");
				}
break;
case 17:
#line 264 "parser_pruebas.y"
	{
				yyval.tipo.valorTipo=2;
				printf("car\n");
				}
break;
case 18:
#line 268 "parser_pruebas.y"
	{
				yyval.tipo.valorTipo=3;
				printf("sin\n");
				}
break;
case 19:
#line 273 "parser_pruebas.y"
	{printf("num: %s\n",yystack.l_mark[0].num.valor);}
break;
case 20:
#line 273 "parser_pruebas.y"
	{
					printf("tip_arreglo\n");
					if(yystack.l_mark[-3].num.tipe==0){
						const char *tmp=yystack.l_mark[-3].num.valor;
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
case 21:
#line 289 "parser_pruebas.y"
	{ yyval.tipo.valorTipo = baseGBL; }
break;
case 22:
#line 291 "parser_pruebas.y"
	{printf("id: %s\n", yystack.l_mark[0].id.lexval);}
break;
case 23:
#line 291 "parser_pruebas.y"
	{}
break;
case 24:
#line 293 "parser_pruebas.y"
	{"id: %s",yystack.l_mark[0].id.lexval;}
break;
case 25:
#line 293 "parser_pruebas.y"
	{}
break;
case 26:
#line 294 "parser_pruebas.y"
	{}
break;
#line 800 "y.tab.c"
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
