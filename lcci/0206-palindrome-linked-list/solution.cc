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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        auto itr = head;
        while (itr) {
            itr = itr->next;
            ++len;
        }
        
        auto dummy = new ListNode;
        for (int i = 0, k = len / 2; i < k; ++i) {
            auto nxt = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = nxt;
        }
        if (len % 2) head = head->next;

        auto a = dummy->next, b = head;
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }

        dummy->next = nullptr;
        delete dummy;

        return true;
    }
};

