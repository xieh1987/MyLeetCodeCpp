class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        if(len<3||(nums[0]+nums[1]+nums[2]>0)||(nums[len-1]+nums[len-2]+nums[len-3]<0)) return res;
        for(auto i=0;i<len-2;++i) {
            int x = -nums[i];
            int j = i+1, k = len-1;
            while(j<k) {
                if(nums[j]+nums[k]>x) --k;
                else if(nums[j]+nums[k]<x) ++j;
                else {
                    vector<int> triplet{nums[i], nums[j], nums[k]};
                    res.push_back(triplet);
                    while(j<k&&nums[j]==nums[j+1]) ++j;
                    while(j<k&&nums[k]==nums[k-1]) --k;
                    ++j;
                    --k;
                }
            }
            while(i<len-2&&nums[i]==nums[i+1]) ++i;
        }
        return res;
    }
};
