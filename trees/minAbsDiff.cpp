#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
Given the root of a Binary Search Tree (BST), return the minimum absolute
difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1
Explanation: The minimum absolute difference is 1, which can be achieved by the
nodes with values 2 and 3, or by the nodes with values 3 and 4

Example 2: Input:
root = [1,0,48,null,null,12,49] Output: 1 Explanation: The minimum absolute
difference is 1, which can be achieved by the nodes with values 48 and 49

Example 3:
Input: root = [236,104,701,null,227,null,911]
Output: 9
Explanation: The minimum absolute difference is 9, which can be achieved by the
nodes with values
*/

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    /*
    Minimum Absolute Difference in BST
    Time Complexity: O(n)
    Space Complexity: O(h) where h is the height of the tree
    */
    int minAbsDiff(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }

   private:
    void inorder(TreeNode* root, TreeNode*& prev, int& minDiff) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, prev, minDiff);
        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;
        inorder(root->right, prev, minDiff);
    }
};

int main() {
    /*
            20
        15      25
    10     18 22   30
    */
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(15);
    root->right = new TreeNode(25);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(18);
    root->right->left = new TreeNode(22);
    root->right->right = new TreeNode(30);

    cout << "Minimum absolute difference in the BST is: "
         << root->minAbsDiff(root) << endl;
    return 0;
}