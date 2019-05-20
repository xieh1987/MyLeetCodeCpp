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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next) {
            if(curr->val<=curr->next->val) curr = curr->next;
            else {
                ListNode* t = curr->next;
                curr->next = t->next;
                ListNode* pos = dummy;
                while(true) {
                    if(pos->next->val<=t->val) pos = pos->next;
                    else {
                        t->next = pos->next;
                        pos->next = t;
                        break;
                    }
                }
            }
        }
        return dummy->next;
    }
};
