#include "../include/utils/Math.h"

CMath::CMath() {}

int CMath::Pow(int n) {
    int k;
    while (n != 0) {
        k = n % 2;
        n = n / 2;
    }
    return k;
}

int CMath::Log2(int x) {
    int result = 1;
    while ((x >>= 1) != 0) {
        result++;
    }
    return result;
}

int CMath::Max(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int CMath::Dimension(int **a, int **b, int rowsA, int colsA, int colsB) {
    return 1 << this->Log2(this->Max(rowsA, colsA, colsB));
}

