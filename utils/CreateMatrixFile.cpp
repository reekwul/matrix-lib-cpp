#include "../include/utils/CreateMatrixFile.h"
#include "../include/utils/CreateRandFile.h"
#include <iostream>
#include <fstream>

int **CreateMatrixFile(const char *filename, int n){
    int **matrix = new int *[n];
    CreateRandFile(filename, n);
    ifstream file(filename);

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }

    return matrix;
}
