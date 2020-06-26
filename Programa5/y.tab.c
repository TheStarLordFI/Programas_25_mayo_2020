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
/*///////////////////////////Variables///////////////////////////////////////*/
int tipoGBL;
int baseGBL;
int tamTSGBL;
int address;
int funcType;
bool funcReturn;
ARGS *listaRET;
char idGBL[32];
#line 51 "parser.y"
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
		char dir[32];
		int valor;
	}exp;

	struct{
		char dir[32];
		int tipo;
		struct list_index *truelist;
		struct list_index *falselist;
	}e_b;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 117 "y.tab.c"

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
#define parametros 315
#define tipo_arg 316
#define param_arr 317
#define variable 318
#define arreglo 319
#define casos 320
#define casos2 321
#define predeterminado 322
#define variable_comp 323
#define dato_est_sim 324
#define delaraciones 325
#define FIN 326
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   12,    0,   13,    8,    8,    8,   14,    6,   15,    1,
    2,    2,    2,    2,    2,    3,    3,    9,   10,   10,
   16,   17,   11,   11,    5,    5,    4,    4,    7,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    4,    0,    0,    5,    0,    3,
    1,    1,    1,    1,    1,    4,    0,    2,    3,    0,
    0,    0,   13,    0,    1,    1,    3,    1,    0,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   11,   12,   13,   15,   14,    3,    9,
    0,    0,    7,    0,    0,    0,    0,    0,    2,    0,
    0,    0,   10,    0,   18,    0,    0,    0,    0,    0,
    0,    5,   21,    8,    4,    0,   19,    0,   16,    0,
   26,    0,    0,   28,   29,    0,   27,    0,    0,    0,
   22,    0,   23,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   23,   42,   43,   11,   44,   12,   17,   25,
   19,    2,   14,   20,   15,   38,   52,
};
static const YYINT yysindex[] = {                         0,
    0, -258, -254,    0,    0,    0,    0,    0,    0,    0,
 -269, -250,    0, -269, -290, -271, -242, -270,    0, -258,
 -241, -267,    0, -257,    0, -258, -256, -233, -296, -273,
 -271,    0,    0,    0,    0, -290,    0, -274,    0, -248,
    0, -253, -272,    0,    0, -224,    0, -258, -275, -289,
    0, -250,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   38,    0,    0, -243, -218,    0,    0,    0, -219,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
 -218,    0,    0,    0,    0, -243,    0,    0,    0, -282,
    0, -264,    0,    0,    0,    0,    0, -268,    0,    0,
    0,   38,    0,
};
static const YYINT yygindex[] = {                         0,
   26,    0,    9,    0,    0,    0,    3,  -20,   32,   16,
   -3,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 312
static const YYINT yytable[] = {                         28,
    6,    6,    3,   29,   13,   32,    4,    5,    6,    7,
    8,   18,   16,   22,   24,   26,   29,   30,    4,    5,
    6,    7,    8,   29,   31,   33,   34,   49,   35,   36,
   40,   41,   45,   46,   48,   50,   51,   24,   17,   20,
    6,   25,    6,   27,   39,   21,   37,   47,   53,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,    6,    6,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    6,
};
static const YYINT yycheck[] = {                         20,
    0,    0,  261,  286,  259,   26,  277,  278,  279,  280,
  281,  262,  282,  304,  286,  258,  258,  285,  277,  278,
  279,  280,  281,  306,  282,  282,  260,   48,  325,  303,
  305,  280,  286,  306,  259,  311,  326,    0,  282,  258,
  260,  306,  311,   18,   36,   14,   31,   45,   52,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  260,   -1,  262,  262,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  311,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 326
#define YYUNDFTOKEN 346
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
"parametros","tipo_arg","param_arr","variable","arreglo","casos","casos2",
"predeterminado","variable_comp","dato_est_sim","delaraciones","FIN",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"$$2 :",
"declaraciones : tipo $$2 lista_var PYC delaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"$$3 :",
"tipo_registro : ESTRUCT INICIO $$3 declaraciones END",
"$$4 :",
"tipo : base $$4 tipo_arreglo",
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
"$$5 :",
"$$6 :",
"funciones : DEF tipo ID $$5 LPAR argumentos RPAR INICIO declaraciones sentencias FIN $$6 funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg :",

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
#line 300 "parser.y"

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
#line 443 "y.tab.c"

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
#line 160 "parser.y"
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
#line 174 "parser.y"
	{ print_code(codigo); }
break;
case 3:
#line 176 "parser.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 176 "parser.y"
	{}
break;
case 5:
#line 177 "parser.y"
	{}
break;
case 6:
#line 178 "parser.y"
	{}
break;
case 7:
#line 180 "parser.y"
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
case 8:
#line 189 "parser.y"
	{
								print_tab_sym(tab_sym_struct);
								print_tab_type(tab_type_struct);
								tab_typeGBL = pop_tt(stack_type);
								tab_symGBL = pop_st(stack_sym);
								structDir = popPDir(stack_dir);
								address = structDir->info;
								TYP *newTYP = set_typ_struct(init_type(),"struct",0,tab_type_struct,tab_sym_struct);
								tipoGBL = append_type(tab_type_struct, newTYP);
						}
break;
case 9:
#line 200 "parser.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 10:
#line 200 "parser.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 11:
#line 202 "parser.y"
	{ 
			yyval.base = 0; }
break;
case 12:
#line 204 "parser.y"
	{ 
		  yyval.base = 1; }
break;
case 13:
#line 206 "parser.y"
	{ 
		  yyval.base = 4; }
break;
case 14:
#line 208 "parser.y"
	{ 
		  yyval.base = 2; }
break;
case 15:
#line 210 "parser.y"
	{ 
		  yyval.base = 3; }
break;
case 16:
#line 213 "parser.y"
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
case 17:
#line 222 "parser.y"
	{ yyval.base = baseGBL; }
break;
case 18:
#line 224 "parser.y"
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
case 19:
#line 235 "parser.y"
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
#line 245 "parser.y"
	{}
break;
case 21:
#line 247 "parser.y"
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
case 22:
#line 266 "parser.y"
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
						printf("Error la funcion no tiene valor de retorno\n");
					}
				}
break;
case 23:
#line 279 "parser.y"
	{}
break;
case 24:
#line 280 "parser.y"
	{}
break;
case 25:
#line 282 "parser.y"
	{ yyval.list.listArgs = yystack.l_mark[0].list.listArgs; yyval.list.num = yystack.l_mark[0].list.num; }
break;
case 26:
#line 283 "parser.y"
	{ printf("SIN ARG\n"); yyval.list.listArgs = NULL; yyval.list.num = 0; }
break;
case 27:
#line 285 "parser.y"
	{
					yyval.list.listArgs = yystack.l_mark[-2].list.listArgs;
					yyval.list.num = yystack.l_mark[-2].list.num+1;
					/*argx = init_arg($3);*/
					append_arg(yyval.list.listArgs, yystack.l_mark[0].base);
				}
break;
case 28:
#line 291 "parser.y"
	{
					yyval.list.listArgs = init_args();
                    /*argx = init_arg($1);*/
                    append_arg(yyval.list.listArgs, yystack.l_mark[0].base);
					yyval.list.num = 1;
				}
break;
case 29:
#line 298 "parser.y"
	{}
break;
#line 866 "y.tab.c"
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
