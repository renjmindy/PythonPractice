// dynamical programming: bottom-up tabulation
// Complexity Analysis
// Time complexity : O(S*n)O(S∗n). On each step the algorithm finds the next F(i)F(i) in nn iterations, where 1\leq i \leq S1≤i≤S. 
// Therefore in total the iterations are S*nS∗n.
// Space complexity : O(S)O(S). We use extra space for the memoization table.

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto &coin : coins) {
        if (coin <= i && dp[i - coin] != INT_MAX) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        } 
      }
    }
    return dp[amount] <= amount ? dp[amount] : -1;
  }
};
