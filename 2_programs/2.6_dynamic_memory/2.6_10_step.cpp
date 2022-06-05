/*
    Created by gerstudent

    Реализуйте функцию getline, которая считывает поток ввода посимвольно,
    пока не достигнет конца потока или не встретит символ переноса строки
    ('\n'), и возвращает C-style строку с прочитанными символами.

*/

#include <iostream>
using namespace std;

char* getline() {
    int count = 0;
    char c;
    char* arr = new char[1];
    while (cin.get(c) && (c != '\n')) {
        arr[count] = c;
        count++;
        char* new_arr = new char[count + 1];
        for (int i = 0; i < count; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    arr[count] = '\0';
    return arr;
}