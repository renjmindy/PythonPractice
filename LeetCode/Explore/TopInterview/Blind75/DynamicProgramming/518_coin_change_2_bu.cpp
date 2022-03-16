// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Time complexity: \mathcal{O}(N \times \textrm{amount})O(N×amount), where N is a length of coins array.
// Space complexity: \mathcal{O}(\textrm{amount})O(amount) to keep dp array.

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto &coin : coins) {
      for (int i = 1; i < amount + 1; i++) {
        if (coin <= i) {
          dp[i] += dp[i - coin];
        }
      }
    }
    return dp[amount];
  }
};
