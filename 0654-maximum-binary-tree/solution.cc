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
private:
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (r == l) return nullptr;
        auto maxe = max_element(nums.begin() + l, nums.begin() + r);
        return new TreeNode(*maxe, construct(nums, l, distance(nums.begin(), maxe)),
                                   construct(nums, distance(nums.begin(), maxe + 1), r));
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};

