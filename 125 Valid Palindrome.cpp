class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<2) return true;
        string temp = "";
        for(auto n : s){
            if((n>='0'&&n<='9')||(n>='a'&&n<='z'))
                temp += n;
            if(n>='A'&&n<='Z')
                temp += n + ('a' - 'A');
        }
        int l = 0, r = temp.size()-1;
        while(l<=r){
            if(temp[l]!=temp[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};
