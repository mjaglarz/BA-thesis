import os
from timeit import default_timer as timer  # On Python 3.3+ default_timer is time.perf_counter() on all platforms.

import fibonacci
import quicksort
import utils


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
    assert(fibonacci.fib(fibarg) == 6765)

    file_name = '/results/python_fibonacci_benchmark.txt'
    path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python') + file_name
    with open(path, 'w') as fd:
        for _ in range(ntests):
            start = timer()
            fibonacci.fib(fibarg)
            end = timer()

            time = end - start
            fd.write(f'{time}\n')


def test_quicksort(ntests):
    arraysize = 1000000
    file_name = '/utils/data/integers.txt'
    path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python') + file_name
    with open(path, 'r') as fdread:
        test_array = fdread.readlines()
        quicksort.quicksort(test_array, 0, arraysize - 1)
        assert(utils.check_if_array_is_sorted(test_array))
        del test_array

        file_name = '/results/python_quicksort_benchmark.txt'
        path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python') + file_name
        with open(path, 'w') as fdwrite:
            for _ in range(ntests):
                fdread.seek(0)
                array = fdread.readlines()
                start = timer()
                quicksort.quicksort(array, 0, arraysize - 1)
                end = timer()
                del array
                
                time = end - start
                fdwrite.write(f'{time}\n')


def test_matrix_multiplication(ntests):
    pass


def test_all(ntests):
    test_fibonacci(ntests)
    test_quicksort(ntests)
    test_matrix_multiplication(ntests)
