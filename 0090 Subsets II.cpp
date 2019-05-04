class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> vec;
        s.insert(vec);
        helper(nums, s, vec, 0);
        return vector<vector<int>>(s.begin(), s.end());
    }
    
    void helper(vector<int>& nums, set<vector<int>>& s, vector<int>& vec, int start) {
        if(start==nums.size()) return;
        vec.push_back(nums[start]);
        s.insert(vec);
        helper(nums, s, vec, start+1);
        vec.pop_back();
        helper(nums, s, vec, start+1);
    }
};
