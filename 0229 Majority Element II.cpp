class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1 = 0, res2 = 0, count1 = 0, count2 = 0;
        for(auto num : nums){
            if(num==res1) ++count1;
            else if(num==res2) ++count2;
            else if(count1==0) res1 = num, count1 = 1;
            else if(count2==0) res2 = num, count2 = 1;
            else --count1, --count2;
        }
        count1 = 0, count2 = 0;
        for(auto num : nums){
            if(num==res1) ++count1;
            else if(num==res2) ++count2;
        }
        vector<int> res;
        if(count1>nums.size()/3) res.push_back(res1);
        if(count2>nums.size()/3) res.push_back(res2);
        return res;
    }
};
