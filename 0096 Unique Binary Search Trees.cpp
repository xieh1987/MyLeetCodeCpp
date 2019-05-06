class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1, 0);
        res[0] = res[1] = 1;
        for(int i=2;i<=n;++i) {
            int sum = 0;
            for(int m=1;m<=i;++m) {
                sum += res[m-1] * res[i-m];
            }
            res[i] = sum;
        }
        return res[n];
    }
};
