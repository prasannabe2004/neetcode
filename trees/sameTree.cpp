#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
Same Tree
https://leetcode.com/problems/same-tree
Given the roots of two binary trees p and q, write a function to check if they
are the same or not. Two binary trees are considered the same if they are
structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
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
     Recursive approach
     Time Complexity: O(N)
     Space Complexity: O(H) where H is the height of the tree
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    /*
     Iterative approach using DFS
     Time Complexity: O(N)
     Space Complexity: O(H) where H is the height of the tree
     */
    bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stackP;
        stack<TreeNode*> stackQ;
        stackP.push(p);
        stackQ.push(q);

        while (!stackP.empty() && !stackQ.empty()) {
            TreeNode* nodeP = stackP.top();
            TreeNode* nodeQ = stackQ.top();
            stackP.pop();
            stackQ.pop();

            if (nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }
            if (nodeP == nullptr || nodeQ == nullptr) {
                return false;
            }
            if (nodeP->val != nodeQ->val) {
                return false;
            }

            stackP.push(nodeP->left);
            stackP.push(nodeP->right);
            stackQ.push(nodeQ->left);
            stackQ.push(nodeQ->right);
        }

        return stackP.empty() && stackQ.empty();
    }
    /*
     Iterative approach using BFS
     Time Complexity: O(N)
     Space Complexity: O(W) where W is the maximum width of the tree
     */
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queueP;
        queue<TreeNode*> queueQ;
        queueP.push(p);
        queueQ.push(q);

        while (!queueP.empty() && !queueQ.empty()) {
            TreeNode* nodeP = queueP.front();
            TreeNode* nodeQ = queueQ.front();
            queueP.pop();
            queueQ.pop();

            if (nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }
            if (nodeP == nullptr || nodeQ == nullptr) {
                return false;
            }
            if (nodeP->val != nodeQ->val) {
                return false;
            }

            queueP.push(nodeP->left);
            queueP.push(nodeP->right);
            queueQ.push(nodeQ->left);
            queueQ.push(nodeQ->right);
        }

        return queueP.empty() && queueQ.empty();
    }
};

int main() {
    Solution sol;

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if (sol.isSameTree(p, q)) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are not the same." << endl;
    }

    if (sol.isSameTreeDFS(p, q)) {
        cout << "The trees are the same (DFS)." << endl;
    } else {
        cout << "The trees are not the same (DFS)." << endl;
    }

    if (sol.isSameTreeBFS(p, q)) {
        cout << "The trees are the same (BFS)." << endl;
    } else {
        cout << "The trees are not the same (BFS)." << endl;
    }

    return 0;
}