#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void ayuda(){
    printf("juegodedados_p: imprime una secuencia de numeros aleatorios\n");
    printf("SINTAXIS:\n");
    printf("juegodedados_p [-n i] [-s x] [-h]\n");
    printf("-n i: tamaño de la secuencia (por defecto, 10)\n");
    printf("-s x: semilla (por defecto, 1)\n");
    printf("-j y: numero de jugadores (por defecto 1)\n");
    printf("-h: imprime esta ayuda y sale\n");
}

void error(){
    printf("Opcion incorrecta\nUse 'juegodedados_p -h' para más información\n");
    exit(EXIT_FAILURE);
}

/**
 * 0 si no es ninguno
 * 1 si es -n
 * 2 si es -s
 * 3 si es -j
 * 4 si es -h
 */
int tipoArg(char *arg){
    if (strcmp(arg,"-n")==0)
        return 1;
    else if (strcmp(arg,"-s")==0)
        return 2;
    else if (strcmp(arg,"-j")==0)
        return 3;
    else if (strcmp(arg,"-h")==0)
        return 4;
    else
        return 0;
}

int modifDato(int datos[], char *arg, char *num){
    int tArg = tipoArg(arg);
    int numero = atoi(num);
    if (numero<0)
        return -1;
    switch(tArg){
        case 1:
            datos[0] = numero;
            return 0;
        case 2:
            datos[1] = numero;
            return 0;
        case 3: 
            datos[2] = numero;
            return 0;
        default:
            return -1;
    }
}
int jugar(int semilla, int tiradas, int jugador){
    int i;
    int dado;
    int acum = 0;

    srand(semilla);
    
    
    /*printf("Semilla: %d\n",semilla);
    printf("Numero de tiradas: %d\n",tiradas);*/
    for (i = 0; i<tiradas;i++){
        dado = (rand() % 6)+1;
        /*printf("Tirada %d: %d\n",i+1,dado);*/
        acum+=dado;
    }
    printf("Jugador: %d\nTOTAL: %d\n",jugador,acum);
        
    return acum;
}