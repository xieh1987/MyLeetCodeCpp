class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mx = nums[0], mn = nums[nums.size()-1], start = 0, end = -2;
        for(int i=0, j=nums.size()-1;i<nums.size();++i,--j){
            if(nums[i]<mx)
                end = i;
            else
                mx = nums[i];
            if(nums[j]>mn)
                start = j;
            else
                mn = nums[j];
        }
        return end==-2? 0 : end-start+1;
    }
};

/********************************************************************
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int left = 0, right = temp.size()-1;
        while(left<=right&&nums[left]==temp[left]){
            ++left;
        }
        while(left<right&&nums[right]==temp[right]){
            --right;
        }
        return right-left+1;
    }
};
*******************************************************************/
