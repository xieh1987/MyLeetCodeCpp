class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combination;
        solve(res, combination, n, k, 1);
        return res;
    }
    
    void solve(vector<vector<int>>& res, vector<int>& combination, int n, int k, int start) {
        if(k==combination.size())
        {
            res.push_back(combination);
        }
        else
        {
            for(int i=start;i<=n;++i)
            {
                combination.push_back(i);
                solve(res, combination, n, k, i+1);
                combination.pop_back();
            }
        }
    }
};
