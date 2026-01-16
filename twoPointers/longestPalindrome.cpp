#include <iostream>
#include <string>
using namespace std;

/*
Given a string which consists of lowercase or uppercase letters, find the length
of the longest palindromes that can be built with those letters.
Input: "abccccdd"
 */
class Solution {
   public:
    /*
    Brute Force
    Time: O(n^3), Space: O(1)
    */
    string longestPalindromeBruteForce(string s) {
        int resLen = 0;
        string res;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                int l = i;
                int r = j;
                while (l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }
                int len = j - i + 1;
                if (l >= r && len > resLen) {
                    res = s.substr(i, len);
                    resLen = max(resLen, len);
                }
            }
        }
        return res;
    }
    /*
    Expand Around Center
    Time: O(n^2), Space: O(1)
    */
    string longestPalindrome(string s) {
        int resLen = 0;
        string res;
        int resIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            // odd length
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > resLen) {
                    resIdx = left;
                    resLen = len;
                }
                left--;
                right++;
            }

            // even length
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > resLen) {
                    resIdx = left;
                    resLen = len;
                }
                left--;
                right++;
            }
        }
        return s.substr(resIdx, resLen);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeBruteForce("abbac") << endl;
    cout << s.longestPalindrome("abbac") << endl;
    return 0;
}