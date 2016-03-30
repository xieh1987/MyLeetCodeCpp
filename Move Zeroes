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
