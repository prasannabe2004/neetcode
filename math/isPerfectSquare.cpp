#include <iostream>

using namespace std;

/*
You are given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false

*/
class Solution {
   public:
    /*
    Brute Force O(n/2)
    Time Complexity : O(n/2) -> O(n)
    Space Complexity : O(1)
    */
    bool isPerfectSquareBruteForce(int num) {
        for (int i = 1; i < num; i++) {
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }
    /*
    Binary Search O(log n)
    Time Complexity : O(log n)
    Space Complexity : O(1)
    */
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        int res = 0;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long square = m * m;
            cout << m << endl;
            if (square == num) {
                return true;
            } else if (square < num) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPerfectSquareBruteForce(625) << endl;
    cout << s.isPerfectSquare(100000000) << endl;
}