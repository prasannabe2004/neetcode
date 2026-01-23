#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/

class Solution {
    unordered_map<char, char> s_map;
    unordered_map<char, char> t_map;

   public:
   /*
   Using two hash maps to store the mapping from s to t and t to s
   Time Complexity: O(n)
   Space Complexity: O(1) since the size of the charset is fixed
   */
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if ((s_map.find(c1) != s_map.end() && s_map[c1] != c2) ||
                (t_map.find(c2) != t_map.end() && t_map[c2] != c1)) {
                return false;
            }
            s_map[c1] = c2;
            t_map[c2] = c1;
        }
        return true;
    }
    /*
    Using one hash map and check if the mapping is consistent
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    bool helper(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (map.find(c1) != map.end()) {
                if (map[c1] != c2) return false;
            } else {
                map[c1] = c2;
            }
        }
        return true;
    }
    bool isIsomorphic2(string s, string t) {
        return helper(s, t) && helper(t, s);
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    return 0;
}
