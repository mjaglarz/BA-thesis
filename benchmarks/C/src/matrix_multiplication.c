#include "matrix_multiplication.h"

void matmul(int A[][N], int B[][N], int R[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            R[i][j] = 0;
            for (int k = 0; k < N; ++k)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
}