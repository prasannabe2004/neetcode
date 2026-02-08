#include <iostream>
using namespace std;

/*
Add Two Numbers 2
https://leetcode.com/problems/add-two-numbers-ii/description/

You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    void printList(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbersUtil(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* curr = head;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr = new ListNode(sum % 10);
            curr->next = head;
            head = curr;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return head;
    }
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        printList(l1);
        printList(l2);
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        printList(l1);
        printList(l2);
        return addTwoNumbersUtil(l1, l2);
    }
};

int main() {
    Solution solution;
    /*
    Given l1 = 2 4 3
    Given l2 = 5 6 4
    lets revers it
    3 4 2
    4 6 5
    8 0 7

    807
    */
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
