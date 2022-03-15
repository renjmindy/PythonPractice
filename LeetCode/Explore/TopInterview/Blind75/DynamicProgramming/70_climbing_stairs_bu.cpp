// Dynamic Programming: bottom-up tabulation
// Complexity Analysis
// Time complexity : O(n)O(n). Single loop upto nn.
// Space complexity : O(n)O(n). dpdp array of size nn is used.

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2) { // base case
      return n;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
