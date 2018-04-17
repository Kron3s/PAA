# makefile do codigo de ordenação 

all:Ordenacao
Ordenacao:	Ordenacao.o	main.o
		gcc	-o	paa	Ordenacao.o	main.o
Ordenacao.o:Ordenacao.c
			gcc -o  Ordenacao.o	-c	Ordenacao.c	-W -Wall	-pedantic	-Wno-implicit
main.o:main.c Ordenacao.h
			gcc	-o	main.o	-c	main.c	-W -Wall -pedantic	-Wno-implicit

clean:
	rm	-rf	*.o
mrproper: clean
	rm	-rf	Ordenacao					

