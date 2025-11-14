#include <iostream>

using namespace std;

/*

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
    /*
    Level Order Traversal
    Time Complexity: O(n^2) in worst case.
    Space Complexity: O(n) in worst case. uses O(n) space for call stack.
    */
    void levelOrderTraversal(TreeNode* root) {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printLevel(root, i);
            cout << endl;
        }
    }
    /*
    Level Order Traversal
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    void levelOrderTraversal2(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            cout << node->val << " ";
            q.pop();
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->inOrderTraversal(root);
    cout << endl;
    root->preOrderTraversal(root);
    cout << endl;
    root->postOrderTraversal(root);
    cout << endl;

    root->levelOrderTraversal2(root);
    cout << endl;
}