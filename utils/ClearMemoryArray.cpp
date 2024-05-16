#include "../include/utils/ClearMemoryArray.h"

//Освобождает память, выделенную для массива значений
void ClearMemoryArray(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        delete mat[i];
    }
    delete[] mat;
}