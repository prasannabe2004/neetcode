#include <stdio.h>

#define NUM 10

void fun(int *x) {
    *x = 11;
}
int main() {
    int x = 10;
    int *p = &x;
    fun(p);
    printf("%d\n", x);
    return 0;
}