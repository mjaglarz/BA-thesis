import os
from timeit import default_timer as timer  # On Python 3.3+ default_timer is time.perf_counter() on all platforms.

import numpy as np

import fibonacci
import matrix_multiplication as matmul
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
        '1': test_fibonacci,
        '2': test_quicksort,
        '3': test_matrix_multiplication,
        '4': test_all
    }
    test = tests.get(suite, lambda: 'Invalid test suite')
    return test(ntests)


def test_fibonacci(ntests):
    fibarg = 20
    base_path = chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python')
    path = base_path + '/results/fibonacci/python_fibonacci_benchmark.txt'

    assert(fibonacci.fib(fibarg) == 6765)

    with open(path, 'w') as fd:
        for _ in range(ntests):
            start = timer()
            fibonacci.fib(fibarg)
            end = timer()

            time = end - start
            fd.write(f'{time:.6f}\n')


def test_quicksort(ntests):
    arraysize = 1000000
    base_path = chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python')
    read_path = base_path + '/utils/data/integers.txt'

    with open(read_path, 'r') as fdread:
        test_array = [int(i) for i in fdread.readlines()]
        quicksort.quicksort(test_array, 0, arraysize - 1)
        assert(check_if_array_is_sorted(test_array))
        del test_array

        write_path = base_path + '/results/quicksort/python_quicksort_benchmark.txt'
        with open(write_path, 'w') as fdwrite:
            for _ in range(ntests):
                fdread.seek(0)
                array = [int(i) for i in fdread.readlines()]
                start = timer()
                quicksort.quicksort(array, 0, arraysize - 1)
                end = timer()
                del array
                
                time = end - start
                fdwrite.write(f'{time:.6f}\n')


def test_matrix_multiplication(ntests):
    matrix_size = 200
    base_path = chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python')
    write_path = base_path + '/results/matrix_multiplication/python_matrix_multiplication_benchmark.txt'
    read_path = base_path + '/utils/data/matmul_assert.txt'

    A = B = [[row for row in range(matrix_size)] for col in range(matrix_size)]
    R = [[0] * matrix_size for _ in range(matrix_size)]
    matmul.matmul(A, B, R)
    R = np.matrix(R)
    C = np.loadtxt(read_path)
    assert(R.all() == C.all())
    del R, C

    with open(write_path, 'w') as fd:
        for _ in range(ntests):
            R = [[0] * matrix_size for _ in range(matrix_size)]
            start = timer()
            matmul.matmul(A, B, R)
            end = timer()
            del R

            time = end - start
            fd.write(f'{time:.6f}\n')


def test_all(ntests):
    test_fibonacci(ntests)
    test_quicksort(ntests)
    test_matrix_multiplication(ntests)