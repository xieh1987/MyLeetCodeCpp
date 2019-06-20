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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0), *curr = res;
        stack<TreeNode*> st;
        while(root||!st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            curr->right = root;
            curr = curr->right;
            curr->left = nullptr;
            root = root->right;
        }
        return res->right;
    }
};
