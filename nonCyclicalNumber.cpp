#include <bits/stdc++.h>
#include <math.h>

/*
A non-cyclical number is an integer defined by the following algorithm:

Given a positive integer, replace it with the sum of the squares of its digits.
Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
If it stops at 1, then the number is a non-cyclical number.
Given a positive integer n, return true if it is a non-cyclical number, otherwise return false.
Example 1:
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

*/

using namespace std;

class Solution
{
public:
    int sumDigitSquare(int n)
    {
        int sq = 0;
        while (n)
        {
            int digit = n % 10;
            sq += digit * digit;
            n = n / 10;
        }
        return sq;
    }
    bool isHappy(int n)
    {
        set<int> s;
        while (1)
        {
            if (n == 1)
                return true;
            n = sumDigitSquare(n);
            if (s.find(n) != s.end())
                return false;
            s.insert(n);
        }
    }
};

int main()
{
    Solution s;
    cout << s.isHappy(101) << endl;
    return 0;
}