class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    int ans = INT_MAX;
    for (int j = 0; j < matrix[0].size(); j++) {
      dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        dp[i][j] = dp[i - 1][j];
        if (j - 1 >= 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
        if (j + 1 < matrix[0].size()) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
        }
        dp[i][j] += matrix[i][j];
      }
    }
    for (int j = 0; j < matrix.size(); j++) {
      ans = min(ans, dp[matrix.size() - 1][j]);
    }
    return ans;
  }
};
