#Makefile
#Archivo usado para compilar el programa
#Autor : Luiscarlo Rivera
#basado en los makefile de ejemplos de aula virtual

CC = gcc 
CFLAGS = -ansi -Wabi -g -ggdb -gstabs -Wall -Wextra -pedantic -pedantic-errors \
	-Werror -Wfatal-errors -Wswitch-default -Wswitch-enum -Wmain \
	-Wmissing-include-dirs -Wmissing-declarations -Wunreachable-code \
	-Winline -Wfloat-equal -Wundef -Wcast-align -Wredundant-decls \
	-Winit-self -Wshadow -Wformat-y2k -Wno-format-extra-args -Wformat=2 \
	-Wno-format-zero-length -Wformat-nonliteral -Wformat-security 
OBJS1 = juegodedados_p.o funciones.o
OBJS2 = juegodedados_h.o funciones.o
PROG1 = juegodedados_p
PROG2 = juegodedados_h


all : $(PROG1) $(PROG2)

$(PROG1): $(OBJS1)
		$(CC) $(CFLAGS) $(OBJS1) -o $(PROG1)
$(PROG2): $(OBJS2)
		$(CC) $(CFLAGS) $(OBJS2) -lpthread -o $(PROG2)
	
%.o: %.c  
	$(CC) $(CFLAGS) -c $< -lpthread
	
clean:
	$(RM) $(PROG1) $(PROG2) $(OBJS1) $(OBJS2) *~ *.o tiradas_*
