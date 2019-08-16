class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int area = 0, res = INT_MIN;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1&&!visited[i][j])
                    helper(grid, i, j, visited, area);
                res = max(res, area);
                area = 0;
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int& area) {
        if(visited[i][j]) return;
        area++;
        visited[i][j] = true;
        if(i>0&&grid[i-1][j]==1) helper(grid, i-1, j, visited, area);
        if(i<grid.size()-1&&grid[i+1][j]==1) helper(grid, i+1, j, visited, area);
        if(j>0&&grid[i][j-1]==1) helper(grid, i, j-1, visited, area);
        if(j<grid[0].size()-1&&grid[i][j+1]==1) helper(grid, i, j+1, visited, area);
    }
};
