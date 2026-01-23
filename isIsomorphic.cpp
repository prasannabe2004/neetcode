#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, char> s_map;
    unordered_map<char, char> t_map;

   public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s_map.find(s[i]) == s_map.end()) {
                s_map[i]] = t[i];
            }
        }
    }
};
