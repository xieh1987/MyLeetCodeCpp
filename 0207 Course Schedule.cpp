class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for(auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }
        queue<int> q;
        for(auto i=0;i<numCourses;++i)
            if(in[i]==0)
                q.push(i);
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto i : graph[t]) {
                --in[i];
                if(in[i]==0) q.push(i);
            }
        }
        for(auto i : in)
            if(i) return false;
        return true;
    }
};
