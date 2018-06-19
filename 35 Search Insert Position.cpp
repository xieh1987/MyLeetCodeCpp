class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        if(target<nums[i]) return 0;
        while(nums[i]<=target){
            if(nums[i]==target) return i;
            else ++i;
        }
        if(target>nums[nums.size()-1]) return nums.size();
        else return i;
    }
};
