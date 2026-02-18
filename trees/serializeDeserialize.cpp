#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
Serialization is the process of converting a data structure or object into a
format that can be stored ( for example, in a file or memory buffer) or
transmitted (for example, over a network connection) and reconstructed later in
the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no
restriction on how your serialization/deserialization algorithm should work. You
just need to ensure that a binary tree can be serialized to a string and this
string can be deserialized to the original tree structure.
Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:
Input: root = []
Output: []
Example 3:
Input: root = [1]
Output: [1]
Example 4:
Input: root = [1,2]
Output: [1,2]
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    void serializeHelper(TreeNode* root, stringstream& ss) {
        if (root == nullptr) {
            ss << "n ";
            return;
        }
        ss << root->val << " ";
        serializeHelper(root->left, ss);
        serializeHelper(root->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
    TreeNode* deserializeHelper(stringstream& ss) {
        string s;
        ss >> s;
        if (s == "n") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
    void preorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main() {
    Solution s;
    /*
              1
            2   3
               4 5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string result = s.serialize(root);
    cout << result << endl;

    TreeNode* deserializedRoot = s.deserialize(result);
    s.preorder(deserializedRoot);
    cout << endl;
    return 0;
}