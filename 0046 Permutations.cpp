class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, int start) {
        if(start>=nums.size()) res.push_back(nums);
        for(int i=start;i<nums.size();++i) {
            swap(nums[i], nums[start]);
            helper(res, nums, start+1);
            swap(nums[i], nums[start]);
        }
    }
};

/*Alternative Solution: no change of the original nums, but record visited numbers.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec, visited(nums.size(), 0);
        helper(res, nums, vec, visited, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& vec, vector<int>& visited, int len) {
        if(len==nums.size()) res.push_back(vec);
        for(int i=0;i<nums.size();++i) {
            if(visited[i]) continue;
            visited[i] = 1;
            vec.push_back(nums[i]);
            helper(res, nums, vec, visited, len+1);
            vec.pop_back();
            visited[i] = 0;
        }
    }
};
*/
