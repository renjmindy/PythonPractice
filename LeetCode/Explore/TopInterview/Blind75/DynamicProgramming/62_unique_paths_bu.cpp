// dynamical programming: bottom-up 

// Complexity Analysis
// Time complexity: \mathcal{O}(N \times M)O(N×M).
// Space complexity: \mathcal{O}(N \times M)O(N×M).

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m, vector<int>(n, 0));
    dp[0][0] = 1; // base case
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0) { // row
          dp[i][j] += dp[i - 1][j];
        }
        if (j > 0) { // column
          dp[i][j] += dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
