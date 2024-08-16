#include <stdio.h>
#include <time.h>

void fibonacci_iterative(int n) {
    unsigned long long a = 0, b = 1, temp;
    for (int i = 0; i < n; i++) {
        printf("%d: %llu\n", i, a);
        temp = a + b;
        a = b;
        b = temp;
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    fibonacci_iterative(50);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}