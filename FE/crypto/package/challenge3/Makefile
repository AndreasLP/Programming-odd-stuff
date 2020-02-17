file=sorted_list_MiM
#input = $(patsubst %.c,%.o,$(wildcard *.c))
CC=g++
CFLAGS=-O3
LDLIBS=-lm -lcrypto -lssl

$(file): $(file).cpp #$(input) $(file).o
	g++ $(file).cpp -o $(file) -lm -O3 -lssl -lcrypto 

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
