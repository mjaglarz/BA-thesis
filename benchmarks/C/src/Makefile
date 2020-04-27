IDIR = ../include
CC = gcc
CFLAGS = -O0 -Wall -I$(IDIR)

ODIR = ../obj

_DEPS = fibonacci.h quicksort.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = fibonacci.o quicksort.o benchmark.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean run

clean:
	rm -f $(ODIR)/*.o *~ a.out test

run:
	./test