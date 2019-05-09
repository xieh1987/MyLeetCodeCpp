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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return NULL;
        return helper(nums, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end) {
        int len = end - start + 1;
        if(len<=0) return NULL;
        TreeNode* root = new TreeNode(nums[start+len/2]);
        root->left = helper(nums, start, start+len/2-1);
        root->right = helper(nums, start+len/2+1, end);
        return root;
    }
};
