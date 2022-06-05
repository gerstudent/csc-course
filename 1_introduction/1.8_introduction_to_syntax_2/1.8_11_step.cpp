/*
    Created by gerstudent

    Напишите программу для решения квадратных уравнений вида ax^2+bx+c=0 (относительно x).
    На вход программа получает три целых числа: a, b, и c соответственно.
    При этом гарантируется, что a ≠ 0. На вывод программа должна вывести два вещественных
    корня уравнения, разделённые пробелом. Если вещественных корней нет, то программа должна
    вывести строку "No real roots". Если у уравнения имеется только один корень
    (кратный корень), то программа должна вывести его дважды.
    Порядок вывода корней не важен. Ничего, кроме этого, выводить не нужно.

    Sample Input 1:
    1 4 4

    Sample Output 1:
    -2 -2

    Sample Input 2:
    1 0 1

    Sample Output 2:
    No real roots

    Sample Input 3:
    1 0 0

    Sample Output 3:
    0 0

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    if (d < 0) {
        cout << "No real roots";
    }
    else {
        cout << (-b - sqrt(d)) / (2.0 * a) << " " << (-b + sqrt(d)) / (2.0 * a) << endl;
    }
    return 0;
}