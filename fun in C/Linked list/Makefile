file=testSort
DEPS = extra/
input = $(patsubst %.c,%.o,$(wildcard $(DEPS)*.c))
CC=gcc
CFLAGS=-Wall -std=c99 -O3 -g

# ifdef SystemRoot
#  	# Windows
# 	LDFLAGS=-L.
# 	LDLIBS=-lopenblas
# else
#  	ifeq ($(shell uname), Darwin)
# 		# macOS
# 		LDLIBS=-lm -llapack -lblas
# 	else
# 		# Gbar
# 		LDFLAGS=-L/usr/lib64/atlas
# 		LDLIBS=-lm -llapack -lf77blas -latlas
# 	endif
# endif

$(file): $(input) $(file).o

.PHONY: clean run crun cmake
clean:
	-$(RM) $(file) *.o $(DEPS)*.o

run: $(file)
	./$(file)

crun:
	make clean
	make run

cmake:
	make clean
	make
