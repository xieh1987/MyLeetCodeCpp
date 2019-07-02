class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int> res = {0, 0, 2, 3, 4};
        for(int i=5;i<=n;++i)
            res.push_back(res[i-3]*3);
        return res[n];
    }
};
