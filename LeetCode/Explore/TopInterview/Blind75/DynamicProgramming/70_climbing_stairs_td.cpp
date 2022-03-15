// dynamical programming: Recursion with Memoization
// Complexity Analysis
// Time complexity : O(n)O(n). Size of recursion tree can go upto nn.
// Space complexity : O(n)O(n). The depth of recursion tree can go upto nn.

class Solution {
  
private:
  int dfs(int n, vector<int> &dp) {
    if (n <= 2) {
      return n;
    }
    if (dp[n] >= 0) {
      return dp[n];
    }
    else {
      return dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp);
    }
  }
  
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return dfs(n, dp);
  }
};
