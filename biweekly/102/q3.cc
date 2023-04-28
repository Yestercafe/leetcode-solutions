/**j
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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            int size;
            size = q.size();
            vector<pair<TreeNode*, TreeNode*>> v;
            long long layer_sum = 0;
            while (size--) {
                auto top = q.front();
                q.pop();
                v.push_back(top);
                if (top.first) {
                    q.push({top.first->left, top.first->right});
                    layer_sum += 1LL * top.first->val;
                }
                if (top.second) {
                    q.push({top.second->left, top.second->right});
                    layer_sum += 1LL * top.second->val;
                }
            }
            
            for (auto [l, r] : v) {
                int csum = (l ? l->val : 0) + (r ? r->val : 0);
                if (l) l->val = layer_sum - csum;
                if (r) r->val = layer_sum - csum;
            }
        }
        return root;
    }
};

