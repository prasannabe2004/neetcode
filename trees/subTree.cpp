#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
Subtree of Another Tree
https://leetcode.com/problems/subtree-of-another-tree
Given the roots of two binary trees root and subRoot, return true if there is a
subtree of root with the same structure and node values as subRoot and false
otherwise. A subtree of a binary tree tree is a tree that consists of a node in
tree and all of this node's descendants. The tree tree could also be considered
as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    /*
    Check if subRoot is a subtree of root
    Time Complexity: O(N*M) in worst case where N is number of nodes in root
    and M is number of nodes in subRoot
    Space Complexity: O(H) where H is the height of the tree
    */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {
    Solution sol;

    /*
                  3
                 / \
                4   5
               / \   \
              1   2
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    /*
          4
         / \
        1   2
    */
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (sol.isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root." << endl;
    } else {
        cout << "subRoot is not a subtree of root." << endl;
    }

    return 0;
}
