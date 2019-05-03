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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL||headB==NULL) return NULL;
        ListNode *currA = headA, *currB = headB;
        while (currA&&currB) {
            currA = currA -> next;
            currB = currB -> next;
        }
        if (!currA) currA = headB;
        if (!currB) currB = headA;
        while (currA&&currB) {
            currA = currA -> next;
            currB = currB -> next;
        }
        if (!currA) currA = headB;
        if (!currB) currB = headA;
        while (currA&&currB) {
            if (currA==currB) return currA;
            currA = currA -> next;
            currB = currB -> next;
        }
        return NULL;
    }
};
