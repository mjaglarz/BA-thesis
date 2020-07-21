IDIR = ../include
CC = gcc
CFLAGS = -O3 -Wall -I$(IDIR)

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

.PHONY: py_ops integers floats clean

py_ops:
	python3 basic_operations.py

jl_ops:
	julia basic_operations.jl

integers:
	python3 data_generator.py integers

floats:
	python3 data_generator.py floats

bench_ops:
	python3 benchmark_operations.py 

best_ops:
	python3 find_best_time.py

clean:
	rm -r -f __pycache__ $(ODIR)/*.o *~ a.out c_ops