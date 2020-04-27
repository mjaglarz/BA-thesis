from time import sleep
from timeit import default_timer as timer  # On Python 3.3+ default_timer is time.perf_counter() on all platforms.

import numpy.random as np


def chop_suffix_from_path(path, suffix):
    if suffix and path.endswith(suffix):
        return path[:-len(suffix)]
    return path


def gen_floats_array(size, start, end):
    return [np.uniform(start, end) for _ in range(size)]


def gen_integers_array(size, start, end):
    return [np.randint(start, end) for _ in range(size)]


def test_sleep(fd, ntests):
    for _ in range(ntests):
        start = timer()
        sleep(100)
        end = timer()
        elapsed_time = end - start
        fd.write(f'Sleep(100): {elapsed_time}\n')
    fd.write('\n')


def test_for_sleep(fd, ntests):
    for _ in range(ntests):
        start = timer()
        for _ in range(100):
            sleep(1)
        end = timer()
        elapsed_time = end - start
        fd.write(f'For 100 times sleep(1): {elapsed_time}\n')
    fd.write('\n')


def test_add(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 0
        start = timer()
        for _ in range(nincr):
            val += 1
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} add 1 to {initial_value}: {elapsed_time}\n')
    fd.write('\n')


def test_subtract(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 1000000
        start = timer()
        for _ in range(nincr):
            val -= 1
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} subtract 1 from {initial_value}: {elapsed_time}\n')
    fd.write('\n')


def test_multiply(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 1
        start = timer()
        for _ in range(nincr):
            val *= 1.01
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} multiply {initial_value} by 1.01: {elapsed_time}\n')
    fd.write('\n')


def test_divide(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 1000000
        start = timer()
        for _ in range(nincr):
            val /= 1.01
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} divide {initial_value} by 1.01: {elapsed_time}\n')
    fd.write('\n')



def test_add_if(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 0
        start = timer()
        for i in range(nincr):
            if i % 2 == 0:
                val += 1
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} add 1 to {initial_value}: {elapsed_time}\n')
    fd.write('\n')


def test_subtract_if(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 1000000
        start = timer()
        for i in range(nincr):
            if i % 2 == 0:
                val -= 1
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} subtract 1 from {initial_value}: {elapsed_time}\n')
    fd.write('\n')


def test_multiply_if(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 1
        start = timer()
        for i in range(nincr):
            if i % 2 == 0:
                val *= 1.01
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} multiply {initial_value} by 1.01: {elapsed_time}\n')
    fd.write('\n')


def test_divide_if(fd, ntests, nincr):
    for _ in range(ntests):
        initial_value = val = 1000000
        start = timer()
        for i in range(nincr):
            if i % 2 == 0:
                val /= 1.01
        end = timer()
        elapsed_time = end - start
        fd.write(f'For {nincr} divide {initial_value} by 1.01: {elapsed_time}\n')
    fd.write('\n')