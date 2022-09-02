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
    int dfs(int pv, TreeNode* root) {
        if (root->val == pv) {
            int l, r;
            l = r = -1;
            if (root->left) {
                l = dfs(root->val, root->left);
            }
            if (root->right) {
                r = dfs(root->val, root->right);
            }
            ans = max(ans, l + r + 2);
            return max(l, r) + 1;
        } else {
            dfs(root->val, root);
        }
        return -1;
    }
    
    int ans;
public:
    Solution() : ans(0) {}
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root->val, root);
        return ans;
    }
};

