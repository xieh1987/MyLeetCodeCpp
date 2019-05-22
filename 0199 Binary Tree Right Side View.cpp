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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return res;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            if(q.front()==nullptr) {
                q.pop();
                if(!q.empty()) q.push(nullptr);
            }
            else {
                TreeNode* t = q.front();
                q.pop();
                if(!q.empty()&&q.front()==nullptr) res.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return res;
    }
};
