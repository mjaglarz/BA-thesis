import cython

@cython.boundscheck(False)
@cython.wraparound(False)
cpdef void matmul(long[:,:] A, long[:,:] B, long[:,:] R):
    cdef long i, j, k
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                R[i][j] += A[i][k] * B[k][j]