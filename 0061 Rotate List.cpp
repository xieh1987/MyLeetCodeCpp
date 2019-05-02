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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int count = 1;
        ListNode* curr = head;
        while(curr->next)
        {
            curr = curr->next;
            ++count;
        }
        int shift = count - k % count;
        curr->next = head;
        for(int i=0;i<shift;++i)
        {
            curr = curr->next;
        }
        ListNode* newhead = curr->next;
        curr->next = NULL;
        return newhead;
    }
};
