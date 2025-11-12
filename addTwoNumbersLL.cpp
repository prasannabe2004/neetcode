#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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

class Solution
{
public:
    /*
    Iterative way
    Time Complexity: O(max(n, m)) where n and m are the lengths of the two linked lists.
    Space Complexity: O(max(n, m)) due to the new linked list created to store the result.
    */
    ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry > 0)
        {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
    ListNode *add(ListNode *l1, ListNode *l2, int carry)
    {
        if (!l1 && !l2 && carry == 0)
        {
            return nullptr;
        }

        int v1 = 0;
        int v2 = 0;
        if (l1)
        {
            v1 = l1->val;
        }
        if (l2)
        {
            v2 = l2->val;
        }

        int sum = v1 + v2 + carry;
        int newCarry = sum / 10;
        int nodeValue = sum % 10;

        ListNode *nextNode = add(
            (l1 ? l1->next : nullptr),
            (l2 ? l2->next : nullptr),
            newCarry);

        return new ListNode(nodeValue, nextNode);
    }
    /*
    Recursive way
    Time Complexity: O(max(n, m)) where n and m are the lengths of the two linked lists.
    Space Complexity: O(max(n, m)) due to the recursive call stack.
    */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return add(l1, l2, 0);
    }
};

int main()
{
    Solution solution;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
