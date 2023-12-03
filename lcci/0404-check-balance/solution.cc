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
    int height(TreeNode* node) {
        if (!node) return 0;
        int l = height(node->left);
        int r = height(node->right);
        if (l < 0 || r < 0 || abs(l - r) > 1) {
            return -1;
        }
        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return height(root) > 0;
    }
};

