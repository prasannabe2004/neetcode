#include <stdio.h>
/*
Function to find sum
*/
int sum(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += arr[i];
    }
    return res;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%lu\n", sizeof(arr) / sizeof(arr[0]));
    printf("%lu\n", sizeof(&arr) / sizeof(arr[0]));
    return 0;
}
