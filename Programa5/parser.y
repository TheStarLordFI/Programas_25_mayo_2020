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
CODE *codigo; 
ARGS *ListaArg; 
INDEX *indiceGlobal, *indiceAux; 
LINDEX *prueba;
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
    	char *idVar;
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

%token COMA 
%right IGUAL
%left OR
%left AND
%left IDENTICO DIFERENTE MENORQUE MENORIGUAL MAYORIGUAL MAYORQUE
%left MAS MENOS
%left MUL DIV MODULO
%right NOT

%nonassoc PUNTO
%nonassoc RCOR 
%nonassoc LCOR 
%nonassoc LPAR RPAR
%nonassoc SITEMP
%nonassoc SINO

%type<tipo> tipo base tipo_arreglo
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
%type lista_var2
%type funciones
%type<listIndice_C> casos casos2
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
                  TGT = init_type_tab(TGT);
				  printf(">>>>>>Tabla general de tipos>>>>>>\n");
				  print_tab_type(TGT);
                  TGS = init_sym_tab();
                  push_st(pSimbolos,TGS);
                  push_tt(pTipos,TGT);
                  tabCadenas = crearTablaCadenas();
                  } declaraciones funciones{print_code(codigo);};
				  
declaraciones:    tipo {typeGBL=$1.valorTipo;} lista_var PYC{
                                                            print_tab_sym(getTopSym(pSimbolos));
                                                            print_tab_type(getTopType(pTipos));															
															} declaraciones
                | tipo_registro {typeGBL=$1.valorTipo;} lista_var PYC{
																		print_tab_sym(getTopSym(pSimbolos));
                                                            			print_tab_type(getTopType(pTipos));	
																	} declaraciones
                | {};

tipo_registro:    ESTRUCT INICIO {TS1 = init_sym_tab();
							   	  TT1 = init_type_tab(TT1);
								  structDir = crearDir();
								  //structDir->info = dir;
								  pushPDir(structDir, pDirecciones);
								  dir = 0;
								  push_tt(pTipos,TT1);
								  push_st(pSimbolos, TS1);} declaraciones END {
									TT1 = pop_tt(pTipos);
									TS1 = pop_st(pSimbolos);
									structDir = popPDir(pDirecciones);
									dir = structDir->info;
									newTYP = set_typ_struct(init_type(),"struct",0,TT1, TS1);
									typeTemp = append_type(TT1, newTYP);
									$$.valorTipo=typeTemp;
									};

tipo:             base{baseGBL=$1.valorTipo;} tipo_arreglo {$$.valorTipo=$3.valorTipo;};

base:   ENTERO{
				$$.valorTipo=0;
				printf("Tipo entero\n");
			} 
		| REAL{
				$$.valorTipo=1;} 
		| DREAL{
				$$.valorTipo=4;} 
		| CAR{
				$$.valorTipo=2;} 
		| SIN {
				$$.valorTipo=3;};

tipo_arreglo:	LCOR NUM RCOR tipo_arreglo {
					if($2.tipe==0){
						const char *tmp=$2.valor;
						int n = atoi(tmp);		
						if(n>0){
							newTYP = init_type();
							newTYP = set_typ(newTYP,"array",$4.valorTipo,n*getTam(getTopType(pTipos),$4.valorTipo),getTopType(pTipos));
							$$.valorTipo = append_type(getTopType(pTipos), newTYP);
						}
						else{
							printf("El tam del arreglo tiene que ser entero y mayor que cero\n");
						}
					}else{
						printf("El tam del arreglo tiene que ser entero y mayor que cero\n");
					}
				} | {$$.valorTipo=baseGBL;} ;

lista_var:		ID lista_var2{
							if( search_id_symbol(getTopSym(pSimbolos),$1.lexval) == -1){
								simbol = init_sym();
								simbol = set_sym(simbol, $1.lexval, dir, typeGBL, "var", NULL, pSimbolos->top, getTopType(pTipos));
								append_sym(pSimbolos->top,simbol);
								dir = dir + getTam(getTopType(pTipos), typeGBL);
							}
							else{
								printf("El identificador ya fue declarado\n");
							}
				};

lista_var2: 	COMA ID lista_var2{
									printf("Agregando var\n");
									if( search_id_symbol(getTopSym(pSimbolos),$2.lexval) == -1){
										simbol = init_sym(); 
										simbol=set_sym(simbol, $2.lexval, dir, typeGBL, "var", NULL, pSimbolos->top, getTopType(pTipos));
										append_sym(pSimbolos->top,simbol);
										dir = dir + getTam(getTopType(pTipos), typeGBL);
									}
									else{
										printf("El identificador ya fue declarado\n");
									}  
							}
				| {};

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
							   	  	TT1 = init_type_tab(TT1);
									push_tt(pTipos,TT1);
								 	push_st(pSimbolos, TS1);
									append_new_quad(codigo,"label","-","-",$3.lexval);
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
					//newTYP = set_typ(init_type(),"array",$4.valorTipo,n*getTam(getTopType(pTipos),$4.valorTipo),getTopType(pTipos));
                    tp = set_typ(tp,"array",$3.valorTipo,0,getTopType(pTipos));
                    $$.valorTipo = append_type(getTopType(pTipos), tp);
				} | {$$.valorTipo=baseGBL;};

sentencias:     sentencias{
					tmpEtq=create_label();
                    backpatch(codigo,$1.nextlist,tmpEtq);
                    append_new_quad(codigo,"label","-","-",tmpEtq);
				} sentencia {$$.nextlist=$3.nextlist;}
				| sentencia {$$.nextlist=$1.nextlist;};

sentencia:        IF e_bool THEN sentencia END {tmpLabel=create_label();
												backpatch(codigo,$2.listTrue,tmpLabel);
												append_new_quad(codigo,"label","-","-",tmpLabel);
												$$.nextlist=combinar($2.listFalse,$4.nextlist);
											    }
                  | IF e_bool THEN sentencia SINO sentencia END{
															tmpLabel=create_label();
															backpatch(codigo,$2.listTrue,tmpLabel);
															append_new_quad(codigo,"label","-","-",tmpLabel);
															tmpLabel=create_label();
															backpatch(codigo,$2.listFalse,tmpLabel);
															append_new_quad(codigo,"label","-","-",tmpLabel);
															$$.nextlist=combinar($4.nextlist,$6.nextlist);
															}
                  | WHILE e_bool DO sentencia END{
													L1=create_label();
													L2=create_label();
													backpatch(codigo,$4.nextlist,L1);
													backpatch(codigo,$2.listTrue,L2);
													$$.nextlist=$2.listFalse;
													append_new_quad(codigo,"label","-","-",L1);
													append_new_quad(codigo,"label","-","-",L2);
													char *L_nextList = create_label();
													backpatch(codigo,$4.nextlist,L_nextList);
													append_new_quad(codigo,"goto","-","-",L_nextList);
												}

                  | DO sentencia WHILE e_bool PYC {tmpLabel=create_label();
												   backpatch(codigo,$4.listTrue,tmpLabel);
												   $$.nextlist=$4.listFalse;
													}
                  | SEGUN LPAR variable RPAR DO casos predeterminado END{
					  												int i;
																	L1=create_label();
																	prueba = combinar($6.prueba, $7.prueba);
																	backpatch(codigo,$6.nextlist,L1);
																	sustituir("??",$3.idVar,prueba,codigo);
																	}
                  | variable IGUAL expresion PYC{
										if((search_id_symbol(getTopSym(pSimbolos),$1.idVar) != -1) || (search_id_symbol(TGS,$1.idVar) != -1 )){
											simbol = init_sym();
											simbol=search_SYM(getTopSym(pSimbolos),$1.idVar);
											if(simbol==NULL){
												simbol=search_SYM(TGS,$1.idVar);
											}
											dir1=reducir($3.dirExp,$3.tipoExp,simbol->tipo,codigo);
											char *tmp=(char*)malloc(sizeof(char));
											char *tmp2=(char*)malloc(sizeof(char));
											sprintf(tmp, "%i", simbol->dir);
											strcpy(tmp2,$1.idVar);
											strcat(tmp2,"+");
											strcat(tmp2,tmp);
											append_new_quad(codigo,"=",dir1,"-",tmp2);
										}else{
											printf("Error => El idntificador  no se ha declarado\n");
										}
										$$.nextlist=NULL;
									}
					| WRITE expresion PYC{
									append_new_quad(codigo,"print",$2.dirExp,"-","-");
									$$.nextlist = NULL;
								}
                  | READ variable PYC{
									append_new_quad(codigo,"scan","-","-",$2.idVar); 
									$$.nextlist = NULL;
								}
				  | DEV PYC {	
						if(funcType==3){
							append_new_quad(codigo,"return","-","-","-");
						}else{
							printf("la funcion debe retornar  algun valor de tipo ==> %d",funcType);
						}
						$$.nextlist=NULL;
					}
                  | DEV expresion PYC { 
					  					if(funcType!=3){
											dir1= reducir($2.dirExp,$2.tipoExp,funcType,codigo);
											append_new_quad(codigo,"return",$2.dirExp,"-","-");
											funcReturn=true;
										}else{
                    						 printf("la funcion debe retornar  algun valor de tipo ==>%d",funcType);
                      					}
										$$.nextlist=NULL;
									}
                  | TERMINAR PYC {	
					  				indiceGlobal = init_index();
									char *tmp3=(char*)malloc(sizeof(char));
									sprintf(tmp3, "%i", indiceGlobal->indice);
									append_new_quad(codigo, "goto", "-", "-", tmp3);
									$$.nextlist = init_list_index(indiceGlobal);
									append_index($$.nextlist, indiceGlobal);
								}
                  | INICIO sentencias END { 
					  						$$.nextlist=$2.nextlist;
										};
				  
casos:            CASO NUM DOSP sentencia casos2{
										$$.nextlist = combinar($$.nextlist, $4.nextlist);
										char *label_C = create_label();
										/*Indica el inicio del código para la sentencia*/
										$$.prueba = $5.prueba;
										//sustituir_c()
										//(if ”??” ”==” num.dir ”goto” L )
									};

casos2:           casos{
						//casos.prueba = newCode()
						char *LT = create_label();
						/*Indica el inicio del código para la sentencia*/
						//genCode(”label” L)
						//casos.prueba.append(if ”??” ”==” num.dir ”goto” L )
						} 
				| {};

predeterminado:   PRED DOSP sentencia{
									//predeterminado.prueba = newCode()
									char *lll = create_label();
									/*Indica el inicio del código para la sentencia*/
									//genCode(”label” L)
									//predeterminado.prueba.append(”goto” L )
									} | {};

e_bool:         e_bool OR {
					tmpEtq = create_label();
					backpatch(codigo,$1.listFalse,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
				} e_bool{
					$$.listTrue=combinar($1.listTrue,$4.listTrue);
					$$.listFalse=$4.listFalse;
				}
                | e_bool AND{
					tmpEtq=create_label();
					backpatch(codigo,$1.listTrue,tmpEtq);
					append_new_quad(codigo,"label","-","-",tmpEtq);
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
					append_new_quad(codigo,"goto","-","-",tmp);}
                | FALSE{
					indiceGlobal = init_index();
					$$.listFalse=init_list_index(NULL); 
					$$.listTrue=init_list_index(NULL);
					append_index($$.listFalse, indiceGlobal);
					char *tmp=(char*)malloc(sizeof(char));
					sprintf(tmp, "%i", indiceGlobal->indice);
					append_new_quad(codigo,"goto","-","-",tmp);
				};

relacional:     relacional MENORQUE relacional {
					$$.listRelTrue = init_list_index(NULL);
					$$.listRelFalse = init_list_index(NULL);
					indiceGlobal = init_index();

					indiceAux = init_index();

					append_index($$.listRelTrue, indiceGlobal);
					append_index($$.listRelFalse, indiceAux);
					$$.tipoRel = max($1.tipoRel, $3.tipoRel);
					dir1 = ampliar($1.dirRel,$1.tipoRel,$$.tipoRel, codigo);
					dir2 = ampliar($3.dirRel,$3.tipoRel,$$.tipoRel, codigo);
					char *tmpIndGlobal=(char*)malloc(sizeof(char));
					char *tmpIndAux=(char*)malloc(sizeof(char));
					sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
					sprintf(tmpIndAux, "%i", indiceAux->indice);
					append_new_quad(codigo,"<", dir1, dir2, tmpIndGlobal);
					append_new_quad(codigo,"goto", "-", "-", tmpIndAux);
				}
                | relacional MAYORQUE relacional {
									indiceGlobal = init_index();
									indiceAux = init_index();
									$$.listRelTrue = init_list_index(indiceGlobal);
									$$.listRelFalse = init_list_index(indiceAux);
									append_index($$.listRelTrue, indiceGlobal);
									append_index($$.listRelFalse, indiceAux);
									$$.tipoRel = max($1.tipoRel, $3.tipoRel);
									dir1 = ampliar($1.dirRel,$1.tipoRel,$$.tipoRel, codigo);
									dir2 = ampliar($3.dirRel,$3.tipoRel,$$.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, ">", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
                | relacional MENORIGUAL relacional {
									indiceGlobal = init_index();
									indiceAux = init_index();
									$$.listRelTrue = init_list_index(indiceGlobal);
									$$.listRelFalse = init_list_index(indiceAux);
									append_index($$.listRelTrue, indiceGlobal);
									append_index($$.listRelFalse, indiceAux);
									$$.tipoRel = max($1.tipoRel, $3.tipoRel);
									dir1 = ampliar($1.dirRel,$1.tipoRel,$$.tipoRel, codigo);
									dir2 = ampliar($3.dirRel,$3.tipoRel,$$.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, "<=", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
                | relacional MAYORIGUAL relacional {
									indiceGlobal = init_index();
									indiceAux = init_index();
									$$.listRelTrue = init_list_index(indiceGlobal);
									$$.listRelFalse = init_list_index(indiceAux);
									append_index($$.listRelTrue, indiceGlobal);
									append_index($$.listRelFalse, indiceAux);
									$$.tipoRel = max($1.tipoRel, $3.tipoRel);
									dir1 = ampliar($1.dirRel,$1.tipoRel,$$.tipoRel, codigo);
									dir2 = ampliar($3.dirRel,$3.tipoRel,$$.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, ">=", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
                | relacional IDENTICO relacional {
									indiceGlobal = init_index();
									indiceAux = init_index();
									$$.listRelTrue = init_list_index(indiceGlobal);
									$$.listRelFalse = init_list_index(indiceAux);
									append_index($$.listRelTrue, indiceGlobal);
									append_index($$.listRelFalse, indiceAux);
									$$.tipoRel = max($1.tipoRel, $3.tipoRel);
									dir1 = ampliar($1.dirRel,$1.tipoRel,$$.tipoRel, codigo);
									dir2 = ampliar($3.dirRel,$3.tipoRel,$$.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, "==", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
                | relacional DIFERENTE relacional {
									indiceGlobal = init_index();
									indiceAux = init_index();
									$$.listRelTrue = init_list_index(indiceGlobal);
									$$.listRelFalse = init_list_index(indiceAux);
									append_index($$.listRelTrue, indiceGlobal);
									append_index($$.listRelFalse, indiceAux);
									$$.tipoRel = max($1.tipoRel, $3.tipoRel);
									dir1 = ampliar($1.dirRel,$1.tipoRel,$$.tipoRel, codigo);
									dir2 = ampliar($3.dirRel,$3.tipoRel,$$.tipoRel, codigo);
									char *tmpIndGlobal=(char*)malloc(sizeof(char));
									char *tmpIndAux=(char*)malloc(sizeof(char));
									sprintf(tmpIndGlobal, "%i", indiceGlobal->indice);
									sprintf(tmpIndAux, "%i", indiceAux->indice);
									append_new_quad(codigo, "<>", dir1, dir2, tmpIndGlobal);
									append_new_quad(codigo, "goto", "-", "-", tmpIndAux);
								}
                | expresion {$$.tipoRel=$1.tipoExp;
	                          $$.dirRel=$1.dirExp;} ;

expresion:        expresion MAS expresion {
					$$.tipoExp = max($1.tipoExp, $3.tipoExp);
                    $$.dirExp = newTemp();
                    dir1 = ampliar($1.dirExp,$1.tipoExp,$$.tipoExp,codigo);
                    dir2 = ampliar($3.dirExp,$3.tipoExp,$$.tipoExp,codigo);
                    append_new_quad(codigo, "+", dir1, dir2,$$.dirExp);
				}
                | expresion MENOS expresion{
					$$.tipoExp = max($1.tipoExp, $3.tipoExp);
                    $$.dirExp = newTemp();
                    dir1 = ampliar($1.dirExp,$1.tipoExp,$$.tipoExp, codigo);
                    dir2 = ampliar($3.dirExp,$3.tipoExp,$$.tipoExp, codigo);
                    append_new_quad(codigo, "-", dir1, dir2,$$.dirExp);
				}
                | expresion MUL expresion {
					$$.tipoExp = max($1.tipoExp, $3.tipoExp);
                    $$.dirExp = newTemp();
                    dir1 = ampliar($1.dirExp,$1.tipoExp,$$.tipoExp, codigo);
                	dir2 = ampliar($3.dirExp,$3.tipoExp,$$.tipoExp, codigo);
                    append_new_quad(codigo, "*", dir1, dir2,$$.dirExp);
				}
                | expresion DIV expresion {
					$$.tipoExp = max($1.tipoExp, $3.tipoExp);
                    $$.dirExp = newTemp();
                	dir1 = ampliar($1.dirExp,$1.tipoExp,$$.tipoExp, codigo);
                    dir2 = ampliar($3.dirExp,$3.tipoExp,$$.tipoExp, codigo);
                    append_new_quad(codigo, "/", dir1, dir2,$$.dirExp);
				}
                | expresion MODULO expresion {
					$$.tipoExp = max($1.tipoExp, $3.tipoExp);
                    $$.dirExp = newTemp();
                    dir1 = ampliar($1.dirExp,$1.tipoExp,$$.tipoExp, codigo);
                    dir2 = ampliar($3.dirExp,$3.tipoExp,$$.tipoExp, codigo);
                    append_new_quad(codigo, "%", dir1, dir2,$$.dirExp);
				}
                | LPAR expresion RPAR {
					$$.dirExp = $2.dirExp;
                    $$.tipoExp = $2.tipoExp;
				}
                | variable {}
                | NUM{
					$$.dirExp = $1.valor;
                    $$.tipoExp = $1.tipe;
				}
                | CADENA{}
                | CARACTER {};
                

variable:     	ID variable_comp {};

variable_comp: 	dato_est_sim{} 
				| arreglo{} 
				| LPAR parametros RPAR{} ;

dato_est_sim:  	dato_est_sim PUNTO ID{} 
				| {};

arreglo:       	LCOR expresion RCOR{}
            	| arreglo LCOR expresion RCOR {};

parametros:    	lista_param{
					$$.listArgs=$1.listArgs;
				} 
				| {$$.listArgs = NULL;};

lista_param:    lista_param COMA expresion {
					$$.listArgs=$1.listArgs;
                    ARG* argx = init_arg($3.tipoExp);
                    append_arg($$.listArgs, argx->arg);
                    append_new_quad(codigo,"param",$3.dirExp," ", " ");
				}
                | expresion {
					$$.listArgs = init_args();
                    ARG* argx = init_arg($1.tipoExp);
                    append_arg($$.listArgs, argx->arg);
                    append_new_quad(codigo,"param",$1.dirExp," ", " ");
				};				  


%%
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