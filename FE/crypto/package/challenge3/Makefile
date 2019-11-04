file=exhaustive
#input = $(patsubst %.c,%.o,$(wildcard *.c))
CC=gcc
CFLAGS=-std=c99 -g -O3
LDLIBS=-lm -lcrypto

$(file): $(file).o #$(input) $(file).o

.PHONY: clean run crun cmake
clean:
	-$(RM) $(file) *.o

run: $(file)
	./$(file)

crun:
	make clean
	make run

cmake:
	make clean
	make
