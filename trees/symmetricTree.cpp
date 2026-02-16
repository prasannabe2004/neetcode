#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
Symmetric Tree
https://leetcode.com/problems/symmetric-tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center). Example 1: Input: root = [1,2,2,3,4,4,3] Output:
true Example 2: Input: root = [1,2,2,null,3,null,3] Output: false
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
     Recursive approach
     Time Complexity: O(N)
     Space Complexity: O(H) where H is the height of the tree
     */
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};

int main() {
    Solution sol;
    // Creating a sample symmetric binary tree
    //       10
    //       / \
    //      5   5
    //     /     \
    //    2       2

    TreeNode* p = new TreeNode(10);
    p->left = new TreeNode(5);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(2);
    p->right->right = new TreeNode(2);

    if (sol.isSymmetric(p)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }
    return 0;
}