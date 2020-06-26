#include <stdio.h>
#include <stdlib.h>
#include "pila_direcciones.h"

/*
* Función: nuevaDir
* Descripción: Crea un nuevo nodo en la pila de direcciones
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
DIR *crearDir(){
  DIR *direccion;
  direccion = (DIR *)malloc(sizeof(DIR));
  direccion->info = 0;
  direccion->sig = NULL;
  return direccion;
}

/*
* Función: crearPilaDir
* Descripción: Crea pila de direcciones
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
DSTACK *crearPilaDir()
{
  printf("Creando la pila de direcciones\n");
  DSTACK *pilaDir;
  pilaDir=(DSTACK*)malloc(sizeof(DSTACK));
  pilaDir->tope=NULL;
  pilaDir->elementosPila = 0;
  return pilaDir;
}

/*
* Función: borrarPDir
* Descripción: borra toda la piila de direcciones
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
void borrarPDir(DSTACK *pilaDir){
  
  DIR *direccion,* dirAux;
  direccion = pilaDir->tope;
  while(direccion != NULL)
  {
    dirAux = direccion;
    direccion = direccion->sig;
    free(dirAux);
  }
  free(pilaDir);
  pilaDir->elementosPila=0;

  printf("Pila de Direcciones: Borrando toda la pila\n");
}

/*
* Función: pushPDir
* Descripción:Inserta en la pila de direcciones una nueva direccion
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
void pushPDir(DIR *direccion, DSTACK *pilaDir){
  direccion->sig = pilaDir->tope;
  pilaDir->tope = direccion;
  pilaDir->elementosPila++;
  printf("Pila de Direcciones: Se ha insertado una direccion\n");
}

/*
* Función: imprimePDir
* Descripción:Imprime todo el contenido de la pila de direcciones
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
void imprimePDir(DSTACK *pila){
    DIR *direccion;
    direccion=pila->tope;
    if (pila->tope!=NULL){
      printf("\n=====================================\n");
      printf("|         PILA DE DIRECCIONES       |\n");
      printf("=====================================\n");
      while(direccion!=NULL){
        printf("%i\n", direccion->info);
        printf("=====================================\n");
        direccion=direccion->sig;
      }
    }
    else
     printf("No hay datos en la pila...");
    printf("\n");
}

/*
* Función: getCimaPDir
* Descripción:regresa el elemento que se encuentra en la cima de la pila
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
DIR *getCimaPDir(DSTACK *pilaDir){
  return pilaDir->tope;
}

/*
* Función: popPDir
* Descripción:Quita un elemento de la pila
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 20 de Junio
*/
DIR *popPDir(DSTACK *pilaDir){
  DIR *direccion;
  direccion=pilaDir->tope;
  pilaDir->tope=direccion->sig;
  pilaDir->elementosPila--;
  printf("Pila de Direcciones: Se ha sacado una direccion\n");
  return direccion;
}
