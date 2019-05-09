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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, sum, res, path);
        return res;
    }
    
    void helper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path) {
        if(!root) return;
        if(!root->left&&!root->right) {
            if(root->val==sum) {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            else return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if(root->left) helper(root->left, sum, res, path);
        if(root->right) helper(root->right, sum, res, path);
        path.pop_back();
    }
};
