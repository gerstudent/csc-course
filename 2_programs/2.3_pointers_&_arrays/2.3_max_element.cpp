#include <iostream>
using namespace std;

int max_element(const int* m, int size) {
    int max = *m;
    for (int i = 0; i < size; ++i) {
        if (m[i] > max) {
            max = m[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << max_element(arr, n);
}