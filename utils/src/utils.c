#include "utils.h"
#include <unistd.h>

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
    fprintf(fd, "Sleep(100): %f\n", get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_for_sleep(FILE *fd, int ntests) {
  struct timespec start, end;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < 100; ++j) {
      sleep(1);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For 100 times sleep(1): %f\n", get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_add(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 0, val = 0;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      val++;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d add 1 to %d: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_subtract(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 1000000, val = 1000000;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      val--;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d subtract 1 from %d: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_multiply(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 1, val = 1;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      val *= 1.01;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d multiply %d by 1.01: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_divide(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 1000000, val = 1000000;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      val /= 1.01;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d divide %d by 1.01: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_add_if(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 0, val = 0;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      if (j % 2 == 0) {
        val++;
      }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d add 1 to %d: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_subtract_if(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 1000000, val = 1000000;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      if (j % 2 == 0) {
        val--;
      }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d subtract 1 from %d: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_multiply_if(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 1, val = 1;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      if (j % 2 == 0) {
        val *= 1.01;
      }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d multiply %d by 1.01: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}

void test_divide_if(FILE *fd, int ntests, int nincr) {
  struct timespec start, end;
  int initial_value = 1000000, val = 1000000;
  for (int i = 0; i < ntests; ++i) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int j = 0; j < nincr; ++j) {
      if (j % 2 == 0) {
        val /= 1.01;
      }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(fd, "For %d divide %d by 1.01: %f\n", nincr, initial_value,
            get_elapsed_time(&start, &end));
  }
  fprintf(fd, "\n");
}