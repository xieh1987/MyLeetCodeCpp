class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        auto n = prices.size();
        if(n<2) return 0;
        for(int i=1;i<n;++i)
            res += prices[i]>prices[i-1]? prices[i]-prices[i-1] : 0;
        return res;
    }
};
