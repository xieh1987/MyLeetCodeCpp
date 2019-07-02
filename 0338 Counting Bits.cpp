class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        if(num==0) return res;
        res[1] = 1;
        if(num==1) return res;
        int n = 1;
        for(int i=2;i<=num;++i) {
            if(i==n*2) {
                res[i] = 1;
                n = i;
            }
            else
                res[i] = 1 + res[i-n];
        }
        return res;
    }
};
