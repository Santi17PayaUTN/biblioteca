#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaFuncionesBasicas.h"
#define T 10
int main()
{  eAbonados listaAbonados[T];
   inicializarEstructura(listaAbonados, T);
   hardcodearDatos(listaAbonados,6);
   MenuOpciones(listaAbonados, T);
}
