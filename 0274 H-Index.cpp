class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int& a, int& b){return a>b;});
        int i = 0;
        while(i<citations.size()) {
            if(citations[i]<=i) break;
            else ++i;
        }
        return i;
    }
};

/*
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0, l = citations.size();
        for(int i=0;i<l;i++) {
            if(citations[i]>=l-i) res = max(res, l-i);
        }
        return res;
    }
};
*/
