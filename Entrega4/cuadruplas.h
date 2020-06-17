#ifndef QUAD_H
#define QUAD_H

typedef struct cuad QUAD;
struct cuad{
    char op[32];
    char arg1[32];
    char arg2[32];
    char res[32];
    QUAD *next;
};

typedef struct code{
    QUAD *head;
    QUAD *tail;
    int num_instru;
} CODE;

QUAD *init_quad(char* op, char* arg1, char* arg2, char* res);//Reserva memoria y crea una nueva cuadrupla
void finish_quad(QUAD *c);//Libera la memoria de una cuadrupla

CODE* init_code();//Reserva memoria para el codigo
void finish_code(CODE *c);//Libera la memoria de la lista ligada del codigo

void append_quad(CODE* c, QUAD *cd);//Agrega una cuadrupla al final de la lsta

void append_new_quad(CODE *c, char* op, char* arg1, char* arg2, char* res);//Crea y agrega una cuadrupla al final del codigo de 3D.

QUAD *search_quad_index(CODE *c,char *i); //busca un indice en quad

#endif