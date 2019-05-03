class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return vector<int>{-1, -1};
        int left = 0, right = n - 1, mid = left + (right - left) / 2;
        while(left<right) {
            if(nums[mid]>=target) {
                right = mid;
                mid = left + (right - left) / 2;
            }
            else {
                left = mid + 1;
                mid = left + (right - left) / 2;
            }
        }
        if(nums[left]!=target) return vector<int>{-1, -1};
        vector<int> res;
        res.push_back(left);
        right = n - 1;
        mid = left + (right - left + 1) / 2;
        while(left<right) {
            if(nums[mid]>target) {
                right = mid - 1;
                mid = left + (right - left + 1) / 2;
            }
            else {
                left = mid;
                mid = left + (right - left + 1) / 2;
            }
        }
        res.push_back(right);
        return res;
    }
};
