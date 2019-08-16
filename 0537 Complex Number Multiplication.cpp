class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> comp1 = stringToComplex(a);
        vector<int> comp2 = stringToComplex(b);
        int re = comp1[0] * comp2[0] - comp1[1] * comp2[1];
        int im = comp1[0] * comp2[1] + comp1[1] * comp2[0];
        return to_string(re) + "+" + to_string(im) + "i";
    }
    
    vector<int> stringToComplex(string& num) {
        vector<int> res;
        int sign = 1, i = 0;
        if(num[0]=='-') {
            sign = -1;
            i++;
        }
        string t = "";
        while(num[i]!='+'&&num[i]!='-')
            t += num[i++];
        res.push_back(stoi(t) * sign);
        t = "";
        if(num[i]=='+') {
            sign = 1;
            i++;
        }
        if(num[i]=='-') {
            sign = -1;
            i++;
        }
        while(i<num.size())
            t += num[i++];
        res.push_back(stoi(t) * sign);
        return res;
    }
};
