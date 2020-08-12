import os
from time import perf_counter

import numpy

import matrix_multiplication
import quicksort


def chop_suffix_from_path(path, suffix):
    if suffix and path.endswith(suffix):
        return path[:-len(suffix)]
    return path


def check_if_array_is_sorted(array: list):
    if(all(array[i] <= array[i + 1] for i in range(len(array) - 1))): 
        return True
    return False


def run_test(suite, ntests):
    tests={
        '1': test_quicksort,
        '2': test_matrix_multiplication,
        '3': test_all
    }
    test = tests.get(suite, lambda: 'Invalid test suite')
    return test(ntests)

def test_quicksort(ntests):
    arraysize = 1000000
    base_path = chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python++/NumPy')
    read_path = base_path + '/utils/data/integers.txt'

    with open(read_path, 'r') as fdread:
        test_array = [int(i) for i in fdread.readlines()]
        test_array = numpy.array(test_array)
        quicksort.quicksort(test_array, 0, arraysize - 1)
        assert(numpy.all(test_array[:-1] <= test_array[1:]))
        del test_array

        write_path = base_path + '/results/quicksort/numpy_quicksort_benchmark.txt'
        with open(write_path, 'w') as fdwrite:
            for _ in range(ntests):
                fdread.seek(0)
                array = [int(i) for i in fdread.readlines()]
                array = numpy.array(array)
                start = perf_counter()
                quicksort.quicksort(array, 0, arraysize - 1)
                numpy.sort(array, kind='quicksort')
                end = perf_counter()
                del array
                
                time = end - start
                fdwrite.write(f'{time:.6f}\n')


def test_matrix_multiplication(ntests):
    matrix_size = 200
    base_path = chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python++/NumPy')
    write_path = base_path + '/results/matrix_multiplication/numpy_matrix_multiplication_benchmark.txt'
    read_path = base_path + '/utils/data/matmul_assert.txt'

    A = B = [[row for row in range(matrix_size)] for col in range(matrix_size)]
    R = [[0] * matrix_size for _ in range(matrix_size)]
    A = numpy.array(A)
    B = numpy.array(B)
    R = numpy.array(R)
    matrix_multiplication.matmul(A, B, R)
    C = numpy.loadtxt(read_path)
    assert(R.all() == C.all())
    del R, C

    with open(write_path, 'w') as fd:
        for _ in range(ntests):
            R = [[0] * matrix_size for _ in range(matrix_size)]
            R = numpy.array(R)
            start = perf_counter()
            matrix_multiplication.matmul(A, B, R)
            end = perf_counter()
            del R

            time = end - start
            fd.write(f'{time:.6f}\n')


def test_all(ntests):
    test_quicksort(ntests)
    test_matrix_multiplication(ntests)