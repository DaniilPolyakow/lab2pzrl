.PHONY: all clean run

all: main

main: main.c calculations.c
	gcc main.c calculations.c -o main.o
run: main
	./main.o
clean:
	*.o
