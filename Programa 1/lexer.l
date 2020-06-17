/*Fecha: 22/mayo/2020*/
/*Autores: Ana Belem Méndez Cabrera y Osmar Juárez Aguilar*/
/*Descripción: Archivo que genera nuestro analizador léxico,*/
/*             a partir de las expresiones regulares y de los*/
/*             terminales encontrados en nuestra gramática.*/
%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  void error(char *s);

  typedef struct _token{
    int clase;
    char valor[32];
} token;
token TOKEN;
enum clase {CARACTER, NUM, ID, CADENA, ESTRUCT,
            INICIO, END, ENTERO, REAL, DREAL, CAR,
            SIN, IF, DEF, THEN, SINO, WHILE, DO, 
            SEGUN, WRITE, READ, DEV, TERMINAR, CASO,
            PRED, OR, AND, NOT, TRUE, FALSE, MODULO,
            IGUAL, LPAR, RPAR, LCOR, RCOR, PUNTO,
            COMA, DOSP, PYC, MENORQUE, MAYORQUE, 
            MENORIGUAL, MAYORIGUAL, IDENTICO, DIFERENTE,
            MAS, MENOS, MUL, DIV};
%}

%option noyywrap
%x COMENTARIO

/*--Expresiones regulares--*/
/*Modificación:25/mayo/20*/
/*Modifico: OJA, ABMC*/
id [a-zA-Z_][a-zA-Z_0-9]*
num [0-9]+
cadena \"([a-zA-Z][a-zA-Z])*\"
caracter \'([a-zA-Z])\' 


/* Reglas/acciones*/
/*Modificación:25/mayo/20*/
/*Modifico: OJA*/
%%
"estructura" {TOKEN.clase = ESTRUCT;
             strcpy(TOKEN.valor, yytext);
             printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
             }
"inicio" {TOKEN.clase = INICIO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"fin" {TOKEN.clase = END;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"si"  {TOKEN.clase = IF;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"def" {TOKEN.clase =DEF;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"entonces" {TOKEN.clase = THEN;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"sino" {TOKEN.clase = SINO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"mientras" {TOKEN.clase = WHILE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"hacer" {TOKEN.clase = DO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"segun" {TOKEN.clase = SEGUN;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"escribir" {TOKEN.clase = WRITE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"leer"  {TOKEN.clase = READ;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"devolver" {TOKEN.clase = DEV;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"terminar" {TOKEN.clase = TERMINAR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"caso" {TOKEN.clase = CASO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"pred" {TOKEN.clase = PRED;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"o" {TOKEN.clase = OR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"y" {TOKEN.clase = AND;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"no" {TOKEN.clase = NOT;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"verdadero" {TOKEN.clase = TRUE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"falso" {TOKEN.clase = FALSE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"ent" {TOKEN.clase = ENTERO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"real" {TOKEN.clase = REAL;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"dreal" {TOKEN.clase = DREAL;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"car" {TOKEN.clase = CAR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"sin" {TOKEN.clase = SIN;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"%" {TOKEN.clase = MODULO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
":=" {TOKEN.clase = IGUAL;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"(" {TOKEN.clase = LPAR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
")" {TOKEN.clase = RPAR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"[" {TOKEN.clase = LCOR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"]" {TOKEN.clase = RCOR;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"." {TOKEN.clase = PUNTO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"," {TOKEN.clase = COMA;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
":" {TOKEN.clase = DOSP;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
";" {TOKEN.clase = PYC;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"<" {TOKEN.clase = MENORQUE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
">" {TOKEN.clase = MAYORQUE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"<=" {TOKEN.clase = MENORIGUAL;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
">=" {TOKEN.clase = MAYORIGUAL;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"=" {TOKEN.clase = IDENTICO;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"<>" {TOKEN.clase = DIFERENTE;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"+" {TOKEN.clase = MAS;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"-" {TOKEN.clase = MENOS;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"*" {TOKEN.clase = MUL;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
"/" {TOKEN.clase = DIV;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
{id} {
        TOKEN.clase = ID;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: ID\n Valor: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
      }
{num} { 
        TOKEN.clase = NUM;
        strcpy(TOKEN.valor, yytext);
        printf("Terminal: NUM\n Valor: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
      }
{cadena} {
          TOKEN.clase = CADENA;
          strcpy(TOKEN.valor, yytext);
          printf("Terminal: CADENA\n Valor: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
        }
{caracter} {
           TOKEN.clase = CARACTER;
           strcpy(TOKEN.valor, yytext);
           printf("Terminal: CARACTER\n Valor: %s\n Num token:%d\n\n", TOKEN.valor, TOKEN.clase);
          }
[ \n\r\t] {}
<INITIAL>"/*" {BEGIN(COMENTARIO);}
<COMENTARIO>[^*/]  {}
<COMENTARIO>[*/]   {}    
<COMENTARIO>"*/"   {BEGIN(INITIAL);}
.     {error(yytext);}

%%

/*Descripcion: La siguiente funcion nos imprime cualquier error lexico que encuentre*/
void error(char *s){
    printf("Error léxico: %s\n\n",s);
}