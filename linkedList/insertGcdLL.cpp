#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int v) {
        val = v;
        next = nullptr;
    }
};

class Solution {
   public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    ListNode* insertGcdLL(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (prev && curr) {
            cout << "Calculating gcd of " << prev->val << " and " << curr->val
                 << endl;
            int g = gcd(prev->val, curr->val);
            ListNode* newNode = new ListNode(g);
            ListNode* tmp = curr;
            prev->next = newNode;
            newNode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(12);
    head->next = new ListNode(15);
    head->next->next = new ListNode(18);
    head->next->next->next = new ListNode(21);
    sol.printList(head);
    sol.insertGcdLL(head);
    sol.printList(head);
    return 0;
}