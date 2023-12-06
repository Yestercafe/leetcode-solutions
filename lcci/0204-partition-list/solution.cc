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
    ListNode* partition(ListNode* head, int x) {
        auto less = new ListNode;
        auto greater = new ListNode;
        auto xs = new ListNode;
        auto l = less, g = greater, s = xs;

        auto itr = head;
        while (itr) {
            auto val = itr->val;
            auto nxt = itr->next;
            itr->next = nullptr;
            if (val < x) {
                l = l->next = itr;
            } else if (val > x) {
                g = g->next = itr;
            } else {
                s = s->next = itr;
            }
            itr = nxt;
        }

        auto dummy = new ListNode;
        auto tail = dummy;
        tail->next = less->next;
        if (less->next) tail = l;
        tail->next = greater->next;
        if (greater->next) tail = g;
        tail->next = xs->next;
        auto detach = dummy->next;
        dummy->next = nullptr;
        delete dummy;

        less->next = nullptr;
        delete less;
        greater->next = nullptr;
        delete greater;
        xs->next = nullptr;
        delete xs;

        return detach;
    }
};

