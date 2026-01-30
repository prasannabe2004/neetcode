
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
You are given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

Example 2:
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    int listLength(ListNode* head) {
        ListNode* curr = head;
        int n = 0;
        while (curr) {
            n++;
            curr = curr->next;
        }
        return n;
    }
    /*
    Time Complexity: O(m+n)
    Space Complexity: O(1)
    */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int headA_len = listLength(headA);
        int headB_len = listLength(headB);
        ListNode *c1, *c2;
        if (headA_len > headB_len) {
            c1 = headA;
            c2 = headB;
        } else {
            c1 = headB;
            c2 = headA;
        }
        int diff = abs(headA_len - headB_len);
        while (diff > 0) {
            c1 = c1->next;
            diff--;
        }
        while (c1 && c2) {
            if (c1 == c2) {
                return c1;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        return nullptr;
    }
    /*
    Time Complexity: O(m+n)
    Space Complexity: O(1)
    */
    ListNode* getIntersectionNodeOptimized(ListNode* headA, ListNode* headB) {
        ListNode* c1 = headA;
        ListNode* c2 = headB;
        while (c1 != c2) {
            c1 = c1 ? c1->next : headB;
            c2 = c2 ? c2->next : headA;
        }
        return c1;
    }
    /*
    Brute Force approach
    Time Complexity: O(m*n)
    Space Complexity: O(1)
    */
    ListNode* getIntersectionNodeBruteForce(ListNode* headA, ListNode* headB) {
        std::vector<ListNode*> v;
        ListNode* curr = headA;
        while (curr) {
            v.push_back(curr);
            curr = curr->next;
        }
        curr = headB;
        while (curr) {
            for (ListNode* node : v) {
                if (node == curr) {
                    return node;
                }
            }
            curr = curr->next;
        }
        return nullptr;
    }

};

int main() {
    Solution s;
    /*
       4->1->8->4->5
             ^
             |
    5->0->1->
    */
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    std::cout << s.getIntersectionNode(headA, headB)->val << std::endl;
    return 0;
}