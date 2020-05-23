function quicksort!(A, lo, hi)
    i = lo
    j = hi
    while i < hi
        pivot = A[(lo + hi) >>> 1]
        while i <= j
            while A[i] < pivot
                i += 1
            end

            while A[j] > pivot
                j -= 1
            end

            if i <= j
                A[i], A[j] = A[j], A[i]
                i, j = i+1, j-1
            end
        end

        if lo < j
            quicksort!(A, lo, j)
        end

        lo = i
        j = hi
    end
end
