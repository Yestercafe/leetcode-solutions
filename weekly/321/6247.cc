/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* rev_aux(ListNode* head) {
        if (head->next == nullptr) return head;
        auto last = rev_aux(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    
    void rev(ListNode* r) {
        r->next = rev_aux(r->next);
    }
public:
    ListNode* removeNodes(ListNode* head) {
        auto itr = head;
        auto re = new ListNode(999999999);
        while (itr) {
            while (re->next && itr->val > re->next->val) {
                re->next = re->next->next;
            }
            auto cur = itr;
            itr = itr->next;
            cur->next = re->next;
            re->next = cur;
        }
        rev(re);
        return re->next;
    }
};
