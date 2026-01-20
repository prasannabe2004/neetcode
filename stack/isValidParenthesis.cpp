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
        unordered_map<char, char> bracketPairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (bracketPairs.find(c) == bracketPairs.end()) {
                cout << "Pushing " << c << " to stack" << endl;
                myStack.push(c);
            } else {
                if (myStack.empty()) {
                    cout << "Stack is empty but found closing bracket " << c
                         << endl;
                    return false;
                }
                // If it's a closing bracket, check for matching opening bracket
                if (myStack.top() == bracketPairs[c]) {
                    cout << "Popping " << myStack.top() << " from stack"
                         << endl;
                    myStack.pop();
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
