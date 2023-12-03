/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (!root) return {{}};
        vector<int> p;
        p.push_back(root->val);
        aux(root, {}, p);
        return ans;
    }

    void aux(TreeNode* node, deque<TreeNode*> q, vector<int>& path) {
        if (!node) return;
        if (node->left) q.push_back(node->left);
        if (node->right) q.push_back(node->right);
        if (q.empty()) {
            ans.push_back(path);
            return;
        }

        int size = q.size();
        while (size--) {
            auto f = q.front();
            q.pop_front();
            path.push_back(f->val);
            aux(f, q, path);
            path.pop_back();
            q.push_back(f);
        }
    }
};

