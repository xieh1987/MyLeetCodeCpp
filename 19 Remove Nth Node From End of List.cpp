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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head, *dumphead;
        dumphead->next = head;
        ListNode* back = dumphead;
        for (int i=0;i<n;i++) {
            front = front->next;
        }
        while (front) {
            back = back->next;
            front = front->next;
            head = head->next;
        }
        back->next = back->next->next;
        return dumphead->next;
    }
};
