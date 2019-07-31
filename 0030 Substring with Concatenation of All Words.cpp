class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = s.size(), n = words.size();
        if(m==0||n==0) return {};
        int wl = words[0].size();
        unordered_map<string, int> mymap;
        vector<int> res;
        for(auto s : words) mymap[s]++;
        for(int i=0;i<=m-n*wl;++i) {
            unordered_map<string, int> wordct;
            int j = 0;
            for(j=0;j<n;++j) {
                string t = s.substr(i + j * wl, wl);
                if(mymap.find(t)==mymap.end()) break;
                wordct[t]++;
                if(wordct[t]>mymap[t]) break;
            }
            if(j==n) res.push_back(i);
        }
        return res;
    }
};
