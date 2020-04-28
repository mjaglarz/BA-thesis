import os
import sys

import utils

def create_file_for_integers(size, start, end):
    path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/src') + '/data/integers.txt'
    with open(path, 'w') as fd:
        [ fd.write(f'{elem}\n') for elem in utils.gen_integers_array(size, start, end) ]


def create_file_for_floats(size, start, end):
    path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/src') + '/data/floats.txt'
    with open(path, 'w') as fd:
        [ fd.write(f'{elem}\n') for elem in utils.gen_floats_array(size, start, end) ]


if __name__ == "__main__":
    size = 1000000
    start = -1000000
    end = 1000000

    if sys.argv[1] == 'integers':
        create_file_for_integers(size, start, end)
    else:
        create_file_for_floats(size, start, end)