class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0], count = 1;
        for(vector<int>::iterator it = nums.begin()+1;it!=nums.end();++it){
            if(*it==result) ++count;
            else{
                --count;
                if(count==0){
                    result = *it;
                    count = 1;
                }
            }
        }
        return result;
    }
};
