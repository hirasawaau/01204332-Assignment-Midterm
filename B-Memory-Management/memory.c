#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack(long long i, long long max_size) {
    printf("Stack (%lld) : %p\n", i, &i);
    if (i + 1 < max_size) {
        stack(i + 1, max_size);
    }
}

long long* A[50000];
int bj;
void heap(long long size) {
    for (long long i = 0; i < size; i++) {
        A[i] = (long long*)malloc(sizeof(long long));
        printf("Heap (%lld) : %p\n", i, A[i]);
    }
    for (long long i = 0; i < size; i++) {
        free(A[i]);
    }
};
int s = 0;
void overflow(long long p) {
    printf("Stack %d: %p\n", s, &p);
    printf("Heap %d: %p\n", s++, malloc(sizeof(long long) * 10));
    overflow(p);
}

int main(int argc, char** argv) {
    int* init = (int*)malloc(sizeof(int));
    printf("Local argc : %p\n", &argc);
    printf("Local argv : %p\n", &argv);
    printf("Global bj : %p\n", &bj);
    printf("Global size : %p\n", &s);
    printf("Global A : %p\n", A);
    if (argc > 1 && argv[1][0] == '1') {
        overflow(0);
        return 1;
    }

    stack(0, 5);
    heap(5);
    free(init);
    return 0;
}
