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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *newHead = head;
        if (head->next)
        {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return newHead;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *h = head;
    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
    Solution s;
    ListNode *newHead = s.reverseList(head);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}