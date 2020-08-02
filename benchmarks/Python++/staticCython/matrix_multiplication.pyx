cpdef void matmul(list A, list B, list R):
    cdef int i, j, k
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                R[i][j] += A[i][k] * B[k][j]