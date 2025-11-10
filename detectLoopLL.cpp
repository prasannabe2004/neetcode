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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Test Case 1: Linked list with cycle
    // Create: 3 -> 2 -> 0 -> -4 -> (back to 2)
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Create cycle: -4 points back to 2

    cout << "Test Case 1: List with cycle [3,2,0,-4], pos=1" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(node1) ? "True" : "False") << endl;
    cout << endl;

    // Test Case 2: Linked list without cycle
    // Create: 1 -> 2 -> 3 -> 4 -> nullptr
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);

    cout << "Test Case 2: List without cycle [1,2,3,4]" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(list2) ? "True" : "False") << endl;
    cout << endl;

    // Test Case 3: Single node with cycle
    ListNode *list3 = new ListNode(1);
    list3->next = list3; // Points to itself

    cout << "Test Case 3: Single node with cycle [1], pos=0" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(list3) ? "True" : "False") << endl;
    cout << endl;

    // Test Case 4: Empty list
    cout << "Test Case 4: Empty list []" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(nullptr) ? "True" : "False") << endl;
    cout << endl;

    // Test Case 5: Two nodes with cycle
    ListNode *list5a = new ListNode(1);
    ListNode *list5b = new ListNode(2);
    list5a->next = list5b;
    list5b->next = list5a; // Create cycle

    cout << "Test Case 5: Two nodes with cycle [1,2], pos=0" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(list5a) ? "True" : "False") << endl;
    cout << endl;

    // Clean up memory for non-cyclic lists
    // Note: Cannot safely delete nodes in cyclic lists without breaking the cycle first
    delete list2->next->next->next;
    delete list2->next->next;
    delete list2->next;
    delete list2;

    cout << "All test cases completed!" << endl;

    return 0;
}
