/*Fecha: 19/Junio/2020*/
/*Autores: Ana Belem Méndez Cabrera, Jose Andres Rodriguez Sanchez,*/
/*		   Osmar Juarez Aguilar, Luis Angel Morales Garcia*/
/*Descripción: Archivo que genera nuestro analizador léxico,*/
/*             ambigüedad,recursividad,factorización*/
/*             terminales encontrados en nuestra gramática.*/
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "tabla_tipos.h"
//#include "cuadruplas.h"
//#include "backpatch.h"
#include "tipos.h"
#include "tabla_cadenas.h"
#include "pila_direcciones.h"

void yyerror(char *s);
extern int yylineno;
extern int yylex();
extern char* yytext;
//void print_code(struct code *c);

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
//TGT: Tabla General de Tipos, TT1: Tabla Tipos 1
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
//CODE *codigo; 
ARGS *ListaArg; 
//INDEX *indiceGlobal, *indiceAux; 
//LINDEX *prueba;
/////////////////////////////Variables doc 2020-2DDS_usr1///////////////////////////////////////
int dir;
char *dir1, *dir2, *dirTemp; //Dir temporales
int typeGBL;
int typeTemp;
int tam;
int baseGBL;
int funcType;
bool funcReturn;
char *L, *tmpLabel;
char *L1, *L2; //L temporales
char IDGBL[32];
char *estTemp;//nombre de la tabla de tipos
char *tmpEtq;
%}

%union{
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

	/*struct{
	  	struct list_index *nextlist;//listIndex
	}listIndice_S; 
	
	struct{
		struct list_index *prueba;//listIndex
	  	struct list_index *nextlist;//listIndex
	}listIndice_C; 

	struct{
		struct list_index *prueba;//listIndex
	}listIndice_P;

	struct{
	   	struct list_index *listTrue; //En la DDS viene como truelist
	   	struct list_index *listFalse; //En la DDS viene como falselist
	}eBool;

	struct{
	    int tipoRel; //En la DDS viene como tipo 
	    char* dirRel;//En la DDS viene como dir
	    struct list_index *listRelTrue;//En la DDS viene como truelist
	    struct list_index *listRelFalse;//En la DDS viene como falselist
  	}rel;*/
	
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
	
	/*struct{
    	struct args *listArgs;//listParam
  	}eListARGS;*/

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
}

%token ERROR
/*Los símbolos terminales de la gramática PARA Bison SON tokens y deben declararse en la sección de definiciones.*/
%token PYC
%token INICIO
%token END
%token ESTRUCT
%token DEF
%token IF THEN
%token WHILE 
%token DO 
%token SEGUN
%token WRITE 
%token DEV
%token READ
%token TERMINAR
%token CASO PRED
%token DOSP
%token FALSE TRUE
%token ENTERO REAL DREAL SIN CAR
%token<id> ID
%token CARACTER
%token<cad> CADENA
%token<num> NUM

//%token COMA 
%right IGUAL
%left OR
%left AND
%left IDENTICO DIFERENTE MENORQUE MENORIGUAL MAYORIGUAL MAYORQUE
%left MAS MENOS
%left MUL DIV MODULO
%right NOT

%nonassoc PUNTO COMA
%nonassoc RCOR
%nonassoc LCOR
%nonassoc LPAR RPAR
%nonassoc SITEMP
%nonassoc SINO

%type<tipo> tipo base tipo_arreglo tipo_registro
//%type<eExpr> expresion
//%type<listIndice_S> sentencia sentencias
//%type<eBool> e_bool
//%type<rel> relacional
//%type<eListARGS> lista_param lista_arg
//%type<eListARGS> argumentos
//%type<eListARGS> parametros
//%type<tipo> arg tipo_registro
//%type<tipo> tipo_arg param_arr
//%type<var> variable arreglo
%type<tipo> declaraciones lista_var lista_var2 programa 
%type funciones 
//%type<listIndice_C> casos casos2
//%type<listIndice_P> predeterminado
//%type<varComp> variable_comp
//%type<datoEst> dato_est_sim

%start programa

%%
programa:{printf("==========================P r o g r a m a==========================\n");
                  dir = 0;
                  //codigo = init_code();
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
                  } declaraciones funciones{/*print_code(codigo);*/};
				  
declaraciones:tipo {typeGBL=$1.valorTipo;} lista_var PYC{
                                                            print_tab_sym(getTopSym(pSimbolos));
                                                            print_tab_type(getTopType(pTipos));															
															} declaraciones
                | tipo_registro {typeGBL=$1.valorTipo;} lista_var PYC{
																		print_tab_sym(getTopSym(pSimbolos));
                                                            			print_tab_type(getTopType(pTipos));	
																	} declaraciones
                | {};

tipo_registro:ESTRUCT INICIO {TS1 = init_sym_tab();
							   	  TT1 = init_type_tab(TT1);
								  structDir = crearDir();
								  //structDir->info = dir;
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);
								} declaraciones END {
									TT1 = pop_tt(pTipos);
									TS1 = pop_st(pSimbolos);
									structDir = popPDir(pDirecciones);
									dir = structDir->info;
									newTYP = set_typ_struct(init_type(),"struct",0,TT1, TS1);
									typeTemp = append_type(TT1, newTYP);
									$$.valorTipo=typeTemp;
									};

tipo:base{baseGBL=$1.valorTipo;} tipo_arreglo {$$.valorTipo=$3.valorTipo;};


base:ENTERO {
				$$.valorTipo=0;
				printf("entero\n");
			} 
		| REAL {
				$$.valorTipo=1;
				printf("real\n");
				} 
		| DREAL {
				$$.valorTipo=4;
				printf("dreal\n");
				} 
		| CAR {
				$$.valorTipo=2;
				printf("car\n");
				} 
		| SIN {
				$$.valorTipo=3;
				printf("sin\n");
				};

tipo_arreglo:LCOR NUM RCOR tipo_arreglo{
								} |  { printf("arr\n"); } ;

lista_var: ID lista_var2 {};

lista_var2:COMA ID{
				printf("id %s",$2.lexval);} lista_var2{}
				| {};

funciones: {}
%%
void yyerror(char *msg){
	printf("%s, token: %s\n",msg, yytext);
}
