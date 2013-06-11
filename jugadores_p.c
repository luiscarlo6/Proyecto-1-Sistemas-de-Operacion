#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugadores_p.h"


/**
 * Funcion: jugar
 * un proceso creado por "juegodedados_p" usa esta funcion
 * para jugar el juego de dados
 */
int jugar(int semilla, int tiradas, int jugador){
    int i;
    int dado;
    int acum = 0;
    char * nomArch = malloc(sizeof(char)*(15));    
    FILE *archJug;

    sprintf(nomArch, "%s_%d","tiradas",jugador);
    archJug = fopen(nomArch, "w+");
    fprintf(archJug,"Jugador: %d\n",jugador);
    fprintf(archJug,"Numero de tiradas: %d\n",tiradas);
    srand(semilla);

    for (i = 0; i<tiradas;i++){
        dado = (rand() % 6)+1;
        fprintf(archJug,"Tirada %d: %d\n",i+1,dado);
        acum+=dado;
    }
    fprintf(archJug,"TOTAL: %d\n",acum);
    fclose(archJug);
    free(nomArch);
    return acum;
}