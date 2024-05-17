#ifndef MATRIX_STATIC_LIB_MATH_H
#define MATRIX_STATIC_LIB_MATH_H


class CMath {
public:
    CMath();
    int Pow(int n);

    int Log2(int x);

    int Max(int a, int b, int c);

    int Dimension(int **a, int **b, int rowsA, int colsA, int colsB);
};


#endif //MATRIX_STATIC_LIB_MATH_H
