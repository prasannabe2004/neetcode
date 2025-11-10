#include <iostream>
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