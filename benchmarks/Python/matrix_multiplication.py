def matmul(A, B, R):
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                R[i][j] += A[i][k] * B[k][j]
    return R