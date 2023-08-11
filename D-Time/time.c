#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_n_time(int n) {
    for (int i = 0; i < n; i++) {
        printf("");
    }
}

void non_print_n_time(int n) {
    for (int i = 0; i < n; i++)
        ;
}

int main(int argc, char **argv) {
    int n;
    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        n = 1000000;
    }
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    print_n_time(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("print_n_time(n=%d): %f secs\n", n, cpu_time_used);

    start = clock();
    non_print_n_time(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("non_print_n_time(n=%d): %f secs\n", n, cpu_time_used);

    return 0;
}