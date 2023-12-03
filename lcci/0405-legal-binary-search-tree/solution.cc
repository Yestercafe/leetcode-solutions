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
    using i64 = long long;
    struct Ret {
        bool valid;
        i64 minn;
        i64 maxx;
    };
    
    Ret isValidBSTAux(TreeNode* root) {
        if (!root) {
            return {true, INT_MAX + 114514LL, INT_MIN - 114514LL};
        }
        
        auto l = isValidBSTAux(root->left);
        auto r = isValidBSTAux(root->right);
        if (l.valid && r.valid && l.maxx < root->val && root->val < r.minn) {
            return {true, min(1LL * root->val, l.minn), max(1LL * root->val, r.maxx)};
        } else {
            return {false, min(1LL * root->val, l.minn), max(1LL * root->val, r.maxx)};
        }
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTAux(root).valid;
    }
};

