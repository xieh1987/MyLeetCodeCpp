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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        TreeNode* dummy = root;
        while(dummy||!st.empty()) {
            while(dummy) {
                st.push(dummy);
                dummy = dummy->left;
            }
            dummy = st.top();
            vec.push_back(dummy->val);
            st.pop();
            dummy = dummy->right;
        }
        sort(vec.begin(), vec.end());
        dummy = root;
        int i = 0;
        while(dummy||!st.empty()) {
            while(dummy) {
                st.push(dummy);
                dummy = dummy->left;
            }
            dummy = st.top();
            dummy->val = vec[i++];
            st.pop();
            dummy = dummy->right;
        }
    }
};
