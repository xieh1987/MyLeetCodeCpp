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
