def quicksort(a, lo, hi):
    i = lo
    j = hi
    while i < hi:
        pivot = a[(lo + hi) // 2]
        while i <= j:
            while a[i] < pivot:
                i += 1

            while a[j] > pivot:
                j -= 1

            if i <= j:
                a[i], a[j] = a[j], a[i]
                i += 1
                j -= 1

        if lo < j:
            quicksort(a, lo, j)

        lo = i
        j = hi
    return a