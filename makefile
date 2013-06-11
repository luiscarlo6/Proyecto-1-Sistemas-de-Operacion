#Makefile
#Archivo usado para compilar el programa
#Autores : 	Luiscarlo Rivera 09-11020
#		Daniel Leones 09-10977
#basado en los makefile de ejemplos de aula virtual

CC = gcc
RMFLAGS = -fv 
CFLAGS = -g -pedantic -Wextra -Wall -ggdb -Wunreachable-code
OBJS1 = juegodedados_p.o entrada.o jugadores_p.o
OBJS2 = juegodedados_h.o entrada.o jugadores_h.o
PROG1 = juegodedados_p
PROG2 = juegodedados_h


all : clean $(PROG1) $(PROG2)

$(PROG1): $(OBJS1)
		$(CC) $(CFLAGS) $(OBJS1) -o $(PROG1)
$(PROG2): $(OBJS2)
		$(CC) $(CFLAGS) $(OBJS2) -lpthread -o $(PROG2)

%.o: %.c  
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) $(PROG1) $(PROG2) $(OBJS1) $(OBJS2) *~ *.o tiradas_*
