/* 
 * Programa: juegodedados_h
 * Autores: Daniel Leones 09-10977
 *          Luiscarlo Rivera 09-11020
 * Descripcion: Juego de dados que utiliza hilos para representar jugadores
 * devuelve los resultados en los archivos tiradas_i
 * Ultima actualizaci®Æn: 10/06/2013 9:16pm 
 */

#include "jugadores_h.h"
#include "entrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
* Funcion main
* 
* ejecuta la rutina principal del programa
*/
int main(int argc, char *argv[]) {

  Ganar *max; 
  int semilla=1;
  int semil;
  int nro_jugadores=0;
  pthread_t *jugadores= NULL;
  Ganar **totales = NULL;
  int nro_tiradas=10;
  int i=0;
  Args *datos;

/*Pasaje de parametros*/
  Parametros(&nro_jugadores,&nro_tiradas,&semilla,argc,argv);

/*Datos entrantes del programa */
  system("clear");
  printf("Numero de tiradas: %d\n", nro_tiradas);
  printf("Semilla: %d\n", semilla);
  printf("Numero de jugadores: %d\n", nro_jugadores);

/*Arreglo para identificadores de hilos */
  jugadores=(pthread_t*)malloc(sizeof(pthread_t)*nro_jugadores);

/*Arreglo de apuntadores para resultados de los hilos */
  totales=(Ganar**)malloc(sizeof(Ganar *)*nro_jugadores);

/*Arreglo de datos entrantes para hilos */
  datos=(Args*)malloc(sizeof(Args)*nro_jugadores);

  if ((jugadores==NULL) || (totales==NULL) || (datos==NULL)){
    printf("ERROR: No hay memoria disponible\n");
    exit(1);
  }

  srand(semilla);  

/* Creaci√≥n de Hilos. */ 
  for (i=1; i <=nro_jugadores; i++) {      
    semil=rand();
    Asignardatos(&datos[i-1],nro_tiradas,semil,i);	  
/*AsignarSemilla(&datos[i-1],semil);
AsignarNro_Tiradas(&datos[i-1],nro_tiradas);
AsignarJugador(&datos[i-1],i);*/
if (pthread_create(&jugadores[i-1],NULL,Jugador,(void *) &datos[i-1])!=0) {
  printf("No se pudo crear el thread\n");
}  
}    

/*Retorno de hilos*/
for (i=1; i <=nro_jugadores; i++) {
  if (0!=pthread_join(jugadores[i-1],(void **) &totales[i-1]))
    printf("ERROR: Hilos sin terminar\n");	
/*printf("Num %d %d\n",totales[i-1]->jugador, totales[i-1]->ptos);*/

} 
totales= (Ganar **) totales;

free(datos);
free(jugadores);

/*Declarar ganador*/
max=totales[0];
for (i=1; i <=nro_jugadores; i++){
  if (Obtptos(max) <= Obtptos(totales[i-1]))
    max=totales[i-1];
}  

printf("\n**** Gana el Jugador %d, con %d ptos\n", Obtjugador(max), Obtptos(max));

DestruirGanar(totales,nro_jugadores);
free(totales);

exit(0);
}
