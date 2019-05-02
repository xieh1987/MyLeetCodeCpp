class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], count = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==res) count++;
            else{
                count--;
                if(count==0){
                    res = nums[i];
                    count++;
                }
            }
        }
        return res;
    }
};

/*Old implementation Using Map to Count All Elements
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
*/
