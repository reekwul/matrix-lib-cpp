#include "../include/utils/CreateRandFile.h"
#include <iostream>
#include <fstream>

using namespace std;

void CreateRandFile(const char *filename, int n) {

    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла";
    }

    for (int i = 0; i < n * n; i++) {
        file << rand() / 10000000 << " ";
    }

    file.close();
}
