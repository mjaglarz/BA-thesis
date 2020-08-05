import os
from time import perf_counter

import fibonacci


def chop_suffix_from_path(path, suffix):
    if suffix and path.endswith(suffix):
        return path[:-len(suffix)]
    return path


def test_fibonacci(ntests):
    fibarg = 20
    base_path = chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/benchmarks/Python++/Caching')
    path = base_path + '/results/fibonacci/caching_fibonacci_benchmark.txt'

    assert(fibonacci.fib(fibarg) == 6765)

    with open(path, 'w') as fd:
        for _ in range(ntests):
            start = perf_counter()
            fibonacci.fib(fibarg)
            end = perf_counter()

            time = end - start
            fd.write(f'{time:.9f}\n')