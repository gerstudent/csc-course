unsigned strlen(const char* str) {
    int res = 0;
    for (; str[res] != '\0'; ++res) {}
    return res;
}