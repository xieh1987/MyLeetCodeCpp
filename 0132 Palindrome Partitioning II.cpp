/*BFS: LTE Solution
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(isPalindrome(s.substr(0, i+1))) {
                if(i==n-1) return 0;
                else q.push(i);
            }
        }
        int layer = 0;
        while(!q.empty()) {
            layer++;
            int m = q.size();
            for(int i=0;i<m;i++) {
                int t = q.front(); q.pop();
                for(int k=t+1;k<n;k++) {
                    if(isPalindrome(s.substr(t+1, k-t))) {
                        if(k==n-1) return layer;
                        else q.push(k);
                    }
                }
            }
        }
        return 0;
    }
    
    bool isPalindrome(string s) {
        if(s.size()<2) return true;
        int i = 0, j = s.size() - 1;
        while(i<j) {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};
*/

//DP
class Solution {
public:
    int minCut(string s) {
        if(s=="") return 0;
        vector<int> res(s.size(), 0);
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int j=0;j<s.size();j++) {
            int mn = INT_MAX;
            for(int i=0;i<=j;i++) {
                if(i==j) dp[i][j] = true;
                else dp[i][j] = s[i]==s[j] && (j-i<3 ? true : dp[i+1][j-1]);
                if(dp[i][j]) {
                    if(i==0) mn = 0;
                    else mn = min(mn, res[i-1] + 1);
                }
            }
            res[j] = mn;
        }
        return res[s.size() - 1];
    }
};
