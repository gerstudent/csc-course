unsigned gcd(unsigned a, unsigned b) {
    return a == 0 ? b : b == 0 ? a : a == b ? a : gcd(b, a % b);
}



