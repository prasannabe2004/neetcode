/*
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * Expectation: Return true if string reads the same forward and backward
 * (ignoring non-alphanumeric characters and case).
 *
 * Example:
 * Input: s = "Was it a car or a cat I saw?"
 * Output: true
 */

#include <bits/stdc++.h>
#include <math.h>

using namespace std;
class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("Was it a car or a cat I saw?") << endl;
    return 0;
}