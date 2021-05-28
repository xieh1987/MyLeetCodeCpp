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

/* Use math
class Solution {
public:
    int arrangeCoins(int n) {
        int res = int((sqrt(8 * long(n) + 1) - 1) / 2);
        return res;
    }
};
*/
