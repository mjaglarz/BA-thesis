#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    char base_path[PATH_MAX] = {0};

    getcwd(base_path, sizeof(base_path));
    for (int i = 0; i < 3; ++i)
        base_path[strrchr(base_path, '/') - base_path] = '\0';

    switch (atoi(argv[1])) {
    case 1: {
        test_fibonacci(base_path, atoi(argv[2]));
        break;
    }
    case 2: {
        test_quicksort(base_path, atoi(argv[2]));
        break;
    }
    case 3: {
        test_matrix_multiplication(base_path, atoi(argv[2]));
        break;
    }
    case 4: {
        test_fibonacci(base_path, atoi(argv[2]));
        test_quicksort(base_path, atoi(argv[2]));
        test_matrix_multiplication(base_path, atoi(argv[2]));
        break;
    }
    }

    return 0;
}