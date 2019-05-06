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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res, root);
        return res;
    }
    
    void helper(vector<int>& res, TreeNode* root) {
        if(!root) return;
        if(root->left) helper(res, root->left);
        res.push_back(root->val);
        if(root->right) helper(res, root->right);
    }
};

/*Use stack without recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> mystack;
        TreeNode* t = root;
        while(t||!mystack.empty()) {
            while(t) {
                mystack.push(t);
                t = t->left;
            }
            t = mystack.top();
            mystack.pop();
            res.push_back(t->val);
            t = t->right;
        }
        return res;
    }
};
*/
