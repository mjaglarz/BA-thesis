#pragma once

#include <stdbool.h>
#include <time.h>

double get_elapsed_time(struct timespec *start, struct timespec *end);
int compare(const void *x, const void *y);
bool check_if_array_is_sorted(int *array);