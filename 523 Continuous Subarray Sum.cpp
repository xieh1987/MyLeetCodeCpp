class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len<2) return false;
        if(k==0){
            for(int i=1;i<len;++i)
                if(nums[i]+nums[i-1]==0) return true;
            return false;
        }
        
        int sum = 0;
        unordered_map<int, int> rm; //remaining and the index
        rm[0] = -1;
        for(int i=0;i<len;++i){
            sum += nums[i];
            if(rm.find(sum%k)==rm.end()) rm[sum%k] = i;
            else if(i-rm[sum%k]>=2)
                return true;
        }
        return false;
    }
};
