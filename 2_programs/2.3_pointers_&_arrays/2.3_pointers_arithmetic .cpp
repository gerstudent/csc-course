#include <iostream>
using namespace std;

// pointers arithmetic example
int main() {
    int m[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* p = &m[4];
    int* q = &m[9]; // address of the last element
    int k = 3;
    cout << *p << ' ' << *q << ' ' << endl;
    cout << *(p + k) << endl;   // shift k int cells to the right
    cout << *(p - k) << endl;   // shift k int cells to the left
    cout << (q - p) << endl;    // number of cells between pointers
    cout << p[k] << ' ' << *(p + k);    // p[k] is equal to *(p + k);
}