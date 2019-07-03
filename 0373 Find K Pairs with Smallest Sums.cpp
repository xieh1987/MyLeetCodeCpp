class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        multimap<int, vector<int>> m;
        for(int i=0;i<nums1.size();++i) {
            for(int j=0;j<nums2.size();++j) {
                m.insert({nums1[i]+nums2[j], {nums1[i], nums2[j]}});
            }
        }
        for(auto it=m.begin();it!=m.end();++it) {
            res.push_back(it->second);
            if(--k<=0) break;
        }
        return res;
    }
};
