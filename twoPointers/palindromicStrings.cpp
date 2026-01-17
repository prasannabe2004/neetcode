#include <iostream>
#include <string>
using namespace std;

/*
Given a string, your task is to count how many palindromic substrings in this
string. The substrings with different start indexes or end indexes are counted
as different substrings even they consist of same characters.
Input: "abc"
Output: 3
*/
class Solution {
   public:
    int expand(string s, int start, int end) {
        int c = 0;
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            c++;
            start--;
            end++;
        }
        return c;
    }
    /*
    Time Complexity: O(n^2) Space Complexity: O(1)
    */
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i;
            count += expand(s, left, right);
            left = i;
            right = i + 1;
            count += expand(s, left, right);
        }
        return count;
    }
    /*
    Time Complexity: O(n^3) Space Complexity: O(1)
    */
    int countSubstringsBruteForce(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                // check if s[i...j] is palindrome
                int left = i;
                int right = j;
                while (left < right && s[left] == s[right]) {
                    left++;
                    right--;
                }
                if (left >= right) count++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("abbac") << endl;
    cout << s.countSubstringsBruteForce("abbac") << endl;
    return 0;
}