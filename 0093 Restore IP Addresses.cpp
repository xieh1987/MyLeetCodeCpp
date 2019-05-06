class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string elem = "";
        helper(res, s, elem, 0, 0);
        return res;
    }
    
    bool checkValid(string& s) {
        int n = s.size();
        if(n<1||n>3) return false;
        if(n==2&&s[0]=='0') return false;
        if(n==3) {
            if(s[0]=='0'||s[0]>'2') return false;
            if(s[0]=='2') {
                if(s[1]>'5') return false;
                else if(s[1]=='5'&&s[2]>'5') return false;
            }
        }
        return true;
    }
    
    void helper(vector<string>& res, string& s, string elem, int len, int seg) {
        if(len==s.size()&&seg==4){
            res.push_back(elem.substr(1));
            return;
        }
        else if(len>=s.size()||seg>=4) return;
        else {
            string temp = "";
            for(int i=len;i<len+3&&i<s.size();++i) {
                temp += s[i];
                if(checkValid(temp))
                    helper(res, s, elem+'.'+temp, len+temp.size(), seg+1);
            }
        }
    }
};
