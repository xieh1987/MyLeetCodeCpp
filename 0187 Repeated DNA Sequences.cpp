class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        if(n<10) return res;
        unordered_map<string, int> m;
        for(int i=0;i<n-9;++i) {
            string t = s.substr(i, 10);
            if(m.find(t)==m.end()) m[t] = 1;
            else {
                if(m[t]==-1) continue;
                if(m[t]>0) {
                    res.push_back(t);
                    m[t] = -1;
                }
            }
        }
        return res;
    }
};
