cmake_minimum_required(VERSION 3.28)
project(matrix_static_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(matrix_static_lib STATIC matrix_multiplication.cpp
        utils/PrintMatrix.cpp
        include/utils/PrintMatrix.h
        utils/NulMatrix.cpp
        utils/CreateRandFile.cpp
        include/utils/CreateMatrixFile.h)