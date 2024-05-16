#ifndef MATRIX_STATIC_LIB_MATRIX_MULTIPLICATION_H
#define MATRIX_STATIC_LIB_MATRIX_MULTIPLICATION_H

void matrixMultiplication(
        int *matrix1,
        int *matrix2,
        int *result,
        int rows1,
        int columns1,
        int columns2
);

int **strassenAlgorithm(
        int **A,
        int **B,
        int n
);

int **blockMatrixMultiplication(
        int **A,
        int **B,
        int n,
        int blockSize
);
#endif //MATRIX_STATIC_LIB_MATRIX_MULTIPLICATION_H
;