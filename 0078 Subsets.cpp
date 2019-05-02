class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> elem;
        vector<vector<int>> res;
        res.push_back(elem);
        helper(nums, res, elem, 0);
        return res;
    };
    
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& elem, int start)
    {
        if(start==nums.size()) return;
        elem.push_back(nums[start]);
        res.push_back(elem);
        helper(nums, res, elem, start+1);
        elem.pop_back();
        helper(nums, res, elem, start+1);
    }
};
