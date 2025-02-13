#include <unistd.h>

#include "utils.h"

double get_elapsed_time(struct timespec *start, struct timespec *end) {
    double delta_s = end->tv_sec - start->tv_sec;
    double delta_ns = end->tv_nsec - start->tv_nsec;
    return delta_s + delta_ns * 1e-9;
}

void test_sleep(FILE *fd, int ntests) {
    struct timespec start, end;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        sleep(100);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("Sleep(100): %lf\n", get_elapsed_time(&start, &end));
        fprintf(fd, "A\t%.6lf\t1\n", get_elapsed_time(&start, &end));
    }
    fprintf(fd, "\n");
}

void test_for_sleep(FILE *fd, int ntests) {
    int niter = 100;
    struct timespec start, end;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < niter; ++j) {
            sleep(1);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For 100 times sleep(1): %lf\n", get_elapsed_time(&start, &end));
        fprintf(fd, "B\t%.6lf\t%d\n", get_elapsed_time(&start, &end), niter);
    }
    fprintf(fd, "\n");
}

void test_add(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 0;
    volatile int val = 0;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            val += 1.0;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d add 1 to %d: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "C\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_add_if(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 0;
    volatile int val = 0;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            if (j % 2 == 0) {
                val += 1.0;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d add 1 to %d: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "D\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_subtract(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 1000000;
    volatile int val = 1000000;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            val -= 1.0;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d subtract 1 from %d: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "E\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_subtract_if(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 1000000;
    volatile int val = 1000000;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            if (j % 2 == 0) {
                val -= 1.0;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d subtract 1 from %d: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "F\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_multiply(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 1;
    volatile int val = 1;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            val *= 1.01;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d multiply %d by 1.01: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "G\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_multiply_if(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 1;
    volatile int val = 1;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            if (j % 2 == 0) {
                val *= 1.01;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d multiply %d by 1.01: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "H\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_divide(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 1000000;
    volatile int val = 1000000;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            val /= 1.01;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d divide %d by 1.01: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "I\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}

void test_divide_if(FILE *fd, int ntests, int nincr) {
    struct timespec start, end;
    int initial_value = 1000000;
    volatile int val = 1000000;
    for (int i = 0; i < ntests; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < nincr; ++j) {
            if (j % 2 == 0) {
                val /= 1.01;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("For %d divide %d by 1.01: %lf\n", nincr, initial_value,
               get_elapsed_time(&start, &end));
        fprintf(fd, "J\t%.6lf\t%d\n", get_elapsed_time(&start, &end), nincr);
    }
    fprintf(fd, "\n");
}