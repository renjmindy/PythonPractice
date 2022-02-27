class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.back() + 1, 0);
    for (int i = 1, j = 0; i < dp.size(); i++) {
      if (i < days[j]) {
        dp[i] = dp[i - 1];
      }
      else if (i == days[j]) {
        dp[i] = dp[i - 1] + costs[0];
        dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
        dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
        j++;
      }
    }
    return dp.back();
  }
};
