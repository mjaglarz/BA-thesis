#include <time.h>

double get_elapsed_time(struct timespec *start, struct timespec *end) {
  double delta_s = end->tv_sec - start->tv_sec;
  double delta_ns = end->tv_nsec - start->tv_nsec;
  return delta_s + delta_ns * 1e-9;
}