#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
Find the maximum depth of a binary tree
Example:
Input: root = [1,2,3,4,5,6,7,8,9,10,11,12,13,14]
Output: 4
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
    /*
    Using Depth First search
    */
    int maxDepthDFS(TreeNode* root) {
        if (root == NULL) return 0;
        int left = maxDepthDFS(root->left);
        int right = maxDepthDFS(root->right);
        return max(left, right) + 1;
    }
    /*
    Using Breadth First search
    */
    int maxDepthBFS(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
    /*
    Using stack Interative
    */
    int maxDepthIterative(TreeNode* root) {
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int res = 0;

        while (!stack.empty()) {
            pair<TreeNode*, int> current = stack.top();
            stack.pop();
            TreeNode* node = current.first;
            int depth = current.second;

            if (node != nullptr) {
                res = max(res, depth);
                stack.push({node->left, depth + 1});
                stack.push({node->right, depth + 1});
            }
        }
        return res;
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

    cout << "Depth of tree using DFS " << root->maxDepthDFS(root) << endl;
    cout << "Depth of tree using BFS " << root->maxDepthBFS(root) << endl;
    cout << "Depth of tree using iterative " << root->maxDepthIterative(root)
         << endl;
    cout << endl;
    return 0;
}