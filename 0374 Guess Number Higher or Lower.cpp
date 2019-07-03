// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int t = low + (high - low) / 2;
        int res = 0;
        do {
            res = guess(t);
            if(res==1) {
                low = t + 1;
                t = low + (high - low) / 2;
            }
            else if(res==-1) {
                high = t - 1;
                t = low + (high - low) / 2;
            }
        } while(res);
        return t;
    }
};
