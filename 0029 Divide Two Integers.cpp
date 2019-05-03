class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0||(dividend==INT_MIN&&divisor==-1)) return INT_MAX;
        int sign = (divisor>=0) ^ (dividend>=0) ? -1 : 1;
        long long m = abs((long long) dividend), n = abs((long long) divisor);
        long long res = 0;
        while(m>=n) {
            long long p = 1, q = n;
            while(m>=q<<1) {
                p <<= 1;
                q <<= 1;
            }
            res += p;
            m -= q;
        }
        return res * sign;
    }
};

//Note: in this algorithm if the input overflows 32bit signed integer the result may not be right.
