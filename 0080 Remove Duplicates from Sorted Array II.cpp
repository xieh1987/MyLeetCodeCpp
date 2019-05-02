class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        for(int i=2;i<n;++i)
        {
            if(nums[i]==nums[i-2])
            {
                nums.erase(nums.begin()+i--);
                --n;
            }
        }
        return n;
    }
};
