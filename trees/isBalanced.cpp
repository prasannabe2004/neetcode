#include <iostream>
using namespace std;

// Node Structure
class Node {
   public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        int data = d;
        left = right = NULL;
    }
};

class Solution {
   public:
    // Function to calculate the height of a tree
    int height(Node* node) {
        if (node == NULL) return 0;

        // Height = 1 + max of left height and right heights
        return 1 + max(height(node->left), height(node->right));
    }

    // Function to check if the binary tree with given root, is height-balanced
    /*
    Time Complexity: O(n^2) in the worst case when the tree is skewed. This is
    because for each node, we are calculating the height of its left and right
    subtrees, which takes O(n) time in the worst case. Space Complexity: O(n) in
    the worst case when the tree is skewed, due to the recursive call stack. In
    the best case of a balanced tree, the space complexity would be O(log n).
    */
    bool isBalanced2(Node* root) {
        if (root == NULL) return true;

        // Get the height of left and right sub trees
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if (abs(lHeight - rHeight) > 1) return false;

        // Recursively check the left and right subtrees
        return isBalanced2(root->left) && isBalanced2(root->right);
    }

    // Function that returns the height of the tree if the tree is balanced
    // Otherwise it returns -1.
    /*
    Time Complexity: O(n) where n is the number of nodes in the tree. This is
    because we visit each node once to check if the tree is balanced and to
    calculate the height. Space Complexity: O(n) in the worst case when the tree
    is skewed, due to the recursive call stack. In the best case of a balanced
    tree, the space complexity would be O(log n). Space Complexity: O(n) in the
    worst case when the tree is skewed, due to the recursive call stack. In the
    best case of a balanced tree, the space complexity would be O(log n).
    */
    int isBalancedRec(Node* root) {
        if (root == NULL) return 0;

        // Find Heights of left and right sub trees
        int lHeight = isBalancedRec(root->left);
        int rHeight = isBalancedRec(root->right);

        // If either the subtrees are unbalanced or the absolute difference
        // of their heights is greater than 1, return -1
        if (lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
            return -1;

        return max(lHeight, rHeight) + 1;
    }

    // Function to check if tree is height balanced
    bool isBalanced(Node* root) { return (isBalancedRec(root) > 0); }
};

int main() {
    // Representation of input BST:
    //            10
    //           / \
    //          20   30
    //         /  \
    //        40   60
    Solution s;
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout << (s.isBalanced(root) ? "true" : "false") << endl;
    return 0;
}