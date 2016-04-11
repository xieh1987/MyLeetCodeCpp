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
