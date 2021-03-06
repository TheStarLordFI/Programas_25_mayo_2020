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
extern YYSTYPE yylval;
