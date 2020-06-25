/*Fecha: 15/junio/2020
*Autor: Osmar Juárez Aguilar
*Descripción: El preente archivo hace un test de las estructuras de las
*             tablas de simbolos y de tipos, sus respectivas pilas y sus
*             respectivas funciones de cada una de las estructuras.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//aqui solo incluye el heder del .h de cuadruplas

#include "cuadruplas.h"

int contTemp = 0;


QUAD *init_quad(char* op, char* arg1, char* arg2, char* res){
  QUAD* new_quad = (QUAD*)malloc(sizeof(QUAD));
  strcpy(new_quad->op, op);
  strcpy(new_quad->arg1, arg1);
  strcpy(new_quad->arg2, arg2);
  strcpy(new_quad->res, res);
  new_quad->next  = NULL;
  return new_quad;
}

void finish_quad(QUAD *c){
  free(c);
  printf("Se ha eliminado una cuadrupla");
}

CODE* init_code(){
  CODE* new_code = (CODE*)malloc(sizeof(CODE));
  new_code->num_instru = 0;
  new_code->head = NULL;
  new_code->tail = NULL;
  return new_code;
}

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

void append_new_quad(CODE *c, char* op, char* arg1, char* arg2, char* res){
    QUAD* new_quad =  init_quad(op, arg1, arg2, res);
    if (c->num_instru == 0) {
      c->tail = new_quad;
      c->head = new_quad;
    }else{
      c->tail->next = new_quad;
      c->tail       = new_quad;
    }
    append_quad(c,new_quad);//se agrega la cuadrupla creada
    c->num_instru++;
}

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

char* newTemp(){
  contTemp++;
  char *n=(char*)malloc(sizeof(char));
  char *tem=(char*)malloc(sizeof(char));
  strcpy(n,"tmp");
  sprintf(tem, "%i", contTemp);
  strcat(n,tem);
  return n;
} 



int main(){
    printf("====================Ejecutando pruebas====================\n");
    
    CODE* new_code;
    CODE *code = NULL;
    code = init_code(code);
    if(code ==NULL){
        printf("Test init_code ================= OK \n");
    }else{
        printf("Test init_code ================= FAILED \n");        
    }
    
    if(init_code == NULL){
        printf("Test init_code() ========================== FAILED \n");
    }else{
        print_tab_type(init_code);
    }
}
