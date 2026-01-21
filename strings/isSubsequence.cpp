#include <iostream>
#include <string>
using namespace std;
/*
Given two strings s and t, return true if s is a subsequence of t, or false
otherwise.
A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true
Explanation: "abc" is a subsequence of "ahbgdc".

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
Explanation: "axc" is not a subsequence of "ahbgdc".
Constraints:
0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.
*/

class Solution {
   public:
    /*
     Time Complexity: O(n)
     Space Complexity: O(1)
    */
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {
            if (t[j] == s[i]) {
                i++;
            }
            j++;
        }
        if (i == s.length()) return true;
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << "Is \"" << s1 << "\" a subsequence of \"" << t1
         << "\": " << (sol.isSubsequence(s1, t1) ? "true" : "false") << endl;

    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << "Is \"" << s2 << "\" a subsequence of \"" << t2
         << "\": " << (sol.isSubsequence(s2, t2) ? "true" : "false") << endl;

    return 0;
}