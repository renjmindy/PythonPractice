class Solution {
  
private:
  int dfs(int m, int n, string text1, string text2, vector<vector<int> > &dp) {
    if (m < 0 || n < 0) {
      return 0;
    }
    
    if (dp[m][n] != -1) {
      return dp[m][n];
    }
    
    if (text1[m] == text2[n]) {
      return dp[m][n] = 1 + dfs(m - 1, n - 1, text1, text2, dp);
    }
    
    return dp[m][n] = max(dfs(m - 1, n, text1, text2, dp), dfs(m, n - 1, text1, text2, dp));
  }
  
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int> > dp(text1.size(), vector<int>(text2.size(), -1));
    return dfs(text1.size() - 1, text2.size() - 1, text1, text2, dp);
  }
};
