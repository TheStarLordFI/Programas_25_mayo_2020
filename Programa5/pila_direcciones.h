#ifndef PILADIRECCIONES_H_INCLUDED
#define PILADIRECCIONES_H_INCLUDED

typedef struct pilaDirecciones DSTACK;
typedef struct dir DIR;

struct dir{
  int info;
  DIR *sig;
};

struct pilaDirecciones{
  DIR *tope;
  int elementosPila;
};

DIR *crearDir();
DSTACK *crearPilaDir();
void imprimePDir(DSTACK pilaDir);
void borrarPDir(DSTACK *pilaDir);
void pushPDir(DIR *direccion,DSTACK *pilaDir);
DIR *getCimaPDir(DSTACK *pilaDir);
DIR *popPDir(DSTACK *pilaDir);
#endif
