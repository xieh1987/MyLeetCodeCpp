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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0) return NULL;
        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
        if(s1>e1||s2>e2) return NULL;
        TreeNode* root = new TreeNode(postorder[e2]);
        int i = s1;
        while(i<e1) {
            if(inorder[i]==postorder[e2]) break;
            ++i;
        }
        int len = i - s1;
        root->left = helper(inorder, postorder, s1, s1+len-1, s2, s2+len-1);
        root->right = helper(inorder, postorder, s1+len+1, e1, s2+len, e2-1);
        return root;
    }
};
