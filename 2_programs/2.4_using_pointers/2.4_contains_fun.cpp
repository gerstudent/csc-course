// function to search for an element in an array
bool contains(int* p, int* q, int value) {
    for (; p != q; ++p) {
        if (*p == value) {
            return true;
        }
    }
    return false;
}