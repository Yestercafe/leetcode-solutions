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
    unordered_map<TreeNode*, int> memo;

    int find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        cout << "find " << root->val << endl;
        if (memo.count(root)) return memo[root];
        
        int l = find(root->left, p, q);
        int r = find(root->right, p, q);
        return memo[root] = ((root == p || root == q) + l + r);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto itr = root;
        while (itr != nullptr) {
            int l = find(itr->left, p, q);
            int r = find(itr->right, p, q);
            if ((l == 1 && l == r) || itr == q || itr == p) {
                return itr;
            } else if (l == 2) {
                itr = itr->left;
            } else {
                itr = itr->right;
            }
        }
        return nullptr;
    }
};

