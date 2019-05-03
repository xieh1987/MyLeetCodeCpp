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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *dummy = new ListNode(0); 
        ListNode* curr = head;
        dummy->next = head;
        ListNode* prev = dummy;
        int tmp = head->val-1;
        while(curr->next){
            if(curr->val==curr->next->val||curr->val==tmp){
                prev->next = curr->next;
            }
            else{
                prev = prev->next;
            }
            tmp = curr->val;
            curr = curr->next;
        }
        if(curr->val==tmp) prev->next = NULL;
        return dummy->next;
    }
};
