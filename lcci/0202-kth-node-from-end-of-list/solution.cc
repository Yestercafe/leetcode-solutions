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
    int kthToLast(ListNode* head, int k) {
        auto ans = head, itr = head;
        while (k--) itr = itr->next;
        while (itr != nullptr) {
            itr = itr->next;
            ans = ans->next;
        }
        return ans->val;
    }
};

