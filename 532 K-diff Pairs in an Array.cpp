class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0, n = nums.size(), j = 0;
        for(int i=0;i<n;++i){
            j = j>i+1?j:i+1;
            while(j<n&&nums[j]-nums[i]<k) ++j;
            if(j<n&&nums[j]-nums[i]==k) ++res;
            while(i<n-1&&nums[i]==nums[i+1]) ++i;
        }
        return res;
    }
};
