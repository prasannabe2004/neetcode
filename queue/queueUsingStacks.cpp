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
    void enqueue(int x) { stack1.push(x); }
    /*
        Removes the element from in front of queue and returns that element.
        Time Complexity: Amortized O(1)
        Space Complexity: O(1)
    */
    int dequeue() {
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

    bool empty() { return stack1.empty() && stack2.empty(); }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->enqueue(1);
    obj->enqueue(2);
    obj->enqueue(3);

    obj->enqueue(4);
    obj->enqueue(5);
    obj->enqueue(6);
    cout << obj->dequeue() << endl;  // returns 1
    cout << obj->dequeue() << endl;  // returns 2
    cout << obj->dequeue() << endl;  // returns 3
    cout << obj->dequeue() << endl;  // returns 4
    cout << obj->dequeue() << endl;  // returns 5
    cout << obj->dequeue() << endl;  // returns 6
    return 0;
}