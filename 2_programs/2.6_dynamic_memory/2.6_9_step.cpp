/*
    Created by gerstudent

    В этой задаче вам нужно реализовать функцию resize. Функция resize
    принимает на вход три аргумента: указатель на область памяти, выделенную
    с помощью оператора new[], размер области (size) и новый размер (new_size).
    Функция должна выделить память размера new_size, скопировать в нее данные из
    переданной области памяти, освободить старую область памяти и вернуть выделенную
    область памяти нового размера со скопированными данными.

*/

/* check
#include <iostream>
using namespace std;
*/

char* resize(const char* str, unsigned size, unsigned new_size) {
    char* str_new = new char[new_size];
    for (int i = 0; i < size && i < new_size; ++i) {
        str_new[i] = str[i];
    }
    str_new[size] = '\0';
    delete[] str;
    str = nullptr;
    return str_new;
}

/* check
int main() {
    int i = 0, size = 8, new_size = 10;
    char* str = new char[size];
    string s = "example";
    for (char j: s) {
        str[i] = j;
        i++;
    }
    char* new_str = resize(str, size, new_size);
    for (int k = 0; k < new_size; k++) {
        cout << new_str[k];
    }
}
*/