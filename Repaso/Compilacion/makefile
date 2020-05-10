#definicion de una regla
#objetivo: dependencias
#instrucciones
COMPI := gcc 
NAME_PROG := "Hola Sisop"
.PHONY: clean install
all: prod
prod: ./src/main.c saludo.o
	echo "creando programa binario => binario"
	$(COMPI) -o $(NAME_PROG) src/main.c saludo.o
	echo "programa binario creado => binario"
saludo.o: src/libs/source/saludo.c src/libs/headers/saludo.h
	echo "creando programa objeto => saludo.o"
	$(COMPI) -c src/libs/source/saludo.c
	echo "programa objeto creado => saludo.o"
clean:
	rm -rf $(NAME_PROG) *.o
install:
	mv $(NAME_PROG) $(dir)/$(NAME_PROG)