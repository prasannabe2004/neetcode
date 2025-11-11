/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * Expectation: Return true if brackets are properly matched and nested.
 *
 * Example:
 * Input: s = "()[]{}"
 * Output: true
 */

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

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
