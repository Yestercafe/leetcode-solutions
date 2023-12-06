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
    bool equal(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr || t2 == nullptr) {
            if (t1 == t2) return true;
            return false;
        }
        if (t1->val != t2->val) return false;
        if (!equal(t1->left, t2->left)) return false;
        if (!equal(t1->right, t2->right)) return false;
        return true;
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t2) return true;
        if (!t1) return false;
        if (equal(t1, t2)) {
            return true;
        }
        return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};

