#include <iostream>

using namespace std;

/*
Power of Two
https://leetcode.com/problems/power-of-two
Given an integer n, return true if it is a power of two. Otherwise, return false
*/

class Solution {
   public:
    bool isPowerOfTwo1(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
    bool isPowerOfTwo2(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n % 2 != 0) {
                return false;
            }
            n = n / 2;
        }
        return true;
    }
    bool isPowerOfTwo(int n) { return n > 0 && (1 << 31) % n == 0; }
};

int main() {
    Solution s;
    cout << s.isPowerOfTwo(1) << endl;   // true
    cout << s.isPowerOfTwo(16) << endl;  // true
    cout << s.isPowerOfTwo(3) << endl;   // false
    return 0;
}