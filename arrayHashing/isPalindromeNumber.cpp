#include <iostream>

using namespace std;
/*
Palindrome Number
https://leetcode.com/problems/palindrome-number
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:
Input: x = -101
Output: false
Explanation: From left to right, it reads -101. From right to left, it becomes
101-. Therefore it is not a palindrome.
*/

class Solution {
   public:
    /*
    Time Complexity: O(n) where n is the number of digits in the input number
    Space Complexity: O(1)
    */
    bool isPalindrome(int x) {
        if (x < 0) return false;  // Negative numbers are not palindromes
        if (x >= 0 && x < 10)
            return true;  // Single digit numbers are palindromes

        int original = x;
        int reversed = 0;

        while (x > 0) {
            int digit = x % 10;  // Get the last digit
            reversed = reversed * 10 +
                       digit;  // Append the digit to the reversed number
            x /= 10;           // Remove the last digit
        }

        return original == reversed;  // Check if the original number is equal
                                      // to the reversed number
    }
};

int main() {
    Solution s;
    int num1 = 121;
    cout << num1 << " is a palindrome: " << s.isPalindrome(num1) << endl;

    int num2 = -121;
    cout << num2 << " is a palindrome: " << s.isPalindrome(num2) << endl;

    int num3 = 10;
    cout << num3 << " is a palindrome: " << s.isPalindrome(num3) << endl;

    int num4 = -101;
    cout << num4 << " is a palindrome: " << s.isPalindrome(num4) << endl;

    return 0;
}