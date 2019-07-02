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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* curr1 = head, *curr2 = dummy;
        while(curr1) {
            if(curr1->next) {
                curr2->next = curr1->next;
                curr1->next = curr1->next->next;
                curr2 = curr2->next;
                curr2->next = nullptr;
            }
            if(curr1->next) curr1 = curr1->next;
            else break;
        }
        curr1->next = dummy->next;
        return head;
    }
};
