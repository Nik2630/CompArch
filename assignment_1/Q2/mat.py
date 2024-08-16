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

    C = multiply_matrices(A, B)


if __name__ == "__main__":
    main()