#include <iostream>
using namespace std;

/*
Add Two Numbers
https://leetcode.com/problems/add-two-numbers

You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order, and each of their
nodes contains a single digit. Add the two numbers and return the sum
as a linked list.
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
    /*
    Iterative way
    Time Complexity: O(max(n, m)) where n and m are the lengths of the
    two linked lists. Space Complexity: O(max(n, m)) due to the new
    linked list created to store the result.
    Space Complexity: O(1)
    */
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
    /*
    Recursive way
    Time Complexity: O(max(n, m)) where n and m are the lengths of the two
    linked lists. Space Complexity: O(max(n, m)) due to the recursive call
    stack.
    */
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int v1 = 0;
        int v2 = 0;
        if (l1) {
            v1 = l1->val;
        }
        if (l2) {
            v2 = l2->val;
        }

        int sum = v1 + v2 + carry;
        int newCarry = sum / 10;
        int nodeValue = sum % 10;

        ListNode* nextNode =
            add((l1 ? l1->next : nullptr), (l2 ? l2->next : nullptr), newCarry);

        return new ListNode(nodeValue, nextNode);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};

int main() {
    Solution solution;
    /*
    Given l1 in revered order = 2 4 3
    Given l2 in reverse order = 5 6 4

    they are already in reverse order
    so if we calculate as such we result in reverse order

    calculated list = 7 0 8

    actual 342
    actual 465
    result 807

    8 0 7
    */
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers1(l1, l2);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
