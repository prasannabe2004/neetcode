#include <iostream>
#include <vector>

using namespace std;

/*
Reorder List
Given the head of a singly linked list, reorder the list to be in the following
form: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ... The reordering should be done
in-place without altering the nodes' values.

Example 1: Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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
    void reorderList(ListNode* head) {
        // Find middle of the node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Merge both the lists
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            next = first->next;
            first->next = second;
            first = next;

            next = second->next;
            second->next = first;
            second = next;
        }
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

    s.reorderList(head);
    for (ListNode* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;
    return 0;
}