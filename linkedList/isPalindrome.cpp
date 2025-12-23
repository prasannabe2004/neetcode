#include <iostream>

using namespace std;

/*
Check given single linked list is a palindrome or not
*/

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   public:
    /*
    Time: O(n)
    Space: O(n)
    */
    bool isPalindrome1(Node* root) {
        vector<int> arr;
        while (root != NULL) {
            arr.push_back(root->data);
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

    Node* reverse(Node* root) {
        Node* prev = NULL;
        Node* curr = root;
        Node* next = NULL;
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
    bool isPalindrome(Node* root) {
        Node* slow = root;
        Node* fast = root;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* rev = reverse(slow);
        Node* curr = root;
        while (rev != NULL) {
            if (rev->data != curr->data) return false;
            rev = rev->next;
            curr = curr->next;
        }
        return true;
    }
};

int main() {
    Solution s;
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(2);
    root->next->next->next->next = new Node(1);
    cout << s.isPalindrome(root) << endl;
    return 0;
}