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

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        ListNode* tmp = second->next;
        second->next = second->next->next;
        delete tmp;
        return dummy->next;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* modifiedHead = s.removeNthFromEnd(head, n);
    cout << "Modified List after removing " << n << "th node from end: ";
    ListNode* current = modifiedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}