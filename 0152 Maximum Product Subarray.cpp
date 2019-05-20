// DP
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dpl(nums.size(), nums[0]);
        vector<int> dps(nums.size(), nums[0]);
        int res = nums[0];
        for(int i=1;i<nums.size();++i) {
            dpl[i] = max(nums[i], max(nums[i] * dpl[i-1], nums[i] * dps[i-1]));
            dps[i] = min(nums[i], min(nums[i] * dpl[i-1], nums[i] * dps[i-1]));
            res = dpl[i]>res ? dpl[i] : res;
        }
        return res;
    }
};

/* Brute Force
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int i=0;i<nums.size();++i) {
            int t = 1;
            for(int j=i;j<nums.size();++j) {
                t *= nums[j];
                res = t>res ? t : res;
            }
        }
        return res;
    }
};
*/
