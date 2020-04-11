CC = gcc
CFLAGS = -I.
DEPS = fibonacci.h
OBJ = benchmark.o fibonacci.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ make