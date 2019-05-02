class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> res(m+1, vector<bool>(n+1, false));
        res[0][0] = true;
        for(int i=1;i<=n;++i)
        {
            if(i>1&&p[i-1]=='*')
                res[0][i] = res[0][i-2];
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[j-1]=='.')
                    res[i][j] = res[i-1][j-1];
                else if(p[j-1]=='*')
                    res[i][j] = (j>1 && res[i][j-2]) || res[i][j-1] || (res[i-1][j] && ((i>1 && s[i-1]==p[j-2]) || (j>1 && p[j-2]=='.')));
                else
                    res[i][j] = res[i-1][j-1] && s[i-1]==p[j-1];
            }
        }
        return res[m][n];
    }
};
