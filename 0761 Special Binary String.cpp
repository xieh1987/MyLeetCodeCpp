class Solution {
public:
    string makeLargestSpecial(string S) {
        string res = "";
        int count = 0, i = 0;
        vector<string> v;
        for(int j=0;j<S.size();j++) {
            count += S[j]=='1' ? 1 : -1;
            if(count==0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        for(auto e : v) res += e;
        return res;
    }
};
