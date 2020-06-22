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
int funcType;
bool funcReturn;
char *L;
char *L1, *L2; //L temporales
char IDGBL[32];
char *estTemp;//nombre de la tabla de tipos
char *tmpEtq;
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
	    struct cadenas *cad;
	}cad;

	struct{
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
    	struct args *listArgs;//listParam
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

tipo:             base {baseGBL=$1.valorTipo;} tipo_arreglo {$$.valorTipo=$3.valorTipo;} 

base:             ENTERO{$$.valorTipo=0;} 
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

funciones:        DEF tipo ID {if(search_id_symbol(TGS,$3.lexval) == -1){
									simbol = init_sym();
									simbol = set_sym(simbol,$3.lexval,-1,$2.valorTipo,"func",NULL,TGS,TGT);
									append_sym(TGS,simbol);
									structDir = crearDir();
									structDir->info = dir;
									pushPDir(structDir,pDirecciones);
									funcType = $2.valorTipo;
									funcReturn = false;
									dir = 0;
									TS1 = init_sym_tab();
							   	  	init_type_tab(TT1);
									push_tt(pTipos,TT1);
								 	push_st(pSimbolos, TS1);
									append_new_quad(codigo,"label"," "," ",$3.lexval);
								}

					} LPAR argumentos RPAR INICIO declaraciones sentencias END{
						tmpEtq = create_label();
						backpatch(codigo,$10.nextlist,tmpEtq);
						TT1= pop_tt(pTipos);
                        TS1= pop_st(pSimbolos);
						structDir = popPDir(pDirecciones);
						dir = structDir->info;
						simbol = init_sym();
						simbol = search_SYM(pSimbolos->top,$3.lexval);
						simbol->args = $6.listArgs;

						if($2.valorTipo != 3 && funcReturn == false){
							printf("Error la funcion no tiene valor de retorno\n");
						}
					} funciones| {};
                    
argumentos:       	lista_arg{$$.listArgs=$1.listArgs;} 
					| SIN{$$.listArgs=NULL;};

lista_arg:      lista_arg COMA arg {
					$$.listArgs = $1.listArgs;
					argx = init_arg($3.valorTipo);
					append_arg($$.listArgs, argx->arg);
				}
				| arg {
					$$.listArgs = init_args();
                    ARG* argx = init_arg($1.valorTipo);
                    append_arg($$.listArgs, argx->arg);
				};

arg:            tipo_arg ID {
					if( search_id_symbol(pSimbolos->top,$2.lexval) == -1){
                          simbol = init_sym();
                          simbol= set_sym(simbol, $2.lexval, dir, typeGBL, "var", NULL,pSimbolos->top, getTopType(pTipos));
                          append_sym(pSimbolos->top,simbol);
                          dir = dir + getTam(getTopType(pTipos), typeGBL);
                    }
                    else
                      printf("El identificador ya fue declarado\n");
                    $$.valorTipo = $1.valorTipo;
				};

tipo_arg:         base param_arr {baseGBL = $1.valorTipo;};

param_arr:      LCOR RCOR param_arr{
					TYP *tp = init_type();
                    tp = set_typ(tp,"array",$3.valorTipo,getTopType(pTipos));
                    $$.valorTipo = append_type(getTopType(pTipos), tp);
				} | {$$.valorTipo=baseGBL;};

sentencias:     sentencias{
					tmpEtq=create_label();
                    backpatch(codigo,$1.nextlist,tmpEtq);
                    append_new_quad(codigo,"label"," "," ",tmpEtq);
				} sentencia {$$.nextlist=$3.nextlist;}
				| sentencia {$$.nextlist=$1.nextlist;};

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

e_bool:         e_bool OR {
					tmpEtq = create_label();
					backpatch(codigo,$1.listFalse,tmpEtq);
					append_new_quad(codigo,"label"," "," ",tmpEtq);
				} e_bool{
					$$.listTrue=combinar($1.listTrue,$4.listTrue);
					$$.listFalse=$4.listFalse;
				}
                | e_bool AND{
					tmpEtq=create_label();
					backpatch(codigo,$1.listTrue,tmpEtq);
					append_new_quad(codigo,"label"," "," ",tmpEtq);
				}
				 e_bool{
					$$.listTrue=$4.listTrue;
					$$.listFalse=combinar($1.listFalse,$4.listFalse);}
                | NOT e_bool{
					$$.listTrue=$2.listFalse;
					$$.listFalse=$2.listTrue;}
                | relacional{
					$$.listTrue=$1.listRelTrue;
					$$.listFalse=$1.listRelFalse;}
                | TRUE{
					indiceGlobal = init_index();
					$$.listFalse=init_list_index(NULL); 
					$$.listTrue=init_list_index(NULL);
					append_index($$.listTrue, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"GOTO"," "," ",tmp);}
                | FALSE{
					indiceGlobal = init_index();
					$$.listFalse=init_list_index(NULL); 
					$$.listTrue=init_list_index(NULL);
					append_index($$.listFalse, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"GOTO"," "," ",tmp);
				};

relacional:     relacional MENORQUE relacional {
					$$.listRelTrue = init_list_index(NULL);
					$$.listRelFalse = init_list_index(NULL);
					indiceGlobal = init_index();

					indiceAux = init_index();

					append_index($$.listRelTrue, indiceGlobal);
					append_index($$.listRelFalse, indiceAux);
					$$.tipoRel = max($1.tipoRel, $3.tipoRel);
					dir1 = ampliar($1.tipoRel,$$.tipoRel,$1.dirRel, codigo);
					dir2 = ampliar($3.tipoRel,$$.tipoRel,$3.dirRel, codigo);
					char *tmpIndGlobal=(char*)malloc(sizeof(char));
					char *tmpIndAux=(char*)malloc(sizeof(char));
					sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
					sprintf(tmpIndAux, "%i", indiceAux->indice);
					append_new_quad(codigo,"<", dir1, dir2, tmpIndGlobal);
					append_new_quad(codigo,"GOTO", " ", " ", tmpIndAux);
				}
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
