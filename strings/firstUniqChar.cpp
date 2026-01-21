#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
/*
Given a string s, find the first non-repeating character in it and return its
index. If it does not exist, return -1.

Example 1: Input: s = "leetcode" Output: 0
Explanation: The first non-repeating character is 'l', which is at index 0.

Example 2: Input: s = "loveleetcode" Output: 2
Explanation: The first non-repeating character is 'v', which is at index 2.

Example 3: Input: s ="aabb" Output: -1
Explanation: There is no non-repeating character, so return -1.

Constraints: 1 <= s.length <= 10^5 s consists of only lowercase English
letters.
*/

class Solution {
   public:
    /*
    Brute Force Approach
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    int firstUniqCharBruteForce(string s) {
        for (int i = 0; i < s.size(); i++) {
            bool isUnique = true;
            for (int j = 0; j < s.size(); j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return i;
            }
        }
        return -1;
    }
    /*
    Optimized Approach using Hash Map
    Time Complexity: O(n)
    Space Complexity: O(1) - Since the character set is fixed (lowercase
    English letters)
    */
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string s1 = "leetcode";
    cout << "First unique character index in \"" << s1
         << "\": " << sol.firstUniqChar(s1) << endl;

    string s2 = "loveleetcode";
    cout << "First unique character index in \"" << s2
         << "\": " << sol.firstUniqChar(s2) << endl;

    string s3 = "aabb";
    cout << "First unique character index in \"" << s3
         << "\": " << sol.firstUniqChar(s3) << endl;

    return 0;
}