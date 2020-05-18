#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fibonacci.h"
#include "matrix_multiplication.h"
#include "quicksort.h"
#include "utils.h"

#define ASIZE 1000000

double get_elapsed_time(struct timespec *start, struct timespec *end) {
    double delta_s = end->tv_sec - start->tv_sec;
    double delta_ns = end->tv_nsec - start->tv_nsec;
    return delta_s + delta_ns * 1e-9;
}

int compare(const void *x, const void *y) {
    return (*(double *)x - *(double *)y);
}

bool check_if_array_is_sorted(int *array) {
    for (int i = 0; i < ASIZE - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool check_if_arrays_are_equal(size_t size, int A[size][size],
                               int B[size][size]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

void test_fibonacci(char path[], int ntests) {
    FILE *fdwrite;
    char write_path[PATH_MAX] = {0};
    struct timespec start, end;
    volatile int fibarg = 20;

    strcat(write_path, path);
    strcat(write_path, "/results/fibonacci/c_fibonacci_benchmark.txt");
    fdwrite = fopen(write_path, "w");

    assert(fib(fibarg) == 6765);

    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        fib(fibarg);
        clock_gettime(CLOCK_MONOTONIC, &end);

        fprintf(fdwrite, "%f\n", get_elapsed_time(&start, &end));
    }

    fclose(fdwrite);
}

void test_quicksort(char path[], int ntests) {
    FILE *fdread, *fdwrite;
    char write_path[PATH_MAX] = {0};
    char read_path[PATH_MAX] = {0};
    struct timespec start, end;

    strcat(write_path, path);
    strcat(write_path, "/results/quicksort/c_quicksort_benchmark.txt");
    fdwrite = fopen(write_path, "w");

    strcat(read_path, path);
    strcat(read_path, "/utils/data/integers.txt");
    fdread = fopen(read_path, "r");

    int *test_array = malloc(ASIZE * sizeof(int));
    for (int i = 0; i < ASIZE; ++i) {
        fscanf(fdread, "%d", &test_array[i]);
    }

    quicksort(test_array, 0, ASIZE - 1);
    assert(check_if_array_is_sorted(test_array));

    memset(test_array, 0, ASIZE * sizeof(*test_array));

    for (int i = 0; i < ntests; ++i) {
        rewind(fdread);
        for (int i = 0; i < ASIZE; ++i) {
            fscanf(fdread, "%d", &test_array[i]);
        }

        clock_gettime(CLOCK_MONOTONIC, &start);
        quicksort(test_array, 0, ASIZE - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);

        memset(test_array, 0, ASIZE * sizeof(*test_array));

        fprintf(fdwrite, "%f\n", get_elapsed_time(&start, &end));
    }

    fclose(fdread);
    fclose(fdwrite);
}

void test_matrix_multiplication(char path[], int ntests) {
    FILE *fdread, *fdwrite;
    char write_path[PATH_MAX] = {0};
    char read_path[PATH_MAX] = {0};
    struct timespec start, end;
    int A[MSIZE][MSIZE], R[MSIZE][MSIZE], C[MSIZE][MSIZE];

    strcat(write_path, path);
    strcat(
        write_path,
        "/results/matrix_multiplication/c_matrix_multiplication_benchmark.txt");
    fdwrite = fopen(write_path, "w");

    strcat(read_path, path);
    strcat(read_path, "/utils/data/matmul_assert.txt");
    fdread = fopen(read_path, "r");

    for (int i = 0; i < MSIZE; ++i) {
        for (int j = 0; j < MSIZE; ++j) {
            A[i][j] = j;
            R[i][j] = 0;
        }
    }

    matmul(A, A, R);

    for (int i = 0; i < MSIZE; ++i) {
        for (int j = 0; j < MSIZE; ++j) {
            fscanf(fdread, "%d", &C[i][j]);
        }
    }

    assert(check_if_arrays_are_equal(MSIZE, R, C));

    for (int i = 0; i < ntests; ++i) {
        for (int j = 0; j < MSIZE; ++j) {
            for (int k = 0; k < MSIZE; ++k) {
                R[j][k] = 0;
            }
        }

        clock_gettime(CLOCK_MONOTONIC, &start);
        matmul(A, A, R);
        clock_gettime(CLOCK_MONOTONIC, &end);

        fprintf(fdwrite, "%f\n", get_elapsed_time(&start, &end));
    }

    fclose(fdread);
    fclose(fdwrite);
}