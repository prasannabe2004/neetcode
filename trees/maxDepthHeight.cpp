#include <iostream>

using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    void printLevel(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (level == 1) {
            cout << root->val << " ";
        }
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
    /*
    Height of a tree
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        return max(lheight, rheight) + 1;
    }
};

int main() {
    /*
              1
            2   3
           4 5 6 7
          8
           9
    */
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->left->right = new TreeNode(9);

    cout << "Height/Max Depth of the tree is: " << endl;
    cout << root->height(root);
    cout << endl;

    return 0;
}