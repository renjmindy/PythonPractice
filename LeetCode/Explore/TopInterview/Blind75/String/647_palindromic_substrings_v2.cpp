class Solution {
public:
    int countSubstrings(string s) {
      vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
      int ans = 0;
      for (int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
        ans++;
      }
      for (int i = 1; i < s.size(); i++) {
        dp[i - 1][i] = (s[i - 1] == s[i]);
        ans += dp[i - 1][i];
      }
      for (int len = 2; len < s.size(); len++) {
        for (int i = 0, j = i + len; j < s.size(); i++, j++) {
          dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
          ans += dp[i][j];
        }
      }
      return ans;
    }
};
