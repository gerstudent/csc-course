/*
    Created by gerstudent

    Реализуйте функцию getline, которая считывает поток ввода посимвольно,
    пока не достигнет конца потока или не встретит символ переноса строки
    ('\n'), и возвращает C-style строку с прочитанными символами.

*/

#include "iostream"
using namespace std;

char* getline() {
    int cnt = 0;
    char c;
    char* arr = new char[1];
    while (cin.get(c) && (c != '\n')) {
        arr[cnt] = c;
        cnt++;
        char* new_arr = new char[cnt + 1];
        for (int i = 0; i < cnt; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    arr[cnt] = '\0';
    return arr;
}