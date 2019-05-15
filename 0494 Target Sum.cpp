class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        helper(nums, S, res, 0, 0);
        return res;
    }
    
    void helper(vector<int>& nums, int target, int& res, int sum, int level) {
        if(level==nums.size()) {
            if(sum==target) ++res;
            return;
        }
        sum += nums[level];
        helper(nums, target, res, sum, level+1);
        sum -= nums[level] * 2;
        helper(nums, target, res, sum, level+1);
    }
};
