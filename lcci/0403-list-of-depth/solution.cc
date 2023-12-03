/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;

        deque<TreeNode*> q;
        q.push_back(tree);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            ans.push_back(new ListNode);
            auto tail = ans.back();   // dummy
            while (size--) {
                auto f = q.front();
                q.pop_front();
                tail = tail->next = new ListNode(f->val);
                if (f->left) q.push_back(f->left);
                if (f->right) q.push_back(f->right);
            }

            ans.back() = ans.back()->next;
        }

        return ans;
    }
};

