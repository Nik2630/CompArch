#include <stdio.h>
#include <time.h>

void fibonacci_iterative_memo(int n) {
    unsigned long long memo[n];
    memo[0] = 0;
    memo[1] = 1;

    printf("0: %llu\n", memo[0]);
    printf("1: %llu\n", memo[1]);

    for (int i = 2; i < n; i++) {
        memo[i] = memo[i-1] + memo[i-2];
        printf("%d: %llu\n", i, memo[i]);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    fibonacci_iterative_memo(50);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}