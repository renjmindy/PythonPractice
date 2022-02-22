class Solution {

private:
  int dfs(int n, vector<int> &dp) {
    if (n <= 2) {
      return n;
    }
    else {
      if (dp[n] < 0) {
        return dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp);
      }
      else {
        return dp[n];
      }
    }
  }
  
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return dfs(n, dp);
  }
};
