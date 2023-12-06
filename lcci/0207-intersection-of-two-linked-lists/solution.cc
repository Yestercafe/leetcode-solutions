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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        auto itr = headA;
        while (itr) {
            itr = itr->next;
            ++lenA;
        }
        itr = headB;
        while (itr) {
            itr = itr->next;
            ++lenB;
        }

        if (lenA > lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        }

        auto a = headA, b = headB;
        for (int i = 0, k = lenB - lenA; i < k; ++i) {
            b = b->next;
        }

        while (a && b) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }

        return nullptr;
    }
};

