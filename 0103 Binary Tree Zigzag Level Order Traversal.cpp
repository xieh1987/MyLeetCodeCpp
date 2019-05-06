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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> elem;
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if(t==NULL) {
                res.push_back(elem);
                elem.clear();
                if(!q.empty()) q.push(NULL);
            }
            else {
                elem.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        for(int i=1;i<res.size();i=i+2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
