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
		char dir[32];
		int valor;
	}exp;

	struct{
		char dir[32];
		int tipo;
		struct list_index *truelist;
		struct list_index *falselist;
	}e_b;
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
%nonassoc LPAR RPAR
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
%type<dir> casos casos2
%type<dir> predeterminado
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
		} declaraciones funciones { print_code(codigo); }; 

declaraciones: tipo {tipoGBL = $1;} lista_var PYC delaraciones {}
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
								print_tab_sym(tab_sym_struct);
								print_tab_type(tab_type_struct);
								tab_typeGBL = pop_tt(stack_type);
								tab_symGBL = pop_st(stack_sym);
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
				} LPAR argumentos RPAR INICIO declaraciones sentencias FIN {
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
				if( search_id_symbol(pSimbolos->top,$2.lexval) == -1){
					simbol = init_sym();
					simbol= set_sym(simbol, $2.lexval, dir, typeGBL, "var", NULL,pSimbolos->top, getTopType(pTipos));
					append_sym(pSimbolos->top,simbol);
					dir = dir + getTam(getTopType(pTipos), typeGBL);
				}else
					printf("ERROR >>> El ID ya fue declarado\n");
				$$ = $1;
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