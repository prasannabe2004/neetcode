#include <iostream>
#include <vector>
using namespace std;

/*
Given a non-negative integer represented as a linked list of digits, plus one to
the integer.

The digits are stored such that the most significant digit is at the head of the
list.

Example:
Input: head  = [1,2,3]
Output: [1,2,4]

Example:
Input: head = [0]
Ouput: [1]

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
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* notNine = dummy;
        ListNode* curr = dummy;

        while (curr) {
            if (curr->val != 9) {
                notNine = curr;
            }
            curr = curr->next;
        }

        notNine->val = notNine->val + 1;
        for (ListNode* curr = notNine->next; curr != nullptr;
             curr = curr->next) {
            curr->val = 0;
        }
        if (dummy->val == 0) {
            ListNode* newHead = dummy->next;
            delete dummy;
            return newHead;
        }
        return dummy;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(9);
    ListNode* newHead = s.plusOne(head);

    for (ListNode* temp = newHead; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;
    return 0;
}