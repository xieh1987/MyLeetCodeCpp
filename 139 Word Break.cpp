class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> res(len, false);
        for(int i=0;i<len;++i){
            if(isInDict(s.substr(0, i+1), wordDict)) res[i] = true;
            for(auto j=0;j<i;++j){
                if(res[j]&&isInDict(s.substr(j+1, i-j), wordDict)){
                    res[i] = true;
                    break;
                }
            }
        }
        return res[len-1];
    }
    
    bool isInDict(string s, vector<string>& dict){
        for(auto n:dict){
            if(s==n) return true;
        }
        return false;
    }
};
