class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxGain = 0, minCost = prices[0];
      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minCost) {
          minCost = prices[i];
        }
        else {
          maxGain = max(maxGain, prices[i] - minCost);
        }
      }
      return maxGain;
    }
};
