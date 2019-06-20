class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> mymap;
        string temp = "", res = "";
        int len = paragraph.size(), mx = 0;
        for(auto c:paragraph) {
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) temp += c;
            else {
                if(temp.size()>0) {
                    mymap[getLower(temp)]++;
                    temp = "";
                }
            }
        }
        if(temp.size()>0) mymap[getLower(temp)]++;
        for(auto s:banned) {
            s = getLower(s);
        }
        for(auto p:mymap) {
            if(find(banned.begin(), banned.end(), p.first)==banned.end()&&p.second>mx) {
                mx = p.second;
                res = p.first;
            }
        }
        return res;
    }
    
    string getLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};
