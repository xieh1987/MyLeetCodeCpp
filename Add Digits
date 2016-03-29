class Solution {
public:
    int addDigits(int num) {
        int sum = num%10, res = num/10;
        while(res>0){
            sum += res%10;
            res /= 10;
        }
        if(sum<10)
            return sum;
        else
            return addDigits(sum);
    }
};
