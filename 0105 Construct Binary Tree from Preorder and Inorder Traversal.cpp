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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0) return NULL;
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        if(s1>e1||s2>e2) return NULL;
        TreeNode* root = new TreeNode(preorder[s1]);
        int i= s2;
        for(;i<=e2;++i) {
            if(inorder[i]==preorder[s1]) break;
        }
        int len = i - s2;
        root->left = helper(preorder, inorder, s1+1, s1+len, s2, s2+len-1);
        root->right = helper(preorder, inorder, s1+1+len, e1, s2+len+1, e2);
        return root;
    }
};
