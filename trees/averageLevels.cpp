#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
Given the root of a binary tree, return the average value of the nodes on each
level in the form of an array. Answers within 10-5 of the actual answer will be
accepted.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and
on level 2 is 11. Hence return [3, 14.5, 11].

Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: This example is the same as example 1.

Example 3:
Input: root = [1]
Output: [1.00000]
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
    Average Level Order Traversal using Queue
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<double> averageLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if (root == nullptr) {
            return {};
        }

        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            double avg = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                avg += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            avg /= size;
            res.push_back(avg);
        }
        return res;
    }
};

int main() {
    /*
                          1
                   2             3
               4      5      6      7
              8 9   10 11  12 13  14  15
    */
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    cout << "Average of each level in the tree is: " << endl;
    vector<double> res = root->averageLevels(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}