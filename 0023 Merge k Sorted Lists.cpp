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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = lists.size();
        if(s==0) return nullptr;
        if(s==1) return lists[0];
        vector<ListNode*> sub1(lists.begin(), lists.begin()+s/2);
        vector<ListNode*> sub2(lists.begin()+s/2, lists.end());
        return mergeTwoLists(mergeKLists(sub1), mergeKLists(sub2));
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy, *p1 = list1, *p2 = list2;
        while(p1&&p2) {
            if(p1->val<=p2->val) {
                curr->next = p1;
                p1 = p1->next;
            }
            else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        if(p1) curr->next = p1;
        if(p2) curr->next = p2;
        return dummy->next;
    }
};
