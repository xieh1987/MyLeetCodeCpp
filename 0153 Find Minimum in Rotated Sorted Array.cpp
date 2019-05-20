class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        while(mid!=left) {
            if(nums[mid]<nums[right]) right = mid;
            else left = mid;
            mid = left + (right - left) / 2;
        }
        return min(nums[left], nums[right]);
    }
};
