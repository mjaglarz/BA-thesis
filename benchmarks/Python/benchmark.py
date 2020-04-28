from timeit import default_timer as timer #On Python 3.3+ default_timer is time.perf_counter() on all platforms.
from random import randint
import os
import sys

import fibonacci
import quicksort
import utils

def generate_random_numbers_array(size: int):
    return [randint(0, 32000) for _ in range(size)]


def check_if_array_is_sorted(array: list):
    if(all(array[i] <= array[i + 1] for i in range(len(array) - 1))): 
        return True
    return False


if __name__ == "__main__":
    sys.path.append('../../utils')

    fibarg = 20
    ntests = 3
    niter = 1000
    tests = []
    arraysize = 1000000

    #Test fibonacci function
    assert(fibonacci.fib(fibarg) == 6765)

    for _ in range(ntests):
        start = timer()
        for _ in range(niter):
            return_value = fibonacci.fib(fibarg)
        end = timer()

        tests.append((end - start) / niter)

    tests.sort()
    print(f"Recursive Fib({fibarg}) = {return_value}: Time elapsed is {tests[ntests//2]} seconds.")

    #Test quicksort function
    tests.clear()
    file_name = '/utils/integers.txt'
    path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python') + file_name
    with open(path, 'r') as fd:
        test_array = fd.readlines()
        quicksort.quicksort(test_array, 0, arraysize - 1)
        assert(check_if_array_is_sorted(test_array))
        del test_array

        for _ in range(ntests):
            array = fd.readlines()
            start = timer()
            quicksort.quicksort(array, 0, arraysize - 1)
            end = timer()
            del array
            
            tests.append((end - start) / niter)

        tests.sort()
    print(f"Quicksort for {arraysize} elements array: Time elapsed is {tests[ntests//2]} seconds.")