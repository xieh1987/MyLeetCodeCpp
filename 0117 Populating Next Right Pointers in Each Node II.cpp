/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* t = root -> next;
        while(t) {
            if(t->left) {
                t = t->left;
                break;
            }
            if(t->right) {
                t = t->right;
                break;
            }
            t = t -> next;
        }
        if(root->right) root->right->next = t;
        if(root->left) root->left->next = root->right ? root->right : t;
        connect(root->right); \\Note here: Recursion on right first!! Very important!
        connect(root->left);
        return root;
    }
};
