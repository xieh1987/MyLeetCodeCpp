/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Divide and conquer
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int t = maxBranch(root, res);
        return max(res, t);
    }
    
    int maxBranch(TreeNode* root, int& res) {
        if(!root) return 0;
        int leftsum = INT_MIN, rightsum = INT_MIN;
        if(root->right) {
            rightsum = maxBranch(root->right, res);
        }
        if(root->left) {
            leftsum = maxBranch(root->left, res);
        }
        int mx, mxbranch;
        if(leftsum<=0&&rightsum<=0) mx = mxbranch = root->val;
        else if(leftsum<=0) mx = mxbranch = root->val + rightsum;
        else if(rightsum<=0) mx = mxbranch = root->val + leftsum;
        else {
            mx = root->val + leftsum + rightsum;
            mxbranch = root->val + max(leftsum, rightsum);
        }
        res = max(res, mx);
        return mxbranch;
    }
};
