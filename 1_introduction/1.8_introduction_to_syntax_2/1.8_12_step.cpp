#include <iostream>
using namespace std;

int main() {
    bool flag = true;
    char c = '\0';
    while (cin.get(c)) {
        if (c != ' ') {
            cout << c;
            flag = true;
        }
        else if (flag) {
            cout << c;
            flag = false;
        }
    }
    return 0;
}