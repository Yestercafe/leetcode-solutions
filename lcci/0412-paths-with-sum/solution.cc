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
public:
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        unordered_map<i64, int> pref;
        pref[0] = 1;

        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, i64 partial_sum) {
            if (!node) return 0;
            
            int ret = 0;
            partial_sum += node->val;
            if (pref.count(partial_sum - sum)) {  // prefix exists
                ret = pref[partial_sum - sum];
            }

            ++pref[partial_sum];
            ret += dfs(node->left, partial_sum);
            ret += dfs(node->right, partial_sum);
            --pref[partial_sum];
            return ret;
        };

        return dfs(root, 0);
    }
};

