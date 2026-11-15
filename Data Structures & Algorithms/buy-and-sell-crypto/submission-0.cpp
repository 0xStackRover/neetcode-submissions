class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int answer = 0;
        int minBuy = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            minBuy = min(minBuy, prices[i - 1]);
            answer = max(answer, prices[i] - minBuy);
        }
        return answer;
    }
};
