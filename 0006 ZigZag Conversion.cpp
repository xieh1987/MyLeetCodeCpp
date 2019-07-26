class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1||numRows>=s.size()) return s;
        vector<string> v(numRows, "");
        int id = 0, dir = 1;
        for(auto c : s) {
            v[id] += c;
            if(id==0)
                dir = 1;
            if(id==numRows-1)
                dir = -1;
            id += dir;
        }
        string res = "";
        for(auto e : v) {
            res += e;
        }
        return res;
    }
};
