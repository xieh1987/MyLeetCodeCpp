class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i!=nums1.size();++i){
            if(find(nums2.begin(), nums2.end(), nums1[i])!=nums2.end()){
                res.push_back(nums1[i]);
            }
        }
        sort(res.begin(), res.end());
        vector<int>::iterator it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(),it));
        return res;
    }
};

/* Use set to remove duplicates

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> res;
        if(!len1||!len2) return res;
        if(len1>len2) swap(nums1, nums2);
        unordered_set<int> n1, res_set;
        for(auto n : nums1)
            n1.insert(n);
        for(auto n : nums2){
            if(n1.find(n)!=n1.end())
                res_set.insert(n);
        }
        for(auto n : res_set)
            res.push_back(n);
        return res;
    }
};
*/
