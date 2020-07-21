import os

import utils


if_ops, add_ops, subtract_ops, multiply_ops, divide_ops, rec_call = 0, 0, 0, 0, 0, 0
rec_call = 0

def fib(n):
    global if_ops, add_ops, subtract_ops, rec_call
    rec_call +=1
    if_ops += 1
    if n < 2:
        return n
    subtract_ops += 2
    add_ops += 1
    return fib(n-1) + fib(n-2)


def quicksort(A, lo, hi):
    global if_ops, add_ops, subtract_ops, divide_ops
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
                subtract_ops += 1
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


def matmul(A, B, R):
    global if_ops, add_ops, multiply_ops
    if_ops += 3
    for i in range(len(A)):
        if_ops += 1
        for j in range(len(B[0])):
            if_ops += 1
            for k in range(len(B)):
                if_ops += 1
                add_ops += 1
                multiply_ops += 1
                R[i][j] += A[i][k] * B[k][j]


if __name__ == "__main__":
    fib(20)
    print(f'Fibonacci:\nIf: {if_ops}, Add: {add_ops}, Subtract: {subtract_ops}. Recursive calls {rec_call}.\n')
    if_ops, subtract_ops, add_ops = 0, 0, 0

    arraysize = 1000000
    base_path = utils.chop_suffix_from_path(os.path.dirname(os.path.abspath(__file__)), '/src')
    read_path = base_path + '/data/integers.txt'

    with open(read_path, 'r') as fdread:
        test_array = [int(i) for i in fdread.readlines()]
        quicksort(test_array, 0, arraysize - 1)
        print(f'Quicksort:\nIf: {if_ops}, Add: {add_ops}, Subtract: {subtract_ops}, Divide {divide_ops}.\n')
        del test_array
    if_ops, add_ops = 0, 0,

    matrix_size = 200
    A = B = [[row for row in range(matrix_size)] for col in range(matrix_size)]
    R = [[0] * matrix_size for _ in range(matrix_size)]
    matmul(A, B, R)
    print(f'Matrix multiplcation:\nIf: {if_ops}, Add: {add_ops}, Multiply: {multiply_ops}.')