#include <stdio.h>

char* my_strcpy(char* dst, const char* src) {
    int i = 0;
    if (dst == NULL) return NULL;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char* my_strcpy2(char* dst, const char* src) {
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return dst;
}

int main() {
    char dst[12];
    char* src = "Hello World";
    my_strcpy2(dst, src);
    printf("%s", dst);
    return 0;
}