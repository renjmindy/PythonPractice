class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    
    int gain = 0, lmin = prices[0], rmax = prices[prices.size() - 1];
    vector<int> dpl(prices.size(), 0), dpr(prices.size() + 1, 0);
    
    for (int l = 1; l < prices.size(); l++) {
      dpl[l] = max(dpl[l - 1], prices[l] - lmin);
      lmin = min(lmin, prices[l]);
    
      int r = prices.size() - l - 1;
      dpr[r] = max(dpr[r + 1], rmax - prices[r]);
      rmax = max(rmax, prices[r]);
    }
    
    for (int i = 0; i < prices.size(); i++) {
      gain = max(gain, dpl[i] + dpr[i]);
    }
    return gain;
  }
};
