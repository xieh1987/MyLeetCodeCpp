class Solution {
public:
    int trailingZeroes(int n) {
        if (n<0) return -1;
        int count = 0;
        for (long int i=5;i<=n;i*=5) {
            count += n/i;
        }
        return count;
    }
};
