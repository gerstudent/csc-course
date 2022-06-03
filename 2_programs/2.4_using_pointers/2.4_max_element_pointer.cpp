#include <iostream>
using namespace std;

// function for finding the maximum element in an array
int* max_element(int* p, int* q) {
    int *pmax = p;
    for (; p != q; ++p) {
        if (*p > *pmax) {
            pmax = p;
        }
    }
    return pmax;
}

int main() {
    int m[5] = {1, 100, 5, 10, 2};
    int *pmax = max_element(m, m + 5);
    cout << *pmax << endl;
    return 0;
}