class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1==0) return num2;
        if(len2==0) return num1;
        
        int i = len1-1, j = len2-1, carry = 0;
        string res;
        while(i>=0||j>=0){
            if(i>=0) carry += num1[i--] - '0';
            if(j>=0) carry += num2[j--] - '0';
            res = to_string(carry % 10) + res;;
            carry /= 10;
        }
        if(carry) res = "1" + res;
        return res;
    }
};
