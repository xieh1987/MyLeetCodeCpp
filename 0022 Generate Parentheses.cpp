class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        helper(n, res, s, 0, 0);
        return res;
    }
    
    void helper(int n, vector<string>& res, string s, int left, int right) {
        if(left+right==n*2) {
            res.push_back(s);
            return;
        }
        if(left<n)
            helper(n, res, s+'(', left+1, right);
        if(left>right)
            helper(n, res, s+')', left, right+1);
    }
};
