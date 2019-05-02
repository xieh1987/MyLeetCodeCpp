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
    void flatten(TreeNode* root) {
        if(!root) return;
        else if(!root->left) flatten(root->right);
        else if(!root->right){
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
        }
        else{
            TreeNode* curr = root->left;
            flatten(curr);
            while(curr->right) curr = curr->right;
            flatten(root->right);
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
