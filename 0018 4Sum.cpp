class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();     
        for(int i=0;i<n-3;++i) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;++j) {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int newtarget = target - nums[i] - nums[j], left = j + 1, right = n - 1;
                while(left<right) {
                    if(newtarget==nums[left]+nums[right]) {
                        vector<int> vec{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(vec);
                        while(left<right&&nums[left]==nums[left+1]) ++left;
                        while(left<right&&nums[right]==nums[right-1]) --right;
                        ++left;
                        --right;
                    }
                    else if(newtarget>nums[left]+nums[right]) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};
