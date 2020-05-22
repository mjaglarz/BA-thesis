IDIR = ../include
CC = gcc
CFLAGS = -O0 -Wall -I$(IDIR)

ODIR = ../obj

_DEPS = fibonacci.h quicksort.h matrix_multiplication.h utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = fibonacci.o quicksort.o utils.o matrix_multiplication.o benchmark.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: run clean

fib:
	./run 1 100

quick:
	./run 2 100

matmul:
	./run 3 100

all:
	./run 4 100

clean:
	rm -f $(ODIR)/*.o *~ a.out run