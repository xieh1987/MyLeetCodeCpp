class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while(res.size()<n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int m = min(m2, min(m3, m5));
            if(m==m2) ++i2;
            if(m==m3) ++i3;
            if(m==m5) ++i5;
            res.push_back(m);
        }
        return res.back();
    }
};
