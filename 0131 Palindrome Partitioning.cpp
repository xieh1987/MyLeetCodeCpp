class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> elem;
        helper(s, res, elem, 0);
        return res;
    }
    
    void helper(string& s, vector<vector<string>>& res, vector<string>& elem, int k) {
        if(k==s.size()) {
            res.push_back(elem);
            return;
        }
        for(int i=k;i<s.size();++i) {
            string t = s.substr(k, i-k+1);
            if(isPalindrome(t)) {
                elem.push_back(t);
                helper(s, res, elem, i+1);
                elem.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        if(s.size()<2) return true;
        int i = 0, j = s.size() - 1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};
