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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);
        while(!myqueue.empty()) {
            vector<int> level;
            while(myqueue.front()) {
                TreeNode* temp = myqueue.front();
                level.push_back(temp->val);
                if (temp->left) myqueue.push(temp->left);
                if (temp->right) myqueue.push(temp->right);
                myqueue.pop();
            }
            myqueue.pop();
            res.push_back(level);
            if (!myqueue.empty()) myqueue.push(NULL);
        }
        return res;
    }
};
