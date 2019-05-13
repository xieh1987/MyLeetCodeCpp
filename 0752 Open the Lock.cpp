class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        if(deadset.count("0000")) return -1;
        int res = 0;
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited{"0000"};
        while(!q.empty()) {
            ++res;
            int len = q.size();
            for(int i=0;i<len;++i) {
                string t = q.front();
                q.pop();
                for(int j=0;j<4;++j) {
                    string s = t;
                    s[j] = (s[j] - '0' + 11) % 10 + '0';
                    if(s==target) return res;
                    if(!visited.count(s)&&!deadset.count(s)) {
                        q.push(s);
                        visited.insert(s);
                    }
                    s = t;
                    s[j] = (s[j] - '0' + 9) % 10 + '0';
                    if(s==target) return res;
                    if(!visited.count(s)&&!deadset.count(s)) {
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        return -1;
    }
};
