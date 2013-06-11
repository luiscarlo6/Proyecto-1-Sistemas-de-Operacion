#include "entrada.h"

/* Función: imprime_ayuda
Entrada: Cadena de caracteres
Salida: Nula
Descripcion: Imprime en la linea de comando ayuda sobre el uso del programa
*/
void imprime_ayuda(char* nombre) {
    printf("%s: imprime una secuencia de numeros aleatorios\n",nombre);
    printf("SINTAXIS:\n");
    printf("juegodedados_p [-n i] [-s x] [-h]\n");
    printf("-n i: tamaño de la secuencia (por defecto, 10)\n");
    printf("-s x: semilla (por defecto, 1)\n");
    printf("-j y: numero de jugadores (por defecto 1)\n");
    printf("-h: imprime esta ayuda y sale\n");
}

/* Función: Parametros
Entrada: *nro_jugadores, *nro_tiradas,*semilla, argc: Nro de parametros
    de Main, **argv: Arreglo de entrada de Main
Salida: *nro_jugadores, *nro_tiradas,*semilla. TRUE: Exito. Errores:
Finaliza el programa
Descripcion: Procesa el pasaje de parametros por linea de comandos
    según la convencion de los sistemas Linux
*/ 
    int Parametros(int *nro_jugadores, int *nro_tiradas, int *semilla, int argc, char **argv) {

        int opciones;   
/* Parametros con : tienen argumentos obligatorios. Con :: son opcionales.
Sin ellos no requieren argumentos. Parece que los compiladores del LDC
interpretan distinto la regla. Debe someterse a prueba */
char *parametros = "n:s:j:h";
*nro_tiradas = 10;
*semilla = 1;
while (-1!=(opciones=getopt(argc, argv, parametros))) {
    switch (opciones) {	
/* "-n i" indica el numero de tiradas (i) que hara cada jugador. */
        case 'n' :
        if (atoi(optarg) > 20 ) {
            printf("El numero de tiradas no debe exceder de 20\n");
            exit(1);
        }
        if (atoi(optarg) < 1 ) {
            printf("Numero de tiradas incorrecto\n");
            exit(1);
        }
        *nro_tiradas=atoi(optarg);
/* printf("Valor: %d", *nro_tiradas); */
        continue;
/* "-s x", el argumento x es un entero. La semilla que utiliza
croupier */
        case 's' :
        *semilla=atoi(optarg);
        continue;
/* "-j y" indica el numero de jugadores.  */
        case 'j' :			
        *nro_jugadores=atoi(optarg);
        continue;
/* Parametros invalidos */
        case '?' : 
        printf("Opcion incorrecta\n");
        printf("Use 'juegodedados_p -h' para más información\n");
        exit(1);
/*Imprime ayuda*/
        case 'h' :
        imprime_ayuda(argv[0]);
        exit(0);
/* Parametros no reconocidos*/
        default : 
        printf("Opcion incorrecta\n");
        printf("Use 'juegodedados_p -h' para más información\n");   
        exit(1);
    }

}

if (*nro_jugadores<=0){
/*printf("Jug: %d %d %d\n",*nro_jugadores, *nro_tiradas, *semilla);*/
    printf("Debe suministrar el numero de jugadores con [-j y]\n");
    printf("O use la ayuda [-h] para mas imformaciono\n");
    exit(1);

}
return TRUE;
}