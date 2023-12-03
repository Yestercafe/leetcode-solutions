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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        auto slow = head, quick = head;
        do {
            slow = slow->next;
            quick = quick->next;
            if (quick) {
                quick = quick->next;
            }
        } while (quick && slow != quick);

        if (!quick) {
            return nullptr;
        }

        slow = head;
        while (slow != quick) {
            slow = slow->next;
            quick = quick->next;
        }
        return slow;
    }
};

