class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        bool flag = true;
        vector<int> res(nums.size()+1);
        res[0] = 0;
        res[1] = nums[0];
        for (int i=2;i<nums.size()+1;++i) {
            if (!flag) {
                res[i] = res[i-1] + nums[i-1];
                flag = true;
            }
            else {
                if (nums[i-1]+res[i-2]>res[i-1]) {
                    res[i] = nums[i-1]+res[i-2];
                    flag = true;
                }
                else {
                    res[i] = res[i-1];
                    flag = false;
                }
            }
        }
        return res[nums.size()];
    }
};
