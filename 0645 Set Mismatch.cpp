class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int duplicated, sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(s.count(nums[i])) duplicated = nums[i];
            else s.insert(nums[i]);
        }
        return {duplicated, duplicated + n * (n + 1) / 2 - sum};
    }
};
