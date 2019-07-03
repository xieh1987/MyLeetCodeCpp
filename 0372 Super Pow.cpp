class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for(int i=0;i<b.size();++i) {
            res = ((Pow(res, 10) % 1337) * (Pow(a, b[i]) % 1337)) % 1337;
        }
        return res;
    }
    
    int Pow(int x, int y) {
        if(y==0) return 1;
        if(y==1) return x % 1337;
        return ((Pow(x, y/2) % 1337) * (Pow(x, y-y/2) % 1337)) % 1337;
    }
};
