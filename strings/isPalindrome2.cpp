 #include <iostream>
#include <string>
using namespace std;
/*
Palindrome 2
You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abc"
Output: false
*/

class Solution {
   public:
   /*
   Time Complexity: O(n)
   Space Complexity: O(1)
   */
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    */
    bool validPalidrome(const string& s) {
        if(isPalindrome(s) == true) {
            return true;
        }

        for(int i = 0; i < s.size(); i++) {
            string t = s;
            t.erase(i, 1);
            if (isPalindrome(t) == true) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.validPalidrome("abc") << endl;
    cout << solution.validPalidrome("abcba") << endl;
    cout << solution.validPalidrome("abccba") << endl;
    return 0;
}