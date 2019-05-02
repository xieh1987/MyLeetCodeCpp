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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        myqueue.push(NULL);
        while(!myqueue.empty()) {
            vector<int> level;
            while(myqueue.front()) {
                TreeNode* temp = myqueue.front();
                level.push_back(temp->val);
                if (temp->left) myqueue.push(temp->left);
                if (temp->right) myqueue.push(temp->right);
                myqueue.pop();
            }
            myqueue.pop();
            res.push_back(level);
            if (!myqueue.empty()) myqueue.push(NULL);
        }
        return res;
    }
};

/* Use a vector to hold the node from same level instead of using NULL as markers
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> level;
        if(!root) return res;
        level.push_back(root);
        while(!level.empty()){
            vector<int> level_val;
            vector<TreeNode*> level_node;
            while(!level.empty()){
                level_val.push_back(level.front()->val);
                level_node.push_back(level.front());
                level.pop_front();
            }
            res.push_back(level_val);
            for(auto node: level_node){
                if(node->left)
                    level.push_back(node->left);
                if(node->right)
                    level.push_back(node->right);
            }
        }
        return res;
    }
};
*/
