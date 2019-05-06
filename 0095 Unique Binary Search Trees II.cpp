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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> tree;
        if(start>end) tree.push_back(NULL);
        for(int i=start;i<=end;++i) {
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            for(int m=0;m<left.size();++m) {
                for(int n=0;n<right.size();++n) {
                    TreeNode* t = new TreeNode(i);
                    t->left = left[m];
                    t->right = right[n];
                    tree.push_back(t);
                }
            }
        }
        return tree;
    }
};
