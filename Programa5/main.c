#include<stdio.h>
#include<stdlib.h>
#include "cuadruplas.h"
extern int yyparse();
extern void print_code(CODE *c);
extern void yyerror(char *s);
extern FILE *yyin;

int main (int argc, char** argv){
    FILE *f;
    if(argc<2){
        printf("Faltan argumentos\n");
        return -1;
    }
    f = fopen(argv[1], "r");
    if(!f){
        printf("El archivo %s no se puede abrir\n", argv[1]);
        return -1;
    }
    yyin = f;
    yyparse();
    fclose(yyin);
    return 0;
}