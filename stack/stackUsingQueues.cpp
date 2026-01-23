#include <iostream>
#include <queue>

using namespace std;

/*

*/

class MyStack {
   public:
    queue<int> q;

    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        int n = q.size() - 1;
        while (n >= 1) {
            int v = q.front();
            q.push(v);
            q.pop();
            n--;
        }
        int v = q.front();
        q.pop();
        return v;
    }

    int top() { return q.back(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    return 0;
}