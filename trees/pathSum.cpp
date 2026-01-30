#include <iostream>
using namespace std;

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.   
A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Example 3:
Input: root = [], targetSum = 0
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
   Time Complexity: O(N)
   Space Complexity: O(H) where H is the height of the tree
   if we don't consider recursive stack space then SC: O(1)
   */
    bool dfs(TreeNode* root, int sum, int currentSum) {
        if (root == nullptr) return false;
        currentSum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return currentSum == sum;
        }
        return dfs(root->left, sum, currentSum) ||
               dfs(root->right, sum, currentSum);
    }
    int hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};

int main() {
    Solution s;
    /*
                  1
                /
              5   -3
             / \    \
            3   2   11
           / \   \
          3  -2  1
    */
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(5);
    t->right = new TreeNode(-3);
    t->left->left = new TreeNode(3);
    t->left->right = new TreeNode(2);
    t->right->right = new TreeNode(11);
    t->left->left->left = new TreeNode(3);
    t->left->left->right = new TreeNode(-2);
    t->left->right->right = new TreeNode(1);

    cout << s.hasPathSum(t, 9) << endl;
    return 0;
}