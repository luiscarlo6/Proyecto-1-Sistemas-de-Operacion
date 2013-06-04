#Makefile
#Archivo usado para compilar el programa
#Autor : Luiscarlo Rivera
#basado en los makefile de ejemplos de aula virtual

CC = gcc 
CFLAGS1 = -D_GNU_SOURCE -ansi -Wabi -g -ggdb -gstabs -Wall -Wextra -pedantic -pedantic-errors \
          -Wswitch-default -Wswitch-enum -Wmain \
        -Wmissing-include-dirs -Wmissing-declarations -Wunreachable-code \
        -Winline -Wfloat-equal -Wundef -Wcast-align -Wredundant-decls \
        -Winit-self -Wshadow -Wformat-y2k -Wno-format-extra-args -Wformat=2 \
        -Wno-format-zero-length -Wformat-nonliteral -Wformat-security 
OBJS  = juegodedados_p.o funciones.o
PROG  = juegodedados_p


all : $(PROG) $(PROG1)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)
	
%.o: %.c  
	$(CC) $(CFLAGS) -c $<

.PHONY : clean

clean:
	$(RM) $(PROG) $(OBJS) *~ *.o