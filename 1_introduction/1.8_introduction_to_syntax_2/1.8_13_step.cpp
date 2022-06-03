#include <iostream>
using namespace std;

int log(int n) {
    int i = 1, p = 0;
    while (i <= n) {
        i *= 2;
        p++;
    }
    return p - 1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        cout << log(a) << endl;
    }
    return 0;
}