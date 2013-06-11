/* 
 * Programa: juegodedados_p
 * Autores: Daniel Leones 09-10977
 *          Luiscarlo Rivera 09-11020
 * Descripcion: Juego de dados que utiliza procesos para representar jugadores
 * devuelve los resultados en los archivos tiradas_i
 * Ultima actualización: 10/06/2013 9:19pm 
 */
#include "jugadores_p.h"
#include "entrada.h"

/**
* Funcion main
* 
* ejecuta la rutina principal del programa
*/
int main(int argc, char *argv[])
{
    pid_t childpid;
    pid_t *hijos;
    int ganador = -1;
    int mayor = -1;
    int *semillas;
    int *resultados;
    int status;
    int i;
    int result = 31;
    int nro_tiradas = 10;
    int semilla = 1;
    int nro_jugadores = 0;

/*Pasaje de parametros*/
    Parametros(&nro_jugadores,&nro_tiradas,&semilla,argc,argv);
    system("clear");
    printf("Numero de tiradas: %d\n",nro_tiradas);
    printf("Semilla: %d\n",semilla);
    printf("Jugadores: %d\n",nro_jugadores);

    
    semillas = malloc(sizeof(int)*(nro_jugadores));
    if (semillas==NULL){
        printf("ERROR: No hay memoria disponible\n");
        exit(1);
    }
    
    srand(semilla);
    /*Genera las semillas para cada proceso*/
    for (i = 0;i<nro_jugadores;i++){
        semillas[i] = rand();
    }

    hijos = malloc(sizeof(pid_t)*(nro_jugadores));
    if (hijos==NULL){
        printf("ERROR: No hay memoria disponible\n");
        exit(1);
    }
    
    /*Creacion de i procesos hijos(CROUPIER)*/
    for(i = 0; i<nro_jugadores;i++){
        if ((childpid = fork())<0){
            perror("fork");
            exit(1);
        }
        if(childpid == 0){
            hijos[i] = getpid();
            result = jugar(rand(),nro_tiradas, i+1);
            free(hijos);
            free(semillas);
            exit(result);
        }
    }

    resultados = malloc(sizeof(int)*(nro_jugadores));
    if (resultados==NULL){
        printf("ERROR: No hay memoria disponible\n");
        exit(1);
    }

    /*Buscar ganador*/
    for (i = 0; i<nro_jugadores; i++){
        waitpid(hijos[i],&status,0);
        resultados[i] = WEXITSTATUS(status);
        if (resultados[i]>mayor){
            mayor = resultados[i];
            ganador = i;
        }
    }

    printf("Gana el jugador %d, con %d puntos\n\n",ganador+1, mayor);
    free(hijos);
    free(resultados);
    free(semillas);
    return 0;
}