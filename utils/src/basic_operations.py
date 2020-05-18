import os

import utils

def run(fd):
    ntests = 3
    nincr_small = 1000
    nincr_big = 10000000

    utils.test_sleep(fd, ntests)
    utils.test_for_sleep(fd, ntests)

    utils.test_add(fd, ntests, nincr_small)
    utils.test_add(fd, ntests, nincr_big)

    utils.test_add_if(fd, ntests, nincr_small)
    utils.test_add_if(fd, ntests, nincr_big)

    utils.test_subtract(fd, ntests, nincr_small)
    utils.test_subtract(fd, ntests, nincr_big)

    utils.test_subtract_if(fd, ntests, nincr_small)
    utils.test_subtract_if(fd, ntests, nincr_big)

    utils.test_multiply(fd, ntests, nincr_small)
    utils.test_multiply(fd, ntests, nincr_big)

    utils.test_multiply_if(fd, ntests, nincr_small)
    utils.test_multiply_if(fd, ntests, nincr_big)

    utils.test_divide(fd, ntests, nincr_small)
    utils.test_divide(fd, ntests, nincr_big)

    utils.test_divide_if(fd, ntests, nincr_small)
    utils.test_divide_if(fd, ntests, nincr_big)


if __name__ == "__main__":
    file_name = '/results/basic_operations/python_basic_operations.txt'
    path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/utils/src') + file_name
    with open(path, 'w') as fd:
        run(fd)