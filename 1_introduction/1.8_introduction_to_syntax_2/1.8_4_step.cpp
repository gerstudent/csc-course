int power(int x, unsigned p) {
    return p == 0 ? 1 : p % 2 == 0 ? x * power(x, p - 1) : x * power(x * x, p / 2);
}