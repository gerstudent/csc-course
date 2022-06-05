/*
    Created by gerstudent

    Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел,
    ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение,
    и меняет эту строку местами с первой строкой массива.

*/

void swap_min(int* m[], unsigned rows, unsigned cols) {
    int min = m[0][0], minVal = 0;
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
                minVal = i;
            }
        }
    }
    // swap(m[minVal], m[0]);
    int* temp = m[minVal];
    m[minVal] = m[0];
    m[0] = temp;
}





