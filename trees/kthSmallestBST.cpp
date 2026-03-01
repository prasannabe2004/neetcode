#include <iostream>
#include <stack>
using namespace std;

/*
Given the root of a binary search tree, and an integer k, return the kth
smallest value (1-indexed) of all the values of the nodes in the tree. Example
1: Input: root = [3,1,4,null,2], k = 1 Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    /*
     Inorder Traversal using Recursion
     Time Complexity: O(n) where n is the number of nodes in the tree. This is
     because we visit each node once to perform the inorder traversal.
     Space Complexity: O(n) in the worst case when the tree is skewed, due to
     the recursive call stack. In the best case of a balanced tree, the space
     complexity would be O(log n).
    */
    void dfs(TreeNode* root, int k, vector<int>& r) {
        if (root == nullptr) return;
        dfs(root->left, k, r);
        r.push_back(root->val);
        dfs(root->right, k, r);
    }
    int kthSmallest2(TreeNode* root, int k) {
        vector<int> res;
        dfs(root, k, res);
        return res[k - 1];
    }
    /*
    Inorder Traversal using Stack
    Time Complexity: O(n) in the worst case when the tree is skewed. In the best
    case of a balanced tree, the time complexity would be O(k) since we only
    need to traverse k nodes to find the kth smallest element.

    Space Complexity: O(n) in the worst case when the tree is skewed, due to the
    stack storing all nodes. In the best case of a balanced tree, the space
    complexity would be O(log n) since the stack would store at most log n nodes
    at any time.
    */
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            k--;
            if (k == 0) return current->val;
            current = current->right;
        }
        return -1;  // This line should never be reached if k is valid
    }
};

int main() {
    Solution s;
    /*
                  5
                /   \
              3      6
             / \
            2   4
           /
          1
    */
    TreeNode* t = new TreeNode(5);
    t->left = new TreeNode(3);
    t->right = new TreeNode(6);
    t->left->left = new TreeNode(2);
    t->left->right = new TreeNode(4);
    t->left->left->left = new TreeNode(1);

    cout << s.kthSmallest(t, 3) << endl;   // Output: 3
    cout << s.kthSmallest2(t, 3) << endl;  // Output: 3
}