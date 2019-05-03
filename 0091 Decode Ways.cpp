class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len==0) return 0;
        vector<int> res(len+1);
        res[0] = 1;
        for(int i=0;i<=len;++i){
            if(s[i-1]>'0')
                res[i] = res[i-1];
            if(i>1&&s.substr(i-2,2)>="10"&&s.substr(i-2,2)<="26")
                res[i] += res[i-2];
        }
        return res[len];
    }
};

/***************************************************************
 * double pointers
 *
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len==0||s[0]=='0') return 0;
        int left = 1, right = 1;
        for(int i=1;i<len;++i){
            int curr = 0;
            if(s[i]>'0')
                curr = right;
            if(s.substr(i-1,2)>="10"&&s.substr(i-1,2)<="26")
                curr += left;
            left = right;
            right = curr;
        }
        return right;
    }
};
*/
