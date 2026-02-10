#include <iostream>
#include <vector>

using namespace std;

/*
Given a linked list, delete all duplicates such that each element appear only
once. Example 1: Input: 1->1->2 Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    ListNode* removeDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current) {
            while (current->next && current->val == current->next->val) {
                current->next = current->next->next;
            }
            current = current->next;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(5);
    cout << "Before removing duplicates: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    Solution s;
    ListNode* newHead = s.removeDuplicates(head);
    cout << "After removing duplicates: ";
    for (ListNode* temp = newHead; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;
    return 0;
}