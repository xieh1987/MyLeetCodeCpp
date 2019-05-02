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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else{
            int leftdepth = maxDepth(root->left);
            int rightdepth = maxDepth(root->right);
            return 1+(leftdepth>=rightdepth?leftdepth:rightdepth);
        }
    }
};
