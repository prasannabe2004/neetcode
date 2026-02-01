#include <iostream>
#include <string>
using namespace std;
/*
Palindrome Check
Given a string, determine if it is a palindrome, considering only alphanumeric
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

class Solution {
   public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    bool isPalindrome(const string& s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            if (isalnum(c)) {
                charCount[tolower(c)]++;
            }
        }
        int oddCounts = 0;
        for (auto it : charCount) {
            if (it.second % 2 != 0) {
                oddCounts++;
                if (oddCounts > 1) {
                    return false;
                }
            }
        }
        return oddCounts <= 1;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome("abbca") << endl;
    cout << solution.isPalindrome("abccba") << endl;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}