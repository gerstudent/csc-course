void strcat(char* to, const char* from) {
    for(;*to; to++) {}
    for(;(*to++ = *from++);) {}
}