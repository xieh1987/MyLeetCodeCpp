class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, n = str.size();
        int i = 0, res = 0;
        while(i<n&&str[i]==' ') ++i;
        if(i<n&&(str[i]=='-'||str[i]=='+')) sign = str[i++]=='+' ? 1 : -1;
        while(i<n&&str[i]>='0'&&str[i]<='9')
        {
            int digit = str[i] - '0';
            if(res>INT_MAX/10||(res==INT_MAX/10&&digit>7))
                return sign==1? INT_MAX : INT_MIN;
            res = res * 10 + digit;
            ++i;
        }
        return res * sign;
    }
};
