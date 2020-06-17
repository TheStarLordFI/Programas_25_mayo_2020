#ifndef TABLACADENAS_H_INCLUDED
#define TABLACADENAS_H_INCLUDED

typedef struct _tablaCadenas tablaCadenas;
typedef struct _cadenas cadenas;

struct _cadenas{
  char *valor;
  cadenas *sig;
};


struct _tablaCadenas{
  int elementos;
  cadenas *head;
  cadenas *tail;
};

cadenas *crearCadena(char *cadena);
tablaCadenas *crearTablaCadenas();
void insertarCadena(tablaCadenas *tabCadenas, cadenas *cadena);

#endif
