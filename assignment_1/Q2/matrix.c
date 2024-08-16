#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void multiply_matrices(void* A, void* B, void* C, int n, int data_type_size) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            void* sum = calloc(1, data_type_size);
            for (int k = 0; k < n; k++) {
                if (data_type_size == sizeof(int)) {
                    *(int*)sum += *((int*)A + i*n + k) * *((int*)B + k*n + j);
                } else {
                    *(double*)sum += *((double*)A + i*n + k) * *((double*)B + k*n + j);
                }
            }
            if (data_type_size == sizeof(int)) {
                *((int*)C + i*n + j) = *(int*)sum;
            } else {
                *((double*)C + i*n + j) = *(double*)sum;
            }
            free(sum);
        }
    }
}

int main() {
    int n = 128; //change n to 64, 128, 256, 512, 1024 
   

    void *A, *B, *C;
    int data_type = 1; // 1 for int, 2 for double

    int data_type_size = (data_type == 1) ? sizeof(int) : sizeof(double);

    A = malloc(n * n * data_type_size);
    B = malloc(n * n * data_type_size);
    C = malloc(n * n * data_type_size);

    // Initialize matrices A and B with random values
    for (int i = 0; i < n * n; i++) {
        if (data_type == 1) {
            ((int*)A)[i] = rand() % 100;
            ((int*)B)[i] = rand() % 100;
        } else {
            ((double*)A)[i] = (double)rand() / RAND_MAX * 100.0;
            ((double*)B)[i] = (double)rand() / RAND_MAX * 100.0;
        }
    }

    multiply_matrices(A, B, C, n, data_type_size);


    free(A);
    free(B);
    free(C);

    return 0;
}