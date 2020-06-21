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
extern YYSTYPE yylval;
