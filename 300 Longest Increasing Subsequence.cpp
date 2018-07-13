/* DP, n^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> dp(len, 1);
        int res = 0;
        
        for(auto i=0;i<len;++i){
            for(auto j=0;j<i;++j){
                if(nums[j]<nums[i])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
*/

/* Greedy+BST */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> res;
        for(auto n : nums){
            auto it = lower_bound(res.begin(), res.end(), n);
            if(it==res.end())
                res.push_back(n);
            else
                *it = n;
        }
        return res.size();
    }
};
