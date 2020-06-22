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
CODE* codigo; 
ARGS *ListaArg; 
INDEX *indiceGlobal, *indiceAux; 

/////////////////////////////Variables doc 2020-2DDS_usr1///////////////////////////////////////
int dir;
int dir1, dir2, dirTemp; //Dir temporales
int typeGBL;
int typeTemp;
int tam;
int baseGBL;
char *L;
char *L1, *L2; //L temporales
char IDGBL[32];
char *estTemp;//nombre de la tabla de tipos
%}

%union{
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
	  	struct LINDEX *nextlist;//listIndex
	}listIndice_S; 
	
	struct{
		struct LINDEX *prueba;//listIndex
	  	struct LINDEX *nextlist;//listIndex
	}listIndice_C; 

	struct{
		struct LINDEX *prueba;//listIndex
	}listIndice_P;

	struct{
	   	struct LINDEX *listTrue; //En la DDS viene como truelist
	   	struct LINDEX *listFalse; //En la DDS viene como falselist
	}eBool;

	struct{
	    int tipoRel; //En la DDS viene como tipo 
	    char* dirRel;//En la DDS viene como dir
	    struct LINDEX *listRelTrue;//En la DDS viene como truelist
	    struct LINDEX *listRelFalse;//En la DDS viene como falselist
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
    	struct ARGS *listArgs;//listParam
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
	

}

%token ERROR
/*Los símbolos terminales de la gramática PARA Bison SON tokens y deben declararse en la sección de definiciones.*/
%token DEF
%token ESTRUCT
%token ENTERO REAL DREAL SIN CAR
%token CARACTER
%token<cad> CADENA
%token<num> NUM
%token<id> ID
%token IF THEN
%token DO WHILE SEGUN
%token TRUE FALSE
%token INICIO TERMINAR END
%token CASO PRED
%token WRITE READ
%token DEV
%token COMA DOSP PYC PUNTO
%left COMA
%right IGUAL
%left OR
%left AND
%left IDENTICO DIFERENTE
%left MENORQUE MENORIGUAL MAYORIGUAL MAYORQUE
%left MAS MENOS
%left MUL DIV MODULO
%right NOT

%nonassoc LPAR RPAR
%nonassoc LCOR RCOR
%nonassoc SITEMP
%nonassoc SINO

%type<tipo> tipo base
%type<tipo> tipo_arreglo
%type<eExpr> expresion
%type<listIndice_S> sentencia sentencias
%type<eBool> e_bool
%type<rel> relacional
%type<eListARGS> lista_param lista_arg
%type<eListARGS> argumentos
%type<eListARGS> parametros
%type<tipo> arg tipo_registro
%type<tipo> tipo_arg param_arr
%type<var> variable arreglo
%type declaraciones
%type lista_var
%type funciones
%type<listIndice_C> casos
%type<listIndice_P> predeterminado
%type<varComp> variable_comp
%type<datoEst> dato_est_sim

%start programa

%%
programa:        {printf("==========================P r o g r a m a==========================\n");
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
                  } declaraciones funciones {/*imprimirCodigo(codigo);*/};
				  
declaraciones:    tipo {typeGBL  = $1.valorTipo;} lista_var PYC declaraciones
                | tipo_registro {typeGBL  = $1.valorTipo;} lista_var PYC declaraciones
                | {};

tipo_registro:    ESTRUCT INICIO {TS1 = init_sym_tab();
							   	  init_type_tab(TT1);
								  structDir = crearDir();
								  structDir->info = dir;
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);} declaraciones {
									  TT1 = pop_tt(pTipos);
								      TS1 = pop_st(pSimbolos);
									  structDir = popPDir(pDirecciones);
									  dir = structDir->info;
									  TYP* newTYP= init_type();
									  newTYP = set_typ(newTYP,"reg",0,getTopType(pTipos));
									  typeTemp = append_type(getTopType(pTipos), newTYP);} END {
										  $$.valorTipo=typeTemp;
									  };

tipo:             base {baseGBL=$1.valorTipo;} tipo_arreglo {$$.valorTipo=$2.valorTipo;};

base:           ENTERO {$$.valorTipo=0;} 
                | REAL{$$.valorTipo=1;} 
                | DREAL{$$.valorTipo=4;} 
                | CAR{$$.valorTipo=2;} 
                | SIN {$$.valorTipo=3;};

tipo_arreglo: 	LCOR NUM RCOR tipo_arreglo{
					if($2.tipe==0){
                        int n = atoi($2.valor);
                                 
                        if(n>0){
                            TYP *newTYP = init_type();
                            newTYP = set_typ(newTYP,"array",$4.valorTipo,getTopType(pTipos));
                            $$.valorTipo = append_type(getTopType(pTipos), newTYP);
                        }
                        else{
                            printf("El indice tiene que ser entero y mayor que cero///////////////////////////////////");
                        }
                    }
                    else{
                        printf("El indice tiene que ser entero y mayor que cero///////////////////////////////////");
                    }
				} 
				| {};

lista_var:        lista_var COMA ID{} | ID{} ;

funciones:        DEF tipo ID LPAR argumentos RPAR INICIO declaraciones sentencias END funciones {}| {};
                    
argumentos:       lista_arg{} | SIN{} ;

lista_arg:        lista_arg COMA arg {}| arg {};

arg:              tipo_arg ID {} ;

tipo_arg:         base param_arr {};

param_arr:        LCOR RCOR param_arr{} | {};

sentencias:       sentencias sentencia {} | sentencia {};

sentencia:        IF e_bool THEN sentencia %prec SITEMP END{}                                                               
                  | IF e_bool THEN sentencia SINO sentencia END{}
                  | WHILE e_bool DO sentencia END{}
                  | DO sentencia WHILE e_bool PYC {}
                  | SEGUN LPAR variable RPAR DO casos predeterminado END{}
                  | variable IGUAL expresion PYC{}
                  | WRITE expresion PYC {}
                  | READ variable PYC{}
                  | DEV PYC{}
                  | DEV expresion PYC {}
                  | TERMINAR PYC {}
                  | INICIO sentencias END {};

casos:            CASO NUM DOSP sentencia casos2{};

casos2:           casos{} | {} ;

predeterminado:   PRED DOSP sentencia{} | {};

e_bool:           e_bool OR e_bool{}
                | e_bool AND e_bool{}
                | NOT e_bool{}
                | relacional{}
                | TRUE{}
                | FALSE{} ;

relacional:       relacional MENORQUE relacional {}
                | relacional MAYORQUE relacional {}
                | relacional MENORIGUAL relacional {}
                | relacional MAYORIGUAL relacional {}
                | relacional IDENTICO relacional {}
                | relacional DIFERENTE relacional {}
                | expresion {};

expresion:        expresion MAS expresion {}
                | expresion MENOS expresion{}
                | expresion MUL expresion {}
                | expresion DIV expresion {}
                | expresion MODULO expresion {}
                | LPAR expresion RPAR {}
                | variable{}
                | NUM{}
                | CADENA{}
                | CARACTER {};
                

variable:         ID variable_comp {};

variable_comp:    dato_est_sim{} | arreglo{} | LPAR parametros RPAR{} ;

dato_est_sim:     dato_est_sim PUNTO ID{} | {};

arreglo:           LCOR expresion RCOR{}
                 | arreglo LCOR expresion RCOR {};

parametros:        lista_param{} | {};

lista_param:       lista_param COMA expresion {}
                  | expresion {};				  


%%
void yyerror(char *msg){
	printf("%s, linea: %d, token: %s\n",msg, yylineno, yytext);
}
