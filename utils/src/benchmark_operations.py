import os

import utils

if_ops = 0
subtract_ops = 0
add_ops = 0
divide_ops = 0

def fib(n):
    global if_ops, subtract_ops, add_ops
    if_ops += 1
    if n < 2:
        return n
    subtract_ops += 2
    add_ops += 1
    return fib(n-1) + fib(n-2)

def quicksort(A, lo, hi):
    global if_ops, subtract_ops, add_ops, divide_ops
    i = lo
    j = hi
    if_ops += 1
    while i < hi:
        if_ops += 1
        add_ops += 1
        divide_ops += 1
        pivot = A[(lo + hi) // 2]
        if_ops += 1
        while i <= j:
            if_ops += 1
            if_ops += 1
            while A[i] < pivot:
                if_ops += 1
                add_ops += 1
                i += 1

            if_ops += 1
            while A[j] > pivot:
                if_ops += 1
                j -= 1

            if_ops += 1
            if i <= j:
                A[i], A[j] = A[j], A[i]
                add_ops += 1
                subtract_ops += 1
                i += 1
                j -= 1

        if_ops += 1
        if lo < j:
            quicksort(A, lo, j)

        lo = i
        j = hi

if __name__ == "__main__":
    fib(20)
    print(f'If: {if_ops}, Subtract: {subtract_ops}, Add: {add_ops}.')
    if_ops, subtract_ops, add_ops = 0, 0, 0

    arraysize = 1000000
    base_path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/src')
    read_path = base_path + '/data/integers.txt'

    with open(read_path, 'r') as fdread:
        test_array = [int(i) for i in fdread.readlines()]
        quicksort(test_array, 0, arraysize - 1)
        print(f'If: {if_ops}, Subtract: {subtract_ops}, Add: {add_ops}, Divide {divide_ops}.')
        del test_array
