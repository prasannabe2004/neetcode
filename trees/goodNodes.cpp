#include <iostream>
using namespace std;

/*
Count the number of good nodes in the binary tree. A node X in the binary tree
is named good if in the path from root to X there are no nodes with a value
greater than X.

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good. Node 3 is always a good node, Node 4 ->
(3,4) is the maximum value in the path starting from the root, Node 5 -> (3,4,5)
is the maximum value in the path, Node 3 -> (3,1,3) is the maximum value in the
path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 3 at the root is a good node, Node 3 -> (3,3) is the maximum
value in the path starting from the root, Node 4 -> (3,3,4) is the maximum value
in the path. Node 2 -> (3,3,2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
*/

// Node Structure
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
    int countGoodNodes(TreeNode* root, int maxSoFar) {
        if (root == nullptr) return 0;
        int count = 0;
        if (root->val >= maxSoFar) {
            count += 1;
            maxSoFar = root->val;
        }

        count += countGoodNodes(root->left, maxSoFar);
        count += countGoodNodes(root->right, maxSoFar);
        return count;
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return countGoodNodes(root, INT_MIN);
    }
};

int main() {
    Solution sol;
    /*
                    3
                   / \
                  1   4
                /    / \
               3    1   5
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << sol.goodNodes(root) << endl;  // Output: 4

    return 0;
}