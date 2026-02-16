#include <iostream>
#include <string>

using namespace std;

/*
You are given a character array s that contains words separated by single
spaces. Your task is to reverse the order of the words in the array while
keeping each word's internal character order intact.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "hello world"
Output: "world hello"
*/

class Solution {
   public:
    void reverseRange(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    string reverseWords(string s) {
        int n = s.length();
        string result;
        int wordStart = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverseRange(s, wordStart, i - 1);
                wordStart = i + 1;
            } else if (i == n - 1) {
                reverseRange(s, wordStart, i);
            }
        }
        reverseRange(s, 0, n - 1);
        return s;
    }
};

int main() {
    Solution sol;
    string s1 = "the sky is blue";
    cout << "Reversed string: " << sol.reverseWords(s1) << endl;

    string s2 = "hello world";
    cout << "Reversed string: " << sol.reverseWords(s2) << endl;

    return 0;
}