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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()||root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            TreeNode* t = st.top();
            st.pop();
            --k;
            if(k==0) return t->val;
            root = t->right;
        }
        return 0;
    }
};
