class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vecp;
        string s;
        for (int i=0;i<str.size();++i) {
            if (str[i]!=' ') {
                s = s + str[i];
            }
            else {
                if (!s.empty()) {
                    cout<<s;
                    vecp.push_back(s);
                    s.clear();
                }
            }
        }
        if (!s.empty()) {
            vecp.push_back(s);
        }
        if (pattern.size()!=vecp.size()) return false;
        unordered_map<char, string> maps;
        unordered_map<string, char> mapp;
        for (int i=0;i<pattern.size();++i) {
            if (mapp.find(vecp[i])!=mapp.end()) {
                if (pattern[i]!=mapp[vecp[i]]) return false;
            }
            else mapp[vecp[i]] = pattern[i];
        }
        for (int i=0;i<pattern.size();++i) {
            if (maps.find(pattern[i])!=maps.end()) {
                if (vecp[i]!=maps[pattern[i]]) return false;
            }
            else maps[pattern[i]] = vecp[i];
        }
        return true;
    }
};
