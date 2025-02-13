#include <limits.h>
#include <string.h>
#include <unistd.h>

#include "basic_operations.h"
#include "utils.h"

void run(FILE *fd) {
    const int ntests = 3;
    const int nincr_small = 1000;
    const int nincr_big = 10000000;

    test_sleep(fd, ntests);
    test_for_sleep(fd, ntests);

    test_add(fd, ntests, nincr_small);
    test_add(fd, ntests, nincr_big);

    test_add_if(fd, ntests, nincr_small);
    test_add_if(fd, ntests, nincr_big);

    test_subtract(fd, ntests, nincr_small);
    test_subtract(fd, ntests, nincr_big);

    test_subtract_if(fd, ntests, nincr_small);
    test_subtract_if(fd, ntests, nincr_big);

    test_multiply(fd, ntests, nincr_small);
    test_multiply(fd, ntests, nincr_big);

    test_multiply_if(fd, ntests, nincr_small);
    test_multiply_if(fd, ntests, nincr_big);

    test_divide(fd, ntests, nincr_small);
    test_divide(fd, ntests, nincr_big);

    test_divide_if(fd, ntests, nincr_small);
    test_divide_if(fd, ntests, nincr_big);
}

int main() {
    FILE *fd;
    char path[PATH_MAX];

    getcwd(path, sizeof(path));
    for (int i = 0; i < 2; ++i)
        path[strrchr(path, '/') - path] = '\0';
    strcat(path, "/results/basic_operations/c_basic_operations.txt");

    fd = fopen(path, "w");
    run(fd);
    fclose(fd);
}