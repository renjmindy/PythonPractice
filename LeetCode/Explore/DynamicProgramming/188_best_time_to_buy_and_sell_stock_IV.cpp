class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (k == 0 || prices.size() <= 1) {
      return 0;
    }
    vector<int> cost(k + 1, INT_MAX);
    vector<int> gain(k + 1, 0);
    for (int i = 0; i < prices.size(); i++) {
      for (int j = 0; j < k; j++) {
        cost[j + 1] = min(cost[j + 1], prices[i] - gain[j]);
        gain[j + 1] = max(gain[j + 1], prices[i] - cost[j + 1]);
      }
    }
    return gain[k];
  }
};
