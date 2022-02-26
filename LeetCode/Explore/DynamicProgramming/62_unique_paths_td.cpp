class Solution {
  
private:
  int dfs(int m, int n, vector<vector<int> > &dp) {
    if (m == 0 && n == 0) {
      dp[m][n] = 1;
    }
    
    int sum = 0;
    if (dp[m][n] == 0) {
      if (m > 0) {
        sum += dfs(m - 1, n, dp);
      }
      if (n > 0) {
        sum += dfs(m, n - 1, dp);
      }
      dp[m][n] = sum;
    }
    return dp[m][n];
  }
  
public:
  int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m, vector<int>(n, 0));
    return dfs(m - 1, n - 1, dp);
  }
};
