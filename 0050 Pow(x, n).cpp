class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double root = myPow(x, n/2);
        if(n%2==0) return root * root;
        if(n>0) return root * root * x;
        return root * root / x;
    }
};
