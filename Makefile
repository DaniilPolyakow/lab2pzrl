.PHONY: all clean run

VAR = calculations.o

all: launch

launch: main.o $(VAR) bin.o oct.o hex.o
	gcc main.o $(VAR) bin.o oct.o hex.o -o launch -lm -Wall -Wextra
main.o: main.c 
	gcc -c main.c
$(VAR): calculations.c
	gcc -c calculations.c
bin.o: bin.c
	gcc -c bin.c 
oct.o: oct.c
	gcc -c oct.c
hex.o: hex.c
	gcc -c hex.c
run: launch
	./launch
clean:
	rm -rf *.o launch
