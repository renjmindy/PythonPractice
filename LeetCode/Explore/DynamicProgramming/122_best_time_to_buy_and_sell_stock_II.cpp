class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int minVal = prices[0], maxVal = 0, sumVal = 0;
      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minVal) {
          minVal = prices[i];
        }
        else {
          maxVal = max(maxVal, prices[i] - minVal);
        }
        if (prices[i] > prices[i - 1]) {
          sumVal += (prices[i] - prices[i - 1]);
        }
      }
      return sumVal;
    }
};
