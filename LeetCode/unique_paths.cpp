class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for (int col = 1; col < n; col++) {
            for (int row = 1; row < m; row++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};
