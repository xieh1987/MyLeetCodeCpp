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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> res;
        if (root) findPath(res, path, root);
        return res;
    }
    
    void findPath(vector<string> &res, string path, TreeNode* node) {
        path += to_string(node->val);
        if (node->left==NULL&&node->right==NULL) {
            res.push_back(path);
        }
        else {
            if (node->left) findPath(res, path+"->", node->left);
            if (node->right) findPath(res, path+"->", node->right);
        }
    }
};
