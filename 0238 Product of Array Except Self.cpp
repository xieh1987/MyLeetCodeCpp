class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> left(n, 1), right(n, 1);
        for(int i=0;i<n-1;++i)
            left[i+1] = left[i] * nums[i];
        for(int j=n-1;j>0;--j)
            right[j-1] = right[j] * nums[j];
        for(int i=0;i<n;++i)
            res.push_back(left[i] * right[i]);
        return res;
    }
};
