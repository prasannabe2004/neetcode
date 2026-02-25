#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedList {
   public:
    ListNode* head;
    LinkedList() : head(nullptr) {}
    ListNode* addNodeFront(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
    ListNode* addNodeTail(int val) {
        if (head == nullptr) return addNodeFront(val);
        ListNode* newNode = new ListNode(val);
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
        return head;
    }
    ListNode* deletedNode(int val) {
        if (head == nullptr) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            if (curr->val == val) {
                prev->next = next;
                delete curr;
            } else {
                prev = curr;
            }
            curr = next;
        }
        head = dummy->next;
        return head;
    }
    void printList() {
        ListNode* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.addNodeFront(1);
    ll.addNodeFront(2);
    ll.addNodeFront(3);
    ll.addNodeFront(4);
    ll.addNodeFront(5);
    ll.addNodeTail(6);
    ll.addNodeTail(7);
    ll.addNodeTail(8);
    ll.addNodeTail(9);
    ll.addNodeTail(10);
    ll.printList();

    ll.deletedNode(6);
    ll.printList();

    ll.deletedNode(5);
    ll.printList();

    ll.deletedNode(10);
    ll.printList();
    return 0;
};