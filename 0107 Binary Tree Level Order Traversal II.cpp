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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            if(q.front()==NULL) {
                res.push_back(level);
                level.clear();
                q.pop();
                if(!q.empty()) q.push(NULL);
            }
            else {
                TreeNode* elem = q.front();
                level.push_back(elem->val);
                q.pop();
                if(elem->left) q.push(elem->left);
                if(elem->right) q.push(elem->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
