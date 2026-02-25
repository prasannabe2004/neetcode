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
Remove all elements from a linked list of integers that have value val.
Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []
Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
Constraints:
The number of nodes in the list is in the range [0, 10^4].
1 <= Node.val <= 50
0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            if (curr->val == val) {
                prev->next = nxt;
                delete curr;
            } else {
                prev = curr;
            }
            curr = nxt;
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;
    // Create linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    // head=[1,1,1,1,1,1,1,1,1,1,2,3,1,2,3,4,1,2]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next->next->next =
        new ListNode(1);
    head->next->next->next->next->next->next->next->next->next->next =
        new ListNode(2);

    int val = 1;
    ListNode* modifiedHead = sol.removeElements(head, val);

    // Print modified linked list
    ListNode* current = modifiedHead;
    cout << "Modified Linked List after removing " << val << ": ";
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