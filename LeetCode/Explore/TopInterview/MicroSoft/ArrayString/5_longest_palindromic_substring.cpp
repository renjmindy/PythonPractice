class Solution {
public:
    string longestPalindrome(string s) {
      vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
      int idx = -1, maxLen = INT_MIN;
      for (int i = 0; i < s.size(); i++) {
        for (int j = i; j >= 0; j--) {
          if (i == j) {
            dp[j][i] = true;
          }
          else if (i - j == 1) {
            dp[j][i] = (s[i] == s[j]);
          }
          else {
            dp[j][i] = dp[j + 1][i - 1] && (s[i] == s[j]); 
          }
          if (dp[j][i] && i - j + 1 > maxLen) {
            idx = j;
            maxLen = i - j + 1;
          }
        }
      }
      return s.substr(idx, maxLen);
    }
};
