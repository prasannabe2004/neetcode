#include <iostream>
#include <vector>

using namespace std;

/*
Given a singly linked list of size N of integers. The task is to check if the
given linked list is palindrome or not.
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
    Time: O(n)
    Space: O(n)
    */
    bool isPalindrome1(ListNode* head) {
        vector<int> arr;
        ListNode* root = head;
        while (root != NULL) {
            arr.push_back(root->val);
            root = root->next;
        }
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (arr[left] != arr[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    ListNode* reverse(ListNode* root) {
        ListNode* prev = NULL;
        ListNode* curr = root;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        root = prev;
        return root;
    }
    /*
    1. Find the middle of the linked list
    2. Reverse the second half of the linked list
    3. Compare the first half and second half
    4. Reverse the second half again
    5. Return the result
    6. Time complexity: O(n)
    7. Space complexity: O(1)
    */
    bool isPalindrome(ListNode* root) {
        ListNode* slow = root;
        ListNode* fast = root;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow);
        ListNode* curr = root;
        while (rev != NULL) {
            if (rev->val != curr->val) return false;
            rev = rev->next;
            curr = curr->next;
        }
        return true;
    }
};

int main() {
    Solution s;
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(2);
    root->next->next->next->next = new ListNode(1);
    cout << s.isPalindrome(root) << endl;
    return 0;
}