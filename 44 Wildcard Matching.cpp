class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while(i<s.size())
        {
            if(p.size()==0) return false;
            if(p[j]==s[i]||p[j]=='?')
            {
                ++i;
                ++j;
            }
            else if(p[j]=='*')
            {
                jStar = j++;
                iStar = i;
            }
            else if(jStar>=0)
            {
                j = jStar + 1;
                i = ++iStar;
            }
            else return false;
        }
        while(j<p.size())
            if(p[j++]!='*') return false;
        return true;
    }
};
