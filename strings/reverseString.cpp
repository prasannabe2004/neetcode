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
    /*
    Two pointer approach
    Time complexity: O(n)
    Space complexity: O(1)
    */
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    /*
    For loop approach
    Time complexity: O(n)
    Space complexity: O(1)
    */
    void reverseString2(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
    /*
    Using stack
    Time complexity: O(n)
    Space complexity: O(n)
    */
    void reverseString3(vector<char>& s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
    /*
    Using recursion
    Time complexity: O(n)
    Space complexity: O(n)
    */
    void reverseHelper(vector<char>& s, int l, int r) {
        if (l >= r) return;
        swap(s[l], s[r]);
        reverseHelper(s, l + 1, r - 1);
    }
    void reverseString4(vector<char>& s) { reverseHelper(s, 0, s.size() - 1); }
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