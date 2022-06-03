#include <iostream>
using namespace std;

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
