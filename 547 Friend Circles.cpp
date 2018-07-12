/*
 * Using BFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size(), res = 0;
        vector<bool> visited(len, false);
        
        for(auto i=0;i<len;++i){
            if(visited[i]) continue;
            checkCircle(M, i, visited);
            ++res;
        }
        return res;
    };
    
    void checkCircle(vector<vector<int>>& M, int id, vector<bool>& visited){
        visited[id] = true;
        int m_size = M.size();
        for(auto i=0;i<m_size;++i){
            if(!visited[i]&&M[i][id])
                checkCircle(M, i, visited);
        }
    }
};
*/

/*Using Union-Find*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        int res = len;
        vector<int> root(len);
        for(auto i=0;i<len;++i) root[i] = i;
        
        for(auto i=0;i<len;++i){
            for(auto j=0;j<len;++j){
                int r_i = getRoot(root, i);
                int r_j = getRoot(root, j);
                if(M[i][j]&&r_i!=r_j){
                    root[r_j] = r_i;
                    --res;
                }
            }
        }
        return res;
    }
    
    int getRoot(vector<int>& root, int id){
        while(root[id]!=id)
            id = root[id];
        return id;
    }
};
