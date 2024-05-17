#include "../include/Matrix.h"
#include "../include/utils/Math.h"

Matrix::Matrix() {}

int **Matrix::AdditionToSquare(int **matrix, int countRows, int countColumns, int n) {
    int **result = new int *[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n];
    }

    for (int i = 0; i < countRows; i++) {
        for (int j = 0; j < countColumns; j++) {
            result[i][j] = matrix[i][j];
        }
    }
    return result;
}

void Matrix::Multiplication(const int *matrixA, const int *matrixB, int *result, int countRowsA, int countColumnsA,
                            int countColumnsB) {
    for (int i = 0; i < countRowsA; ++i) {
        for (int j = 0; j < countColumnsB; ++j) {
            result[i * countColumnsB + j] = 0;
            for (int k = 0; k < countColumnsA; ++k) {
                result[i * countColumnsB + j] += matrixA[i * countColumnsA + k] * matrixB[k * countColumnsB + j];
            }
        }
    }
}

int **Matrix::BlockMultiplication(int **matrixA, int **matrixB, int n, int blockSize) {
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
                            C[bi + i][bj + j] += matrixA[bi + i][bk + k] * matrixB[bk + k][bj + j];
                        }
                    }
                }
            }
        }
    }
    return C;
}

int **Matrix::Multiply(int **matrixA, int **matrixB, int n) {
    int **result = new int *[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n];
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int **Matrix::StrassenAlgorithm(int **matrixA, int **matrixB, int n) {
    CMath math;
    if (!math.Pow(n)) {
        int newSize = math.Dimension(matrixA, matrixB, n, n, n);
        matrixA = this->AdditionToSquare(matrixA, n, n, newSize);
        matrixB = this->AdditionToSquare(matrixB, n, n, newSize);
    }
    int **C = new int *[n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }
    if (n <= 64) {
        C = this->Multiply(matrixA, matrixB, n);
        return C;
    }

    int newSize = n / 2;
    int **A11 = new int *[newSize];
    int **A12 = new int *[newSize];
    int **A21 = new int *[newSize];
    int **A22 = new int *[newSize];
    int **B11 = new int *[newSize];
    int **B12 = new int *[newSize];
    int **B21 = new int *[newSize];
    int **B22 = new int *[newSize];
    int **C11 = new int *[newSize];
    int **C12 = new int *[newSize];
    int **C21 = new int *[newSize];
    int **C22 = new int *[newSize];
    int **M1 = new int *[newSize];
    int **M2 = new int *[newSize];
    int **M3 = new int *[newSize];
    int **M4 = new int *[newSize];
    int **M5 = new int *[newSize];
    int **M6 = new int *[newSize];
    int **M7 = new int *[newSize];
    int **temp1 = new int *[newSize];
    int **temp2 = new int *[newSize];

    for (int i = 0; i < newSize; i++) {
        A11[i] = new int[newSize];
        A12[i] = new int[newSize];
        A21[i] = new int[newSize];
        A22[i] = new int[newSize];
        B11[i] = new int[newSize];
        B12[i] = new int[newSize];
        B21[i] = new int[newSize];
        B22[i] = new int[newSize];
        C11[i] = new int[newSize];
        C12[i] = new int[newSize];
        C21[i] = new int[newSize];
        C22[i] = new int[newSize];
        M1[i] = new int[newSize];
        M2[i] = new int[newSize];
        M3[i] = new int[newSize];
        M4[i] = new int[newSize];
        M5[i] = new int[newSize];
        M6[i] = new int[newSize];
        M7[i] = new int[newSize];
        temp1[i] = new int[newSize];
        temp2[i] = new int[newSize];
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    int **temp1_1 = new int *[newSize];
    int **temp1_2 = new int *[newSize];
    int **temp2_1 = new int *[newSize];
    int **temp2_2 = new int *[newSize];

    for (int i = 0; i < newSize; i++) {
        temp1_1[i] = new int[newSize];
        temp1_2[i] = new int[newSize];
        temp2_1[i] = new int[newSize];
        temp2_2[i] = new int[newSize];
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            temp1_1[i][j] = A11[i][j] + A22[i][j];
            temp1_2[i][j] = B11[i][j] + B22[i][j];
            temp2_1[i][j] = A21[i][j] + A22[i][j];
            temp2_2[i][j] = B11[i][j];
        }
    }

    M1 = this->StrassenAlgorithm(temp1_1, temp1_2, newSize);
    M2 = this->StrassenAlgorithm(A22, B11, newSize);
    M3 = this->StrassenAlgorithm(A11, B12, newSize);
    M4 = this->StrassenAlgorithm(temp2_1, B22, newSize);
    M5 = this->StrassenAlgorithm(A11, temp2_2, newSize);
    M6 = this->StrassenAlgorithm(temp1_2, B21, newSize);
    M7 = this->StrassenAlgorithm(A12, temp2_1, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    return C;
}
