#include <iostream>
#include <fstream>
#include "matrix_multiplication.h"
#include "include/utils/NulMatrix.h"
#include "include/utils/CreateMatrixFile.h"
#include "include/utils/ClearMemoryArray.h"

using namespace std;

int main() {
    int n;
    cout << "Введите размер матрицы (n*n): ";
    cin >> n;
    int **matrix1 = new int *[n];
    int **matrix2 = new int *[n];
    int **result = new int *[n];

    matrix1 = CreateMatrixFile("matrix1.txt", n);
    matrix2 = CreateMatrixFile("matrix2.txt", n);
    result = NulMatrix(result, n);

//    result = strassenAlgorithm(matrix1, matrix2, 2);
//    ofstream file3("result=matrix.txt");
//    if (file3.is_open()) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                file3 << result[i][j] << " ";
//            }
//            file3 << "\n";
//        }
//        file3.close();
//    }

    ClearMemoryArray(matrix1, n);
    ClearMemoryArray(matrix2, n);
    ClearMemoryArray(result, n);
    return 0;
}




