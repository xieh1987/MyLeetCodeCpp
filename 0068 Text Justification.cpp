class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> line;
        int space = maxWidth;
        for(int i=0;i<words.size();i++) {
            if(words[i].size()+line.size()>space) {
                res.push_back(composeLine(line, space, false));
                line.clear();
                line.push_back(words[i]);
                space = maxWidth - words[i].size();
            }
            else {
                line.push_back(words[i]);
                space -= words[i].size();
            }
        }
        res.push_back(composeLine(line, space, true));
        return res;
    }
    
    string composeLine(vector<string>& line, int space, bool lastline) {
        string res = "";
        int l = line.size();
        if(lastline || l==1) {
            for(int i=0;i<l;i++) {
                if(i!=l-1) res += line[i] + " ";
                else res += line[i];
            }
            space -= line.size() - 1;
            string tail(space, ' ');
            res += tail;
        }
        else {
            int interval = space / (l - 1), blank = space % (l - 1);
            for (int i=0;i<l;i++) {
                if(i==l-1) res += line[i];
                else if(i<blank) {
                    string t(interval+1, ' ');
                    res += line[i] + t;
                }
                else {
                    string t(interval, ' ');
                    res += line[i] + t;
                }
            }
        }
        return res;
    }
};













