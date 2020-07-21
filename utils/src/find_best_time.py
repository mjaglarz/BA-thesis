import os

import utils


def generate_results_path(func, lang):
    base_path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/utils/src') 
    return base_path + '/results/' + func + '/' + lang + '_' + func + '_benchmark.txt'


def find_average_time(path, func, lang):
    with open(path, 'r') as fd:
        array = [float(i) for i in fd.readlines()]
        print(f'{lang.capitalize()} {func.replace("_", " ")} best result: {min(array):.6f}s.')


if __name__ == "__main__":
    langs = ['c', 'julia', 'python']
    funcs = ['fibonacci', 'quicksort', 'matrix_multiplication']

    for f in funcs:
        for l in langs:
            find_average_time(generate_results_path(f, l), f, l)