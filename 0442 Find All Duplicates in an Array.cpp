class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res = {};
        for (int i=0;i<nums.size();++i) {
            int id = abs(nums[i])-1;
            if(nums[id]<0) res.push_back(id+1);
            else nums[id] = -nums[id];
        }
        return res;
    }
};
