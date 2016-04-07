class Solution {
public:
    bool isHappy(int n) {
        if (n<0) return isHappy(-n);
        set<int> myset;
        while (n!=1) {
            if (myset.find(n)!=myset.end()) return false;
            else {
                myset.insert(n);
                n = sumDigits(n);
            }
        }
        return true;
    }
     int sumDigits(int num) {
         int res = 0, curr = num;
         while (curr) {
             res += (curr%10) * (curr%10);
             curr /= 10;
         }
         return res;
     }
};
