class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n, triangle[n-1]);
        for(int i=n-2;i>=0;--i) {
            for(int j=0;j<i+1;++j) {
                dp[i][j] = triangle[i][j] + (dp[i+1][j]<dp[i+1][j+1] ? dp[i+1][j] : dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
