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
    map<int, int> h;
    map<int, int> a;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        h[root->val] = 1 + max(height(root->left), height(root->right));
        return h[root->val];
    }

    void dfs(TreeNode* root, int depth, int rest) {
        if (root == nullptr) return ;
        ++depth;
        a[root->val] = rest;
        dfs(root->left, depth, max(rest, depth + (root->right ? h[root->right->val] : 0)));
        dfs(root->right, depth, max(rest, depth + (root->left ? h[root->left->val] : 0)));
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        dfs(root, -1, 0);
        vector<int> r;
        for (auto& q : queries) r.push_back(a[q]);
        return r;
    }
};

