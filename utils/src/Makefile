IDIR = ../include
CC = gcc
CFLAGS = -Wall -I$(IDIR)

ODIR = ../obj

_DEPS = basic_operations.h utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = basic_operations.o utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

c_ops: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	./c_ops

.PHONY: integers floats python clean

integers:
	python3 data_generator.py integers

floats:
	python3 data_generator.py floats

py_ops:
	python3 basic_operations.py

clean:
	rm -r -f __pycache__ $(ODIR)/*.o *~ a.out c_ops