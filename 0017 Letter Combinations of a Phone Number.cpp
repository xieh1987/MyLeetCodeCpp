class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string> {};
        
        vector<string> res{""};
        unordered_map<char, vector<char>> dict{{'2',{'a','b','c'}}, {'3',{'d','e','f'}}, {'4',{'g','h','i'}},
                                           {'5',{'j','k','l'}}, {'6',{'m','n','o'}}, {'7',{'p','q','r','s'}},
                                           {'8',{'t','u','v'}}, {'9',{'w','x','y','z'}}};
        
        for(auto num : digits){
            vector<string> temp;
            for(auto letter : dict[num]){
                for(auto str : res)
                    temp.push_back(str+letter);
            }
            res = temp;
        }
        return res;
    }
};
