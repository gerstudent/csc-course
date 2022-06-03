#include <iostream>
using namespace std;

// function for finding the maximum element in an array using pointers
int max_element(int* p, int* q) {
    int max = *p;
    for (; p != q; ++p) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int main() {
    int m[5] = {1, 100, 5, 10, 2};
    int max = max_element(m, m + 5);
    cout << max << endl;
    return 0;
}