#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
LeetCode Problem: Length of Longest Substring Without Repeating Characters
https://leetcode.com/problems/length-of-longest-substring-without-repeating-characters
Given a string s, find the length of the longest substring without repeating
characters.

Example: Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

class Solution {
   public:
    /*
    Brute force approach
     Time Complexity: O(N^2)
     Space Complexity: O(min(M,N)) where M is the size of charset and N is the
     size of string
     */
    int lengthOfLongestSubstringBruteForce(string s) {
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> charSet;
            for (int j = i; j < n; j++) {
                if (charSet.find(s[j]) != charSet.end()) {
                    break;
                }
                charSet.insert(s[j]);
            }
            res = max(res, static_cast<int>(charSet.size()));
        }
        return res;
    }
    /*
    Optimized sliding window approach using index array
    Time Complexity: O(N)
    Space Complexity: O(M) where M is the size of charset
    */
    int lengthOfLongestSubstring(string s) {
        // vector<int> index(256, -1);  // ASCII size
        vector<int> index(4, -1);
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            int i = s[right] - 'a';
            if (index[i] != -1) {
                left = max(index[i] + 1, left);
            }
            index[i] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }

    /*
    Sliding window approach
    Time Complexity: O(N)
    Space Complexity: O(min(M,N)) where M is the size of charset and N is the
    size of string
    */

    int lengthOfLongestSubstring2(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < s.size(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "abcabcd";
    cout << "Length of longest substring without repeating characters: " << endl
         << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}