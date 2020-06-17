#ifndef LISTAINDEX_H_INCLUDED
#define LISTAINDEX_H_INCLUDED

typedef struct _myIndex myIndex;
typedef struct _listIndex listIndex;
typedef struct _label label;

struct _listIndex{
  myIndex *head;
  myIndex *tail;
  int elementos;
};

struct _myIndex{
  int valorMyIndex;
  myIndex *sig;
};

myIndex *crearIndex();
listIndex *crearListIndex();
char *crearLabel();
void insertarIndex(listIndex *listIndice, myIndex *indice);
listIndex *combinar(listIndex *lista1, listIndex *lista2);

#endif