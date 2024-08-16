import numpy as np
# import time

def multiply_matrices(A, B):
    return np.dot(A, B)

def main():
    n = 128 # change n to 64, 128, 256, 512, 1024
    data_type = 'int' # change data_type to 'int' or 'double'

    if data_type == 'int':
        A = np.random.randint(0, 100, size=(n, n))
        B = np.random.randint(0, 100, size=(n, n))
    else:
        A = np.random.rand(n, n) * 100
        B = np.random.rand(n, n) * 100

    start_time = time.time()
    C = multiply_matrices(A, B)
    end_time = time.time()

    cpu_time_used = end_time - start_time
    print(f"CPU time used for meat portions: {cpu_time_used:.6f} seconds")

if __name__ == "__main__":
    main()