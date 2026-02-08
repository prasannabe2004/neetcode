#include <iostream>
#include <vector>

using namespace std;

/*
 * Given k sorted linked lists, merge them into one sorted linked list.
 *
 * Expectation: Return the head of the merged sorted linked list.
 *
 * Example:
 * Input: l1 = [1,4,7], l2 = [2,5,8], l2 = [3,6,9]
 * Output: [1,2,3,4,5,6,7,8,9]
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 != NULL) curr->next = l1;
        if (l2 != NULL) curr->next = l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i - 1]);
        }
        return lists.back();
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(8);

    ListNode* l3 = new ListNode(3);
    l3->next = new ListNode(6);
    l3->next->next = new ListNode(9);

    Solution s;

    vector<ListNode*> l;
    l.push_back(l1);
    l.push_back(l2);
    l.push_back(l3);
    ListNode* head = s.mergeKLists(l);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}