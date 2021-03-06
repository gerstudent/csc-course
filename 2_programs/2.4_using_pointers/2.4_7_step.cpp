/*
    Created by gerstudent

    Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк.
    Функция конкатенации принимает на вход две C-style строки и дописывает вторую
    в конец первой так, чтобы первая строка представляла из себя одну C-style строку
    равную конкатенации двух исходных.

    Гарантируется, что в первой строке достаточно памяти (т.е. она располагается
    в массиве достаточной длины), чтобы разместить конкатенацию обеих строк, но не больше.

*/

void strcat(char* to, const char* from) {
    for(;*to; to++) {}
    for(;(*to++ = *from++);) {}
}