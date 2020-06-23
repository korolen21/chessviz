.PHONY: clean all bin build default

all: bin build default

default: bin/key

bin/key: build/main.o build/board.o build/movement.o
	gcc -Wall -Werror -std=c99 build/main.o build/board.o build/movement.o -o bin/key

build/main.o: src/main.c 
	gcc -c -Wall -Werror -std=c99 src/main.c -o build/main.o 

build/board.o: src/board.c 
	gcc -c -Wall -Werror -std=c99 src/board.c -o build/board.o

build/movement.o: src/movement.c 
	gcc -c -Wall -Werror -std=c99 src/movement.c -o build/movement.o

build:
	mkdir -p build

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin