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
        if (l1->next == NULL && l2->next == NULL &&
            l1->val == 0 && l2->val == 0) {
            return new ListNode(0);
        }
        bool l1s, l2s;
        int addOne = 0;
        
        ListNode *res = NULL, *itr;
        
        while (l1 != NULL || l2 != NULL) {
            int bit = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + addOne;
            addOne = 0;
            if (bit > 9) {
                bit -= 10;
                addOne = 1;
            }
            
            if (res == NULL) {
                res = new ListNode(bit);
                itr = res;
            } else {
                itr->next = new ListNode(bit);
                itr = itr->next;
            }
            
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        
        if (addOne != 0) {
            itr->next = new ListNode(addOne);
        }
        
        return res;
    }
};

