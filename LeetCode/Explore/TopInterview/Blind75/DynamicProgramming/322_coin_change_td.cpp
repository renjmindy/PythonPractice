// dynamical programming: recursion memorization

// Complexity Analysis
// Time complexity : O(S*n)O(S∗n). where S is the amount, n is denomination count. 
// In the worst case the recursive tree of the algorithm has height of SS and the algorithm solves only SS subproblems because it caches precalculated solutions in a table. 
// Each subproblem is computed with nn iterations, one by coin denomination. Therefore there is O(S*n)O(S∗n) time complexity.
// Space complexity : O(S)O(S), where SS is the amount to change We use extra space for the memoization table.

class Solution {

private:
  int dfs(vector<int> &coins, int amount, vector<int> &dp) {
    if (amount < 0) { // base case
      return -1;
    }
    if (amount == 0) { // base case
      return 0;
    }
    if (dp[amount - 1] < INT_MAX) {
      return dp[amount - 1];
    }
    int minCoins = INT_MAX;
    for (auto &coin : coins) {
      int minCoin = dfs(coins, amount - coin, dp);
      if (minCoin >= 0 && minCoin < minCoins) {
        minCoins = 1 + minCoin;
      }
    }
    dp[amount - 1] = minCoins < INT_MAX ? minCoins : -1;
    return dp[amount - 1];
  }
  
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount, INT_MAX);
    return dfs(coins, amount, dp);
  }
};
