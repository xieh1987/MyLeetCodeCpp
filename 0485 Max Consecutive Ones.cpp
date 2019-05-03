class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                res = res<count? count : res;
                count = 0;
            }
            else ++count;
        }
        return res<count? count : res;
    }
};
