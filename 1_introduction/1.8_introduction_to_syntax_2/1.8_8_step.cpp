/*
    Created by gerstudent

    Реализуйте макрос MAX от трёх параметров, который присваивает целочисленной (int) переменной,
    переданной в качестве третьего аргумента, наибольшее из значений, переданных в первых двух аргументах.

    Пример вызова макроса:

    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a, b, c); // теперь c равно 20
    MAX(a += b, b, c); // теперь a = с = 30

*/

#define MAX(x, y, r) ({typeof(x) nx = x; typeof(y) ny = y; (r) = (nx > ny ? nx : ny);})