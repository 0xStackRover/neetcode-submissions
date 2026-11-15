class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int sz = prices.size();
        int maxSell = prices[sz - 1];

        int profit = 0;
        for (int i = sz - 1; i >= 0; i--) {
            profit = max(profit, maxSell - prices[i]);
            maxSell = max(maxSell, prices[i]);
        }
        return profit;
    }
};
