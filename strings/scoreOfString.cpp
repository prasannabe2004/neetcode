#include <iostream>
#include <string>

using namespace std;

/*
Score of a String
https://leetcode.com/problems/score-of-a-string
The score of a string is defined as the sum of the absolute differences of the
ASCII values of adjacent characters in the string. Given a string s, return the
score of s.

Example 1:
Input: s = "abc"
Output: 2
Explanation: The score of "abc" is abs('a' - 'b') + abs('b' - 'c') = 1 + 1 = 2.

Example 2:
Input: s = "aaa"
Output: 0
Explanation: The score of "aaa" is abs('a' - 'a') + abs('a' - 'a') = 0 + 0 = 0.
*/

class Solution {
   public:
    /*
     Time Complexity: O(n) where n is the length of the input string
     Space Complexity: O(1)
     */
    int scoreOfString(string s) {
        int res = 0;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int score = abs(s[i] - s[i - 1]);
            res += score;
        }
        return res;
    }
};

int main() {
    Solution s;
    string str1 = "abc";
    cout << "Score of \"" << str1 << "\": " << s.scoreOfString(str1) << endl;

    string str2 = "aaa";
    cout << "Score of \"" << str2 << "\": " << s.scoreOfString(str2) << endl;

    string str3 = "hello";
    cout << "Score of \"" << str3 << "\": " << s.scoreOfString(str3) << endl;

    return 0;
}