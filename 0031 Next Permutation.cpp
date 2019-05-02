class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len<2) return;
        int p = len-2;
        while(p>=0){
            if(nums[p]<nums[p+1]){
                int i = p + 1;
                while(nums[i]>nums[p]&&i<len)
                    ++i;
                swap(nums[p], nums[i-1]);
                break;
            }
            else
                --p;
        }
        int q = len - 1;
        while(p + 1 < q)
            swap(nums[(p++)+1], nums[q--]);
    }
};
