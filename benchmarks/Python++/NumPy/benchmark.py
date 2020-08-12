import pyximport
pyximport.install(language_level=3, inplace=True)

import sys

import utils


if __name__ == "__main__":
    suite, ntests = sys.argv[1], int(sys.argv[2])
    utils.run_test(suite, ntests)