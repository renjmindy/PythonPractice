class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int sold = 0, held = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      
      sold = max(sold, held + prices[i] - fee);
      held = max(held, sold - prices[i]);
    }
    return sold;
  }
};
