#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int k, m;
    cin >> k, m;
    swap(&k, &m);
    cout << k << ' ' << m;
    return 0;
}