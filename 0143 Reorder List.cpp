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
    void reorderList(ListNode* head) {
        vector<ListNode*> splitnodes = splitList(head);
        splitnodes[1] = reverseList(splitnodes[1]);
        head = mergeLists(splitnodes[0], splitnodes[1]);
    }
    
    vector<ListNode*> splitList(ListNode* head) {
        if(!head) return {nullptr, nullptr};
        ListNode* fast = head, *slow = head;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* t = slow->next;
        slow->next = nullptr;
        return {head, t};
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        while(head->next) {
            ListNode* cur = head->next;
            head->next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
        }
        return dummy->next;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(l1) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
            if(l2) {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        return dummy->next;
    }
};
