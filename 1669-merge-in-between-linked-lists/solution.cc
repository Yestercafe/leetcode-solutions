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
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list2, *tail = list2, *tail_n = list2->next;
        while (tail_n) {
            tail = tail_n;
            tail_n = tail_n->next;
        }

        list1 = new ListNode(0, list1);
        ListNode *insert_pos = list1, *concat_pos = list1;
        for (int i = 0; i <= b; ++i) {
            if (i < a) insert_pos = insert_pos->next;
            concat_pos = concat_pos->next;
        }

        insert_pos->next = head;
        tail->next = concat_pos->next;

        return list1->next;
    }
};

