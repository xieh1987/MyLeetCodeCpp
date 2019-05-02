class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string res = "";
        for(int i=0;i<strs[0].size();++i)
        {
            for(auto s:strs)
                if(i>s.size()-1||s[i]!=strs[0][i]) return res;
            res += strs[0][i];
        }
        return res;
    }
};
