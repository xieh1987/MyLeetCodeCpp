class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ll = 0, rr = n-1;
        while(ll<=rr)
        {
            int mid = ll + (rr - ll) / 2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[ll])
            {
                if(nums[ll]<=target&&nums[mid]>target) rr = mid - 1;
                else ll = mid + 1;
            }
            else
            {
                if(nums[rr]>=target&&nums[mid]<target) ll = mid + 1;
                else rr = mid - 1;
            }
        }
        return -1;
    }
};
