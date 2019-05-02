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
    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;
        return getBalanced(root)!=-1;
    }
    
    int getBalanced(TreeNode* root) {
        if (root==NULL) return 0;
        int lval = getBalanced(root->left);
        int rval = getBalanced(root->right);
        if (lval==-1||rval==-1||abs(lval-rval)>1) 
            return -1;
        return max(lval, rval)+1;
    }
};
