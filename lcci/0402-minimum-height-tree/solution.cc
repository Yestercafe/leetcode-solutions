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
    TreeNode* sortedArrayToBSTAux(vector<int>& nums, int l, int r) {
        int len = r - l;
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode(nums[l]);
        
        int mid = l + r >> 1;
        auto node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBSTAux(nums, l, mid);
        node->right = sortedArrayToBSTAux(nums, mid + 1, r);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTAux(nums, 0, nums.size());
    }
};

