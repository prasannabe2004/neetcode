/*
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * Expectation: Return true if string reads the same forward and backward
 * (ignoring non-alphanumeric characters and case).
 *
 * Example:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 */

#include <iostream>
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
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;
    return 0;
}
