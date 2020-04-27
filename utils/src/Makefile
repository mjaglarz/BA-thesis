IDIR = ../include
CC = gcc
CFLAGS = -Wall -I$(IDIR)

ODIR = ../obj

_DEPS = utils.h basic_operations.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = utils.o basic_operations.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

c_ops: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	./c_ops

.PHONY: integers floats python clean

py_ops:
	python3 basic_operations.py

integers:
	python3 data_generator.py integers

floats:
	python3 data_generator.py floats

clean:
	rm -r -f __pycache__ $(ODIR)/*.o *~ a.out c_ops