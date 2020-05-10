#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "fibonacci.h"
#include "quicksort.h"
#include "utils.h"

#define ARRAYSIZE 1000000

double get_elapsed_time(struct timespec *start, struct timespec *end) {
    double delta_s = end->tv_sec - start->tv_sec;
    double delta_ns = end->tv_nsec - start->tv_nsec;
    return delta_s + delta_ns * 1e-9;
}

int compare(const void *x, const void *y) {
    return (*(double *)x - *(double *)y);
}

bool check_if_array_is_sorted(int *array) {
    for (int i = 0; i < ARRAYSIZE - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void test_fibonacci(FILE *fdwrite, int ntests) {
    struct timespec start, end;
    volatile int fibarg = 20;

    assert(fib(fibarg) == 6765);

    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        fib(fibarg);
        clock_gettime(CLOCK_MONOTONIC, &end);

        fprintf(fdwrite, "%f\n", get_elapsed_time(&start, &end));
    }
}

void test_quicksort(FILE *fdwrite, FILE *fdread, int ntests) {
    struct timespec start, end;

    int *test_array = malloc(ARRAYSIZE * sizeof(int));
    for (int i = 0; i < ARRAYSIZE; i++) {
        fscanf(fdread, "%d", &test_array[i]);
    }

    quicksort(test_array, 0, ARRAYSIZE - 1);
    assert(check_if_array_is_sorted(test_array));

    memset(test_array, 0, ARRAYSIZE * sizeof(*test_array));

    for (int i = 0; i < ntests; ++i) {
        rewind(fdread);
        for (int i = 0; i < ARRAYSIZE; i++) {
            fscanf(fdread, "%d", &test_array[i]);
        }

        clock_gettime(CLOCK_MONOTONIC, &start);
        quicksort(test_array, 0, ARRAYSIZE - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        memset(test_array, 0, ARRAYSIZE * sizeof(*test_array));

        fprintf(fdwrite, "%f\n", get_elapsed_time(&start, &end));
    }
}