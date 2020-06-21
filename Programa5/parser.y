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
#include "tabla_simbolos.h"
#include "tabla_tipos.h"
#include "cuadruplas.h"
#include "backpatch.h"
#include "tipos.h"

void yyerror(char *s);
extern int yylex();
extern int n;


/*Se deben declarar las estructuras que para nuestro proyecto se tienen.
* Estas estructuras estan dentro de Data.h, cuadruplas.h, backpatch.h y tipos.h
*/
SSTACK *pSimbolos; 
TSTACK *pTipos; 
DSTACK *pDirecciones; 
SYMTAB *TGS, *TS1, *tTempSimbol;
//TGT: Tabla General de Tipos, TT1: Tabla Tipos 1
TYPTAB *TGT, *TT1, *tTempTipos; 
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
%}

//////////////////////////////////////////////////////Proyecto Actual//////////////////////////////////////////////////////
%union{
	.
	.
	.
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
	    struct CADENA *cad;//FALTA IMPLEMENTACION DE LA ESTRUCTURA CADENAS
	}cad;

	struct{
	  	struct LINDEX *listIndex;//En la DDS viene como prueba
	}indice; 
	
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
	.
	.
	.
}
////////////////////////////////////////////////////////////////////////////////////////////////////////


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

/*No terminales van declarados en minuscula*/
//%type<exp> programa declaraciones tipo_registro tipo base tipo_arreglo lista_var funciones argumentos lista_arg arg tipo_arg param_arr sentencias sentencia casos predeterminado e_bool relacional expresion variable variable_comp dato_est_sim arreglo parametros lista_param
//...
%type<>
%type<>
%type<>
%type<indice> sentencia sentencias
%type<eBool> e_bool
%type<rel> relacional
%type<>
%type<>
//...

%start programa

%%