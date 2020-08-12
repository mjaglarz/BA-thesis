cpdef void quicksort(list A, long lo, long hi):
    cdef long i, j
    i = lo
    j = hi
    while i < hi:
        pivot = A[(lo + hi) // 2]
        while i <= j:
            while A[i] < pivot:
                i += 1

            while A[j] > pivot:
                j -= 1

            if i <= j:
                A[i], A[j] = A[j], A[i]
                i += 1
                j -= 1

        if lo < j:
            quicksort(A, lo, j)

        lo = i
        j = hi