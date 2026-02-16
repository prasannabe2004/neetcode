#include <iostream>
#include <vector>
using namespace std;
/*
Remove Nth Node From End of Linked List
https://leetcode.com/problems/remove-nth-node-from-end-of-list
Given the head of a linked list, remove the nth node from the end of the list
and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:
Input: head = [1], n = 1
Output: []
Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    /*
    Two Pointer approach
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        cout << "First pointer after moving " << n << " steps: " << first->val
             << endl;

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        cout << "Second pointer after moving " << n << " steps: " << second->val
             << endl;
        ListNode* tmp = second->next;
        second->next = second->next->next;
        delete tmp;
        return dummy->next;
    }
    /*
    using length of the list
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        int k = 0;
        ListNode* curr = head;
        while (curr) {
            k++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 1; i < k - n; i++) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);

    cout << "Original List: ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    int n = 2;
    ListNode* modifiedHead = s.removeNthFromEnd(head, n);
    cout << "Modified List after removing " << n << "th node from end: ";
    current = modifiedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    modifiedHead = s.removeNthFromEnd2(head, n);
    cout << "Modified List after removing " << n << "th node from end: ";
    current = modifiedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}