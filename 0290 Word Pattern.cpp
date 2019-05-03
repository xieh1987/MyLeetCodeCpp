class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        vector<string> words = S2W(str);
        if(words.size()!=pattern.size()) return false;
        for(int i=0;i<pattern.size();i++){
            if(s2p.find(words[i])!=s2p.end()){
                if(s2p[words[i]]!=pattern[i]) return false;
            }
            else if(p2s.find(pattern[i])!=p2s.end())
                return false;
            else{
                s2p[words[i]] = pattern[i];
                p2s[pattern[i]] = words[i];
            }
        }
        return true;
    }
    
    vector<string> S2W(string str) {
        vector<string> res;
        string word;
        for(int i=0;i<str.size();i++){
            if(str[i]!=' ')
                word += str[i];
            else{
                res.push_back(word);
                word.clear();
            }
        }
        if(word!="")
            res.push_back(word);
        return res;
    }
};
