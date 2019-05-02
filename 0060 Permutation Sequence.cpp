class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<char> number;
        for(int i=0;i<n;++i)
            number.push_back('1' + i);
        vector<int> factorial(n, 1);
        for(int i=n-2;i>=0;--i)
            factorial[i] = (n - 1 - i) * factorial[i+1];
        for(int i=0;i<n;++i)
        {
            int digit = (k - 1) / factorial[i];
            res += number[digit];
            number.erase(number.begin() + digit);
            k = (k - 1) % factorial[i] + 1;
        }
        return res;
    }
};
