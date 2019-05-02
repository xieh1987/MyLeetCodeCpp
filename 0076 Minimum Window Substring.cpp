class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.size(), lent = t.size();
        if(lens<lent||lens==0||lent==0) return "";
        
        unordered_map<char, int> dict;
        for(auto l:t){
            if(dict.find(l)!=dict.end())
                ++dict[l];
            else
                dict[l] = 1;
        }
        
        int left = 0, count = 0, minlen = lens+1;
        string res = "";
        
        for(int right=0;right<lens;++right){
            if(dict.find(s[right])!=dict.end()){
                --dict[s[right]];
                if(dict[s[right]]>=0) ++count;
            }
            while(count==lent){
                if(right-left+1<minlen){
                    minlen = right - left + 1;
                    res = s.substr(left, minlen);
                }
                if(dict.find(s[left])!=dict.end()){
                    ++dict[s[left]];
                    if(dict[s[left]]>0) --count;
                }
                ++left;
            }
        }
        return res;
    }
};
