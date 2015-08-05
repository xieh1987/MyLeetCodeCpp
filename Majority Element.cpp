class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mymap;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();++it){
            if(mymap.find(*it)==mymap.end())
            mymap[*it] = 1;
            else
            mymap[*it] += 1;
            if(mymap[*it]>nums.size()/2)
            return *it;
        }
    }
};
