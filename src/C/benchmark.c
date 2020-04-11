#include <stdio.h>
#include <time.h>

#include "fibonacci.h"

#define N 20

int main() {
    int return_value = 0;
    double time_spent = 0.0;

    clock_t begin = clock();

    return_value = fib(N);

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Fib(%d): Time elapsed is %f seconds.\n", N, time_spent);

    return 0;
}