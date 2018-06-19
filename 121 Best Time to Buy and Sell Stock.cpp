class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<int> max_profit(n), lowest(n);
        lowest[0] = prices[0];
        max_profit[0] = 0;
        for(int i = 1;i<n;++i){
            if(prices[i]-lowest[i-1]>max_profit[i-1])
                max_profit[i] = prices[i]-lowest[i-1];
            else max_profit[i] = max_profit[i-1];
            lowest[i] = lowest[i-1]<prices[i]? lowest[i-1] : prices[i];
        }
        return max_profit[n-1];
    }
};
