#include <stdio.h>
#include <stdlib.h>

#ifndef __CAJA_H__
#define __CAJA_H__

void ayuda();

void error();

int tipoArg(char *arg);

int modifDato(int datos[], char *arg,char *num);

int jugar(int semilla, int tiradas, int jugador);

#endif