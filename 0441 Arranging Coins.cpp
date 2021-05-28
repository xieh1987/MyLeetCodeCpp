class Solution {
public:
    int arrangeCoins(int n) {
        if(n<1) return 0;
        for(int layer=1;;layer++) {
            n -= layer;
            if(n<=layer) return layer;
        }
    }
};
