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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* temp;
        if(l1->val>l2->val){
            temp = l2;
            l2 = l1;
            l1 = temp;
        }
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};
