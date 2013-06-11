#include "jugadores_h.h"

/* Función: Jugador (Hilo)
Entrada: Estructura generica (Args)
Salida: Estructura Ganar
Descripcion: Con los parametros Args, se crea una archivo de texto
Tiradas_i.txt, en el se escribe los resultados. Se retorna una
estructar Ganar con el resultado final.

*/
void *Jugador(void* dat) {

  Args *nes = (Args *) dat; 
  int dado= 0;
  int i=1;
  int total=0;
  Ganar *jug= NULL;
  FILE *fd;
  char nombre[30]=" ";

  srand(nes->semilla);

/*Creacion del archivo tirada_i*/
  sprintf(nombre,"tiradas_%d", nes->jugadores);
  fd=fopen(nombre,"w");
  if (fd == NULL) {
    printf("ERROR: No se creó el archivo\n");
  }

  fprintf(fd, "Jugador: %d\n", nes->jugadores);
  fprintf(fd, "Numero de tiradas: %d\n", nes->nro_tiradas);

/*Suma de dados y totales. Impresion sobre el archivo*/
  for (i=1; i <=nes->nro_tiradas; i++){
    dado=(rand()%6)+1;
    dado=dado+((rand()%6)+1);
    total+=dado;
    fprintf(fd,"Tirada %d: %d\n", i, dado);      
  }
  fprintf(fd,"Total: %d\n", total);

  fclose(fd);

/*Creacion de la estructura de datos finales. Salida del hilo*/
  jug=(Ganar*)malloc(sizeof(Ganar));
  if (jug == NULL) {
    printf("ERROR: Datos sin retornar\n");
  }
  jug->jugador=nes->jugadores;
  jug->ptos=total; 

  pthread_exit(jug);  
}


int DestruirArgs(Args *caj){

  if (caj == NULL) 
    return -1;
  caj->semilla=0;
  caj->nro_tiradas=0;
  caj->jugadores=0;
  free(caj);
  return TRUE;
}

/* Función: DestruirGanar
Entrada: Apuntador a arreglo de apuntadores de Estructura Ganar
Salida: TRUE Exito en la destruccion; FALSE Error
Descripcion: Libera memoria de las posiciones de memoria de arglo 
*/

int DestruirGanar(Ganar **arglo, int nro_jugadores){

  int i=0;
  if (arglo == NULL) 
    return FALSE;

  for (i=0; i < nro_jugadores; i++){
    free(arglo[i]);
  }
  return TRUE;
}
/* Función: Obtptos
Entrada: Estructura Ganar
Salida: Entero
Descripcion: Devuelve el contenido del campo ptos 
*/
int Obtptos(Ganar *caj){

  if (caj == NULL) 
    return -1;

  return caj->ptos;
}

/* Función: Obtjugador
Entrada: Estructura Ganar
Salida: Entero
Descripcion: Devuelve el contenido del campo jugador 
*/
int Obtjugador(Ganar *caj){

  if (caj == NULL) 
    return FALSE;

  return caj->jugador;
}

/* Función: AsignarSemilla
Entrada: Estructura Args, Entero
Salida: TRUE: Exito en la asignación, FALSE Error
Descripcion: Asigna un valor entero en el campo semilla
*/
int AsignarSemilla(Args *caj, int sel){

  if (caj == NULL) 
    return FALSE;

  caj->semilla=sel;
  return TRUE;
}

/* Función: AsignarNro_Tiradas
Entrada: Estructura Args, Entero
Salida: TRUE: Exito en la asignación, FALSE Error
Descripcion: Asigna un valor entero en el campo nro_tiradas
*/
int AsignarNro_Tiradas(Args *caj, int nro){

  if (caj == NULL) 
    return FALSE;

  caj->nro_tiradas=nro;
  return TRUE;
}

/* Función: Asignardatos
Entrada: Estructura Args, Enteros
Salida: TRUE: Exito en la asignación, FALSE Error
Descripcion: Asigna valores enteros en el campo nro_tiradas, jugadores, semilla
*/
int Asignardatos(Args *caj, int nro, int sel, int jug){

  if (caj == NULL) 
    return FALSE;

  caj->nro_tiradas=nro;
  caj->jugadores=jug;
  caj->semilla=sel;
  return TRUE;
}

/* Función: AsignarJugador
Entrada: Estructura Args, Entero
Salida: TRUE: Exito en la asignación, FALSE Error
Descripcion: Asigna un valor entero en el campo jugadores
*/
int AsignarJugador(Args *caj, int jug){

  if (caj == NULL) 
    return FALSE;

  caj->jugadores=jug;
  return TRUE;
}
