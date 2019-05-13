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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL) return false;
        if (root->left==NULL&&root->right==NULL&&root->val==sum) return true;
        if (hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val)) return true;;
        return false;
    }
};

/*Just simpler:
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left&&!root->right&&root->val==sum) return true;
        return((root->left&&hasPathSum(root->left, sum-root->val))||(root->right&&hasPathSum(root->right, sum-root->val)));
    }
};
*/
