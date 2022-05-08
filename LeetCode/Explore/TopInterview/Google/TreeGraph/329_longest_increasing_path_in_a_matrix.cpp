class Solution {
  
private:
  vector<vector<int> > dp;
  int dfs(int i, int j, int pre, vector<vector<int> > &matrix) {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || pre >= matrix[i][j]) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    int tb = dfs(i + 1, j, matrix[i][j], matrix);
    int bt = dfs(i - 1, j, matrix[i][j], matrix);
    int lr = dfs(i, j + 1, matrix[i][j], matrix);
    int rl = dfs(i, j - 1, matrix[i][j], matrix);
    
    return dp[i][j] = 1 + max({tb, bt, lr, rl});
  }
  
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      dp.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
      int ans = 0;
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
          ans = max(ans, dfs(i, j, -1, matrix));
        }
      }
      return ans;
    }
};
