class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = haystack.size(), length2 = needle.size();
        for(int pos1=0;pos1<length1-length2+1;++pos1){
            int pos2 = 0;
            while(pos2<needle.size()){
                if(haystack[pos1+pos2]==needle[pos2])
                    pos2++;
                else break;
            }
            if(pos2==needle.size()) return pos1;
        }
        return -1;
    }
};
