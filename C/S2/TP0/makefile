build: main.o tactix.o
	gcc -Wall -o tactix main.o tactix.o

all: build clean

main.o: main.c
	gcc -Wall -c main.c

tactix.o: tactix.c
	gcc -Wall -c tactix.c

clean:
	rm -f *.o
