class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<vector<int>> dp(nums.size());
        int id = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();++i) {
            for(int j=0;j<i;++j) {
                if(nums[i]%nums[j]==0) {
                    if(dp[j].size()>dp[i].size())
                        dp[i] = dp[j];
                }
            }
            dp[i].push_back(nums[i]);
            if(dp[i].size()>dp[id].size()) id = i;
        }
        return dp[id];
    }
};
