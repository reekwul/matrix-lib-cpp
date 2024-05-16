#include "matrix_multiplication.h"

void matrixMultiplication(int const *matrix1, int const *matrix2, int *result, int rows1, int columns1, int columns2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            result[i * columns2 + j] = 0;
            for (int k = 0; k < columns1; ++k) {
                result[i * columns2 + j] += matrix1[i * columns1 + k] * matrix2[k * columns2 + j];
            }
        }
    }
}

int **blockMatrixMultiplication(int **A, int **B, int n, int blockSize) {
    int **C = new int *[n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }
    for (int bi = 0; bi < n; bi += blockSize) {
        for (int bj = 0; bj < n; bj += blockSize) {
            for (int bk = 0; bk < n; bk += blockSize) {
                for (int i = 0; i < blockSize; ++i) {
                    for (int j = 0; j < blockSize; ++j) {
                        for (int k = 0; k < blockSize; ++k) {
                            C[bi + i][bj + j] += A[bi + i][bk + k] * B[bk + k][bj + j];
                        }
                    }
                }
            }
        }
    }
    return C;
}

bool isPower(int n) {
    int k;
    while (n != 0) {
        k = n % 2;
        n = n / 2;
    }
    return k == 0;
}

int log2(int x) {
    int result = 1;
    while ((x >>= 1) != 0) {
        result++;
    }
    return result;
}

int getMax(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int getNewDimension(int **a, int **b, int rowsA, int colsA, int colsB) {
    return 1 << log2(getMax(rowsA, colsA, colsB));
}

int **addition2SquareMatrix(int **a, int rowsA, int colsA, int n) {
    int **result = new int *[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n];
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            result[i][j] = a[i][j];
        }
    }
    return result;
}

// Функция для умножения матриц
int **multiply(int **a, int **b, int n) {
    int **result = new int *[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n];
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int **strassenAlgorithm(int **A, int **B, int n) {

    if (!isPower(n)) {
        int newSize = getNewDimension(A, B, n, n, n);
        A = addition2SquareMatrix(A, n, n, newSize);
        B = addition2SquareMatrix(B, n, n, newSize);
    }
    int **C = new int *[n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }
    if (n <= 64) {
        C = multiply(A, B, n);
        return C;
    }

    return C;
//    int newSize = n / 2;
//    int **A11 = new int *[newSize];
//    int **A12 = new int *[newSize];
//    int **A21 = new int *[newSize];
//    int **A22 = new int *[newSize];
//    int **B11 = new int *[newSize];
//    int **B12 = new int *[newSize];
//    int **B21 = new int *[newSize];
//    int **B22 = new int *[newSize];
//    int **C11 = new int *[newSize];
//    int **C12 = new int *[newSize];
//    int **C21 = new int *[newSize];
//    int **C22 = new int *[newSize];
//    int **M1 = new int *[newSize];
//    int **M2 = new int *[newSize];
//    int **M3 = new int *[newSize];
//    int **M4 = new int *[newSize];
//    int **M5 = new int *[newSize];
//    int **M6 = new int *[newSize];
//    int **M7 = new int *[newSize];
//    int **temp1 = new int *[newSize];
//    int **temp2 = new int *[newSize];
//
//    for (int i = 0; i < newSize; i++) {
//        A11[i] = new int[newSize];
//        A12[i] = new int[newSize];
//        A21[i] = new int[newSize];
//        A22[i] = new int[newSize];
//        B11[i] = new int[newSize];
//        B12[i] = new int[newSize];
//        B21[i] = new int[newSize];
//        B22[i] = new int[newSize];
//        C11[i] = new int[newSize];
//        C12[i] = new int[newSize];
//        C21[i] = new int[newSize];
//        C22[i] = new int[newSize];
//        M1[i] = new int[newSize];
//        M2[i] = new int[newSize];
//        M3[i] = new int[newSize];
//        M4[i] = new int[newSize];
//        M5[i] = new int[newSize];
//        M6[i] = new int[newSize];
//        M7[i] = new int[newSize];
//        temp1[i] = new int[newSize];
//        temp2[i] = new int[newSize];
//    }
//
//    for (int i = 0; i < newSize; i++) {
//        for (int j = 0; j < newSize; j++) {
//            A11[i][j] = A[i][j];
//            A12[i][j] = A[i][j + newSize];
//            A21[i][j] = A[i + newSize][j];
//            A22[i][j] = A[i + newSize][j + newSize];
//            B11[i][j] = B[i][j];
//            B12[i][j] = B[i][j + newSize];
//            B21[i][j] = B[i + newSize][j];
//            B22[i][j] = B[i + newSize][j + newSize];
//        }
//    }
//
//    int **temp1_1 = new int *[newSize];
//    int **temp1_2 = new int *[newSize];
//    int **temp2_1 = new int *[newSize];
//    int **temp2_2 = new int *[newSize];
//
//    for (int i = 0; i < newSize; i++) {
//        temp1_1[i] = new int[newSize];
//        temp1_2[i] = new int[newSize];
//        temp2_1[i] = new int[newSize];
//        temp2_2[i] = new int[newSize];
//    }
//
//    for (int i = 0; i < newSize; i++) {
//        for (int j = 0; j < newSize; j++) {
//            temp1_1[i][j] = A11[i][j] + A22[i][j];
//            temp1_2[i][j] = B11[i][j] + B22[i][j];
//            temp2_1[i][j] = A21[i][j] + A22[i][j];
//            temp2_2[i][j] = B11[i][j];
//        }
//    }
//
//    M1 = strassenAlgorithm(temp1_1, temp1_2, newSize);
//    M2 = strassenAlgorithm(A22, B11, newSize);
//    M3 = strassenAlgorithm(A11, B12, newSize);
//    M4 = strassenAlgorithm(temp2_1, B22, newSize);
//    M5 = strassenAlgorithm(A11, temp2_2, newSize);
//    M6 = strassenAlgorithm(temp1_2, B21, newSize);
//    M7 = strassenAlgorithm(A12, temp2_1, newSize);
//
//    for (int i = 0; i < newSize; i++) {
//        for (int j = 0; j < newSize; j++) {
//            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
//            C12[i][j] = M3[i][j] + M5[i][j];
//            C21[i][j] = M2[i][j] + M4[i][j];
//            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
//        }
//    }
//
//    for (int i = 0; i < newSize; i++) {
//        for (int j = 0; j < newSize; j++) {
//            C[i][j] = C11[i][j];
//            C[i][j + newSize] = C12[i][j];
//            C[i + newSize][j] = C21[i][j];
//            C[i + newSize][j + newSize] = C22[i][j];
//        }
//    }
//    return C;
}