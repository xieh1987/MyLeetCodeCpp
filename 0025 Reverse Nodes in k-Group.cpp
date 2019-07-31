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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* start = dummy, *tail = dummy;
        dummy->next = head;
        for(int i=0;i<k;++i)
            if(tail) tail = tail->next;
        while(tail) {
            ListNode* newhead = start->next;
            for(int i=0;i<k-1;++i) {
                ListNode* curr = newhead->next;
                ListNode* t = curr->next;
                curr->next = start->next;
                start->next = curr;
                newhead->next = t;
            }
            start = newhead;
            tail = newhead;
            for(int i=0;i<k;++i)
                if(tail) tail = tail->next;
        }
        return dummy->next;
    }
};
