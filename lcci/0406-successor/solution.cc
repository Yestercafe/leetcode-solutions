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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return nullptr;
        auto fnd = root;
        vector<TreeNode*> anc;
        while (fnd != nullptr) {
            anc.push_back(fnd);
            if (fnd->val == p->val) break;
            if (p->val < fnd->val) {
                fnd = fnd->left;
            } else {
                fnd = fnd->right;
            }
        }

        if (!fnd) return fnd;
        if (fnd->right) {
            auto itr = fnd->right;
            while (itr->left != nullptr) {
                itr = itr->left;
            }
            return itr;
        }
        for (auto ri = anc.rbegin(); ri != anc.rend(); ++ri) {
            if ((*ri)->val > p->val) {
                return *ri;
            }
        }
        return nullptr;
    }
};

