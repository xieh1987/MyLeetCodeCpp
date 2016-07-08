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
