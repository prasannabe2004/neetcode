#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

class MinStack {
   private:
    stack<int> mainStack;
    stack<int> minStack;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        int v = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(v);
    }
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    int top() { return mainStack.top(); }
    int getMin() { return minStack.top(); }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;  // return -3
    minStack.pop();
    cout << minStack.top() << endl;     // return 0
    cout << minStack.getMin() << endl;  // return -2
    return 0;
}