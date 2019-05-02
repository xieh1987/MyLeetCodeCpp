class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m+1, vector<int>(n+1, grid[0][0]));
        for(int i=1;i<=m;++i)
            res[i][0] = res[i-1][0] + grid[i-1][0];
        for(int i=1;i<=n;++i)
            res[0][i] = res[0][i-1] + grid[0][i-1];
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i==1&&j==1) res[i][j] = grid[i-1][j-1];
                else res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i-1][j-1];
            }
        }
        return res[m][n];
    }
};
