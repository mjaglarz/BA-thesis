#include <limits.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

#define NTESTS 100
#define ARRAYSIZE 1000000

int main(int argc, char *argv[]) {
    FILE *fdread, *fdwrite;
    char base_path[PATH_MAX], read_path[PATH_MAX], write_path[PATH_MAX] = {0};

    getcwd(base_path, sizeof(base_path));
    for (int i = 0; i < 3; ++i)
        base_path[strrchr(base_path, '/') - base_path] = '\0';
    strcat(read_path, base_path);
    strcat(read_path, "/utils/data/integers.txt");
    strcat(write_path, base_path);
    strcat(write_path, "/results/fibonacci/c_fibonacci_benchmark.txt");

    fdwrite = fopen(write_path, "w");
    test_fibonacci(fdwrite, 100);
    fclose(fdwrite);

    for (int i = 0; i < 2; ++i)
        write_path[strrchr(write_path, '/') - write_path] = '\0';
    strcat(write_path, "/quicksort/c_quicksort_benchmark.txt");

    fdwrite = fopen(write_path, "w");
    fdread = fopen(read_path, "r");

    test_quicksort(fdwrite, fdread, 100);

    fclose(fdread);
    fclose(fdwrite);

    for (int i = 0; i < 2; ++i)
        write_path[strrchr(write_path, '/') - write_path] = '\0';
    strcat(write_path,
           "/matrix_multiplication/c_matrix_multiplication_benchmark.txt");
    read_path[strrchr(read_path, '/') - read_path] = '\0';
    strcat(read_path, "/matmul_assert.txt");

    fdwrite = fopen(write_path, "w");
    fdread = fopen(read_path, "r");

    test_matrix_multiplication(fdwrite, fdread, 100);

    fclose(fdread);
    fclose(fdwrite);

    return 0;
}