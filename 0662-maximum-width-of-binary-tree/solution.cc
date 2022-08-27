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
    static ll Left(const ll& root) { return root * 2; }
    static ll Right(const ll& root) { return root * 2 + 1; }
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, ll>> pq;
        pq.push_back({root, 1});
        ll maxWidth = 0;
        while (!pq.empty()) {
            maxWidth = max(maxWidth, pq.back().second - pq.front().second + 1);
            int size = pq.size();
            int des = pq.front().second;
            for (int i = 0; i < size; ++i) {
                auto& [front, pos] = pq.front();
                if (front->left) pq.push_back({front->left, Left(pos - des)});
                if (front->right) pq.push_back({front->right, Right(pos - des)});
                pq.pop_front();
            }
        }
        return maxWidth;
    }
};
