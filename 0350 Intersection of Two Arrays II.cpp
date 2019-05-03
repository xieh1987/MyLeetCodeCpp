class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> res;
        if(!len1||!len2) return res;
        
        unordered_map<int, int> occr;
        if(len1>len2) swap(nums1, nums2);
        for(auto n : nums1) ++occr[n];
        for(auto n : nums2){
            if(occr.find(n)!=occr.end()&&occr[n]){
                res.push_back(n);
                --occr[n];
            }
        }
        return res;
    }
};
