class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxGain = INT_MIN, curCost = prices[0];
      for (int i = 1; i < prices.size(); i++) {
        if (curCost > prices[i]) {
          curCost = prices[i];
        }
        else {
          maxGain = max(maxGain, prices[i] - curCost);
        }
      }
      return maxGain > INT_MIN ? maxGain : 0;
    }
};
