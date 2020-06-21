/*Fecha: 13/junio/2020
*Autor: Luis Angel Morales Garcia
*Descripción: El presente código contiene la deficion de las fuciones de 
*             backpatch.h 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backpatch.h"

int contLabel=0;
int contadorIndices=0;

/*
* Función: init_index
* Descripción: Reserva memoria para un nodo de indice
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
INDEX *init_index(){
    INDEX *nuevoInd;
    contadorIndices++;
    nuevoInd = (INDEX*)malloc(sizeof(INDEX));
    nuevoInd->indice =contadorIndices;
    nuevoInd->next = NULL;
    return nuevoInd;
} 

/*
* Función: finishindex
* Descripción: Libera la memoria de un nodo indice
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
void finish_index(INDEX *i){
    free(i);
    printf("Se ha borrado un indice");
}

/*
* Función: init_list_index
* Descripción: Reserva memoria para la lista de indice se inserta el primero
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
LINDEX *init_list_index(INDEX *i){
    LINDEX *listIndice;
    listIndice = (LINDEX*)malloc(sizeof(LINDEX));
    if (i != NULL)
    {
        listIndice->numelemt = 1;
        listIndice->head = i;
        listIndice->tail = i;    
    }
    else
    {
        listIndice->numelemt = 0;
        listIndice->head = NULL;
        listIndice->tail = NULL; 
    }

    return listIndice;
}

/*
* Función:finish_list_index
* Descripción: Libera la memoria de la lista y de todos los nodos dentro
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
void finish_list_index(LINDEX *l){
    INDEX* iAuxRecorrer;
    INDEX* iAux;
    iAuxRecorrer = l->head;
    while (iAuxRecorrer->next != NULL)
    {
        iAux = iAuxRecorrer;
        iAuxRecorrer = iAuxRecorrer->next;
        finish_index(iAux);
    }

    free(l);

    printf("Se ha borrado toda la lista de indices");
}

/*
* Función:append_index
* Descripción: Agrega un nodo indice al final de la lista
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
void append_index(LINDEX *l,INDEX *i){
    if(l->head == NULL){
        l->head = i;
        l->tail = i;
        l->numelemt ++;
    }
    else {
        l->tail->next = i;
        l->tail = i;
        i->next = NULL;
        l->numelemt ++;
    }
}

/*
* Función:combinar
* Descripción: Retorna una lista ligada de la concatenacion de l1 con l2
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
LINDEX *combinar(LINDEX *l1,LINDEX *l2){
    LINDEX *l3;
    l3 = (LINDEX*)malloc(sizeof(LINDEX));
    if (l1 == NULL && l2 == NULL ){
        return l3;
    }
    else if(l1 == NULL ){
        l3->head = l2->head;
        l3->tail = l2->tail;
    }
    else if (l2 == NULL){
        l3->head = l1->head;
        l3->tail = l1->tail;
    }
    else if ((l2->head != NULL && l2->tail!= NULL) && (l1->head != NULL && l1->tail!= NULL) ){
        l3->head = l1->head;
        l3->tail = l1->tail;
        l3->tail->next = l2->head;
        l3->tail = l2->tail;
    }
    return l3;
}

/*
* Función:create_label
* Descripción: Crea una nueva etiqueta 
* Autor: Juarez Aguilar Osmar
* Fecha de creación: 14 de junio 2020
*/
char *create_label(){
    char *label=(char*)malloc(sizeof(char));
    char *tmp=(char*)malloc(sizeof(char));
    strcpy(label, "L");
    sprintf(tmp, "%i", contLabel);
    strcat(label, tmp);
    contLabel++;
    return label;
}

/*
* Función:backpatch
* Descripción: Reemplaza label en cada aparicion de un indice en la cuadruplas del codigo c
* Autor: Morales Garcia Luis
* Fecha de creación: 13 de junio 2020
*/
void backpatch(CODE *c, LINDEX *l, char *label){
    QUAD *q = (QUAD*)malloc(sizeof(QUAD));
    INDEX *i;
    char *tmp=(char*)malloc(sizeof(char));
 
    if(l!=NULL){
        i = l->head;
        while(i != NULL){
            sprintf(tmp, "%i", i->indice);
            q = search_quad_index(c,tmp);
            if (q!=NULL){
                strcpy(q->res, label);
      
            }
            i = i->next;
        }
    }
}