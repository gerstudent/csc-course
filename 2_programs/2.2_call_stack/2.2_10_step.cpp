#include "iostream"
using namespace std;

void reverse() {
    int t;
    cin >> t;
    if (t != 0) {
        reverse();
        cout << t << " ";
    }
}

int main() {
    reverse();
}