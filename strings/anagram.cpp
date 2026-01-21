/*
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * Expectation: Return boolean indicating if strings are anagrams.
 *
 * Example:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 */

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
   public:
    /* Implementation of anagram checking using sorting
    Time Complexity: O(n log n)
    Space Complexity: O(1) or O(n) depending on sorting algorithm
    */
    bool isAnagramSorting(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    /* Implementation of anagram checking using hash map
    Time Complexity: O(n)
    Space Complexity: O(1) assuming fixed character set
    */
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> m;
        for (char c : s) {
            m[c] += 1;
        }
        for (char c : t) {
            m[c] -= 1;
        }
        for (auto v : m) {
            if (v.second != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isAnagram("racecar", "carrace") << endl;
    return 0;
}
