class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int left = 0, right = x/2+1;
        while(left<right){
            int mid = left + (right-left) / 2;
            if(x/mid<mid) right = mid;
            else left = mid+1;
        }
        return right - 1;
    }
};
