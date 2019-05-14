/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//DFS:
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return helper(node, m);
    }
    
    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if(!node) return NULL;
        if(m.count(node)) return m[node];
        Node* nd = new Node(node->val);
        m[node] = nd;
        for(auto neighbor : node->neighbors) {
            nd->neighbors.push_back(helper(neighbor, m));
        }
        return nd;
    }
};

/*BFS:
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> m;
        Node* res = new Node(node->val);
        m[node] = res;
        while(!q.empty()) {
            Node* t = q.front();
            q.pop();
            for(auto neighbor : t->neighbors) {
                if(!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[t]->neighbors.push_back(m[neighbor]);
            }
        }
        return res;
    }
};
*/
