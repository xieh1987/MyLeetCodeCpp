//O(n) with greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, res = 0, i=0;
        while(curr<nums.size()-1) {
            res++;
            int pre = curr;
            for(;i<=pre;++i) {
                curr = max(curr, nums[i]+i);
            }
        }
        return res;
    }
};

/*DP
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int j = 1;
        for(int i=0;i<nums.size();i++) {
            while(j<=i+nums[i]&&j<nums.size()) res[j++] = res[i] + 1;
        }
        return res[nums.size() - 1];
    }
};
*/

/* LTE solution: time complexity O(n^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i=1;i<nums.size();++i) {
            int mn = INT_MAX;
            for(int j=0;j<i;++j) {
                if(nums[j]+j>=i) mn = min(dp[j]+1, mn);
            }
            dp[i] = mn;
        }
        return dp[nums.size()-1];
    }
};
*/
