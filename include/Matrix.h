#ifndef MATRIX_STATIC_LIB_MATRIX_H
#define MATRIX_STATIC_LIB_MATRIX_H


class Matrix {
public:
    Matrix();
    void Multiplication(const int *matrixA, const int *matrixB, int *result, int countRowsA, int countColumnsA, int countColumnsB);
    int **BlockMultiplication(int **matrixA, int **matrixB, int n, int blockSize);
    int **AdditionToSquare(int **matrix, int countRows, int countColumns, int n);
    int **Multiply(int **matrixA, int **matrixB, int n);
    int **StrassenAlgorithm(int **matrixA, int **matrixB, int n);
};


#endif //MATRIX_STATIC_LIB_MATRIX_H
