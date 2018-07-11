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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 1;
        deque<TreeNode*> dq;
        dq.push_back(root);
        TreeNode* dummy;
        dq.push_back(dummy);
        while(!dq.empty()){
            if(dq.front()==dummy){
                dq.pop_front();
                if(!dq.empty()){
                    dq.push_back(dummy);
                    ++depth;
                }
            }
            else {
                TreeNode* temp = dq.front();
                dq.pop_front();
                if((temp!=root)&&!temp->left&&!temp->right)
                    return depth;
                else{
                    if(temp->left) dq.push_back(temp->left);
                    if(temp->right) dq.push_back(temp->right);
                }
            }
        }
        return depth;
    }
};
