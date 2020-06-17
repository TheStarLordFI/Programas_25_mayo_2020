#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cuadruplas.h"

/** Función:QUAD *init_quad();
* Descripción: Reserva memoria para una nueva cuadrupla y la crea agregando
*              a sus elementos los valores pasados por parametro.
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 11 de junio 2020*/
QUAD *init_quad(char* op, char* arg1, char* arg2, char* res){
  QUAD* new_quad = (QUAD*)malloc(sizeof(QUAD));
  strcpy(new_quad->op, op);
  strcpy(new_quad->arg1, arg1);
  strcpy(new_quad->arg2, arg2);
  strcpy(new_quad->res, res);
  new_quad->next  = NULL;
  return new_quad;
}

/** Función:void finish_quad(QUAD *c);
* Descripción: Libera memoria para una cuadrupla
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 11 de junio 2020*/
void finish_quad(QUAD *c){
  free(c);
  printf("Se ha eliminado una cuadrupla");
}

/*
* Función: init_code
* Descripción: Reserva memoria para el codigo
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020*/
CODE* init_code(){
  CODE* new_code = (CODE*)malloc(sizeof(CODE));
  new_code->num_instru = 0;
  new_code->head = NULL;
  new_code->tail = NULL;
  return new_code;
}

/** Función:void finish_code(CODE *c);
* Descripción: Libera la memoria de la lista ligada del codigo
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 11 de junio 2020*/
void finish_code(CODE *c)
{
  QUAD* elimina1;
  QUAD* elimina2 = c->head;
  while(elimina2 != NULL){
    elimina1 = elimina2;
    elimina2 = elimina2->next;
    finish_quad(elimina1);
  }
  free (c);
  printf("Se ha eliminado una lista de codigo");
}

/** Función: void append_quad(CODE* c, QUAD *cd);
* Descripción: Agrega una cuadrupla al final de la lista.
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 11 de junio 2020*/
void append_quad(CODE* c, QUAD *cd)
{
  if (c->num_instru == 0) {
	c->tail = cd;
	c->head = cd;
  }else{
	c->tail->next = cd;
	c->tail  = cd;
  }
  c->num_instru++;
}

/*
* Función: append_new_quad
* Descripción: Crea y agrega una cuadrupla al final del codigo de 3D.
* Autor: Juarez Aguilar Osmar 
* Fecha de creación: 10 de junio 2020*/
void append_new_quad(CODE *c, char* op, char* arg1, char* arg2, char* res){
    QUAD* new_quad =  init_quad(op, arg1, arg2, res);
    if (c->num_instru == 0) {
      c->tail = new_quad;
      c->head = new_quad;
    }else{
      c->tail->next = new_quad;
      c->tail       = new_quad;
    }
    c->num_instru++;
}

/*
* Función: search_quad_index
* Descripción: Busca indice en Quad
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020*/
QUAD *search_quad_index(CODE *c,char *i){
  QUAD *q;
  q = c->head;

  while(q!=NULL){
    if (strcmp(q->res,i)==0){
      return q;
    }
    q = q->next;
  }
  printf ("Codigo: El indice %s no se encuentra en el codigo", i);
  return NULL;
}