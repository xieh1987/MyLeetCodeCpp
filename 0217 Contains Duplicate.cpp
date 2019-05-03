class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for (int i=0;i<nums.size();++i){
            if (myset.find(nums[i])!=myset.end()) return true;
            else myset.insert(nums[i]);
        }
        return false;
    }
};

/*************************************************************
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};
**************************************************************/
