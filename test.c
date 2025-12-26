#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%lu\n", sizeof(arr) / sizeof(arr[0]));
    printf("%lu\n", sizeof(&arr) / sizeof(arr[0]));
    return 0;
}
