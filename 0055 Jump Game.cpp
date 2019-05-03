class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return true;
        int mx = 0;
        for(int i=0;i<n-1;++i) {
            if(i>mx) return false;
            int temp = nums[i] + i;
            if(temp>=n-1) return true;
            if(temp>mx) mx = temp;
        }
        return false;
    }
};
