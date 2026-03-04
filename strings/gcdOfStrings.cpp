#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;
/*
Greatest Common Divisor of Strings
https://leetcode.com/problems/greatest-common-divisor-of-strings
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (t
concatenated with itself 1 or more times) Given two strings str1 and str2,
return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Explanation: "ABC" is the largest string that divides both str1 and str2.

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Explanation: "AB" is the largest string that divides both str1 and str2.

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""
Explanation: There is no string that divides both str1 and str2.
*/

class Solution {
   public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        auto gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution s;
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "GCD of \"" << str1 << "\" and \"" << str2
         << "\": " << s.gcdOfStrings(str1, str2) << endl;

    str1 = "ABABAB";
    str2 = "ABAB";
    cout << "GCD of \"" << str1 << "\" and \"" << str2
         << "\": " << s.gcdOfStrings(str1, str2) << endl;

    str1 = "LEET";
    str2 = "CODE";
    cout << "GCD of \"" << str1 << "\" and \"" << str2
         << "\": " << s.gcdOfStrings(str1, str2) << endl;

    return 0;
}