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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        helper(res, root);
        return res;
    }
    
    void helper(vector<int>& res, TreeNode* root) {
        if(!root) return;
        if(root->left) helper(res, root->left);
        if(root->right) helper(res, root->right);
        res.push_back(root->val);
    }
};

/*Iteratively:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p||!s.empty()) {
            if(p) {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            }
            else {
                p = s.top();
                s.pop();
                p = p->left;
            }
        }
        return res;
    }
};
*/
