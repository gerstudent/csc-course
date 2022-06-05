/*
    Created by gerstudent

    В этой задаче вам нужно реализовать функцию, которая сдвигает содержимое
    массива влево на заданное число позиций (циклический сдвиг). На вход функция
    принимает массив, его размер и величину сдвига. Например, если на вход функции
    подан массив: int a[] = { 1, 2, 3, 4, 5 }; и требуется циклически сдвинуть его
    влево на 2 позиции, то на выходе мы получим числа в таком порядке: 3, 4, 5, 1, 2.

*/

/* check
#include <iostream>
using namespace std;
*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int a[], unsigned size, int shift) {
    for (int i = 0; i < shift; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            swap(&a[j], &a[j + 1]);
        }
    }
}

/* check
int main() {
    unsigned size;
    int shift;
    cin >> size >> shift;
    int a[size];
    for (int i = 0; i < size; ++i) {
        cin >> a[i];
    }
    rotate(a, size, shift);
    for (int i = 0; i < size; ++i) {
        cout << a[i] << ' ';
    }
}
*/