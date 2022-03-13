// one pass
// Complexity Analysis
// Time complexity: O(n)O(n). Only a single pass is needed.
// Space complexity: O(1)O(1). Only two variables are used.
  
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0, minPurchase = prices[0];
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < minPurchase) {
        minPurchase = prices[i];
      }
      else {
        maxProfit = max(maxProfit, prices[i] - minPurchase);
      }
    }
    return maxProfit;
  }
};
