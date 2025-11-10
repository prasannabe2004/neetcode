#include <bits/stdc++.h>
#include <math.h>

/*
Valid Anagram Problem:
Given two strings s and t, return true if the two strings are anagrams of each other,
otherwise return false.

An anagram is a word or phrase formed by rearranging the letters of another word or phrase,
using all the original letters exactly once.

Solution Approaches:

1. isAnagramSorting:
   - Sort both strings and compare if they are equal
   - Time Complexity: O(n log n) - due to sorting
   - Space Complexity: O(1) or O(n) depending on sort implementation

2. isAnagram (Hash Map approach):
   - Use a hash map to count character frequencies
   - Increment count for characters in s, decrement for characters in t
   - If all counts are 0, the strings are anagrams
   - Time Complexity: O(n) - single pass through both strings
   - Space Complexity: O(k) where k is the number of unique characters

Example:
Input: s = "anagram", t = "nagaram"
Output: true (both contain the same letters with same frequencies)
*/

using namespace std;

class Solution
{
public:
    bool isAnagramSorting(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> m;
        for (char c : s)
        {
            m[c] += 1;
        }
        for (char c : t)
        {
            m[c] -= 1;
        }
        for (auto v : m)
        {
            if (v.second != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("racecar", "carrace") << endl;
    return 0;
}
