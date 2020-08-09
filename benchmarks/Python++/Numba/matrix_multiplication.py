from numba import jit

@jit(nopython=True)
def matmul(A, B, R):
    for i in range(len(A)):
        for j in range(len(B)):
            for k in range(len(B)):
                R[i][j] += A[i][k] * B[k][j]