#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"

Output: false
*/
class Solution {
   public:
   /*
   Using hashmap
   Time complexity: O(n)
   Space complexity: O(n)
   */
    bool wordPattern(string pattern, string s) {
        // Split the words from string s
        // pattern - "abba"
        // s - "dog cat cat dog"
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c) && charToWord[c] != w) return false;
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
    return 0;
}