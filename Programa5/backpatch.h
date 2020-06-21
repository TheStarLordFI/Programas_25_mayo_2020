#ifndef BACKPATCH_H
#define BACKPATCH_H

#include "cuadruplas.h"

typedef struct index INDEX;

struct index{
  int indice;
  INDEX *next;
};

typedef struct list_index{
  INDEX *head;
  INDEX *tail;
  int numelemt;
}LINDEX;

INDEX *init_index(); // Reserva memoria para un nodo de indice
void finish_index(INDEX *i); // Libera la memoria de un nodo indice

LINDEX *init_list_index(INDEX *i); // Reserva memoria para la lista de indice se inserta el primero
void finish_list_index(LINDEX *l); // Libera la memoria de la lista y de todos los nodos dentro
void append_index(LINDEX *l,INDEX *i); // Agrega un nodo indice a l final de la lista
LINDEX *combinar(LINDEX *l1,LINDEX *l2); // Retorna una lista ligada de la concatenacion de l1 con l2

char *create_label();//crea una nueva etiqueta

void backpatch(CODE *c, LINDEX *l, char *label); // Reemplaza label en cada aparicion de un indice en la cuadruplas del codigo c

#endif