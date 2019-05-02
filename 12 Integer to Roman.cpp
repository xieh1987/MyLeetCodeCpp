class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mymap = {{1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"}};
        string res;
        for(map<int, string>::reverse_iterator rit=mymap.rbegin();;)
        {
            if(num==0) break;
            if(num>=rit->first)
            {
                res += rit->second;
                num -= rit->first;
            }
            else ++rit;
        }
        return res;
    }
};
