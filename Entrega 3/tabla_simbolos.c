/*Fecha: 22/mayo/2020
*Autor: Osmar Juárez Aguilar
*Descripción: El presente código describe que hace cada función que ocuparemos
*             para la creación de una tabla de símbolos. Dichas funciones 
*             se han definido en nuestro archivo tabla_simbolos.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

/*
* Función: append_sym
* Descripción: Inserta un nuevo simbolo al final de la Tabla de simbolos.
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
void append_sym(SYMTAB *tabSimbolos,SYM *simbol){
  int insertado = -1;
  int duplicado = -1;
  if(tabSimbolos->head == NULL){
    tabSimbolos->head = simbol;
    tabSimbolos->tail = simbol;
    insertado = 1;
  } else {
    duplicado = search_id_symbol(tabSimbolos, simbol->id);
    if(duplicado == -1){
      (tabSimbolos->tail)->next=simbol;
      tabSimbolos->tail=simbol;
      insertado = 1;
    }
  }
  if (insertado == 1){
    tabSimbolos->num++;
    printf("\nTabla de simbolos: insertando simbolo: %s", simbol->id);
    //imprimeTS(*tabSimbolos);
    return;
  } else {
    printf("Tabla de simbolos: ERROR! no se inserto el simbolo, el id \"%s\" ya existe\n", simbol->id);
    free(simbol);
    return;
  }
}

/*
* Función:init_sym
* Descripción: reserva memoria para un simbolo vacio
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
SYM *init_sym(){
  SYM *nuevoSYM;
    nuevoSYM= (SYM *)malloc(sizeof(SYM));
    nuevoSYM->next = NULL;
  return nuevoSYM;
}

/*
* Función: finish_sym
* Descripción: Borra una tabla de Simbolos en cualquier parte de la lista
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
void finish_sym(SYMTAB *tabSimbolos, SYM *simbol){
  SYM *aux = NULL;
  SYM *anterior;
  anterior = search_Prev_SYM(tabSimbolos,simbol->id);
    if (anterior == NULL){
      aux = tabSimbolos->head;
      if (tabSimbolos->head == tabSimbolos->tail)
        tabSimbolos->head = tabSimbolos->tail = NULL;
      else
        tabSimbolos->head = aux->next;
    }else{
      aux = anterior->next;
      if (aux == tabSimbolos->tail)
        tabSimbolos->tail = anterior;
      anterior->next = aux->next;
    } 
    printf("Tabla de simbolos: Se ha borrado el simbolo con id \"%s\"\n",simbol->id);
    //imprimeTS(*tabSimbolos);
    free(simbol);
}


/*
* Función: finish_sym_tab
* Descripción: Libera memoria para una tabla de simbolos
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
void finish_sym_tab(SYMTAB *tabSimbolos){
   SYM *aux,*otro;
   aux=tabSimbolos->head;
   while(aux != NULL){
      otro= aux;
      aux = otro->next;
      finish_sym(tabSimbolos, otro);
   }
   printf("Se ha borrado la tabla de simbolos\n");
}


/*
* Función: print_tab
* Descripción: Imprime la tabla de simbolos
* Autor: OJA
* Fecha de creación: 30  de mayo 2020
*/
void print_tab(SYMTAB *tabSimbolos){
  SYM *simbol;
  simbol=tabSimbolos->head;
  printf("\n=======================================================================\n");
  printf("  |                          TABLA DE SIMBOLOS                          |\n");
  printf("=========================================================================\n");
  printf("  |   DIR   |   TIPO   |     ID     |    ARGS    |     NUM    |   VAR   |\n");
  printf("=========================================================================\n");
  while(simbol!=NULL){
    if(simbol->args == NULL)
      printf("|%i\t|%i\t|%s\t| -\t|%i\t|%i\t|\n",simbol->dir,simbol->tipo,simbol->id,simbol->num,simbol->var);
    else if(simbol->args != NULL)
      printf("|%i\t|%i\t|%s\t|%i\t|%i\t|%i\t|\n",simbol->dir,simbol->tipo,simbol->id,simbol->args->num,simbol->num,simbol->var);
    simbol=simbol->next;
  }
  printf("=========================================================================\n");
}

/*
* Función: search_SYM
* Descripción: Regresa el apuntador al simbolo encontrado, si no NULL
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
SYM *search_SYM(SYMTAB *tabSimbolos, char * id){
  SYM *simbol;
  simbol=tabSimbolos->head;
  while(simbol!=NULL){
    if (strcmp(simbol->id,id)==0)
      return simbol;
    simbol = simbol->next;
  }
  return NULL;
}

/*
* Función: buscarIdSimbolo
* Descripción: busca en la Tabla de simbolos el id solicitado y retorna
*   su posición, caso contrario retorna un -1
* Autor: Mendoza Guillen Sergio Adrián
* Fecha de creación: 03 noviembre 2019
*/
int search_id_symbol(SYMTAB *tabSimbolos, char *id){
  SYM *simbol;
  simbol = tabSimbolos->head;
  //printf("Tabla de simbolos: Buscando el id : %s\n",id);
  while(simbol!=NULL){
      if(strcmp(simbol->id,id)==0){
         return simbol->dir;
      }
      simbol = simbol->next;
    }
  //printf("Tabla de simbolos: El id no se enuentra en la tabla \n");
  return -1;
}


/*
* Función:search_Prev_SYM
* Descripción: Debido a que se puede borrar un simbolo en cualquier parte
*   de la lista, necesitamos otra función buscar que nos permita borrarla y no
*   perder la dirección del simbolo anterior
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
SYM *search_Prev_SYM(SYMTAB *tabSimbolos, char *id){
    SYM *simbolAux;
    SYM *anterior = NULL;
    int existeTS = 0;
    simbolAux = tabSimbolos->head;
    while(simbolAux!=NULL){
        if (strcmp(simbolAux->id,id)==0){
            existeTS = 1;
            return anterior;
        }
        anterior = simbolAux;
        simbolAux = simbolAux->next;
    }
    printf ("Tabla de simbolos: ERROR! el simbolo no esta en la lista");
    return NULL;
}

/*
* Función: getTipo
* Descripción: Retorna el tipo de dato de un id, en caso de no en contrarlo retorna −1
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
int getTipo(SYMTAB *st,char *id){
  SYM *simbol=search_SYM(st,id);
  return simbol ? simbol->tipo : -1;
}

/*
* Función: getVar
* Descripción: Retorna el tipo de una variable, en caso de no encontrarla regresa -1
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
int getVar(SYMTAB *st,char *id){
    SYM *simbol = search_SYM(st,id);
  return simbol ? simbol->var : -1;
}

/*
* Función: getDir
* Descripción: Retorna la dirección de un id, en caso de no encontralo retorna -1
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
int getDir(SYMTAB *st,char *id){
  SYM *simbol = search_SYM(st,id);
  return simbol ? simbol->dir : -1;
}

/*
* Función: getArgs
* Descripción: Retorna la lista de argumntos de un id, en caso de no encontarlo retorna null
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
ARGS *getArgs(SYMTAB *st,char *id){
  SYM *aux = search_SYM(st,id);
  return aux ? aux->args : NULL;
}

/*
* Función: getNumArgs
* Descripción: Retorna el # de parameteos de un id, si no lo encuentra retorna -1
* Autor: OJA
* Fecha de creación: 30 de mayo 2020
*/
int getNumArgs(SYMTAB *st,char *id){
  ARGS *lista = getArgs(st,id);
  return lista ? lista->num : -1;
}

/*
* Función: append_arg
* Descripción: Agrega un argumento al final
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
void append_arg(ARGS* args, int arg){
  ARG* temporal;
  ARG* nuevoArg;

  nuevoArg = init_arg(arg);

  if(args->num > 1){

    temporal = args->tail;

    args->tail = nuevoArg;
    temporal->next = nuevoArg;
    nuevoArg->next = NULL;
  }
  else if (args->num = 1)
  {
    args->head->next = nuevoArg;
    args->tail = nuevoArg;
    nuevoArg->next = NULL;
  }else
  {
    args->head = nuevoArg;
    args->tail = nuevoArg;
    nuevoArg->next = NULL;
  }
  
      args->num ++;

}


/*
* Función: compare_args
* Descripción: Compara dos listas y devuelve 1 si son iguales, 0 si son diferentes
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
int compare_args(ARGS *a1, ARGS *a2){
  int i;

  if (a1->num == a2->num)
  {
    ARG* temp1;
    ARG* temp2;

    temp1 = a1->head;
    temp2 = a2->head;

      for (i = 0; i < a1->num; i++)
      {
        if (temp1->arg != temp2->arg)
        {
          printf("Las listas de argumentos son diferentes\n");
          return 0;
        }else{
          temp2 = temp2->next;
          temp1 = temp1->next;
        } 
      }

      printf("Las listas de argumentos son iguales\n");
      return 1;
      
      
  }else{
    printf("Las listas de argumentos son de diferente tamanio\n");
    return 0;
  }

}

/*
* Función: pop_st
* Descripción: Ejecuta un pop sobre la pila de tablas de simbolos
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
SYMTAB pop_st(SSTACK *s){
  SYMTAB* temp;
  temp = s->top;
  s->top = temp->next;
  //s->numeroelementos --;
  printf("Se ha sacado una tabla de simbolos\n");
  return *temp;
}

/*
* Función: push_st
* Descripción: Ingresa una tabla a la pila de tablas de simbolos
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
void push_st (SSTACK *s,SYMTAB *st){
  st->next = s->top;
  s->top = st;
  //s->numeroelementos ++;
  printf("Se ha insertado una tabla de simbolos\n");
}

/*
* Función: init_args
* Descripción: Retorna el apuntador a un tipo ARGS
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
ARGS *init_args(){
  ARGS* nuevoArgs;
  nuevoArgs = (ARGS*)malloc(sizeof(ARGS));
  nuevoArgs->head = NULL;
  nuevoArgs->num = 0;
  nuevoArgs->tail=NULL;
  printf("Creando nueva lista de argumentos\n");
  return nuevoArgs;
}

/*
* Función: init_arg
* Descripción: Reserva memoria para un tipo ARG y retrona el apuntador
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
ARG *init_arg(int dato){
  ARG* nuevoArg;
  nuevoArg = (ARG*)malloc(sizeof(ARG));
  nuevoArg->arg = dato;
  nuevoArg->next = NULL;
  printf("Creando nuevo argumento\n");
  return nuevoArg;
}

/*
* Función: init_sym_tab_stack
* Descripción: Reserva memoria para la pila
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
SSTACK *init_sym_tab_stack(){
  SSTACK* nuevaPila;
  nuevaPila = (SSTACK*)malloc(sizeof(SSTACK));
  //nuevaPila->numeroelementos = 0;
  nuevaPila->tail = NULL;
  nuevaPila->top = NULL;
  printf("Creando nueva pila de simbolos");
  return nuevaPila;
}

/*
* Función: init_sym_tab
* Descripción: Reserva memoria para una tabla de simbolos vacia
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
SYMTAB *init_sym_tab(){
  SYMTAB* nuevaTablaS;
  nuevaTablaS = (SYMTAB*)malloc(sizeof(SYMTAB));
  nuevaTablaS->head = NULL;
  nuevaTablaS->next = NULL;
  nuevaTablaS->num = 0;
  nuevaTablaS->tail = NULL;
  printf("Creando nueva tabla de simbolos");
  return nuevaTablaS;
}

/*
* Función: finish_sym_tab_stack
* Descripción: Libera la memoria para la pila
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
void finish_sym_tab_stack(SSTACK *s){
  SYMTAB* tSimbolos;
  SYMTAB* tAux;
  tSimbolos = s->top;
  while (tSimbolos->next != NULL)
  {
    tAux = tSimbolos;
    tSimbolos = tSimbolos->next;
    free(tAux);
  }

  free(s);

  printf("Se ha borrado toda la pila de simbolos");
  
}

/*
* Función: finish_arg
* Descripción: Libera memoria para un arg
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
void finish_arg(ARG *s){
  free(s);
  printf("Se ha borrado un argumento");
}

/*
* Función: finish_args
* Descripción: Libera memoria para una lista ARGS
* Autor: Morales Garcia Luis
* Fecha de creación: 31 de mayo 2020
*/
void finish_args(ARGS *s){
  ARG* argumento;
  ARG* arAux;
  argumento = s->head;
  while (argumento->next != NULL)
  {
    arAux = argumento;
    argumento = argumento->next;
    finish_arg(arAux);
  }

  free(s);

  printf("Se ha borrado toda la pila de argumentos");
}
