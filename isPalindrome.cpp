#include <iostream>
using namespace std;

/*
Valid Palindrome Problem:
Given a string s, determine if it is a palindrome, considering only alphanumeric characters
and ignoring cases.

A palindrome reads the same forward and backward.

Solution Approach:
Two-pointer technique:
- Use left pointer starting from beginning and right pointer from end
- Skip non-alphanumeric characters (using isalnum())
- Compare characters case-insensitively (using tolower())
- If characters don't match, return false
- If pointers meet/cross, the string is a palindrome

Time Complexity: O(n) - single pass through the string
Space Complexity: O(1) - only uses two pointers

Example:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome when ignoring spaces and punctuation
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;
    return 0;
}
