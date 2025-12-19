#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint32_t a;
    float f;
} u;

/*
3f       80         00          00
01111111 10000000   00000000    00000000
*/
int main() {
    u uni;
    uni.a = 1;
    uni.f = 2.5;
    printf("%d\n", uni.a);
    printf("%.1f\n", uni.f);
    return 0;
}