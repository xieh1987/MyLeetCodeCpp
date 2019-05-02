class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while(i<s.size())
        {
            if(p.size()==0) return false;
            if(p[j]==s[i]||p[j]=='?')
            {
                ++i;
                ++j;
            }
            else if(p[j]=='*')
            {
                jStar = j++;
                iStar = i;
            }
            else if(jStar>=0)
            {
                j = jStar + 1;
                i = ++iStar;
            }
            else return false;
        }
        while(j<p.size())
            if(p[j++]!='*') return false;
        return true;
    }
};

/*===============DP==================
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=1;i<n+1;++i)
        {
            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[j-1]=='*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else if(p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1]);
            }
        }
        return dp[m][n];
    }
};
==================End DP===========*/
