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