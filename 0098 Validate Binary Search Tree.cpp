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
    bool isValidBST(TreeNode* root) {
        vector<int> elem;
        stack<TreeNode*> my_stack;
        
        while(root||!my_stack.empty()){
            while(root){
                my_stack.push(root);
                root = root->left;
            }
            root = my_stack.top();
            elem.push_back(root->val);
            my_stack.pop();
            root = root->right;
        }
        if(elem.size()<2) return true;
        for(auto i=1;i<elem.size();++i){
            if(elem[i]<=elem[i-1]) return false;
        }
        return true;
    }
};
