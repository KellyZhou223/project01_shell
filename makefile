all: main.o shell.o parse.o
	gcc -o skssh main.o shell.o parse.o

main.o: main.c shell.h
	gcc -c main.c

shell.o: shell.c shell.h
	gcc -c shell.c

parse.o: parse.c parse.h
	gcc -c parse.c

run:
	./skssh

clean:
	rm *.o
