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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto itr = dummy;
        unordered_set<int> vis;
        while (itr && itr->next) {
            auto nxt = itr->next;
            if (vis.count(nxt->val) == 0) {
                vis.insert(nxt->val);
                itr = itr->next;
            } else {
                itr->next = nxt->next;
                nxt->next = nullptr;
                delete nxt;
            }
        }

        auto detach = dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return detach;
    }
};

