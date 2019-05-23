/* Brute force DFS: LTE:
lass Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size(), res = -1, count = 0;
        for(int i=n-1;i>=0;--i)
            helper(coins, amount, count, res, i);
        return res;
    }
    
    void helper(vector<int>& coins, int& amount, int& count, int& res, int k) {
        if(amount<0||(res>=0&&count>=res)) return;
        if(amount==0) {
            cout<<count<<endl;
            res = (res == -1 || res > count) ? count : res;
            return;
        }
        amount -= coins[k];
        ++count;
        for(int i=k;i>=0;--i)
            helper(coins, amount, count, res, i);
        amount += coins[k];
        --count;
    }
};
*/

//DP:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1;i<amount+1;++i) {
            for(int j=0;j<coins.size();++j) {
                if(i>=coins[j]) dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount]==amount+1 ? -1 : dp[amount];
    }
};
