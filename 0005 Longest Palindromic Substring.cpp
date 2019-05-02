class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2) return s;
        int len = 0, start = 0;
        for(int i=0;i+len/2<=n;)
        {
            int left = i, right = i;
            while(right<n-1&&s[right]==s[right+1]) ++right;
            i = right + 1;
            while(left>0&&right<n-1&&s[left-1]==s[right+1])
            {
                ++right;
                --left;
            }
            if(len<right-left+1)
            {
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};
