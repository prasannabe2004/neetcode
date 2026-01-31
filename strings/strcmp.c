#include <stdio.h>
#include <string.h>
int my_strcmp(char* dst, const char* src) {
    while (*dst != '\0' && *src != '\0') {
        if (*dst != *src) {
            return *dst - *src;
        }
        dst++;
        src++;
    }
    return 0;
}

int main() {
    char* dst = "Hello WOrld";
    char* src = "Hello World";
    printf("%d\n", strcmp(dst, src));
    printf("%d\n", my_strcmp(dst, src));
    return 0;
}