class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        res.push_back((digits[digits.size()-1]+1)%10);
        int carry = (digits[digits.size()-1]+1)/10;
        for(int i=digits.size()-2;i>=0;--i){
            res.push_back((digits[i]+carry)%10);
            carry = (digits[i]+carry)/10;
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
