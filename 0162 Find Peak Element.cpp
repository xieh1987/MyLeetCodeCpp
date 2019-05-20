/* Linear:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m = nums.size();
        if(m<=1||nums[0]>nums[1]) return 0;
        if(nums[m-1]>nums[m-2]) return m-1;
        for(int i=1;i<m-1;++i) {
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) return i;
        }
        return 0;
    }
};
*/

// Binary Search:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left<right) {
            int mid = left + (right - left) / 2;
            if(nums[mid]<nums[mid+1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
