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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy, *slow = dummy;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
            if(fast->next) fast = fast->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        return mergeList(head, head2);
    }
    
    ListNode* mergeList(ListNode* h1, ListNode* h2) {
        h1 = sortList(h1);
        h2 = sortList(h2);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(h1&&h2) {
            if(h1->val<h2->val) {
                curr->next = h1;
                h1 = h1->next;
            }
            else {
                curr->next = h2;
                h2 = h2->next;
            }
            curr = curr->next;
        }
        if(h1) curr->next = h1;
        if(h2) curr->next = h2;
        return dummy->next;
    }
};
