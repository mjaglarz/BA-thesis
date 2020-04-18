from timeit import default_timer as timer #On Python 3.3+ default_timer is time.perf_counter() on all platforms.
from time import sleep
import fibonacci
import quicksort

if __name__ == "__main__":
    fibarg = 20
    ntests = 3
    niter = 1000
    tests = []

    #Test fibonacci function
    assert(fibonacci.fib(fibarg) == 6765)

    tmin = float('inf')
    for _ in range(ntests):
        start = timer()
        for _ in range(niter):
            return_value = fibonacci.fib(fibarg)
        end = timer()

        tests.append((end - start) / niter)

    tests.sort()
    print(f"Recursive Fib({fibarg}) = {return_value}: Time elapsed is {tests[ntests//2]} seconds.")

    #Test quicksort function