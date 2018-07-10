class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int nums_size = nums.size();
        if(nums_size==0) return 0;
        int left = 0, right = 0, sum = nums[0], len = 0;
        while(right<nums_size){
            if(sum>=s){
                len = len==0||len>right-left+1 ? right-left+1 : len;
                sum -= nums[left];
                ++left;
            }
            else
                sum += nums[++right];
        }
        return len;
    }
};
