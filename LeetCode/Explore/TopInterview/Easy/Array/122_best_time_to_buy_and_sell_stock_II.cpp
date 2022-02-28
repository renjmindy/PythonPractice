class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sumGain = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1]) {
        sumGain += (prices[i] - prices[i - 1]);
      }
    }
    return sumGain;
  }
};
