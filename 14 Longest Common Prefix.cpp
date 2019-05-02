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

/*Old implementation
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        string common = strs[0];
        int count = common.size();
        for (int i=1;i<strs.size();++i) {
            for (int j=0;j<count;++j) {
                if (strs[i][j]!=common[j]) {
                    common = common.substr(0,j);
                    count = j;
                }
                if (count==0) {
                    return "";
                }
            }
        }
        return common;
    }
};
*/
