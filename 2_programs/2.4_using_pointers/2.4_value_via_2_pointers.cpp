#include <iostream>
using namespace std;

// returning a value through a pointer to a pointer
bool max_element(int* p, int* q, int** res) {
    if (p == q){
        return false;
    }
    *res = p;
    for(; p != q; ++p) {
        if (*p > **res) {
            *res = p;
        }
    }
    return true;
}

int main() {
    int m[5] = {1, 100, 5, 10, 2};
    int *pmax = 0;
    if (max_element(m, m + 5, &pmax)) {
        cout << *pmax;
    }
    return 0;
}
