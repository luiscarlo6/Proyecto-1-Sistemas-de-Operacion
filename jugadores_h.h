#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FALSE 0
#define TRUE !FALSE

#ifndef __JUGADORES_H_H__
#define __JUGADORES_H_H__
/*Estructura para datos entrantes de los hilos*/
typedef struct {
	int semilla;
	int jugadores;
	int nro_tiradas;
} Argu;

typedef Argu Args;

/*Estructura para devolucion de totales de hilos*/
typedef struct {
	int ptos;
	int jugador;
} Gan;

typedef Gan Ganar;

void* Jugador(void *dat);

int AsignarJugador(Args *caj, int jug);

int AsignarNro_Tiradas(Args *caj, int nro);

int AsignarSemilla(Args *caj, int sel);

int Obtjugador(Ganar *caj);

int Obtptos(Ganar *caj);

int Asignardatos(Args *caj, int nro, int sel, int jug);

int DestruirGanar(Ganar **arglo, int nro_jugadores);

int DestruirArgs(Args *caj);

#endif