class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int res = 0, copy = x;
        while (copy) {
            res = res * 10 + copy % 10;
            copy /= 10;
        }
        return res==x;
    }
};
