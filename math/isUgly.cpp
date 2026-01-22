#include <iostream>
using namespace std;

/* LeetCode Problem: Ugly Number
https://leetcode.com/problems/ugly-number
An ugly number is a positive integer whose prime factors are limited to 2, 3,
and 5. Given an integer n, return true if n is an ugly number.

Example 1:
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: n = 8
Output: true
Explanation: 8 = 2 × 2 × 2
*/

class Solution {
   public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n = 28;
    if (solution.isUgly(n)) {
        std::cout << n << " is an ugly number." << std::endl;
    } else {
        std::cout << n << " is not an ugly number." << std::endl;
    }
    return 0;
}