class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if(len==1) return 0;
        int mx1, mx2;
        if(nums[0]>nums[1]) {
            mx1 = 0; mx2 = 1;
        }
        else {
            mx1 = 1; mx2 = 0;
        }
        for(int i=2;i<len;++i) {
            if(nums[i]>nums[mx1]) {
                mx2 = mx1;
                mx1 = i;
            }
            else
                mx2 = nums[i]>nums[mx2] ? i : mx2;
        }
        return nums[mx1]>=nums[mx2]*2 ? mx1 : -1;
    }
};
