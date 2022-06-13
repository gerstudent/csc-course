/*
    Created by gerstudent

    Завершите класс String, добавив к нему оператор присваивания. Будьте аккуратны при работе
    с памятью. Инвариант класса остается тем же (в size хранится размер строки без завершающего
    0 символа, str указывает на C-style строку, т. е. с завершающим нулевым символом).

*/

#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

struct String {
    String(const char *str = "");
    String(size_t n, char c);
    String(const String &other);
    ~String();

    void swap(String &other) {
        std::swap(size, other.size);
        std::swap(str, other.str);
    }

    /* Реализуйте оператор присваивания */
    String &operator=(const String &other) {
        if (this != &other) {
            String(other).swap(*this);
        }
        return *this;
    }

    void append(const String &other);

    size_t size;
    char *str;
};
