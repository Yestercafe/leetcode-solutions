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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto a = l1, b = l2;
        auto tail = a;
        while (a && b) {
            int va = a->val, vb = b->val;
            a->val = (va + vb + carry) % 10;
            carry = (va + vb + carry) / 10;
            a = a->next;
            b = b->next;
            if (tail->next) tail = tail->next;
        }

        if (b) {
            tail->next = b;
            a = b;
        }
        while (a) {
            int va = a->val;
            a->val = (va + carry) % 10;
            carry = (va + carry) / 10;
            a = a->next;
            if (tail->next) tail = tail->next;
        }

        if (carry) {
            tail->next = new ListNode(carry);
        }

        return l1;
    }
};

