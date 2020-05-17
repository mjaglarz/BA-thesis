#pragma once

#include <stdbool.h>
#include <time.h>

double get_elapsed_time(struct timespec *start, struct timespec *end);
int compare(const void *x, const void *y);
bool check_if_array_is_sorted(int *array);
bool check_if_arrays_are_equal(size_t size, int A[*][*], int B[*][*]);
void test_fibonacci(char path[], int ntests);
void test_quicksort(char path[], int ntests);
void test_matrix_multiplication(char path[], int ntests);