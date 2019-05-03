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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* slow = dummyhead, *fast = dummyhead;
        if(fast->next&&fast->next->next)
            fast = fast->next->next;
        else return head;
        while(fast) {
            ListNode* helper = slow->next;
            helper->next = fast->next;
            fast->next = helper;
            slow->next = fast;
            fast = fast->next;
            if(fast->next&&fast->next->next) {
                fast = fast->next->next;
                slow = slow->next->next;
            }
            else break;
        }
        return dummyhead->next;
    }
};
