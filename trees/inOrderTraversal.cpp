#include <iostream>

using namespace std;

/*
Tree traversal is a process of visiting each node in a tree data structure
exactly once via Inorder Traversal Iterative
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
    Time Complexity: O(n)
    Space Complexity: O(h) where h is the height of the tree
    n = number of nodes in a tree
    */
    vector<int> inOrderTraversalIterative(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }

    void dfs(TreeNode* root, vector<int>& r) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, r);
        r.push_back(root->val);
        dfs(root->right, r);
    }
    /*
    Inorder Traversal Recursive
    Time Complexity: O(n)
    Space Complexity: O(h) where h is the height of the tree
    */
    vector<int> inOrderTraversalRecursive(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};

int main() {
    /*
    Inorder =  4 2 5 1 6 3 7
    Tree =
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = root->inOrderTraversalIterative(root);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    result = root->inOrderTraversalRecursive(root);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}