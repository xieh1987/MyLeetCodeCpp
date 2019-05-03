/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(!root) return;
        while(root){
            mystack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = mystack.top();
        int val = tmp->val;
        mystack.pop();
        tmp = tmp->right;
        while(tmp){
            mystack.push(tmp);
            tmp = tmp->left;
        }
        return val;
    }
    
    private:
    stack<TreeNode*> mystack; 
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
