class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> dicts, dictt;
        for (int i=0;i<s.size();++i) {
            if (dicts.find(s[i])!=dicts.end()) {
                if (t[i]!=dicts[s[i]]) return false;
            }
            else dicts[s[i]] = t[i];
            if (dictt.find(t[i])!=dictt.end()) {
                if (s[i]!=dictt[t[i]]) return false;
            }
            else dictt[t[i]] = s[i];
        }
        return true;
    }
};
