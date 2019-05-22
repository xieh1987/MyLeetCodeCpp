class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        if(denominator==0) return "0";
        bool sign = (numerator<0^denominator<0);
        string res;
        if(sign) res += '-';
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        res += to_string(num / den);
        long long rm = num % den * 10;
        if(!rm) return res;
        res += '.';
        unordered_map<long long, int> m;
        int id = res.size();
        while(rm) {
            if(m.find(rm)!=m.end()) {
                res.insert(m[rm], "(");
                res += ")";
                return res;
            }
            m[rm] = id++;
            res += to_string(rm / den);
            rm = rm % den * 10;
        }
        return res;
    }
};
