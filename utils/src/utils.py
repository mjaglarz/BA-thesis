import numpy.random as np


def gen_floats_array(size, start, end):
    return [np.uniform(start, end) for _ in range(size)]


def gen_integers_array(size, start, end):
    return [np.randint(start, end) for _ in range(size)]


def chop_suffix_from_path(path, suffix):
    if suffix and path.endswith(suffix):
        return path[:-len(suffix)]
    return path
