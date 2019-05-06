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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0), *pre = dummy;
        dummy->next = head;
        for(int i=0;i<m-1;++i) 
            pre = pre->next;
        ListNode* curr = pre->next;
        for(int i=m;i<n;++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};

/*Alternative Implementation: use stack to reverse
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;
        for(int i=0;i<n-m+1;++i)
            fast = fast->next;
        for(int i=0;i<m-1;++i) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* curr = slow, *temp = new ListNode(0);
        temp->next = fast->next;
        stack<ListNode*> mystack;
        for(int i=0;i<n-m+1;++i) {
            mystack.push(curr->next);
            curr = curr->next;
        }
        curr = slow;
        while(!mystack.empty()) {
            curr->next = mystack.top();
            mystack.pop();
            curr = curr->next;
        }
        curr->next = temp->next;
        return dummy->next;
    }
};
*/
