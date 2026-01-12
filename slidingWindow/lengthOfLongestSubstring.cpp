#include <iostream>
#include <unordered_set>

using namespace std;

/*
LeetCode Problem: Length of Longest Substring Without Repeating Characters
https://leetcode.com/problems/length-of-longest-substring-without-repeating-characters
Given a string s, find the length of the longest substring without repeating
characters. Example: Input: s = "abcabcbb" Output: 3 Explanation: The answer is
"abc", with the length of 3.
*/

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int r = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "
         << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}