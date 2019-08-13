//DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(n==0) return 1;
        if(m==0) return 0;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        long long count = 0;
        for(int i=0;i<m;i++) {
            if(s[i]==t[0]) count++;
            dp[i][0] = count;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m-1][n-1];
    }
};
