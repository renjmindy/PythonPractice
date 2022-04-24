class Solution {
public:
    bool isMatch(string s, string p) {
      vector<vector<bool> > dp(31, vector<bool>(31, false));
      for (int i = 0; i <= p.size(); i++) {
        for (int j = 0; j <= s.size(); j++) {
          if (i == 0 && j == 0) {
            dp[i][j] = true;
          }
          else if (i == 0) {
            dp[i][j] = false;
          }
          else if (j == 0) {
            if(p[i-1] != '*') {
              dp[i][j] = false;
            }
            else {
              dp[i][j] = dp[i-2][j];
            }
          }
          else {
            if (p[i-1] != '*') {
              if (p[i-1] == s[j-1] || p[i-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
              }
              else {
                dp[i][j] = false;
              }
            }
            else {
              dp[i][j] = dp[i-2][j];
              if (s[j-1] == p[i-2] || p[i-2] == '.') {
                dp[i][j] = dp[i][j] || dp[i][j-1];
              }
            }
          }
        }
      }
      return dp[p.size()][s.size()];
    }
};
