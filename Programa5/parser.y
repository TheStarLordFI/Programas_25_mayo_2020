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
extern int yylex();
extern char* yytext;
void print_code(struct code *c);
/////////////////////////////estructuras/////////////////////////////////////
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
INDEX *indiceGlobal;
/////////////////////////////Variables///////////////////////////////////////
int tipoGBL;
int baseGBL;
int tamTSGBL;
int address;
int funcType;
bool funcReturn;
ARGS *listaRET;
char idGBL[32];
%}

%union{
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
}

%token ERROR
/*Los símbolos terminales de la gramática PARA Bison SON tokens y deben declararse en la sección de definiciones.*/
%token PYC
%token INICIO
%token END
%token ESTRUCT
%token DEF
%token IF 
%token THEN
%token WHILE 
%token<dir> DO 
%token SEGUN
%token WRITE 
%token DEV
%token READ
%token TERMINAR
%token CASO PRED
%token DOSP
%token FALSE TRUE
%token<base> ENTERO REAL DREAL SIN CAR
%token<dir> ID
%token<dir> CARACTER
%token<dir> CADENA
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
%nonassoc<dir> LPAR RPAR
%nonassoc SITEMP
%nonassoc SINO

%type<base> tipo base tipo_arreglo
%type<exp> expresion
%type<tSentencia> sentencia sentencias
%type<e_b> e_bool
%type<e_b> relacional
%type<list> lista_param lista_arg
%type<list> argumentos
%type<list> parametros
%type<dir> tipo_registro
%type<base> tipo_arg param_arr arg 
%type<var> variable arreglo
%type<dir> programa declaraciones
%type<dir> lista_var
%type<dir> lista_var2
%type<dir> funciones
%type<casosPred> casos casos2
%type<casosPred> predeterminado
%type<var> variable_comp
%type<var> dato_est_sim

%start programa

%%
programa: {
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
		} declaraciones { //print_tab_sym(getTopSym(stack_sym));
						  //print_tab_type(getTopType(stack_type));
						   } funciones { print_code(codigo); }; 

declaraciones: tipo {tipoGBL = $1;} lista_var PYC declaraciones {}
			| tipo_registro lista_var PYC declaraciones {}
			| {};

tipo_registro: ESTRUCT INICIO{
							tab_sym_struct = init_sym_tab();
							tab_type_struct = init_type_tab(tab_type_struct);
							structDir = crearDir();
							structDir->info = address;
							pushPDir(structDir, stack_dir);
							push_tt(stack_type,tab_type_struct);
							push_st(stack_sym, tab_sym_struct);
						
						} declaraciones END{
								//printf(">>>>>>>>>>>>>Tablas de tipos y simbolos generales>>>>>>>>>>>>>\n");
								//print_tab_sym(tab_symGBL);
								//print_tab_type(getTopType(stack_type));
								tab_typeGBL = pop_tt(stack_type);
								tab_symGBL = pop_st(stack_sym);
								print_tab_sym(tab_sym_struct);
								print_tab_type(tab_type_struct);
								structDir = popPDir(stack_dir);
								address = structDir->info;
								TYP *newTYP = set_typ_struct(init_type(),"struct",0,tab_type_struct,tab_sym_struct);
								tipoGBL = append_type(tab_type_struct, newTYP);
						} ;

tipo: base { baseGBL = $1; } tipo_arreglo { $$ = $3; };

base: ENTERO { 
			$$ = 0; }
	  | REAL { 
		  $$ = 1; }
	  | DREAL { 
		  $$ = 4; }
	  | CAR { 
		  $$ = 2; }
	  |	SIN { 
		  $$ = 3; };

tipo_arreglo: LCOR NUM RCOR tipo_arreglo{
				if ($2.tipo == 0){
					if($2.num > 0 ){
						TYP *newTYP = init_type();
						newTYP = set_typ(newTYP,"array",$4,$2.num*getTam(getTopType(stack_type),$4),getTopType(stack_type));
						$$ = append_type(getTopType(stack_type), newTYP);
					}else{ printf("ERROR >>> El tam del arreglo debe ser mayo a cero\n"); }
				}else { printf("ERROR >>> El tam del arreglo debe ser un numero entero\n"); }
			}
			| { $$ = baseGBL; };

lista_var: ID lista_var2 {
					if(search_id_symbol(getTopSym(stack_sym),$1)==-1){
						SYM *new_sym = init_sym();
						new_sym= set_sym(new_sym, $1, address, tipoGBL, "var", NULL, getTopSym(stack_sym), getTopType(stack_type));
						append_sym(getTopSym(stack_sym),new_sym);
						address = address + getTam(getTopType(stack_type), tipoGBL);
					}else{
						printf("ERROR >>> El ID ya fue declarado \n");
					}
				};

lista_var2: COMA ID lista_var2{
						if(search_id_symbol(getTopSym(stack_sym),$2)==-1){
							SYM *new_sym = init_sym();
							new_sym= set_sym(new_sym, $2, address, tipoGBL, "var", NULL, getTopSym(stack_sym), getTopType(stack_type));
							append_sym(getTopSym(stack_sym),new_sym);
							address = address + getTam(getTopType(stack_type), tipoGBL);
						}else{
							printf("ERROR >>> El ID ya fue declarado \n");
						}
					}
			| {};

funciones: DEF tipo ID{
					if(search_id_symbol(getTopSym(stack_sym),$3)==-1){
							simbol = init_sym();
							simbol = set_sym(simbol,$3,-1,$2,"func",NULL,tab_symGBL,tab_typeGBL);
							append_sym(tab_symGBL,simbol);
							structDir = crearDir();
							structDir->info = address;
							pushPDir(structDir,stack_dir);
							funcType = $2;
							funcReturn = false;
							address = 0;
							new_ST = init_sym_tab();
							new_TT = init_type_tab(new_TT);
							push_tt(stack_type,new_TT);
							push_st(stack_sym, new_ST);
							append_new_quad(codigo,"label","-","-",$3);
					}else{
						printf("ERROR >>> El ID ya fue declarado \n");
					}
				} LPAR argumentos RPAR INICIO declaraciones sentencias END {
					simbol = init_sym();
					simbol = search_SYM(getTopSym(stack_sym),$3);
					simbol->args = $6.listArgs;
					char *tmpEtq = create_label();
					backpatch(codigo,$10.nextList,tmpEtq);
					new_TT= pop_tt(stack_type);
					new_ST= pop_st(stack_sym);
					structDir = popPDir(stack_dir);
					address = structDir->info;
					if($2 != 3 && funcReturn == false){
						printf("ERROR >>> la funcion no tiene valor de retorno\n");
					}
				} funciones {}
			| {};

argumentos: lista_arg { $$.listArgs = $1.listArgs; $$.num = $1.num; }
			| SIN {  $$.listArgs = NULL; $$.num = 0; };

lista_arg: lista_arg COMA arg {
					$$.listArgs = $1.listArgs;
					$$.num = $1.num+1;
					//argx = init_arg($3);
					append_arg($$.listArgs, $3);
				}
				| arg {
					$$.listArgs = init_args();
                    //argx = init_arg($1);
                    append_arg($$.listArgs, $1);
					$$.num = 1;
				};

arg: tipo_arg ID {
				if( search_id_symbol(getTopSym(stack_sym),$2) == -1){
					simbol = init_sym();
					simbol= set_sym(simbol, $2, address, tipoGBL, "var", NULL,getTopSym(stack_sym), getTopType(stack_type));
					append_sym(getTopSym(stack_sym),simbol);
					address = address + getTam(getTopType(stack_type), tipoGBL);
					$$ = $1;
				}else
					printf("ERROR >>> El ID ya fue declarado\n");
			};

tipo_arg: base { baseGBL = $1; } param_arr { $$ = $3; };

param_arr: LCOR RCOR param_arr {
					TYP *tp = init_type();
                    tp = set_typ(tp,"array",$3,0,getTopType(stack_type));
                    $$ = append_type(getTopType(stack_type), tp);
				} | { $$ = baseGBL; };

sentencias: sentencias sentencia {
							if (strcmp($2.final_label,"") == 0){ 
								strcpy($$.final_label,$1.final_label);
    						} else { strcpy($$.final_label,$2.final_label); }
						}
			| {
				$$.nextList= init_list_index(init_index());
				char *tmpEtq=create_label();
				strcpy($$.label,tmpEtq);
				backpatch(codigo,$$.nextList,tmpEtq);
				append_new_quad(codigo,"label","-","-",tmpEtq);
			};

sentencia: IF e_bool THEN sentencia END {
						char *tmpLabel=create_label();
						strcpy($$.label,tmpLabel);
						backpatch(codigo,$2.listTrue,tmpLabel);
						append_index( $4.nextList, init_index());
						$$.nextList=combinar($2.listFalse,$4.nextList);
						backpatch(codigo,$$.nextList,tmpLabel);
						append_new_quad(codigo,"label","-","-",tmpLabel);
						strcpy($$.final_label,$4.final_label);
				}
			| IF e_bool THEN sentencias {
						char *L1=create_label();
						char *L2=create_label();
						char *tmpLabel=create_label();
						strcpy(tmpLabel,$4.label);
						backpatch(codigo,$2.listTrue,tmpLabel);
						append_index($2.listFalse,init_index());
						append_new_quad(codigo,"goto","-","-",L2);
						append_index($4.nextList,init_index());
						append_new_quad(codigo,"label","-","-",L1);
				} SINO sentencias END {
						char *L3=create_label();
						char *L4=create_label();
						append_index($2.listFalse,init_index());
						backpatch(codigo,$2.listTrue,L4);
						backpatch(codigo,$4.nextList,L3);
						append_new_quad(codigo,"label","-","-",L3);
				}
			| WHILE e_bool DO sentencia END {
						char *L1=create_label();
						char *L2=create_label();
						backpatch(codigo,$4.nextList,L1);
						backpatch(codigo,$2.listTrue,L2);
						$$.nextList=$2.listFalse;
						append_new_quad(codigo,"label","-","-",L1);
						append_new_quad(codigo,"label","-","-",L2);
						char *L_nextList = create_label();
						backpatch(codigo,$4.nextList,L_nextList);
						append_new_quad(codigo,"goto","-","-",L_nextList);
					}
			| DO sentencia WHILE e_bool PYC {
						char *tmpLabel=create_label();
						char *tmpLabel2=create_label();
						strcpy(tmpLabel2,$2.label);
						backpatch(codigo,$4.listTrue,tmpLabel2);
						backpatch(codigo,$4.listFalse,tmpLabel);
						append_new_quad(codigo,"label","-","-",tmpLabel);
					}
			| SEGUN LPAR variable RPAR DO casos predeterminado END {
						char *L1=create_label();
						LINDEX *prueba  =  (LINDEX *)malloc(sizeof(LINDEX));
						prueba = combinar($6.nextList, $7.nextList);
						backpatch(codigo,$6.nextList,L1);
						sustituir("??",$3.dir,prueba,codigo);
					}
			| variable IGUAL expresion PYC {
						if((search_id_symbol(getTopSym(stack_sym),$1.dir) != -1) || (search_id_symbol(tab_symGBL,$1.dir) != -1 )){
							simbol = init_sym();
							simbol = search_SYM(getTopSym(stack_sym),$1.dir);
							if(simbol==NULL){
								simbol=search_SYM(tab_symGBL,$1.dir);
							}
							char *dir1 = (char*)malloc(sizeof(char)*15);
							dir1 = reducir($3.dir,$3.tipo,$1.tipo,codigo);
							char *tmp2=(char*)malloc(sizeof(char)*15);
							strcpy(tmp2,$1.dir);
							append_new_quad(codigo,"=",dir1,"-",tmp2);
						}else{
							printf("ERROR >>> La variable  no se ha declarado\n");
						}
					}
			| WRITE expresion PYC {
						char *e_dir = (char*)malloc(sizeof(char)*15);
      					strcpy(e_dir,$2.dir);
						append_new_quad(codigo,"write",e_dir,"-","-");
					}
			| READ variable PYC {
						char *v_dir = (char*)malloc(sizeof(char)*15);
      					strcpy(v_dir,$2.dir);
						append_new_quad(codigo,"read","-","-",v_dir); 
					}
			| DEV PYC {	
						if(funcType==3){
							append_new_quad(codigo,"return","-","-","-");
						}else{
							printf("ERROR >>> La funcion debe retornar  algun valor de tipo => %d",funcType);
						}
					}
			| DEV expresion PYC { 
						if(funcType!=3){
							char *new_dir = (char*)malloc(sizeof(char)*15);
							new_dir= reducir($2.dir,$2.tipo,funcType,codigo);
							append_new_quad(codigo,"return",$2.dir,"-","-");
							funcReturn=true;
						}else{
								printf("ERROR >>> La funcion debe retornar  algun valor de tipo ==>%d",funcType);
						}
					}
			| TERMINAR PYC {	
						indiceGlobal = init_index();
						char *tmp3=(char*)malloc(sizeof(char)*15);
						sprintf(tmp3, "%i", indiceGlobal->indice);
						append_new_quad(codigo, "goto", "-", "-", tmp3);
						$$.nextList = init_list_index(indiceGlobal);
						append_index($$.nextList, indiceGlobal);
					}
			| INICIO sentencias END { 
						$$.nextList=$2.nextList;
					};

casos: CASO NUM DOSP sentencia casos2 {
						//$$.nextList = combinar($$.nextList, $4.nextList);
						//char *label_C = create_label();
						/*Indica el inicio del código para la sentencia*/
						//$$.prueba = $5.prueba;
						//sustituir_cc()
						//(if ”??” ”==” num.dir ”goto” L )
					};

casos2: casos {
			//casos.prueba = newCode()
			//char *LT = create_label();
			/*Indica el inicio del código para la sentencia*/
			//genCode(”label” L)
			//casos.prueba.append(if ”??” ”==” num.dir ”goto” L )
		} 
		| {};

predeterminado: PRED DOSP sentencia {
					//predeterminado.prueba = newCode()
					//char *lll = create_label();
					/*Indica el inicio del código para la sentencia*/
					//genCode(”label” L)
					//predeterminado.prueba.append(”goto” L )
				} 
				| {};

e_bool:  e_bool OR {
			char *tmpEtq = create_label();
			backpatch(codigo,$1.listFalse,tmpEtq);
			append_new_quad(codigo,"label","-","-",tmpEtq);
		} e_bool {
			$$.listTrue=combinar($1.listTrue,$4.listTrue);
			$$.listFalse=$4.listFalse;
		}
		| e_bool AND {
			char *tmpEtq=create_label();
			backpatch(codigo,$1.listTrue,tmpEtq);
			append_new_quad(codigo,"label","-","-",tmpEtq);
		}e_bool {
			$$.listTrue=$4.listTrue;
			$$.listFalse=combinar($1.listFalse,$4.listFalse);}
		| NOT e_bool {
			$$.listTrue=$2.listFalse;
			$$.listFalse=$2.listTrue;}
		| relacional {
			printf("relacional\n");
			$$.listTrue=$1.listTrue;
			$$.listFalse=$1.listFalse;}
		| TRUE {
			indiceGlobal = init_index();
			$$.listFalse=init_list_index(NULL); 
			$$.listTrue=init_list_index(NULL);
			append_index($$.listTrue, indiceGlobal);
			char *tmp=(char*)malloc(sizeof(char)*15);
			sprintf(tmp, "%i", indiceGlobal->indice);
			append_new_quad(codigo,"goto","-","-",tmp);}
		| FALSE {
			indiceGlobal = init_index();
			$$.listFalse=init_list_index(NULL); 
			$$.listTrue=init_list_index(NULL);
			append_index($$.listFalse, indiceGlobal);
			char *tmp=(char*)malloc(sizeof(char)*15);
			sprintf(tmp, "%i", indiceGlobal->indice);
			append_new_quad(codigo,"goto","-","-",tmp);
		};

relacional: relacional MAYORQUE relacional {
				//printf("relacional > \n");
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				$$.listTrue = init_list_index(NULL);
				$$.listFalse = init_list_index(NULL);
				strcpy(tmpR1,$1.dir);
    			strcpy(tmpR2,$3.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index($$.listTrue,tmpI1);
				append_index($$.listFalse,tmpI2);
				append_quad(codigo,init_quad(">",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
			| relacional MENORQUE relacional {	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				$$.listTrue = init_list_index(NULL);
				$$.listFalse = init_list_index(NULL);
				strcpy(tmpR1,$1.dir);
    			strcpy(tmpR2,$3.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index($$.listTrue,tmpI1);
				append_index($$.listFalse,tmpI2);
				append_quad(codigo,init_quad("<",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
			| relacional MENORIGUAL relacional {	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				$$.listTrue = init_list_index(NULL);
				$$.listFalse = init_list_index(NULL);
				strcpy(tmpR1,$1.dir);
    			strcpy(tmpR2,$3.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index($$.listTrue,tmpI1);
				append_index($$.listFalse,tmpI2);
				append_quad(codigo,init_quad("<=",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			} 
			| relacional MAYORIGUAL relacional {	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				$$.listTrue = init_list_index(NULL);
				$$.listFalse = init_list_index(NULL);
				strcpy(tmpR1,$1.dir);
    			strcpy(tmpR2,$3.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index($$.listTrue,tmpI1);
				append_index($$.listFalse,tmpI2);
				append_quad(codigo,init_quad(">=",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
			| relacional DIFERENTE relacional {	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				$$.listTrue = init_list_index(NULL);
				$$.listFalse = init_list_index(NULL);
				strcpy(tmpR1,$1.dir);
    			strcpy(tmpR2,$3.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index($$.listTrue,tmpI1);
				append_index($$.listFalse,tmpI2);
				append_quad(codigo,init_quad("<>",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
			| relacional IDENTICO relacional {	
				char *tmpI1C = (char *)malloc(sizeof(char)*10);
    			char *tmpI2C = (char *)malloc(sizeof(char)*10);
    			char *tmpR1 = (char *)malloc(sizeof(char)*10);
    			char *tmpR2 = (char *)malloc(sizeof(char)*10);
    			char *tmp = (char *)malloc(sizeof(char)*10);
				INDEX *tmpI1 = init_index();
				INDEX *tmpI2 = init_index();
				$$.listTrue = init_list_index(NULL);
				$$.listFalse = init_list_index(NULL);
				strcpy(tmpR1,$1.dir);
    			strcpy(tmpR2,$3.dir);
				sprintf(tmpI1C,"%i",tmpI1->indice);
				sprintf(tmpI2C,"%i",tmpI2->indice);
				append_index($$.listTrue,tmpI1);
				append_index($$.listFalse,tmpI2);
				append_quad(codigo,init_quad("=",tmpR1,tmpR2,tmpI1C));
				append_quad(codigo,init_quad("goto","-","-",tmpI2C));
			}
			| expresion {
				strcpy($$.dir,$1.dir);
				$$.tipo = $1.tipo;
			};

expresion: expresion MAS expresion {
				$$.tipo = max($1.tipo, $3.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				$$.dir = nuevaTemp();
				strcpy(dirTmp,$$.dir);
				dir1 = ampliar($1.dir,$1.tipo,$$.tipo,codigo);
				dir2 = ampliar($3.dir,$3.tipo,$$.tipo,codigo);
				append_new_quad(codigo,"+", dir1, dir2, dirTmp);
			}
			| expresion MENOS expresion {
				$$.tipo = max($1.tipo, $3.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				$$.dir = nuevaTemp();
				strcpy(dirTmp,$$.dir);
				dir1 = ampliar($1.dir,$1.tipo,$$.tipo,codigo);
				dir2 = ampliar($3.dir,$3.tipo,$$.tipo,codigo);
				append_new_quad(codigo,"-", dir1, dir2, dirTmp);
			}
			| expresion MUL expresion {
				$$.tipo = max($1.tipo, $3.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				$$.dir = nuevaTemp();
				strcpy(dirTmp,$$.dir);
				dir1 = ampliar($1.dir,$1.tipo,$$.tipo,codigo);
				dir2 = ampliar($3.dir,$3.tipo,$$.tipo,codigo);
				append_new_quad(codigo,"*", dir1, dir2, dirTmp);
			}
			| expresion DIV expresion {
				$$.tipo = max($1.tipo, $3.tipo);
				char *dir1 = (char *)malloc(sizeof(char)*10);
				char *dir2 = (char *)malloc(sizeof(char)*10);
				char *dirTmp = (char *)malloc(sizeof(char)*10);
				$$.dir = nuevaTemp();
				strcpy(dirTmp,$$.dir);
				dir1 = ampliar($1.dir,$1.tipo,$$.tipo,codigo);
				dir2 = ampliar($3.dir,$3.tipo,$$.tipo,codigo);
				append_new_quad(codigo,"/", dir1, dir2, dirTmp);
			}
			| expresion MODULO expresion {
				if ($1.tipo==1 && $3.tipo==1){
					$$.tipo = max($1.tipo, $3.tipo);
					char *dir1 = (char *)malloc(sizeof(char)*10);
					char *dir2 = (char *)malloc(sizeof(char)*10);
					char *dirTmp = (char *)malloc(sizeof(char)*10);
					$$.dir = nuevaTemp();
					strcpy(dirTmp,$$.dir);
					dir1 = ampliar($1.dir,$1.tipo,$$.tipo,codigo);
					dir2 = ampliar($3.dir,$3.tipo,$$.tipo,codigo);
					append_new_quad(codigo,"%", dir1, dir2, dirTmp);
				}else{
					printf("ERROR >>> La operacion modulo no se puede aplicar\n");
				}
			}
			| LPAR expresion RPAR {
				$$.tipo = $2.tipo;
				strcpy($$.dir,$2.dir);
				}
			| variable {
				$$.tipo = $1.tipo;
				strcpy($$.dir,$1.dir);
				}
			| NUM {
				$$.tipo = $1.tipo;
				strcpy($$.dir,$1.dir);
				$$.valor = $1.num;
			}
			| CADENA {}
			| CARACTER {};

variable: ID {
			if ((search_id_symbol(stack_sym->top,$1) == -1|| search_id_symbol(stack_sym->tail,$1) == -1)) { 
				strcpy(idGBL,$1);
			} else {
				printf("ERROR >>> No se ha declarado variable %s\n",$1);
			}
		} variable_comp {
			if ($3.estruct == 1) {
				char *tmp = (char *)malloc(sizeof(char)*10);
				char *tmp2 = (char *)malloc(sizeof(char)*20);
				tmp = nuevaTemp();
				strcpy($$.dir,tmp);
				$$.tipo = $3.tipo;
				sprintf(tmp2,"%s[%s]",$1,$3.dir);
				append_quad(codigo,init_quad("=",tmp2,"-",tmp));
				strcpy($$.base,$1);
				$$.estruct = 1;
				$$.des = $3.des;
			} else if ($3.estruct == 2){
				strcpy($$.dir,$3.dir);
				$$.tipo = getTipo(stack_sym->top,$1);
				$$.estruct = 0;
			} else {
				strcpy($$.dir,$1);
				$$.tipo = getTipo(stack_sym->top,$1);
				$$.estruct = 0;
			}
		};

variable_comp: dato_est_sim {
					$$.tipo = $1.tipo;
					$$.des = $1.des;
					$$.estruct = $1.estruct;
					if ($1.estruct == 1) {
					char *tmp = (char *)malloc(sizeof(char)*10);
					char *tmp2 = (char *)malloc(sizeof(char)*10);
					tmp = nuevaTemp();
					sprintf(tmp2,"%d",$1.des);
					append_quad(codigo,init_quad("=",tmp2,"-",tmp));
					strcpy($$.dir,tmp);
					}
				}
				| arreglo {
					$$.tipo = $1.tipo;
					$$.des = $1.des;
					$$.estruct = 1;
					strcpy($$.dir,$1.dir);
				}
				| LPAR {strcpy($1,idGBL);} parametros RPAR {
					char *tmp = (char *)malloc(sizeof(char)*10);
					char *tmp2 = (char *)malloc(sizeof(char)*10);
					strcpy(tmp,$1);
					tmp2 = nuevaTemp();
					strcpy($$.dir,tmp2);
					$$.estruct = 2;
					if (strcmp(getVar(stack_sym->top,tmp),"func") == 0) {
						ARGS *lista = getArgs(stack_sym->top,tmp);
						int num = lista->num;
						if (num != $3.num) { printf("ERROR >>> El numero de parametros no coinciden con la funcion\n"); }
						if (compare_args(lista,$3.listArgs) == 0) { printf("ERROR >>> El numero de parametros no coinciden con la funcion\n"); }
					} else { printf("ERROR >>> La variable no es una funcion\n"); }
					append_quad(codigo,init_quad("call",tmp,"-",tmp2));
				};

dato_est_sim: dato_est_sim PUNTO ID {
					if ($1.code_struct == 1) {
						if (search_id_symbol($1.tab_sym,$3) != -1) {
							$$.des = $1.des + getDir($1.tab_sym,$3);
							char *idDir =(char *)malloc(sizeof(char)*32);
							strcpy(idDir,$3);
							int tipoTmp= getTipo($1.tab_sym,idDir);
							$$.tipo = tipoTmp;
							char est[15];
							strcpy(est,getNombre($1.tab_sym->tt_asoc,tipoTmp));
							if (strcmp(est,"struct") == 0) {
								$$.code_struct = 1;
								$$.tab_sym = get_TS_asoc($1.tab_sym->tt_asoc,tipoTmp);
							} else {
								$$.code_struct = 0;
								$$.tab_sym = NULL;
							}
						} else {
							printf("ERROR >>> La variable no ha sido declarada\n");
						}
					} else{ 
						printf("ERROR >>> La variable no es una estructura\n");
						}
				}
			| {
				int tipoTmp = getTipo(getTopSym(stack_sym),idGBL);
				if (strcmp(getNombre(getTopType(stack_type),tipoTmp),"struct") == 0) {
					$$.estruct = 1;
					$$.code_struct = 1;
					$$.tab_sym = get_TS_asoc(getTopType(stack_type),tipoTmp);
					$$.des = 0;
				} else {
					$$.estruct = 0;
					$$.code_struct = 0;
					$$.tipo = tipoTmp;
				}
			};

arreglo : LCOR expresion RCOR {
				$$.tipo = getTipo(getTopSym(stack_sym),idGBL);
				if (strcmp(getNombre(getTopType(stack_type),$$.tipo),"array") == 0) {
					if ($2.tipo == 1) {
						int tmp3 = getTipoBase(getTopType(stack_type),$$.tipo);
						int tam = getTam(getTopType(stack_type),tmp3);
						char *tmp5 = (char *)malloc(sizeof(char)*10);
						char *tmp7 = (char *)malloc(sizeof(char)*10);
						char *tmp4 = nuevaTemp();
						strcpy($$.dir,tmp4);
						sprintf(tmp5,"%d",tam);
						strcpy(tmp7,$2.dir);
						append_quad(codigo,init_quad("*",tmp7,tmp5,tmp4));
					} else { printf("ERROR >>> El numero del arreglo no es un numero entero\n"); }
				} else { printf("ERROR >>> La variable asociada no es de tipo arreglo\n"); }
			}
			| LCOR expresion RCOR arreglo {
			$$.tipo = getTipoBase(getTopType(stack_type),$4.tipo);
			if (strcmp(getNombre(getTopType(stack_type),$$.tipo),"array") == 0) {
				if ($2.tipo == 1) {
					int tmp = getTipoBase(getTopType(stack_type),$$.tipo);
					int tam = getTam(getTopType(stack_type),tmp);
					char *tmp3 = (char *)malloc(sizeof(char)*10);
					char *tmp4 = (char *)malloc(sizeof(char)*10);
					char *tmp6 = (char *)malloc(sizeof(char)*10);
					char *tmp2 = nuevaTemp();
					char *tmp5 = nuevaTemp();
					strcpy($$.dir,tmp5);
					sprintf(tmp3,"%d",tam);
					strcpy(tmp4,$2.dir);
					strcpy(tmp6,$4.dir);
					append_quad(codigo,init_quad("*",tmp4,tmp3,tmp2));
					append_quad(codigo,init_quad("+",tmp2,tmp6,tmp5));
					$$.des = $2.valor * atoi(tmp3);
				} else { printf("ERROR >>> El numero del arreglo no es un numero entero\n"); }
			} else { printf("ERROR >>> La variable asociada no es de tipo arreglo\n"); }
			};

parametros : lista_param {
				$$.listArgs = $1.listArgs;
				$$.num = $1.num;
			}
			| {
				$$.listArgs = NULL;
				$$.num = 0;
			};

lista_param : lista_param COMA expresion {
				$$.listArgs = $1.listArgs;
				append_arg($$.listArgs,$3.tipo);
				$$.num = $$.num + 1;
			}
			| expresion {
				$$.listArgs = init_args();
				append_arg($$.listArgs,$1.tipo);
				$$.num = 1;
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
		printf("	|%s\t|%s\t|%s\t|%s\t|\n	",q->op,q->arg1,q->arg2,q->res);
		q=q->next;
	}
}