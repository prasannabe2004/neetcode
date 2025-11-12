/*
 * Given a positive integer n, return true if it is a happy number, or false if
 * not.
 *
 * Expectation: Return true if repeatedly replacing with sum of squares of
 * digits eventually reaches 1.
 *
 * Example:
 * Input: n = 19
 * Output: true
 */

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
   public:
    int sumDigitSquare(int n) {
        int sq = 0;
        while (n) {
            int digit = n % 10;
            sq += digit * digit;
            n = n / 10;
        }
        return sq;
    }
    bool isHappy(int n) {
        set<int> s;
        while (1) {
            if (n == 1) return true;
            n = sumDigitSquare(n);
            if (s.find(n) != s.end()) return false;
            s.insert(n);
        }
    }
};

int main() {
    Solution s;
    cout << s.isHappy(101) << endl;
    return 0;
}