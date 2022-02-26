class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sold = 0, held = -prices[0], reset = 0;
    for (int i = 1; i < prices.size(); i++) {
      int preSold = sold;
      
      sold = max(sold, held + prices[i]);
      held = max(held, reset - prices[i]);
      reset = max(reset, preSold);
    }
    return max(sold, reset);
  }
};
