/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* curr = head;
        unordered_map<Node*, Node*> m;
        while(curr) {
            Node* t = new Node(curr->val);
            m[curr] = t;
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};
