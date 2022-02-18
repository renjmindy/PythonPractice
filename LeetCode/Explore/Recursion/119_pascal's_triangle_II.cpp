class Solution {
public:
    vector<int> getRow(int rowIndex) {
      int nrows = rowIndex + 1;
      vector<vector<int> > ans;
      for (int i = 0; i < nrows; i++) {
        vector<int> dp(i + 1, 0);
        dp[0] = 1;
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
          dp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(dp);
      }
      return ans[rowIndex];
    }
};
