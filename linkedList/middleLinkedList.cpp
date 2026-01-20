#include <iostream>
#include <vector>
using namespace std;

/*
Find the Middle of a Linked List
https://leetcode.com/problems/middle-of-the-linked-list
Given the head of a singly linked list, return the middle node of the linked
list. If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middle = s.middleNode(head);
    cout << "Middle Node Value: " << middle->val << endl;

    head->next->next->next->next->next = new ListNode(6);
    middle = s.middleNode(head);
    cout << "Middle Node Value: " << middle->val << endl;

    return 0;
}