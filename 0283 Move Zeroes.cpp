class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p_0 = 0;
        for(int i=0;i<nums.size();++i)
            if(nums[i])
                swap(nums[i], nums[p_0++]);
    }
};

/****************************************************
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idzero = 0;
        for (int index=0;index<nums.size();++index) {
            if (nums[index]!=0) {
                nums[idzero++] = nums[index];
            }
        }
        for (int i=idzero;i<nums.size();++i) {
            nums[i] = 0;
        }
    }
};
***************************************************/
