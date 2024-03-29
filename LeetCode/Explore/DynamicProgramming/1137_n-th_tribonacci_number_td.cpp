class Solution {

private:
  int dfs(int n, vector<int> &dp) {
    if (n == 0) {
      return 0;
    }
    else if (n >= 1 && n <= 2) {
      return 1;
    }
    else {
      if (dp[n] < 0) {
        dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp) + dfs(n - 3, dp);
      }
    }
    return dp[n];
  }
  
public:
  int tribonacci(int n) {
    vector<int> dp(n + 1, -1);
    return dfs(n, dp);
  }
};
