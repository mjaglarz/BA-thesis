import sys

import utils
import pyximport

if __name__ == "__main__":
    pyximport.install(pyimport = True)

    suite, ntests = sys.argv[1], int(sys.argv[2])
    utils.run_test(suite, ntests)