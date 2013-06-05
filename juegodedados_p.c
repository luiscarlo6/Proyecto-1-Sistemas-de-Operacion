#include "funciones.h"
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
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
    int datos[3]; 
    int result = 31;
    datos[0] = 10; /*num_tiradas*/
    datos[1] = 1; /*semill*/
    datos[2] = 1; /*num_jug */
    switch(argc){
        case 1:
            break;
        case 2:
            if (tipoArg(argv[1])==4){
                ayuda();
            }
            else{
                error();
            }
            exit(EXIT_FAILURE);
            
        case 3:
            if (modifDato(datos,argv[1],argv[2]) == -1)
                error();
            break;
        case 5:
            if(modifDato(datos,argv[1],argv[2]) == -1 ||
               modifDato(datos,argv[3],argv[4]) == -1)
                error();
            break;
        case 7:
            if(modifDato(datos,argv[1],argv[2]) == -1 || 
               modifDato(datos,argv[3],argv[4]) == -1 || 
               modifDato(datos,argv[5],argv[6]) == -1)
                error();
            break;
        default:
            error();
            exit(EXIT_FAILURE);
            
    }
    printf("Numero de tiradas: %d\n",datos[0]);
    printf("Semilla: %d\n",datos[1]);
    printf("Jugadores: %d\n",datos[2]);
    
    srand(datos[1]);
    semillas = malloc(sizeof(int)*(datos[2]));
    for (i = 0;i<datos[2];i++){
        semillas[i] = rand();
    }
    
    hijos = malloc(sizeof(pid_t)*(datos[2]));
    for(i = 0; i<datos[2];i++){
        if ((childpid = fork())<0){
            perror("fork");
            exit(1);
        }
        if(childpid == 0){
            hijos[i] = getpid();
            result = jugar(semillas[i],datos[0], i+1);
            exit(result);
        }
    }
    resultados = malloc(sizeof(int)*(datos[2]));
    for (i = 0; i<datos[2]; i++){
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