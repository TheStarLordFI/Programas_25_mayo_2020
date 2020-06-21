/*Fecha: 22/mayo/2020*/
/*Autores: Ana Belem Méndez Cabrera y Osmar Juárez Aguilar*/
/*Descripción: Archivo que genera nuestro analizador léxico,*/
/*             a partir de las expresiones regulares de los*/
/*             terminales encontrados en nuestra gramática.*/
%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "y.tab.h"
%}

%option noyywrap
%x COMENTARIO

/*--Expresiones regulares--*/
/*Modificación:25/mayo/20*/
/*Modifico: OJA*/
id [a-zA-Z_][a-zA-Z_0-9]*
num [0-9]+
cadena \"([a-zA-Z][a-zA-Z])*\"
caracter \'([a-zA-Z])\' 

/* Reglas/acciones*/
/*Modificación:25/mayo/20*/
/*Modifico: OJA*/
%%
"estructura" {return ESTRUCT;}
"inicio" {return INICIO;}
"fin" {return END;}
"si"  {return IF;}
"def" {return DEF;}
"entonces" {return THEN;}
"sino" {return SINO;}
"mientras" {return WHILE;}
"hacer" {return DO;}
"segun" {return SEGUN;}
"escribir" {return WRITE;}
"leer"  {return READ;}
"devolver" {return DEV;}
"terminar" {return TERMINAR;}
"caso" {return CASO;}
"pred" {return PRED;}
"o" {return OR;}
"y" {return AND;}
"no" {return NOT;}
"verdadero" {return TRUE;}
"falso" {return FALSE;}
"ent" {return ENTERO;}
"real" {return REAL;}
"dreal" {return DREAL;}
"car" {return CAR;}
"sin" {return SIN;}
"%" {return MODULO;}
":=" {return IGUAL;}
"(" {return LPAR;}
")" {return RPAR;}
"[" {return LCOR;}
"]" {return RCOR;}
"." {return PUNTO;}
"," {return COMA;}
":" {return DOSP;}
";" {return PYC;}
"<" {return MENORQUE;}
">" {return MAYORQUE;}
"<=" {return MENORIGUAL;}
">=" {return MAYORIGUAL;}
"=" {return IDENTICO;}
"<>" {return DIFERENTE;}
"+" {return MAS;}
"-" {return MENOS;}
"*" {return MUL;}
"/" {return DIV;}
{caracter} {
           strcpy(yylval.cad.lexval,yytext); 
           return CARACTER;
          }
{num} { 
        yylval.num.tipe= 0;
        yylval.num.valor= strdup(yytext);
        return NUM;
      }
{id} {  
        /* Ej: el valor de yytext se copia en el parser, 
           en el elemento de la union id, estructura dentro de la union*/
        strcpy(yylval.id.lexval,yytext);
        return ID;
      }
{cadena} {
          strcpy(yylval.cad.lexval,yytext);
          return CADENA;
        }
[ \n\r\t] {}//se ignoran el salto de linea, el retorno de carro y los espacios en blancos
<INITIAL>"/*" {BEGIN(COMENTARIO);}
<COMENTARIO>[^*/]  {}
<COMENTARIO>[*/]   {}    
<COMENTARIO>"*/"   {BEGIN(INITIAL);}
.     {return ERROR;}

%%
