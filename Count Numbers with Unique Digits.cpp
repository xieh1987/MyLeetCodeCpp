class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n<0)
            return 0;
        int res[11], sum[11];
        res[0] = 0, res[1] = 9, sum[0] = 1, sum[1] = sum[0] + res[1];
        if (n<=1) return sum[n];
        if (n>1&&n<=10){
            for (int i=2;i<12;++i) {
                res[i] = res[i-1] * (11-i);
                sum[i] = sum[i-1] + res[i];
            }
            return sum[n];
        }
        else return sum[11];
    };
};
