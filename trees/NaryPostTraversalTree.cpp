#include <iostream>
#include <vector>
using namespace std;
/*
Given the root of an n-ary tree, return the postorder traversal of its nodes'
values.

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: [5,6,3,2,4,1]

Example 3:
Input: root = []
Output: []
*/
// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
};

class Solution {
   public:
    vector<int> dfs(Node* root, vector<int>& res) {
        if (root == nullptr) return res;
        for (Node* child : root->children) {
            dfs(child, res);
        }
        res.push_back(root->val);
        return res;
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        return dfs(root, result);
    }
};

int main() {
    /*
                1
              / | \
             3  2  4
            / \
           5   6
    */
    Node* root = new Node(1);
    Node* child1 = new Node(3);
    Node* child2 = new Node(2);
    Node* child3 = new Node(4);
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    Node* child4 = new Node(5);
    Node* child5 = new Node(6);
    child1->children.push_back(child4);
    child1->children.push_back(child5);

    Solution s;
    vector<int> res = s.postorder(root);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}