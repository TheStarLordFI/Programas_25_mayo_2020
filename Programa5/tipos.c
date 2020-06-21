/*Fecha: 10/junio/2020
*Autor: Osmar Juárez Aguilar
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tipos.h"

int conta_tmp = 0; //contador gobal de teporales creadas

/*
* Función: nuevaTemp
* Descripción: Reserva memoria y retorna la diracción de inicio de la nueva variable.
* Autor: OJA
* Fecha de creación: 10 de junio 2020
*/
char* nuevaTemp(){
    conta_tmp++;
    char *n=(char*)malloc(sizeof(char));
    char *tem=(char*)malloc(sizeof(char));
    strcpy(n,"tmp");
    sprintf(tem, "%i", conta_tmp);
    strcat(n,tem);
    return n;
}

/*
* Función: ampliar
* Descripción: Si el primero es mas chico que el segundo genera la cuadrupla 
*              para realizar la apmpliacion del tipo.
*              Retorna la nueva direccion generada por la ampliacion
*              o la direccion original en caso de que no se realice
*              ID dreal =4 , ID real = 1, ID ent = 0, ID car = 2
* Autor: OJA
* Fecha de creación: 10 de junio 2020
*/
char *ampliar(char *dir, int t1, int t2, CODE *c){
    char* nuevaDir = (char*)malloc(sizeof(char));
    char *ent = "(ENT)";
    char *real = "(REAL)";
    char *dreal = "(DREAL)";
    char *igual = " ";

    if(t1 == t2){
        nuevaDir = dir;
    }else if(t2 == 4 && (t1 == 0 || t1 == 1 || t1 == 2)){ //ampliacion a dreal
        nuevaDir = nuevaTemp();
        append_new_quad(c, dreal,igual,dir,nuevaDir);
    }else if (t2 == 1 && (t1 == 0 || t1 == 2 )){ //ampliacion a real
        nuevaDir = nuevaTemp();
        append_new_quad(c, real,igual, dir,nuevaDir);
    }else if (t2 == 0 && t1 == 2){ //ampliacion a ent
        nuevaDir = nuevaTemp();
        append_new_quad(c, ent,igual, dir, nuevaDir);
    }else{
        printf("ERROR: No es posible hacer una del tipo ampliación\n");
        nuevaDir = NULL;
    }
  
  return nuevaDir;
}

/*
* Función: reducir
* Descripción: Recibe dos tipos, cada uno es su indice hacia la tabla de tipos en la cima de la pila
*              Si el primero es mas grande que el segundo genera la cuadupla 
*              para realizar la reduccion del tipo 
*              Retorna la nueva direccion generada por la reduccion 
*              o la rireccion original en caso de que no se realice.
*              ID dreal =4 , ID real = 1, ID ent = 0, ID car = 2
* Autor: OJA
* Fecha de creación: 10 de junio 2020
*/
char *reducir(char *dir, int t1, int t2, CODE *c){
    char* nuevaDir=(char*)malloc(sizeof(char));
    char *car = "(CAR)";
    char *real = "(REAL)";
    char *ent = "(ENT)";
    char *igual = " ";

    if (t1 == t2) {
        nuevaDir = dir;
    } else if (t1 == 4 && t2 == 1) { //Reducción a real
        nuevaDir = nuevaTemp();
        append_new_quad(c, real,igual, dir,nuevaDir);
    } else if ((t1 == 4 || t1 == 1) && t2 == 0) { //Reducción a ent
        nuevaDir = nuevaTemp();
        append_new_quad(c, ent,igual, dir,nuevaDir);
    } else if ((t1 == 4 || t1 == 1 || t1 == 0) && t2 == 2) { //Reducción a car
        nuevaDir = nuevaTemp();
        append_new_quad(c, car,igual, dir,nuevaDir);
    } else {
        printf("ERROR:No es posible hacer la reducción\n");
        nuevaDir =NULL;
    }
    return nuevaDir;
}

/*
* Función: max
* Descripción: Recibe dos tipos, cada uno es indice hacia la tabla de tipos en la cima 
*              de la pila retorna el indice de mayor dimension. Si no existe el tipo retorna -1
*              De acuerdo al ID de los tipos nativos ID dreal =4 , ID real = 1, ID ent = 0, ID car = 2
* Autor: OJA
* Fecha de creación: 10 de junio 2020
*/
int max(int t1, int t2){
    int tipos[] = {4,1,0,2};
    for (int i = 0; i < 4; i++){
        if(tipos[i]==t1){
            return t1;
        }else if(tipos[i]==t2){
            return t2;
        }
    }
    return -1;
}

/*
* Función: min
* Descripción: Recibe dos tipos, cada uno es indice hacia la tabla de tipos en la cima 
*              de la pila retorna el indice de menor dimension. Si no existe el tipo retorna -1.
*              De acuerdo al ID de los tipos nativos ID car = 2, ID ent = 0,, ID real = 1, ID dreal =4 
* Autor: OJA
* Fecha de creación: 10 de junio 2020
*/
int min(int t1, int t2){
    int tipos[] = {2,0,1,4};
    for (int i = 0; i < 4; i++){
        if(tipos[i]==t1){
            return t1;
        }else if(tipos[i]==t2){
            return t2;
        }
    }
    return -1;
}