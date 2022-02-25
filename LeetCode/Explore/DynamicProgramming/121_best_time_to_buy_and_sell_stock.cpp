class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int minVal = prices[0], maxVal = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < minVal) {
        minVal = prices[i];
      }
      else {
        maxVal = max(maxVal, prices[i] - minVal);
      }
    }
    return maxVal;
  }
};
