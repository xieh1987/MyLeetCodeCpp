/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Recursion: 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res, root);
        return res;
    }
    
    void helper(vector<int>& res, TreeNode* root) {
        if(!root) return;
        res.push_back(root->val);
        if(root->left) helper(res, root->left);
        if(root->right) helper(res, root->right);
    }
};

/*Iteratively:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p||!s.empty()) {
            if(p) {
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return res;
    }
};
*/
