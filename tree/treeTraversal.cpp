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
    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
    void preOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void postOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->val << " ";
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->inOrderTraversal(root);
    cout << endl;
    root->preOrderTraversal(root);
    cout << endl;
    root->postOrderTraversal(root);
    cout << endl;
}