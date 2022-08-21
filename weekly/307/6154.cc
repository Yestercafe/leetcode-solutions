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
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*> parent(100001, nullptr);
        vector<bool> vis(100001, false);
        parent[root->val] = nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = nullptr;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front->val == start) {
                startNode = front;
            }
            if (front->left) {
                parent[front->left->val] = front;
                q.push(front->left);
            }
            if (front->right) {
                parent[front->right->val] = front;
                q.push(front->right);
            }
        }
        
        q.push(startNode);
        int depth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto front = q.front();
                vis[front->val] = true;
                q.pop();
                if (front->left && !vis[front->left->val]) q.push(front->left);
                if (front->right && !vis[front->right->val]) q.push(front->right);
                if (parent[front->val] && !vis[parent[front->val]->val]) q.push(parent[front->val]);
            }
            ++depth;
        }
        
        return depth - 1;
    }
};
