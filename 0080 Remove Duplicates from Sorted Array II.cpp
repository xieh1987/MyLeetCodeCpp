//Removed the elements in-place: Simpler version
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=2;i<nums.size();i++) {
            while(nums[i]==nums[i-2]&&i<nums.size()) nums.erase(nums.begin()+i);
        }
        return nums.size();
    }
};

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        for(int i=2;i<n;++i)
        {
            if(nums[i]==nums[i-2])
            {
                nums.erase(nums.begin()+i--);
                --n;
            }
        }
        return n;
    }
};
*/
