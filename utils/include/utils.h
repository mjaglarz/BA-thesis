#pragma once

#include <stdio.h>
#include <time.h>

double get_elapsed_time(struct timespec *start, struct timespec *end);
void test_sleep(FILE *fd, int ntests);
void test_for_sleep(FILE *fd, int ntests);
void test_add(FILE *fd, int ntests, int nincr);
void test_subtract(FILE *fd, int ntests, int nincr);
void test_multiply(FILE *fd, int ntests, int nincr);
void test_divide(FILE *fd, int ntests, int nincr);
void test_add_if(FILE *fd, int ntests, int nincr);
void test_subtract_if(FILE *fd, int ntests, int nincr);
void test_multiply_if(FILE *fd, int ntests, int nincr);
void test_divide_if(FILE *fd, int ntests, int nincr);