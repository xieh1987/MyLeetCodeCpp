/*a TLE method using BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n==0) return res;
        int mn = INT_MAX;
        for(int i=0;i<n;++i) {
            vector<bool> visited(edges.size(), false);
            queue<int> q;
            q.push(i);
            q.push(-1);
            int depth = 1;
            while(!q.empty()) {
                if(q.front()==-1) {
                    q.pop();
                    if(!q.empty()) {
                        ++depth;
                        if(depth>mn) break;
                        q.push(-1);
                    }
                }
                else {
                    int t = q.front();
                    q.pop();
                    for(int j=0;j<edges.size();++j) {
                        if(!visited[j]) {
                            if(edges[j][0]==t) {
                                q.push(edges[j][1]);
                                visited[j] = true;
                            }
                            if(edges[j][1]==t) {
                                q.push(edges[j][0]);
                                visited[j] = true;
                            }
                        }
                    }
                }
            }
            if(depth==mn) res.push_back(i);
            else if(depth<mn) {
                mn = depth;
                res.clear();
                res.push_back(i);
            }
        }
        return res;
    }
};
*/

//At most two MHTs from graph!!!
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> res;
        if(n==0) return res;
        vector<unordered_set<int>> s(n);
        for(auto v : edges) {
            s[v[0]].insert(v[1]);
            s[v[1]].insert(v[0]);
        }
        queue<int> q;
        for(int i=0;i<s.size();++i)
            if(s[i].size()==1)
                q.push(i);
        while(n>2) {
            int len = q.size();
            n -= len;
            for(int i=0;i<len;++i) {
                int t = q.front();
                q.pop();
                for(auto elem : s[t]) {
                    s[elem].erase(t);
                    if(s[elem].size()==1) q.push(elem);
                }
            }
        }
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
        }
        return res;
    }
};
