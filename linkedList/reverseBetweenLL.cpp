#include <iostream>
#include <vector>
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
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example 1:
Input: 1->2->3->4->5, m = 2, n = 4
Output: 1->4->3->2->5

Example 2:
Input: 1->2->3, m = 1, n = 2
Output: 2->1->3

Constraints:
The number of nodes in the list is between 1 and 500.
-500 <= Node.val <= 500
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* Lprev = dummy;
        ListNode* curr = head;

        // Move curr to the left position
        for (int i = 0; i < left; i++) {
            Lprev = curr;
            curr = curr->next;
        }

        // Reverse from left to right
        ListNode* prev = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        Lprev->next->next = curr;
        Lprev->next = prev;
        return dummy->next;
    }
};

int main() {
    Solution sol;

    // Create linked list 1->2->3->4->5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    int m1 = 2, n1 = 4;
    ListNode* result1 = sol.reverseBetween(head1, m1, n1);
    cout << "Reversed Linked List 1: ";
    while (result1) {
        cout << result1->val << " ";
        result1 = result1->next;
    }
    cout << endl;

    // Create linked list 1->2->3
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);

    int m2 = 1, n2 = 2;
    ListNode* result2 = sol.reverseBetween(head2, m2, n2);
    cout << "Reversed Linked List 2: ";
    while (result2) {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    cout << endl;

    return 0;
}