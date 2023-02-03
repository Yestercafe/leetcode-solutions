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
    TreeNode* findNode(TreeNode* root, int x) {
        if (!root) return root;
        if (root->val == x) return root;
        auto fnd_l = findNode(root->left, x);
        return fnd_l ? fnd_l : findNode(root->right, x);
    }
    int countNode(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto fnd = findNode(root, x);
        auto cnt_l = countNode(fnd->left), cnt_r = countNode(fnd->right), cnt_pa = n - 1 - cnt_l - cnt_r;
        auto maxx = max({cnt_l, cnt_r, cnt_pa});
        return maxx > n - maxx;
    }
};

