//Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i=0;i<nums.size();i++) {
            if(mx<i) return false;
            mx  = max(i + nums[i], mx);
        }
        return true;
    }
};

/*
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

//Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return true;
        int mx = 0;
        for(int i=0;i<n-1;++i) {
            if(i>mx) break;
            if(nums[i] + i>mx) mx = nums[i] + i;
        }
        return mx >= n - 1;
    }
};
*/
