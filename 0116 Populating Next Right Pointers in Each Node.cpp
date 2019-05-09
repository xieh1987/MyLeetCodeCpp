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

//Using Resursion
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left) {
            root->left->next = root->right;
            root->right->next = root->next? root->next->left : NULL;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};

/*Using Queue
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* t = q.front();
            q.pop();
            if(t==NULL) {
                if(!q.empty()) q.push(NULL);
            }
            else {
                t->next = q.front();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return root;
    }
};
*/
