#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
Find the diameter of a binary tree. The diameter of a binary tree is the length
of the longest path between any two nodes in a tree. This path may or may not
pass through the root.
Note: You can assume that there are at least two nodes in the tree.

Input: root = [1,2,3,4,5]
Output: 3
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
    int res;

    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        int res = left + right;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        res = max(res, max(leftDiameter, rightDiameter));
        return res;
    }

    int diameterRecur(TreeNode* root, int &maxDiameter) {
    if (!root)
        return 0;

    // Find the height of left and right subtree
    int lHeight = diameterRecur(root->left, maxDiameter);
    int rHeight = diameterRecur(root->right, maxDiameter);

    // Update the global max diameter if this node gives a longer path
    maxDiameter = max(maxDiameter, lHeight + rHeight);

    // Return height of current subtree
    return 1 + max(lHeight, rHeight);
}

// Function to get diameter of a binary tree
int diameter(TreeNode* root) {
    int maxDiameter = 0; 
    diameterRecur(root, maxDiameter);
    return maxDiameter;
}
};

int main() {
    TreeNode* root = new TreeNode(1);
    /*
                   1
               /      \
             2.         3
           /    \     /    \
          4      5   6      7
        /   \   /  \      /
       8     9 10   11  13
                   /   /
                 12   14
    */
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->left->right->right->left = new TreeNode(12);
    root->right->right->left = new TreeNode(13);
    root->right->right->left->left = new TreeNode(14);

    cout << "Diameter of the tree is " << root->diameterOfBinaryTree(root)
         << endl;
    cout << "Diameter2 " << root->diameter(root) << endl;
    return 0;
}