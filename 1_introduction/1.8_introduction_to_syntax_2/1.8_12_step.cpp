/*
    Created by gerstudent

    Напишите программу, которая посимвольно читает из std::cin, пока не достигнет
    конца потока ввода, и заменяет несколько подряд идущих пробелов одним и выводит
    полученный результат в std::cout. Никаких других символов, кроме пробелов удалять
    не нужно. При выполнении задания вам не разрешается пользоваться дополнительной
    памятью, а именно: массивами, стандартными контейнерами и строками, даже если вы уже
    с ними знакомы. Вы можете определять любые вспомогательные функции, если они вам нужны.

    Sample Input:
    There are    a     lot  of    spaces  here

    Sample Output:
    There are a lot of spaces here

*/

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