#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 50

unsigned long long memo[MAX];

unsigned long long fibonacci_recursive_memo(int n) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = fibonacci_recursive_memo(n - 1) + fibonacci_recursive_memo(n - 2);
    return memo[n];
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    memset(memo, 0, sizeof(memo));

    start = clock();

    for (int i = 0; i < 50; i++) {
        printf("%d: %llu\n", i, fibonacci_recursive_memo(i));
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}