class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mymap;
        for(unsigned int i=0;i<nums.size();++i){
            if(mymap.find(target-nums[i])==mymap.end()){
                mymap[nums[i]] = i;
            }
            else{
                res.push_back(mymap[target-nums[i]]);
                res.push_back(i);
                return res;
            }
        }
    }
};
