class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sold = INT_MIN, held = INT_MIN, reset = 0;
    for (int i = 0; i < prices.size(); i++) {
      int preSold = sold;
      
      sold = held + prices[i];
      held = max(held, reset - prices[i]);
      reset = max(reset, preSold);
    }
    return max(sold, reset);
  }
};
