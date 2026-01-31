#include <iostream>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/construct-string-from-binary-tree/description/
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"

Explanation: The original format will be "1(2(4)())(3()())".
We need to omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
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
    Time Complexity: O(n)
    Space Complexity: O(h) where h is the height of the tree
    */
    void preorder(TreeNode* root, string& res) {
        if (root == nullptr) return;

        res.append("(");
        res.append(to_string(root->val));
        if (!root->left && root->right) res.append("()");
        preorder(root->left, res);
        preorder(root->right, res);
        res.append(")");
    }
    string tree2str(TreeNode* root) {
        string res;
        preorder(root, res);
        int n = res.size();
        return res.substr(1, n - 2);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    cout << sol.tree2str(root) << endl;
    return 0;
}