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

/*No set used. Use a vector added to check visit and remove duplicates
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> vec, added(nums.size(), false);
        res.push_back(vec);
        helper(nums, res, vec, added, 0);
        return res;
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& vec, vector<int>& added, int start) {
        if(start==nums.size()) return;
        if(start==0||(start>0&&(nums[start]!=nums[start-1]||(nums[start]==nums[start-1]&&added[start-1])))) {
            vec.push_back(nums[start]);
            res.push_back(vec);
            added[start] = true;
            helper(nums, res, vec, added, start+1);
            vec.pop_back();
            added[start] = false;
        }
        helper(nums, res, vec, added, start+1);
    }
};
*/
