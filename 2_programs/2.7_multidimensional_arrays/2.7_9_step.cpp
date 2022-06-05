/*
    Created by gerstudent

    Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами,
    просто двумерный целочисленный массив) размера rows × cols, и возвращает
    транспонированную матрицу M^T (тоже двумерный целочисленный массив) размера cols × rows.
    Если в M на пересечении i-ой строки и j-ого столбца стояло число x, то на пересечении
    j-ой строки и i-ого столбца в матрице M^T тоже будет стоять число x, или другими словами
    M^T[j][i] = M[i][j].

*/

int** transpose(const int * const * m, unsigned rows, unsigned cols) {
    // memory allocation
    int** mt = new int* [cols];
    mt[0] = new int [cols * rows];
    for (unsigned i = 1; i != cols; ++i) {
        mt[i] = mt[i - 1] + rows;
    }
    // transpose
    for (unsigned i = 0; i < cols; ++i) {
        for (unsigned j = 0; j < rows; ++j) {
            mt[i][j] = m[j][i];
        }
    }
    return mt;
}