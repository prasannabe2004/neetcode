#include <limits.h>

#include <iostream>
using namespace std;

/*
Given the root of a binary tree, determine if it is a valid binary search tree
(BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's
key. The right subtree of a node contains only nodes with keys greater than the
node's key. Both the left and right subtrees must also be binary search trees.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    bool isValidBSTUtil(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return isValidBSTUtil(root->left, min, root->val) &&
               isValidBSTUtil(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    Solution s;
    /*
        2
      1   3
    */
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << s.isValidBST(root) << endl;

    /*
            5
        1       4
             3     6
    */
    root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    cout << s.isValidBST(root) << endl;

    return 0;
}