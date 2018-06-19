class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, sum = 0;
        for(int i=0;i<nums.size();++i){
            sum = sum<0? nums[i] : sum+nums[i];
            if(sum>max_sum)
                max_sum = sum;
        }
        return max_sum;
    }
};
