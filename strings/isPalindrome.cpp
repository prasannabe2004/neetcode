#include <iostream>
#include <string>
using namespace std;
/*
Palindrome Check
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
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
};

int main() {
    Solution solution;
    cout << solution.isPalindrome("abcba") << endl;
    cout << solution.isPalindrome("abccba") << endl;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}