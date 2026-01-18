#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * Expectation: Return true if brackets are properly matched and nested.
 *
 * Example:
 * Input: s = "()[]{}"
 * Output: true
 */

class Solution {
   public:
    bool isValid(string s) {
        stack<char> myStack;
        unordered_map<char, char> m = {{'{', '}'}, {'[', ']'}, {'(', ')'}};

        for (char c : s) {
            if (m.find(c) != m.end()) {
                myStack.push(c);
            } else {
                if (myStack.empty()) {
                    return false;
                }
                char top = myStack.top();
                myStack.pop();
                if (m[top] != c) {
                    return false;
                }
            }
        }
        return myStack.empty();
    }
};

int main() {
    Solution s;
    string str = "()[]";
    cout << s.isValid(str) << endl;
    str = "([)]";
    cout << s.isValid(str) << endl;
    return 0;
}
