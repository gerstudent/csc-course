/*
    Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных
    целых чисел (Greatest Common Divisor, GCD). Для этого воспользуйтесь следующими свойствами:

    1. GCD(a,b) = GCD(b,a mod b)
    2. GCD(0,a) = a
    3. GCD(a,b) = GCD(b,a)

 */

unsigned gcd(unsigned a, unsigned b) {
    return a == 0 ? b : b == 0 ? a : a == b ? a : gcd(b, a % b);
}