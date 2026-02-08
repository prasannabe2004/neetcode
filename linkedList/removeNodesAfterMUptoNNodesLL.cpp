#include <iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
using namespace std;
/*
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* removeElements(ListNode* head, int m, int n) {
        ListNode* curr = head;
        ListNode* last = head;

        while (curr) {
            int newM = m;
            int newN = n;
            while (curr && newM > 0) {
                last = curr;
                curr = curr->next;
                newM--;
            }
            while (curr && newN > 0) {
                curr = curr->next;
                newN--;
            }
            last->next = curr;
        }
        return head;
    }
};

int main() {
    Solution sol;
    // 1,2,3,4,5,6,7,8,9,10,11,12,13

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next =
        new ListNode(10);
    head->next->next->next->next->next->next->next->next->next->next =
        new ListNode(11);
    head->next->next->next->next->next->next->next->next->next->next->next =
        new ListNode(12);
    head->next->next->next->next->next->next->next->next->next->next->next
        ->next = new ListNode(13);

    int m = 2, n = 3;
    ListNode* modifiedHead = sol.removeElements(head, m, n);

    // Print modified linked list
    ListNode* current = modifiedHead;
    cout << "Modified Linked List after removing " << ": ";
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Free remaining nodes
    current = modifiedHead;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}