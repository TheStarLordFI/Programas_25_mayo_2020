#include<stdio.h>
extern int yylex();
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
    yylex();
    fclose(yyin);
    return 0;
}