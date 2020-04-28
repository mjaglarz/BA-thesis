#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fibonacci.h"
#include "quicksort.h"

#define NTESTS 3
#define NITER 1000

#define ARRAYSIZE 1000000

double get_elapsed_time(struct timespec *start, struct timespec *end) {
    double delta_s = end->tv_sec - start->tv_sec;
    double delta_ns = end->tv_nsec - start->tv_nsec;
    return delta_s + delta_ns * 1e-9;
}

int compare(const void *x, const void *y) {
    return (*(double *)x - *(double *)y);
}

int *generate_random_numbers_array(int size) {
    srand(time(NULL));
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }
    return array;
}

bool check_if_array_is_sorted(int *array) {
    int i;
    for (i = 0; i < ARRAYSIZE - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    struct timespec start, end;
    volatile int fibarg =
        20; // Each volatile variable read has a corresponding memory access.
    int return_value = 0;
    double tests[NTESTS];

    // Test fibonacci function
    assert(fib(fibarg) == 6765);

    for (int i = 0; i < NTESTS; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < NITER; ++j) {
            return_value = fib(fibarg);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);

        tests[i] = get_elapsed_time(&start, &end) / NITER;
    }

    qsort(tests, NTESTS, sizeof(double), compare);
    printf("Recursive Fib(%d) = %d: Time elapsed is %f seconds.\n", fibarg,
           return_value, tests[NTESTS / 2]);

    // Test quicksort function
    int *test_array = generate_random_numbers_array(ARRAYSIZE);
    quicksort(test_array, 0, ARRAYSIZE - 1);
    assert(check_if_array_is_sorted(test_array));
    free(test_array);

    for (int i = 0; i < NTESTS; ++i) {
        int *array = generate_random_numbers_array(ARRAYSIZE);
        clock_gettime(CLOCK_MONOTONIC, &start);
        quicksort(array, 0, ARRAYSIZE - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        free(array);

        tests[i] = get_elapsed_time(&start, &end) / NITER;
    }

    qsort(tests, NTESTS, sizeof(double), compare);
    printf("Quicksort for %d elements array: Time elapsed is %f seconds.\n",
           ARRAYSIZE, tests[NTESTS / 2]);

    return 0;
}