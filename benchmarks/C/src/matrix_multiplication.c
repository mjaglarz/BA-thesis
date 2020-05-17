#include "matrix_multiplication.h"

void matmul(int A[][MSIZE], int B[][MSIZE], int R[][MSIZE]) {
    for (int i = 0; i < MSIZE; ++i) {
        for (int j = 0; j < MSIZE; ++j) {
            R[i][j] = 0;
            for (int k = 0; k < MSIZE; ++k)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
}