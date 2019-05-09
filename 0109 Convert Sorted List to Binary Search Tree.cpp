/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* t = head;
        while(t) {
            ++n;
            t = t->next;
        }
        return helper(head, n-1);
    }
    
    TreeNode* helper(ListNode* head, int n) {
        if(n<0) return NULL;
        ListNode* curr = head;
        for(int i=0;i<n/2;++i) {
            curr = curr->next;
        }
        TreeNode* root = new TreeNode(curr->val);
        root->left = helper(head, n/2-1);
        root->right = helper(curr->next, n-n/2-1);
        return root;
    }
};
