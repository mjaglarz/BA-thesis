import sys

import pyximport

import utils

pyximport.install(pyimport = True)

if __name__ == "__main__":
    suite, ntests = sys.argv[1], int(sys.argv[2])
    utils.run_test(suite, ntests)
