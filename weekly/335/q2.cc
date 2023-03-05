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
    using ll = long long;
    vector<ll> ans;
    void bfs(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int len = q.size();
            ll sum {};
            while (len--) {
                auto nde = q.front();
                sum += nde->val;
                q.pop_front();
                if (nde->left) q.push_back(nde->left);
                if (nde->right) q.push_back(nde->right);
            }
            ans.push_back(sum);
        }
    }
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        if (ans.size() < k) return -1;
        nth_element(ans.begin(), ans.begin() + k - 1, ans.end(), greater<ll>{});
        return ans[k - 1];
    }
};

