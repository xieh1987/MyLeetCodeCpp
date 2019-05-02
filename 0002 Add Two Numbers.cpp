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
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int digit = 0;
        while(l1||l2)
        {
            if(l1)
            {
                digit += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                digit += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(digit % 10);
            digit /= 10;
            curr = curr->next;
        }
        if(digit)
        {
            curr->next = new ListNode(digit);
        }
        return head->next;
    }
};
