#include "funciones.h"
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * Funcion main
 * 
 * ejecuta la rutina principal del programa
 */
int main(int argc, char *argv[])
{
    pid_t childpid;
    int datos[3]; 
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
    
    if((childpid = fork())==0){
        fprintf(stderr,"Soy hijo PID: %d\n",getpid());
    }
    else if (childpid>0){
        fprintf(stderr,"Soy padre PID: %d\n",getpid());
    }
    return 0;
}