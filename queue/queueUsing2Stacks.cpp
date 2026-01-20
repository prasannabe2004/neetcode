#include <iostream>
#include <stack>

using namespace std;

/*
Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks
Implement a first in first out (FIFO) queue using only two stacks. The
implemented queue should support all the functions of a normal queue (push,
pop, peek, and empty).

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]
Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost element is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

class MyQueue {
   private:
    stack<int> stack1;
    stack<int> stack2;

   public:
    MyQueue() {}

    /*
    Push element x to the back of queue.
    Time Complexity: O(1)
    Space Complexity: O(1)
    */
    void push(int x) { stack1.push(x); }
    /*
        Removes the element from in front of queue and returns that element.
        Time Complexity: Amortized O(1)
        Space Complexity: O(1)
    */
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int topElement = stack2.top();
        stack2.pop();
        return topElement;
    }
    /*
        Returns the element at the front of the queue.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() { return stack1.empty() && stack2.empty(); }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);

    obj->push(4);
    obj->push(5);
    obj->push(6);
    cout << obj->pop() << endl;  // returns 1
    cout << obj->pop() << endl;  // returns 2
    cout << obj->pop() << endl;  // returns 3
    cout << obj->pop() << endl;  // returns 4
    cout << obj->pop() << endl;  // returns 5
    cout << obj->pop() << endl;  // returns 6
    return 0;
}