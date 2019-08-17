/*BFS: passed all small test cases, but TLE for large cases
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int res = 0;
        helper(m, n, N, i, j, res);
        return res;
    }
    
    void helper(int m, int n, int N, int i, int j, int& res) {
        if(N==0) {
            return;
        }
        if(i==0)
            res = (res + 1) % 1000000007;
        else
            helper(m, n, N-1, i-1, j, res);
        if(i==m-1)
            res = (res + 1) % 1000000007;
        else if(i<m-1)
            helper(m, n, N-1, i+1, j, res);
        if(j==0)
            res = (res + 1) % 1000000007;
        else helper(m, n, N-1, i, j-1, res);
        if(j==n-1)
            res = (res + 1) % 1000000007;
        else if(j<n-1)
            helper(m, n, N-1, i, j+1, res);
    }
};
*/

//DP
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(m, vector<int>(n, 0)));
        for(int k=1;k<=N;k++) {
            for(int x=0;x<m;x++) {
                for(int y=0;y<n;y++) {
                    long long p1 = (x==0) ? 1 : dp[k-1][x-1][y];
                    long long p2 = (x==m-1) ? 1 : dp[k-1][x+1][y];
                    long long p3 = (y==0) ? 1 : dp[k-1][x][y-1];
                    long long p4 = (y==n-1) ? 1 : dp[k-1][x][y+1];
                    dp[k][x][y] = (p1 + p2 + p3 + p4) % 1000000007;
                }
            }
        }
        return dp[N][i][j];
    }
};
