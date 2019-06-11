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
