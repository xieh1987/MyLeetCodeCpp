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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> small, large;
        ListNode* curr = head;
        while(curr) {
            if(curr->val<x) small.push(curr);
            else large.push(curr);
            curr = curr->next;
        }
        ListNode* dummyhead = new ListNode(0);
        curr = dummyhead;
        while(!small.empty()){
            curr->next = small.front();
            small.pop();
            curr = curr->next;
        }
        while(!large.empty()) {
            curr->next = large.front();
            large.pop();
            curr = curr->next;
        }
        curr->next = NULL;
        return dummyhead->next;
    }
};

/*Alternative Implemenation: Using a new generated list
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode * res = new ListNode(0);
        ListNode* curr = dummyhead, *rescurr = res;
        while(curr&&curr->next) {
            if(curr->next->val<x) {
                rescurr->next = curr->next;
                curr->next = curr->next->next;
                rescurr = rescurr->next;
            }
            else curr = curr->next;
        }
        while(dummyhead->next) {
            rescurr->next = dummyhead->next;
            dummyhead = dummyhead->next;
            rescurr = rescurr->next;
        }
        return res->next;
    }
};
*/
