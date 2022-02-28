class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int minPrice = prices[0], maxGain = 0;
    for (auto &price : prices) {
      if (price < minPrice) {
        minPrice = price;
      }
      else {
        maxGain = max(maxGain, price - minPrice);
      }
    }
    return maxGain;
  }
};
