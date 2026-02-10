#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/*
Merge Two Binary Trees by adding overlapping nodes
https://leetcode.com/problems/merge-two-binary-trees
You are given two binary trees root1 and root2. Imagine that when you put one of
the trees to cover the other, some nodes of the two trees are overlapped while
the others are not. You need to merge the two trees into a new binary tree. The
merging rule is that if two nodes overlap, then sum node values up as the new
value of the merged node. Otherwise, the NOT null node will be used as the node
of the new tree.

Example 1:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
Example 2:
Input: root1 = [1], root2 = [1,2]
Output: [2,2]
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }

        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

int main() {
    Solution s;
    /*
             1
            3 2
           5
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    /*
            2
           1  3
          4
    */
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode* mergedRoot = s.mergeTrees(root1, root2);
    cout << "Merged Root Value: " << mergedRoot->val << endl;  // Should print 3
    cout << "Left Child Value: " << mergedRoot->left->val
         << endl;  // Should print 4
    cout << "Right Child Value: " << mergedRoot->right->val
         << endl;  // Should print 5

    return 0;
}