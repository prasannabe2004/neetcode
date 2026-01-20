#include <iostream>
#include <vector>

using namespace std;

/*
Reverse a string in place.
https://leetcode.com/problems/reverse-string
Write a function that reverses a string. The input string is given as an array
of characters s.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}