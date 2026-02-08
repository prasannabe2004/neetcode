#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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
    Level Order Traversal using Queue
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node != nullptr) level.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    /*
              1
            2   3
           4 5 6 7
    */
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Level order traversal of the tree is: " << endl;
    vector<vector<int>> res = root->levelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}