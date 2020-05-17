#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

double get_elapsed_time(struct timespec *start, struct timespec *end);
int compare(const void *x, const void *y);
bool check_if_array_is_sorted(int *array);
bool check_if_arrays_are_equal(size_t size, int A[*][*], int B[*][*]);
void test_fibonacci(FILE *fdwrite, int ntests);
void test_quicksort(FILE *fdwrite, FILE *fdread, int ntests);
void test_matrix_multiplication(FILE *fdwrite, FILE *fdread, int ntests);