class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val)
                nums[i-count] = nums[i];
            else
                ++count;
        }
        return nums.size()-count;
    }
};
