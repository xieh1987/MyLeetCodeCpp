class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(visited[i][j]) continue;
                if(grid[i][j]=='1') {
                    ++res;
                    visited[i][j] = true;
                    q.push(vector<int>{i, j});
                    while(!q.empty()) {
                        vector<int> t = q.front();
                        q.pop();
                        if(t[0]>0&&grid[t[0]-1][t[1]]=='1'&&!visited[t[0]-1][t[1]]) {
                            q.push(vector<int>{t[0]-1, t[1]});
                            visited[t[0]-1][t[1]] = true;
                        }
                        if(t[1]>0&&grid[t[0]][t[1]-1]=='1'&&!visited[t[0]][t[1]-1]) {
                            q.push(vector<int>{t[0], t[1]-1});
                            visited[t[0]][t[1]-1] = true;
                        }
                        if(t[0]+1<m&&grid[t[0]+1][t[1]]=='1'&&!visited[t[0]+1][t[1]]) {
                            q.push(vector<int>{t[0]+1, t[1]});
                            visited[t[0]+1][t[1]] = true;
                        }
                        if(t[1]+1<n&&grid[t[0]][t[1]+1]=='1'&&!visited[t[0]][t[1]+1]) {
                            q.push(vector<int>{t[0], t[1]+1});
                            visited[t[0]][t[1]+1] = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};
