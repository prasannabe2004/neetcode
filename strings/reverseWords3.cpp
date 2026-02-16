#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
Given a string s, reverse the order of characters in each word within a sentence
while still preserving whitespace and initial word order.
Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:
Input: s = "God Ding"
Output: "doG gniD"
*/

class Solution {
   public:
    string reverseWords2(string s) {
        string tmpStr = "";
        string res = "";

        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                res += tmpStr;
                tmpStr = "";
                if (i != s.length()) {
                    res += " ";
                }
            } else {
                tmpStr = s[i] + tmpStr;
            }
        }
        return res;
    }
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res;
        bool first = true;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            if (first) {
                first = false;
                res = res + word;
            } else {
                res = res + " " + word;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s1 = "Let's take LeetCode contest";
    cout << "Reversed string: " << sol.reverseWords(s1) << endl;

    string s2 = "God Ding";
    cout << "Reversed string: " << sol.reverseWords2(s2) << endl;

    return 0;
}