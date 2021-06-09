class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for(;i<s.size()&&j<t.size();j++) {
            if(s[i]==t[j]) ++i;
        }
        return i==s.size();
    }
};

/* DP
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        vector<vector<bool>> res (ls+1, vector<bool>(lt+1, false));
        for(int j=0;j<=lt;++j) {
            res[0][j] = true;
        }
        for(int i=1;i<=ls;++i) {
            for(int j=i;j<=lt;++j) {
                res[i][j] = (res[i-1][j-1] && s[i-1]==t[j-1]) || (res[i][j-1]);
            }
        }
        return res[ls][lt];
    }
};
*/
