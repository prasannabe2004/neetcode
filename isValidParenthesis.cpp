#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

/*
Valid Parentheses Problem:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets
2. Open brackets must be closed in the correct order
3. Every close bracket has a corresponding open bracket of the same type

Solution Approach:
Stack-based solution:
- Use a stack to track opening brackets
- Use a hash map to store matching pairs: opening -> closing
- For each character in the string:
  - If it's an opening bracket: push to stack
  - If it's a closing bracket: check if it matches the top of stack
    - If stack is empty or doesn't match: invalid
    - If matches: pop from stack
- At the end, stack must be empty (all brackets matched)

Time Complexity: O(n) - single pass through the string
Space Complexity: O(n) - stack can hold up to n/2 opening brackets

Example:
Input: s = "()[]{}"
Output: true (all brackets are properly matched and nested)

Input: s = "([)]"
Output: false (improper nesting)
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> myStack;
        unordered_map<char, char> m = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'}};

        for (auto ch : s)
        {
            if (m.count(ch))
            {
                myStack.push(ch);
            }
            else
            {
                if (myStack.empty() || m[myStack.top()] != ch)
                {
                    return false;
                }
                myStack.pop();
            }
        }
        return myStack.empty();
    }
};

int main()
{
    Solution s;
    string str = "()[]";
    cout << s.isValid(str) << endl;
    return 0;
}
