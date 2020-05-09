#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "fibonacci.h"
#include "quicksort.h"
#include "utils.h"

#define NTESTS 100
#define ARRAYSIZE 1000000


int main() {
    FILE *fdread;
    FILE *fdwrite;

    char read_path[PATH_MAX];
    char write_path[PATH_MAX];
    char base_path[PATH_MAX];

    getcwd(base_path, sizeof(base_path));
    base_path[strrchr(base_path, '/') - base_path] = '\0';
    base_path[strrchr(base_path, '/') - base_path] = '\0';
    base_path[strrchr(base_path, '/') - base_path + 1] = '\0';
    strcat(read_path, base_path);
    strcat(write_path, base_path);
    strcat(read_path, "utils/data/integers.txt");
    strcat(write_path, "results/c_fibonacci_benchmark.txt");

    struct timespec start, end;
    volatile int fibarg =
        20; // Each volatile variable read has a corresponding memory access.

    fdwrite = fopen(write_path, "w");

    // Test fibonacci function
    assert(fib(fibarg) == 6765);

    for (int i = 0; i < NTESTS; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        fib(fibarg);
        clock_gettime(CLOCK_MONOTONIC, &end);

        fprintf(fdwrite, "%f\n", get_elapsed_time(&start, &end));
    }

    fclose(fdwrite);

    // Test quicksort function
    write_path[strrchr(write_path, '/') - write_path + 1] = '\0';
    strcat(write_path, "c_quicksort_benchmark.txt");
    fdwrite = fopen(write_path, "w");

    fdread = fopen(read_path, "r");
    int *test_array = malloc(ARRAYSIZE * sizeof(int));
    for (int i = 0; i < ARRAYSIZE; i++) {
        fscanf(fdread, "%d", &test_array[i]);
    }

    quicksort(test_array, 0, ARRAYSIZE - 1);
    assert(check_if_array_is_sorted(test_array));
    memset(test_array, 0, ARRAYSIZE * sizeof(*test_array));

    for (int i = 0; i < NTESTS; ++i) {
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

    fclose(fdread);
    fclose(fdwrite);

    return 0;
}