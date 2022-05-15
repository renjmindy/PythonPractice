class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount + 1, INT_MAX);
      dp[0] = 0;
      for (int money = 1; money <= amount; money++) {
        for (auto &coin : coins) {
          if (coin <= money && dp[money - coin] < INT_MAX) {
            dp[money] = min(dp[money], dp[money - coin] + 1);
          }
        }
      }
      return dp[amount] <= amount ? dp[amount] : -1;
    }
};
