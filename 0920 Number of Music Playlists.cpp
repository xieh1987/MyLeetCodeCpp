//DP: dp[i][j] calculates the number of possible playlists of length j using i songs out of N songs with K interval
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long>> dp(L+1, vector<long long>(N+1, 0));
        for(int i=1;i<=L;i++) {
            for(int j=1;j<=N;j++) {
                if(i==1&&j==1) dp[i][j] = N;
                else {
                    dp[i][j] = dp[i-1][j-1] * (N - j + 1) + dp[i-1][j] * max(0, j - K);
                    dp[i][j] %= 1000000007;
                }
            }
        }
        return dp[L][N];
    }
};

/*DSP, passed small tested cases, but TLE
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        unordered_map<int, int> m;
        for(int i=1;i<=N;i++) 
            m[i] = -1;
        int res = 0;
        helper(N, L, K, m, res);
        return res;
    }
    
    void helper(int N, int L, int K, unordered_map<int, int>& m, int& res) {
        if(L==0) {
            for(int i=1;i<=N;i++)
                if(m[i]==-1) return;
            res = (res + 1) % 1000000007;
            return;
        }
        for(int i=1;i<=N;i++) {
            if(m[i]!=-1&&m[i]-L-1<K) continue;
            int s = m[i];
            m[i] = L;
            helper(N, L-1, K, m, res);
            m[i] = s;
        }
    }
};
*/
