class Solution {
public:
    string countAndSay(int n) {
        vector<string> res(n);
        res[0] = '1';
        for (int i=1;i<n;++i) {
            string elem = res[i-1];
            int count = 1;
            for (int j=1;j<elem.size();++j) {
                if (elem[j]==elem[j-1]) {
                    count++;
                }
                else {
                    res[i] = res[i] + to_string(count) + elem[j-1];
                    count = 1;
                }
            }
            res[i] = res[i] + to_string(count) + elem[elem.size()-1];
        }
        return res[n-1];
    }
};
