class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for(int i = 0;i<s.size();++i) {
            int temp = int(s[i]) - 64;
            num = num * 26 + temp;
        }
        return num;
    }
};
