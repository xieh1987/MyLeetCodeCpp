class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> elem;
        vector<vector<int>> res;
        res.push_back(elem);
        helper(nums, res, elem, 0, n);
        return res;
    };
    
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& elem, int start, int length)
    {
        if(start==length) return;
        elem.push_back(nums[start]);
        res.push_back(elem);
        helper(nums, res, elem, start+1, length);
        elem.pop_back();
        helper(nums, res, elem, start+1, length);
    }
};
