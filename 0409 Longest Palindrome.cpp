class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> dict;
        for(auto n : s) ++dict[n];
        bool odd = false;
        for(auto n : dict){
            res += dict[n.first] / 2;
            odd = odd || (dict[n.first]%2);
        }
        return res * 2 + odd;
    }
};
