class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> vec, visited(nums.size(), 0);
        helper(res, nums, vec, visited, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& vec, vector<int>& visited, int len) {
        if(len==nums.size()) res.push_back(vec);
        for(int i=0;i<nums.size();++i) {
            if(visited[i]) continue;
            if(i>0&&nums[i]==nums[i-1]&&visited[i-1]==0) continue;
            visited[i] = 1;
            vec.push_back(nums[i]);
            helper(res, nums, vec, visited, len+1);
            vec.pop_back();
            visited[i] = 0;
        }
    }
};

/*Alternative Solution: refer to Problem 0046 Permutations.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(res, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int> nums, int start) {
        if(start>=nums.size()) res.push_back(nums);
        for(int i=start;i<nums.size();++i) {
            if(i!=start&&nums[i]==nums[start]) continue;
            swap(nums[i], nums[start]);
            helper(res, nums, start+1);
        }
    }
};
*/
