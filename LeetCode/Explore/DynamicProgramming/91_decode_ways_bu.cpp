class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i <= s.size(); i++) {
      int one = s[i - 1] - '0';
      int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      if (one >= 1) {
        dp[i] += dp[i - 1];
      }
      if (two >= 10 && two <= 26) {
        dp[i] += dp[i - 2];
      }
    }
    return dp[s.size()];
  }
};
