class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;
        for(int i=0;i<k;i++){
            res += nums[i];
        }
        res /= k;
        vector<double> res_vec(nums.size(),0);
        res_vec[k-1] = res;
        double max = res;
        for(int i=k;i<nums.size();++i){
            res = (res_vec[i-1] * k + nums[i] - nums[i-k]) / k;
            res_vec[i] = res;
            if(max<res) max = res;
        }
        return max;
    }
};
