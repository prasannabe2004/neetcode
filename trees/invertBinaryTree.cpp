#include <iostream>
#include <vector>

using namespace std;

/*
Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree
Given the root of a binary tree, invert the tree, and return its root.

Example:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
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
     Breadth-First Search (BFS) approach
      Time Complexity: O(N)
      Space Complexity: O(W) where W is the maximum width of the tree
    */
    TreeNode* inverTressBFS(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        vector<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.erase(queue.begin());

            TreeNode* tmp = current->left;
            current->left = current->right;
            current->right = tmp;

            if (current->left != nullptr) {
                queue.push_back(current->left);
            }
            if (current->right != nullptr) {
                queue.push_back(current->right);
            }
        }

        return root;
    }
    /*
    Depth-First Search (DFS) approach
     Time Complexity: O(N)
     Space Complexity: O(H) where H is the height of the tree
    */
    TreeNode* invertTreeDFS(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTreeDFS(root->left);
        invertTreeDFS(root->right);

        return root;
    }
    /*
    Depth-First Search (DFS) Iterative approach
     Time Complexity: O(N)
     Space Complexity: O(H) where H is the height of the tree
    */
    TreeNode* invertTreeDFSIterative(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        vector<TreeNode*> stack;
        stack.push_back(root);

        while (!stack.empty()) {
            TreeNode* current = stack.back();
            stack.pop_back();

            TreeNode* tmp = current->left;
            current->left = current->right;
            current->right = tmp;

            if (current->left != nullptr) {
                stack.push_back(current->left);
            }
            if (current->right != nullptr) {
                stack.push_back(current->right);
            }
        }

        return root;
    };

    int main() {
        Solution sol;
        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(7);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(9);

        cout << "Original Root Value: " << root->val << endl;
        cout << "Left Child of Original Root: " << root->left->val << endl;
        cout << "Right Child of Original Root: " << root->right->val << endl;

        TreeNode* invertedRoot = sol.invertTreeDFS(root);
        cout << "Inverted Root Value: " << invertedRoot->val << endl;
        cout << "Left Child of Inverted Root: " << invertedRoot->left->val
             << endl;
        cout << "Right Child of Inverted Root: " << invertedRoot->right->val
             << endl;

        return 0;
    }