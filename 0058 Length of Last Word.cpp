class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size(), res = 0;
        while (length>0) {
            if (s[length-1]!=' ') break;
            --length;
        }
        while (length>0) {
            if (s[length-1]==' ') break;
            --length;
            ++res;
        }
        return res;
    }
};
