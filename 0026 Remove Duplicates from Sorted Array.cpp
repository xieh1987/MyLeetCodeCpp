//Removed the elements in-place
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();++i) {
            while(nums[i]==nums[i-1]&&i<nums.size()) nums.erase(nums.begin()+i);
        }
        return nums.size();
    }
};

/*Only calculated the new size
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=1) return nums.size();
        int count = 1;
        for (int i=1;i<nums.size();++i) {
            if (nums[i]!=nums[i-1]) nums[count++] = nums[i];
        }
        return count;
    }
};
*/
