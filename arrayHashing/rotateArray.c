/*
 * C version of rotateArray.cpp
 * Implements in-place rotation using the 3-reverse method
 */

#include <stdio.h>
#include <stdlib.h>

void swapElements(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int* a, int start, int end) {
    while (start <= end) {
        swapElements(&a[start], &a[end]);
        start++;
        end--;
    }
}

void rotateArray(int* nums, int n, int d) {
    if (n <= 0) return;
    d = d % n;
    reverseArray(nums, 0, n - 1);
    reverseArray(nums, 0, d - 1);
    reverseArray(nums, d, n - 1);
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    rotateArray(a, n, 3);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
