class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1, 0);
        res[0] = res[1] = 1;
        for(int i=2;i<=n;++i)
            for(int m=1;m<=i;++m)
                res[i] += res[m-1] * res[i-m];
        return res[n];
    }
};
