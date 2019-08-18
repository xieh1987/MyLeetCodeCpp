class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> isPrime(n, true);
        for(int i=2;i<n;i++) {
            if(!isPrime[i]) continue;
            res++;
            for(int j=i;j<n;j+=i) {
                isPrime[j] = false;
            }
        }
        return res;
    }
};
