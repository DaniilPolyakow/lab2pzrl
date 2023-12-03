.PHONY: all clean run

all: main

main: main.c calculations.c bin.c oct.c hex.c
	gcc main.c calculations.c bin.c oct.c hex.c -lm -o main.o
run: main
	./main.o
clean:
	rm -rf *.o
