#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE

#ifndef __ENTRADA_H__
#define __ENTRADA_H__

void imprime_ayuda(char* nombre);

int Parametros(int *nro_jugadores, int *nro_tiradas, int *semilla, int argc, char **argv);

#endif