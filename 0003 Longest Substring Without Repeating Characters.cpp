class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, n = s.size(), res = 0;
        unordered_map<char, int> mymap;
        for(int i=0;i<n;++i)
        {
            if(mymap.find(s[i])!=mymap.end()&&mymap[s[i]]>left)
                left = mymap[s[i]];
            mymap[s[i]] = i;
            res = max(res, i-left);
        }
        return res;
    }
};
