class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        while(left<right) {
            int mid = left + (right - left) / 2, ct = 0;
            for(int i=0;i<nums.size();++i)
                if(nums[i]<=mid) ++ct;
            if(ct<=mid) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
