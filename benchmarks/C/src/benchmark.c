#include <limits.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

#define NTESTS 100
#define ARRAYSIZE 1000000

int main(int argc, char *argv[]) {
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

    fdwrite = fopen(write_path, "w");
    test_fibonacci(fdwrite, 100);
    fclose(fdwrite);

    write_path[strrchr(write_path, '/') - write_path + 1] = '\0';
    strcat(write_path, "c_quicksort_benchmark.txt");

    fdwrite = fopen(write_path, "w");
    fdread = fopen(read_path, "r");

    test_quicksort(fdwrite, fdread, 100);

    fclose(fdread);
    fclose(fdwrite);

    return 0;
}