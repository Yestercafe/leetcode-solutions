/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int dfs(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(dfs(node->left), dfs(node->right));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> visual;
        const int row = dfs(root);
        const int col = (1 << row) - 1;
        // cout << row << ' ' << col << endl;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, (col - 1) / 2});
        int prow = 0;

        while (!q.empty()) {
            visual.push_back(vector<string>(col, ""s));
            for (int size = q.size(); size--; ) {
                auto& [node, c] = q.front();
                visual[prow][c] = to_string(node->val);
                if (node->left)  q.push({node->left , c - (1 << (row - prow - 2))});
                if (node->right) q.push({node->right, c + (1 << (row - prow - 2))});
                q.pop();
            }
            ++prow;
        }
        
        return visual;
    }
};

