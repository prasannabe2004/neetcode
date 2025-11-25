#include <iostream>
#include <stack>

using namespace std;

class queue {
   public:
    stack<int> s1;
    stack<int> s2;
    void enqueue(int data) {
        while (s1.empty() != true) {
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        s1.push(data);
        while (s2.empty() != true) {
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }
    }
    int dequeue() {
        int top = -1;
        if (s1.empty() != true) {
            top = s1.top();
            s1.pop();
        }
        return top;
    }
};

int main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;  // Output: 1
    cout << q.dequeue() << endl;  // Output: 2
    q.enqueue(4);
    cout << q.dequeue() << endl;  // Output: 3
    cout << q.dequeue() << endl;  // Output: 4
    return 0;
}