#include <iostream>
using namespace std;

/*
Given the root of a binary tree, return the preorder traversal of its nodes'
values.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& r) {
        if (root == nullptr) {
            return;
        }
        r.push_back(root->val);
        dfs(root->left, r);
        dfs(root->right, r);
    }
    /*
    DFS preorder using stack
    */
    void dfs2(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            cout << node->val << " ";
            if (node->right != nullptr) {
                s.push(node->right);
            }
            if (node->left != nullptr) {
                s.push(node->left);
            }
        }
    }
};

int main() {
    /*
              1
            2   3
           4 5 6 7
    */
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = s.preorderTraversal(root);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}