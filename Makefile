.PHONY: all clean run

all: launch

launch: main calculations bin oct hex
	gcc main calculations bin oct hex -lm -o launch
main: main.c 
	gcc main.c -c -o main
calculations: calculations.c
	gcc calculations.c -c -o calculations
bin: bin.c
	gcc bin.c -c -lm -o bin
oct: oct.c
	gcc oct.c -c -lm -o oct
hex: hex.c
	gcc hex.c -c -lm -o hex
run: launch
	./launch
clean:
	rm -rf main calculations hex oct bin launch
