class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0, n = nums.size(), j = 0;
        for(int i=0;i<n;++i){
            j = j>i+1?j:i+1;
            while(j<n&&nums[j]-nums[i]<k) ++j;
            if(j<n&&nums[j]-nums[i]==k) ++res;
            while(i<n-1&&nums[i]==nums[i+1]) ++i;
        }
        return res;
    }
};

/***********************************************
//Using hashmap to find pairs
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> mymap;
        for(auto num:nums) ++mymap[num];
        for(auto i:mymap){
            if(k==0&&i.second>1) ++res;
            if(k>0&&mymap.find(i.first+k)!=mymap.end()) ++res;
        }
        return res;
    }
};
************************************************/
