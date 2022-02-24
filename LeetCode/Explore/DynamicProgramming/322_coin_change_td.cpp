class Solution {
  
private:
  int dfs(vector<int> &coins, int amount, vector<int> &dp) {
    if (amount < 0) {
      return -1;
    }
    if (amount == 0) {
      return 0;
    }
    if (dp[amount - 1] != 0) {
      return dp[amount - 1];
    }
    int minVal = INT_MAX;
    for (auto &coin : coins) {
      int res = dfs(coins, amount - coin, dp);
      if (res >= 0 && res < minVal) {
        minVal = 1 + res;
      }
    }
    dp[amount - 1] = (minVal < INT_MAX) ? minVal : -1;
    return dp[amount - 1];
  }
  
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount, 0);
    return dfs(coins, amount, dp);
  }
};
