import os

import utils


def generate_results_path(func, lang):
    base_path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/utils/src') 
    return base_path + '/results/' + func + '/' + lang + '_' + func + '_benchmark.txt'


def find_average_time(path, func, lang):
    try:
        with open(path, 'r') as fd:
            array = [float(i) for i in fd.readlines()]
            if round(min(array), 6) == 0:
                print(f'{lang.capitalize()} {func.replace("_", " ")} best result: {min(array):.9f}s.')
            else:
                print(f'{lang.capitalize()} {func.replace("_", " ")} best result: {min(array):.6f}s.')
    except OSError:
        pass

if __name__ == "__main__":
    tools = ['c', 'julia', 'python', 'cython', 'static', 'caching']
    funcs = ['fibonacci', 'quicksort', 'matrix_multiplication']

    for f in funcs:
        for t in tools:
            find_average_time(generate_results_path(f, t), f, t)