#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    getcwd(path, sizeof(path));
    path[strrchr(path, '/') - path]  = '\0';
    path[strrchr(path, '/') - path + 1]  = '\0';
    strcat(path, "results/basic_operations_c.txt");
    printf(path);
}