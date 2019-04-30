class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> res(m, vector<long>(n, 1));
        if(obstacleGrid[0][0]==1) return 0;
        for(int i=1;i<m;++i)
        {
            if(obstacleGrid[i][0]==1)
                res[i][0] = 0;
            else res[i][0] = res[i-1][0];
        }
        for(int j=1;j<n;++j)
        {
            if(obstacleGrid[0][j]==1)
                res[0][j] = 0;
            else res[0][j] = res[0][j-1];
        }
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(obstacleGrid[i][j]==1)
                    res[i][j] = 0;
                else res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};
